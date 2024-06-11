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
    \ T = uint32_t,class S = int>\nstruct BinaryTrie{\n    struct Node{\n        array<Node*,2>\
    \ ch;\n        S cnt;\n        Node():ch{nullptr,nullptr},cnt(0){}\n    };\n \
    \   Node* root;\n    BinaryTrie():root(new Node()){}\n    S size(){\n        return\
    \ root->cnt;\n    }\n    S get_cnt(Node* t){\n        return t?t->cnt:0;\n   \
    \ }\n    void insert(T x,S k=1){\n        Node* t=root;\n        t->cnt+=k;\n\
    \        for(int i=BIT-1;i>=0;i--){\n            int u=x>>i&1;\n            if(!t->ch[u])t->ch[u]=new\
    \ Node();\n            t=t->ch[u];\n            t->cnt+=k;\n        }\n    }\n\
    \    void erase(T x,S k=1){\n        Node* t=root;\n        t->cnt-=k;\n     \
    \   for(int i=BIT-1;i>=0;i--){\n            int u=x>>i&1;\n            t=t->ch[u];\n\
    \            t->cnt-=k;\n        }\n    }\n    T kth(S k,T x=0){\n        Node*\
    \ t=root;\n        T res=0;\n        for(int i=BIT-1;i>=0;i--){\n            int\
    \ u=x>>i&1;\n            if(k<get_cnt(t->ch[u])){\n                t=t->ch[u];\n\
    \            }else{\n                res|=T(1)<<i;\n                k-=get_cnt(t->ch[u]);\n\
    \                t=t->ch[u^1];\n            }\n        }\n        return res;\n\
    \    }\n    T min(T x){\n        return kth(0,x);\n    }\n    T max(T x){\n  \
    \      return kth(size()-1,x);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-11\n * Description:\
    \ Binary Trie\n */\n\ntemplate<int BIT,class T = uint32_t,class S = int>\nstruct\
    \ BinaryTrie{\n    struct Node{\n        array<Node*,2> ch;\n        S cnt;\n\
    \        Node():ch{nullptr,nullptr},cnt(0){}\n    };\n    Node* root;\n    BinaryTrie():root(new\
    \ Node()){}\n    S size(){\n        return root->cnt;\n    }\n    S get_cnt(Node*\
    \ t){\n        return t?t->cnt:0;\n    }\n    void insert(T x,S k=1){\n      \
    \  Node* t=root;\n        t->cnt+=k;\n        for(int i=BIT-1;i>=0;i--){\n   \
    \         int u=x>>i&1;\n            if(!t->ch[u])t->ch[u]=new Node();\n     \
    \       t=t->ch[u];\n            t->cnt+=k;\n        }\n    }\n    void erase(T\
    \ x,S k=1){\n        Node* t=root;\n        t->cnt-=k;\n        for(int i=BIT-1;i>=0;i--){\n\
    \            int u=x>>i&1;\n            t=t->ch[u];\n            t->cnt-=k;\n\
    \        }\n    }\n    T kth(S k,T x=0){\n        Node* t=root;\n        T res=0;\n\
    \        for(int i=BIT-1;i>=0;i--){\n            int u=x>>i&1;\n            if(k<get_cnt(t->ch[u])){\n\
    \                t=t->ch[u];\n            }else{\n                res|=T(1)<<i;\n\
    \                k-=get_cnt(t->ch[u]);\n                t=t->ch[u^1];\n      \
    \      }\n        }\n        return res;\n    }\n    T min(T x){\n        return\
    \ kth(0,x);\n    }\n    T max(T x){\n        return kth(size()-1,x);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2024-06-11 21:32:30+07:00'
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
