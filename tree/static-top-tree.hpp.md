---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/static-top-tree-dp.hpp
    title: tree/static-top-tree-dp.hpp
  - icon: ':warning:'
    path: verify/yosupo/data-structure/point_set_tree_path_composite_sum.cpp
    title: verify/yosupo/data-structure/point_set_tree_path_composite_sum.cpp
  - icon: ':warning:'
    path: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.cpp
    title: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/static-top-tree.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-11-14\n * Description: Static Top Tree.\n */\n\ntemplate<class\
    \ HLD>\nstruct StaticTopTree{\n    using P = pair<int,int>;\n    enum Type{Compress,Rake,AddEdge,AddVertex,Vertex};\n\
    \    int n,root;\n    HLD &hld;\n    vector<int> lch,rch,par;\n    vector<Type>\
    \ type;\n    StaticTopTree(HLD &_hld):hld(_hld){build();}\n    void build(){\n\
    \        n=hld.n;\n        lch=rch=par=vector<int>(n,-1);\n        type.assign(n,Compress);\n\
    \        root=compress(hld.root).first;\n    }\n    int add(int i,int l,int r,Type\
    \ t){\n        if(i==-1){\n            i=n++;\n            lch.emplace_back(l);\n\
    \            rch.emplace_back(r);\n            par.emplace_back(-1);\n       \
    \     type.emplace_back(t);\n        }else{\n            lch[i]=l,rch[i]=r,type[i]=t;\n\
    \        }\n        if(l!=-1)par[l]=i;\n        if(r!=-1)par[r]=i;\n        return\
    \ i;\n    }\n    P merge(const vector<P> &a,Type t){\n        if(a.size()==1)return\
    \ a[0];\n        vector<P> b,c;\n        int tot=0;\n        for(auto [i,s]:a)tot+=s;\n\
    \        for(auto [i,s]:a){\n            (tot>s?b:c).emplace_back(i,s);\n    \
    \        tot-=2*s;\n        }\n        auto [i,si]=merge(b,t);\n        auto [j,sj]=merge(c,t);\n\
    \        return {add(-1,i,j,t),si+sj};\n    }\n    P compress(int i){\n      \
    \  vector<P> a{add_vertex(i)};\n        while(hld.hv[i]!=-1)a.emplace_back(add_vertex(i=hld.hv[i]));\n\
    \        return merge(a,Compress);\n    }\n    P rake(int i){\n        vector<P>\
    \ a;\n        for(int j:hld.g[i])if(j!=hld.par[i]&&j!=hld.hv[i])a.emplace_back(add_edge(j));\n\
    \        return a.empty()?P(-1,0):merge(a,Rake);\n    }\n    P add_edge(int i){\n\
    \        auto [j,sj]=compress(i);\n        return {add(-1,j,-1,AddEdge),sj};\n\
    \    }\n    P add_vertex(int i){\n        auto [j,sj]=rake(i);\n        return\
    \ {add(i,j,-1,j==-1?Vertex:AddVertex),sj+1};\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-11-14\n * Description:\
    \ Static Top Tree.\n */\n\ntemplate<class HLD>\nstruct StaticTopTree{\n    using\
    \ P = pair<int,int>;\n    enum Type{Compress,Rake,AddEdge,AddVertex,Vertex};\n\
    \    int n,root;\n    HLD &hld;\n    vector<int> lch,rch,par;\n    vector<Type>\
    \ type;\n    StaticTopTree(HLD &_hld):hld(_hld){build();}\n    void build(){\n\
    \        n=hld.n;\n        lch=rch=par=vector<int>(n,-1);\n        type.assign(n,Compress);\n\
    \        root=compress(hld.root).first;\n    }\n    int add(int i,int l,int r,Type\
    \ t){\n        if(i==-1){\n            i=n++;\n            lch.emplace_back(l);\n\
    \            rch.emplace_back(r);\n            par.emplace_back(-1);\n       \
    \     type.emplace_back(t);\n        }else{\n            lch[i]=l,rch[i]=r,type[i]=t;\n\
    \        }\n        if(l!=-1)par[l]=i;\n        if(r!=-1)par[r]=i;\n        return\
    \ i;\n    }\n    P merge(const vector<P> &a,Type t){\n        if(a.size()==1)return\
    \ a[0];\n        vector<P> b,c;\n        int tot=0;\n        for(auto [i,s]:a)tot+=s;\n\
    \        for(auto [i,s]:a){\n            (tot>s?b:c).emplace_back(i,s);\n    \
    \        tot-=2*s;\n        }\n        auto [i,si]=merge(b,t);\n        auto [j,sj]=merge(c,t);\n\
    \        return {add(-1,i,j,t),si+sj};\n    }\n    P compress(int i){\n      \
    \  vector<P> a{add_vertex(i)};\n        while(hld.hv[i]!=-1)a.emplace_back(add_vertex(i=hld.hv[i]));\n\
    \        return merge(a,Compress);\n    }\n    P rake(int i){\n        vector<P>\
    \ a;\n        for(int j:hld.g[i])if(j!=hld.par[i]&&j!=hld.hv[i])a.emplace_back(add_edge(j));\n\
    \        return a.empty()?P(-1,0):merge(a,Rake);\n    }\n    P add_edge(int i){\n\
    \        auto [j,sj]=compress(i);\n        return {add(-1,j,-1,AddEdge),sj};\n\
    \    }\n    P add_vertex(int i){\n        auto [j,sj]=rake(i);\n        return\
    \ {add(i,j,-1,j==-1?Vertex:AddVertex),sj+1};\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/static-top-tree.hpp
  requiredBy:
  - verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.cpp
  - verify/yosupo/data-structure/point_set_tree_path_composite_sum.cpp
  - tree/static-top-tree-dp.hpp
  timestamp: '2024-11-14 23:02:13+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/static-top-tree.hpp
layout: document
redirect_from:
- /library/tree/static-top-tree.hpp
- /library/tree/static-top-tree.hpp.html
title: tree/static-top-tree.hpp
---
