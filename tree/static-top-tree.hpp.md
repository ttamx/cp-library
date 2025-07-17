---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/static-top-tree-dp.hpp
    title: tree/static-top-tree-dp.hpp
  - icon: ':heavy_check_mark:'
    path: tree/static-top-tree-rerooting-dp.hpp
    title: tree/static-top-tree-rerooting-dp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
    title: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/static-top-tree.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-11-14\n * Description: Static Top Tree.\n */\n\ntemplate<class\
    \ HLD>\nstruct StaticTopTree{\n    using P = pair<int,int>;\n    enum Type{Compress,Rake,AddEdge,AddVertex,Vertex};\n\
    \    int n,root;\n    HLD &hld;\n    vector<int> lch,rch,par;\n    vector<Type>\
    \ type;\n    StaticTopTree(HLD &_hld):hld(_hld){build();}\n    void build(){\n\
    \        n=hld.n;\n        lch=rch=par=vector<int>(n,-1);\n        type.assign(n,Compress);\n\
    \        root=compress(hld.root).second;\n    }\n    int add(int i,int l,int r,Type\
    \ t){\n        if(i==-1){\n            i=n++;\n            lch.emplace_back(l);\n\
    \            rch.emplace_back(r);\n            par.emplace_back(-1);\n       \
    \     type.emplace_back(t);\n        }else{\n            lch[i]=l,rch[i]=r,type[i]=t;\n\
    \        }\n        if(l!=-1)par[l]=i;\n        if(r!=-1)par[r]=i;\n        return\
    \ i;\n    }\n    P compress(int i){\n        vector<P> a{add_vertex(i)};\n   \
    \     auto work=[&](){\n            auto [sj,j]=a.back();\n            a.pop_back();\n\
    \            auto [si,i]=a.back();\n            a.back()={max(si,sj)+1,add(-1,i,j,Compress)};\n\
    \        };\n        while(hld.hv[i]!=-1){\n            a.emplace_back(add_vertex(i=hld.hv[i]));\n\
    \            while(true){\n                if(a.size()>=3&&(a.end()[-3].first==a.end()[-2].first||a.end()[-3].first<=a.back().first)){\n\
    \                    P tmp=a.back();\n                    a.pop_back();\n    \
    \                work();\n                    a.emplace_back(tmp);\n         \
    \       }else if(a.size()>=2&&a.end()[-2].first<=a.back().first){\n          \
    \          work();\n                }else break;\n            }\n        }\n \
    \       while(a.size()>=2)work();\n        return a[0];\n    }\n    P rake(int\
    \ i){\n        priority_queue<P,vector<P>,greater<P>> pq;\n        for(int j:hld.g[i])if(j!=hld.par[i]&&j!=hld.hv[i])pq.emplace(add_edge(j));\n\
    \        while(pq.size()>=2){\n            auto [si,i]=pq.top();pq.pop();\n  \
    \          auto [sj,j]=pq.top();pq.pop();\n            pq.emplace(max(si,sj)+1,add(-1,i,j,Rake));\n\
    \        }\n        return pq.empty()?make_pair(0,-1):pq.top();\n    }\n    P\
    \ add_edge(int i){\n        auto [sj,j]=compress(i);\n        return {sj+1,add(-1,j,-1,AddEdge)};\n\
    \    }\n    P add_vertex(int i){\n        auto [sj,j]=rake(i);\n        return\
    \ {sj+1,add(i,j,-1,j==-1?Vertex:AddVertex)};\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-11-14\n * Description:\
    \ Static Top Tree.\n */\n\ntemplate<class HLD>\nstruct StaticTopTree{\n    using\
    \ P = pair<int,int>;\n    enum Type{Compress,Rake,AddEdge,AddVertex,Vertex};\n\
    \    int n,root;\n    HLD &hld;\n    vector<int> lch,rch,par;\n    vector<Type>\
    \ type;\n    StaticTopTree(HLD &_hld):hld(_hld){build();}\n    void build(){\n\
    \        n=hld.n;\n        lch=rch=par=vector<int>(n,-1);\n        type.assign(n,Compress);\n\
    \        root=compress(hld.root).second;\n    }\n    int add(int i,int l,int r,Type\
    \ t){\n        if(i==-1){\n            i=n++;\n            lch.emplace_back(l);\n\
    \            rch.emplace_back(r);\n            par.emplace_back(-1);\n       \
    \     type.emplace_back(t);\n        }else{\n            lch[i]=l,rch[i]=r,type[i]=t;\n\
    \        }\n        if(l!=-1)par[l]=i;\n        if(r!=-1)par[r]=i;\n        return\
    \ i;\n    }\n    P compress(int i){\n        vector<P> a{add_vertex(i)};\n   \
    \     auto work=[&](){\n            auto [sj,j]=a.back();\n            a.pop_back();\n\
    \            auto [si,i]=a.back();\n            a.back()={max(si,sj)+1,add(-1,i,j,Compress)};\n\
    \        };\n        while(hld.hv[i]!=-1){\n            a.emplace_back(add_vertex(i=hld.hv[i]));\n\
    \            while(true){\n                if(a.size()>=3&&(a.end()[-3].first==a.end()[-2].first||a.end()[-3].first<=a.back().first)){\n\
    \                    P tmp=a.back();\n                    a.pop_back();\n    \
    \                work();\n                    a.emplace_back(tmp);\n         \
    \       }else if(a.size()>=2&&a.end()[-2].first<=a.back().first){\n          \
    \          work();\n                }else break;\n            }\n        }\n \
    \       while(a.size()>=2)work();\n        return a[0];\n    }\n    P rake(int\
    \ i){\n        priority_queue<P,vector<P>,greater<P>> pq;\n        for(int j:hld.g[i])if(j!=hld.par[i]&&j!=hld.hv[i])pq.emplace(add_edge(j));\n\
    \        while(pq.size()>=2){\n            auto [si,i]=pq.top();pq.pop();\n  \
    \          auto [sj,j]=pq.top();pq.pop();\n            pq.emplace(max(si,sj)+1,add(-1,i,j,Rake));\n\
    \        }\n        return pq.empty()?make_pair(0,-1):pq.top();\n    }\n    P\
    \ add_edge(int i){\n        auto [sj,j]=compress(i);\n        return {sj+1,add(-1,j,-1,AddEdge)};\n\
    \    }\n    P add_vertex(int i){\n        auto [sj,j]=rake(i);\n        return\
    \ {sj+1,add(i,j,-1,j==-1?Vertex:AddVertex)};\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/static-top-tree.hpp
  requiredBy:
  - tree/static-top-tree-dp.hpp
  - tree/static-top-tree-rerooting-dp.hpp
  timestamp: '2024-11-15 02:28:18+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
documentation_of: tree/static-top-tree.hpp
layout: document
redirect_from:
- /library/tree/static-top-tree.hpp
- /library/tree/static-top-tree.hpp.html
title: tree/static-top-tree.hpp
---
