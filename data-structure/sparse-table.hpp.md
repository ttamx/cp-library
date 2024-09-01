---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/suffix-array.hpp
    title: string/suffix-array.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/staticrmq.test.cpp
    title: verify/yosupo/data-structure/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/string/number_of_substrings2.test.cpp
    title: verify/yosupo/string/number_of_substrings2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/string/suffixarray.test.cpp
    title: verify/yosupo/string/suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sparse-table.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-06-12\n * Description: Sparse Table class.\n */\n\ntemplate<class\
    \ Monoid>\nstruct SparseTable{\n    using T = typename Monoid::value_type;\n \
    \   int n;\n    vector<vector<T>> t;\n    SparseTable(){}\n    SparseTable(const\
    \ vector<T> &a){init(a);}\n    void init(const vector<T> &a){\n        n=(int)a.size();\n\
    \        int lg=31-__builtin_clz(n);\n        t.assign(lg+1,vector<T>(n,Monoid::unit()));\n\
    \        t[0]=a;\n        for(int i=0;i<lg;i++){\n            for(int j=0;j+(2<<i)<=n;j++){\n\
    \                t[i+1][j]=Monoid::op(t[i][j],t[i][j+(1<<i)]);\n            }\n\
    \        }\n    }\n    T query(int l,int r){\n        int lg=31-__builtin_clz(r-l+1);\n\
    \        return Monoid::op(t[lg][l],t[lg][r-(1<<lg)+1]);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-12\n * Description:\
    \ Sparse Table class.\n */\n\ntemplate<class Monoid>\nstruct SparseTable{\n  \
    \  using T = typename Monoid::value_type;\n    int n;\n    vector<vector<T>> t;\n\
    \    SparseTable(){}\n    SparseTable(const vector<T> &a){init(a);}\n    void\
    \ init(const vector<T> &a){\n        n=(int)a.size();\n        int lg=31-__builtin_clz(n);\n\
    \        t.assign(lg+1,vector<T>(n,Monoid::unit()));\n        t[0]=a;\n      \
    \  for(int i=0;i<lg;i++){\n            for(int j=0;j+(2<<i)<=n;j++){\n       \
    \         t[i+1][j]=Monoid::op(t[i][j],t[i][j+(1<<i)]);\n            }\n     \
    \   }\n    }\n    T query(int l,int r){\n        int lg=31-__builtin_clz(r-l+1);\n\
    \        return Monoid::op(t[lg][l],t[lg][r-(1<<lg)+1]);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - string/suffix-array.hpp
  timestamp: '2024-06-12 17:31:48+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/string/number_of_substrings2.test.cpp
  - verify/yosupo/string/suffixarray.test.cpp
  - verify/yosupo/data-structure/staticrmq.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse-table.hpp
- /library/data-structure/sparse-table.hpp.html
title: data-structure/sparse-table.hpp
---
