"""oj-bundle the given file, drop #line directives, and strip comments from library code.

Usage: python bundle.py main.cpp [-I dir]...

Comments in the main file are kept; only code that came from included headers is stripped.
"""
import argparse
import json
import os
import pathlib
import sys

from onlinejudge_verify.languages.cplusplus import CPlusPlusLanguage


def is_digit_separator(line, i):
    k = i - 1
    while k >= 0 and (line[k].isalnum() or line[k] in "'._"):
        k -= 1
    return line[k + 1:i][:1].isdigit()


def strip_comments(line, state):
    out = []
    i, n = 0, len(line)
    while i < n:
        if state['block']:
            j = line.find('*/', i)
            if j < 0:
                break
            state['block'] = False
            i = j + 2
            continue
        c = line[i]
        if line.startswith('//', i):
            break
        if line.startswith('/*', i):
            state['block'] = True
            out.append(' ')
            i += 2
            continue
        if c == '"' or (c == "'" and not is_digit_separator(line, i)):
            j = i + 1
            while j < n and line[j] != c:
                j += 2 if line[j] == '\\' else 1
            out.append(line[i:j + 1])
            i = j + 1
            continue
        out.append(c)
        i += 1
    return ''.join(out)


def bundle(path, include_paths):
    code = CPlusPlusLanguage().bundle(path, basedir=include_paths[0], options={'include_paths': include_paths})
    lines = code.decode('utf-8', 'surrogateescape').split('\n')

    def resolve(name):
        p = pathlib.Path(name)
        if not p.is_absolute():
            p = include_paths[0] / p
        return p.resolve()

    def is_main(p):
        try:
            return os.path.samefile(p, path)
        except OSError:
            return False

    def label(p):
        if is_main(p):
            return p.name
        for d in include_paths[1:] + include_paths[:1]:
            try:
                return p.relative_to(d.resolve()).as_posix()
            except ValueError:
                pass
        return p.as_posix()

    result = []
    in_main = True
    state = {'block': False}
    pending = last = None
    for line in lines:
        if line.startswith('#line '):
            p = resolve(json.loads(line.split(' ', 2)[2]))
            in_main = is_main(p)
            state['block'] = False
            pending = label(p)
            continue
        if not in_main:
            stripped = strip_comments(line, state).rstrip()
            if stripped != line.rstrip() and not stripped.strip():
                continue
            line = stripped
        if not line.strip():
            if pending is not None or (result and not result[-1].strip()):
                continue
        elif pending is not None:
            if pending != last:
                if result and result[-1].strip():
                    result.append('')
                result.append('// ' + pending)
                last = pending
            pending = None
        result.append(line)
    while result and not result[-1].strip():
        result.pop()
    return '\n'.join(result) + '\n'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('path', type=pathlib.Path)
    parser.add_argument('-I', metavar='dir', action='append', type=pathlib.Path, dest='include', default=[pathlib.Path.cwd()])
    args = parser.parse_args()
    try:
        code = bundle(args.path, args.include)
    except Exception as e:
        print(f'bundle failed: {e}', file=sys.stderr)
        sys.exit(1)
    sys.stdout.buffer.write(code.encode('utf-8', 'surrogateescape'))


if __name__ == '__main__':
    main()
