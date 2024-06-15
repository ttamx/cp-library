---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
    title: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
    title: verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
    title: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/tree/lca.test.cpp
    title: verify/yosupo/tree/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/hld.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-15\n\
    \ * Description: Heavy-Light Decomposition.\n */\n\ntemplate<class G>\nstruct\
    \ HLD{\n    G &g;\n    int root,timer;\n    vector<int> par,sz,dep,hv,head,tin,tout;\n\
    \    HLD(G &_g,int _root=0)\n        : g(_g),root(_root),timer(-1),par(g.n,root),sz(g.n,1),\n\
    \          dep(g.n),hv(g.n,-1),head(g.n),tin(g.n),tout(g.n){\n        dfs_sz(root);\n\
    \        dfs_hld(root);\n    }\n    void dfs_sz(int u){\n        for(int v:g[u])if(v!=par[u]){\n\
    \            par[v]=u;\n            dep[v]=dep[u]+1;\n            dfs_sz(v);\n\
    \            sz[u]+=sz[v];\n            if(hv[u]==-1||sz[v]>sz[hv[u]])hv[u]=v;\n\
    \        }\n    }\n    void dfs_hld(int u){\n        tin[u]=++timer;\n       \
    \ if(hv[u]!=-1){\n            head[hv[u]]=head[u];\n            dfs_hld(hv[u]);\n\
    \        }\n        for(int v:g[u])if(v!=par[u]&&v!=hv[u]){\n            head[v]=v;\n\
    \            dfs_hld(v);\n        }\n        tout[u]=timer;\n    }\n    vector<pair<int,int>>\
    \ get_path(int u,int v,bool vertex,bool commutative=true){\n        vector<pair<int,int>>\
    \ up,down;\n        while(head[u]!=head[v]){\n            if(dep[head[u]]>dep[head[v]]){\n\
    \                up.emplace_back(tin[head[u]],tin[u]);\n                u=par[head[u]];\n\
    \            }else{\n                down.emplace_back(tin[head[v]],tin[v]);\n\
    \                v=par[head[v]];\n            }\n        }\n        if(dep[u]>dep[v])up.emplace_back(tin[v]+1,tin[u]),u=v;\n\
    \        else if(u!=v)down.emplace_back(tin[u]+1,tin[v]),v=u;\n        if(vertex)up.emplace_back(tin[u],tin[u]);\n\
    \        reverse(down.begin(),down.end());\n        if(!commutative)for(auto &[x,y]:up)swap(x,y);\n\
    \        up.insert(up.end(),down.begin(),down.end());\n        return up;\n  \
    \  }\n    int lca(int u,int v){\n        while(head[u]!=head[v]){\n          \
    \  if(dep[head[u]]>dep[head[v]])swap(u,v);\n            v=par[head[v]];\n    \
    \    }\n        return dep[u]<dep[v]?u:v;\n    }\n    int dist(int u,int v){\n\
    \        return dep[u]+dep[v]-2*dep[lca(u,v)];\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-15\n * Description:\
    \ Heavy-Light Decomposition.\n */\n\ntemplate<class G>\nstruct HLD{\n    G &g;\n\
    \    int root,timer;\n    vector<int> par,sz,dep,hv,head,tin,tout;\n    HLD(G\
    \ &_g,int _root=0)\n        : g(_g),root(_root),timer(-1),par(g.n,root),sz(g.n,1),\n\
    \          dep(g.n),hv(g.n,-1),head(g.n),tin(g.n),tout(g.n){\n        dfs_sz(root);\n\
    \        dfs_hld(root);\n    }\n    void dfs_sz(int u){\n        for(int v:g[u])if(v!=par[u]){\n\
    \            par[v]=u;\n            dep[v]=dep[u]+1;\n            dfs_sz(v);\n\
    \            sz[u]+=sz[v];\n            if(hv[u]==-1||sz[v]>sz[hv[u]])hv[u]=v;\n\
    \        }\n    }\n    void dfs_hld(int u){\n        tin[u]=++timer;\n       \
    \ if(hv[u]!=-1){\n            head[hv[u]]=head[u];\n            dfs_hld(hv[u]);\n\
    \        }\n        for(int v:g[u])if(v!=par[u]&&v!=hv[u]){\n            head[v]=v;\n\
    \            dfs_hld(v);\n        }\n        tout[u]=timer;\n    }\n    vector<pair<int,int>>\
    \ get_path(int u,int v,bool vertex,bool commutative=true){\n        vector<pair<int,int>>\
    \ up,down;\n        while(head[u]!=head[v]){\n            if(dep[head[u]]>dep[head[v]]){\n\
    \                up.emplace_back(tin[head[u]],tin[u]);\n                u=par[head[u]];\n\
    \            }else{\n                down.emplace_back(tin[head[v]],tin[v]);\n\
    \                v=par[head[v]];\n            }\n        }\n        if(dep[u]>dep[v])up.emplace_back(tin[v]+1,tin[u]),u=v;\n\
    \        else if(u!=v)down.emplace_back(tin[u]+1,tin[v]),v=u;\n        if(vertex)up.emplace_back(tin[u],tin[u]);\n\
    \        reverse(down.begin(),down.end());\n        if(!commutative)for(auto &[x,y]:up)swap(x,y);\n\
    \        up.insert(up.end(),down.begin(),down.end());\n        return up;\n  \
    \  }\n    int lca(int u,int v){\n        while(head[u]!=head[v]){\n          \
    \  if(dep[head[u]]>dep[head[v]])swap(u,v);\n            v=par[head[v]];\n    \
    \    }\n        return dep[u]<dep[v]?u:v;\n    }\n    int dist(int u,int v){\n\
    \        return dep[u]+dep[v]-2*dep[lca(u,v)];\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/hld.hpp
  requiredBy: []
  timestamp: '2024-06-16 02:15:01+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  - verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
  - verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
  - verify/yosupo/tree/lca.test.cpp
documentation_of: tree/hld.hpp
layout: document
redirect_from:
- /library/tree/hld.hpp
- /library/tree/hld.hpp.html
title: tree/hld.hpp
---