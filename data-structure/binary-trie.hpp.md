---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/set_xor_min.test.cpp
    title: verify/yosupo/data-structure/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/binary-trie.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-06-11\n * Description: Binary Trie\n */\n\ntemplate<int BIT,class\
    \ T = uint32_t,class S = int>\nstruct BinaryTrie{\n    struct Node{\n        array<int,2>\
    \ ch;\n        S cnt;\n        Node():ch{-1,-1},cnt(0){}\n    };\n    vector<Node>\
    \ t;\n    BinaryTrie():t{Node()}{}\n    int new_node(){\n        t.emplace_back(Node());\n\
    \        return t.size()-1;\n    }\n    S size(){\n        return t[0].cnt;\n\
    \    }\n    bool empty(){\n        return size()==0;\n    }\n    S get_cnt(int\
    \ i){\n        return i!=-1?t[i].cnt:S(0);\n    }\n    void insert(T x,S k=1){\n\
    \        int u=0;\n        t[u].cnt+=k;\n        for(int i=BIT-1;i>=0;i--){\n\
    \            int v=x>>i&1;\n            if(t[u].ch[v]==-1)t[u].ch[v]=new_node();\n\
    \            u=t[u].ch[v];\n            t[u].cnt+=k;\n        }\n    }\n    void\
    \ erase(T x,S k=1){\n        int u=0;\n        assert(t[u].cnt>=k);\n        t[u].cnt-=k;\n\
    \        for(int i=BIT-1;i>=0;i--){\n            int v=x>>i&1;\n            u=t[u].ch[v];\n\
    \            assert(u!=-1&&t[u].cnt>=k);\n            t[u].cnt-=k;\n        }\n\
    \    }\n    T kth(S k,T x=0){\n        assert(k<size());\n        int u=0;\n \
    \       T res=0;\n        for(int i=BIT-1;i>=0;i--){\n            int v=x>>i&1;\n\
    \            if(k<get_cnt(t[u].ch[v])){\n                u=t[u].ch[v];\n     \
    \       }else{\n                res|=T(1)<<i;\n                k-=get_cnt(t[u].ch[v]);\n\
    \                u=t[u].ch[v^1];\n            }\n        }\n        return res;\n\
    \    }\n    T min(T x){\n        return kth(0,x);\n    }\n    T max(T x){\n  \
    \      return kth(size()-1,x);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-11\n * Description:\
    \ Binary Trie\n */\n\ntemplate<int BIT,class T = uint32_t,class S = int>\nstruct\
    \ BinaryTrie{\n    struct Node{\n        array<int,2> ch;\n        S cnt;\n  \
    \      Node():ch{-1,-1},cnt(0){}\n    };\n    vector<Node> t;\n    BinaryTrie():t{Node()}{}\n\
    \    int new_node(){\n        t.emplace_back(Node());\n        return t.size()-1;\n\
    \    }\n    S size(){\n        return t[0].cnt;\n    }\n    bool empty(){\n  \
    \      return size()==0;\n    }\n    S get_cnt(int i){\n        return i!=-1?t[i].cnt:S(0);\n\
    \    }\n    void insert(T x,S k=1){\n        int u=0;\n        t[u].cnt+=k;\n\
    \        for(int i=BIT-1;i>=0;i--){\n            int v=x>>i&1;\n            if(t[u].ch[v]==-1)t[u].ch[v]=new_node();\n\
    \            u=t[u].ch[v];\n            t[u].cnt+=k;\n        }\n    }\n    void\
    \ erase(T x,S k=1){\n        int u=0;\n        assert(t[u].cnt>=k);\n        t[u].cnt-=k;\n\
    \        for(int i=BIT-1;i>=0;i--){\n            int v=x>>i&1;\n            u=t[u].ch[v];\n\
    \            assert(u!=-1&&t[u].cnt>=k);\n            t[u].cnt-=k;\n        }\n\
    \    }\n    T kth(S k,T x=0){\n        assert(k<size());\n        int u=0;\n \
    \       T res=0;\n        for(int i=BIT-1;i>=0;i--){\n            int v=x>>i&1;\n\
    \            if(k<get_cnt(t[u].ch[v])){\n                u=t[u].ch[v];\n     \
    \       }else{\n                res|=T(1)<<i;\n                k-=get_cnt(t[u].ch[v]);\n\
    \                u=t[u].ch[v^1];\n            }\n        }\n        return res;\n\
    \    }\n    T min(T x){\n        return kth(0,x);\n    }\n    T max(T x){\n  \
    \      return kth(size()-1,x);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2024-08-02 02:29:01+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/set_xor_min.test.cpp
documentation_of: data-structure/binary-trie.hpp
layout: document
redirect_from:
- /library/data-structure/binary-trie.hpp
- /library/data-structure/binary-trie.hpp.html
title: data-structure/binary-trie.hpp
---
