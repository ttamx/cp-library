---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/unionfind.test.cpp
    title: verify/yosupo/data-structure/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/dsu.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-06-28\n * Description: Disjoint Set Union.\n */\n\nstruct DSU{\n\
    \    vector<int> p,sz;\n    DSU(){}\n    DSU(int n){init(n);}\n    void init(int\
    \ n){\n        p.resize(n);\n        iota(p.begin(),p.end(),0);\n        sz.assign(n,1);\n\
    \    }\n    int find(int u){\n        return p[u]==u?u:p[u]=find(p[u]);\n    }\n\
    \    bool same(int u,int v){\n        return find(u)==find(v);\n    }\n    bool\
    \ merge(int u,int v){\n        u=find(u),v=find(v);\n        if(u==v)return false;\n\
    \        sz[u]+=sz[v];\n        p[v]=u;\n        return true;\n    }\n    int\
    \ size(int u){\n        return sz[find(u)];\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n * Description:\
    \ Disjoint Set Union.\n */\n\nstruct DSU{\n    vector<int> p,sz;\n    DSU(){}\n\
    \    DSU(int n){init(n);}\n    void init(int n){\n        p.resize(n);\n     \
    \   iota(p.begin(),p.end(),0);\n        sz.assign(n,1);\n    }\n    int find(int\
    \ u){\n        return p[u]==u?u:p[u]=find(p[u]);\n    }\n    bool same(int u,int\
    \ v){\n        return find(u)==find(v);\n    }\n    bool merge(int u,int v){\n\
    \        u=find(u),v=find(v);\n        if(u==v)return false;\n        sz[u]+=sz[v];\n\
    \        p[v]=u;\n        return true;\n    }\n    int size(int u){\n        return\
    \ sz[find(u)];\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dsu.hpp
  requiredBy: []
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/unionfind.test.cpp
documentation_of: data-structure/dsu.hpp
layout: document
redirect_from:
- /library/data-structure/dsu.hpp
- /library/data-structure/dsu.hpp.html
title: data-structure/dsu.hpp
---
