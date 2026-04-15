---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/general-matching.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2025-09-03\n * Description: General matching using blossom algorithm.\n\
    \ * Time: O(E \\sqrt{V} log_{\\max(2,1+E/V)}).\n */\n\nstruct GeneralMatching{\n\
    \    int n;\n    vector<vector<int>> adj;\n    vector<int> match,vis,link,fa,dep;\n\
    \    queue<int> q;\n    GeneralMatching(int n):n(n),adj(n),match(n,-1),vis(n),link(n),fa(n),dep(n){}\n\
    \    void add_edge(int u,int v){\n        adj[u].emplace_back(v);\n        adj[v].emplace_back(u);\n\
    \    }\n    int fp(int u){\n        while(fa[u]!=u)u=fa[u]=fa[fa[u]];\n      \
    \  return u;\n    }\n    int lca(int u,int v){\n        u=fp(u),v=fp(v);\n   \
    \     while(u!=v){\n            if(dep[u]<dep[v])swap(u,v);\n            u=fp(link[match[u]]);\n\
    \        }\n        return u;\n    }\n    void blossom(int u,int v,int p){\n \
    \       while(fp(u)!=p){\n            link[u]=v;\n            v=match[u];\n  \
    \          if(vis[v]==0){\n                vis[v]=1;\n                q.emplace(v);\n\
    \            }\n            fa[u]=fa[v]=p;\n            u=link[v];\n        }\n\
    \    }\n    int augment(int u){\n        while(!q.empty())q.pop();\n        iota(fa.begin(),fa.end(),0);\n\
    \        fill(vis.begin(),vis.end(),-1);\n        q.emplace(u);\n        vis[u]=1;\n\
    \        dep[u]=0;\n        while(!q.empty()){\n            int u=q.front();\n\
    \            q.pop();\n            for(auto v:adj[u]){\n                if(vis[v]==-1){\n\
    \                    vis[v]=0;\n                    link[v]=u;\n             \
    \       dep[v]=dep[u]+1;\n                    if(match[v]==-1){\n            \
    \            for(int x=v,y=u,z;y!=-1;x=z,y=x==-1?-1:link[x]){\n              \
    \              z=match[y];\n                            match[x]=y;\n        \
    \                    match[y]=x;\n                        }\n                \
    \        return 1;\n                    }\n                    vis[match[v]]=1;\n\
    \                    dep[match[v]]=dep[u]+2;\n                    q.emplace(match[v]);\n\
    \                }else if(vis[v]==1&&fp(u)!=fp(v)){\n                    int p=lca(u,v);\n\
    \                    blossom(u,v,p);\n                    blossom(v,u,p);\n  \
    \              }\n            }\n        }\n        return 0;\n    }\n    int\
    \ max_matching(){\n        int res=0;\n        for(int u=0;u<n;u++){\n       \
    \     if(match[u]!=-1)continue;\n            for(auto v:adj[u]){\n           \
    \     if(match[v]==-1){\n                    match[u]=v;\n                   \
    \ match[v]=u;\n                    res++;\n                    break;\n      \
    \          }\n            }\n        }\n        for(int u=0;u<n;u++){\n      \
    \      if(match[u]==-1){\n                res+=augment(u);\n            }\n  \
    \      }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2025-09-03\n * Description:\
    \ General matching using blossom algorithm.\n * Time: O(E \\sqrt{V} log_{\\max(2,1+E/V)}).\n\
    \ */\n\nstruct GeneralMatching{\n    int n;\n    vector<vector<int>> adj;\n  \
    \  vector<int> match,vis,link,fa,dep;\n    queue<int> q;\n    GeneralMatching(int\
    \ n):n(n),adj(n),match(n,-1),vis(n),link(n),fa(n),dep(n){}\n    void add_edge(int\
    \ u,int v){\n        adj[u].emplace_back(v);\n        adj[v].emplace_back(u);\n\
    \    }\n    int fp(int u){\n        while(fa[u]!=u)u=fa[u]=fa[fa[u]];\n      \
    \  return u;\n    }\n    int lca(int u,int v){\n        u=fp(u),v=fp(v);\n   \
    \     while(u!=v){\n            if(dep[u]<dep[v])swap(u,v);\n            u=fp(link[match[u]]);\n\
    \        }\n        return u;\n    }\n    void blossom(int u,int v,int p){\n \
    \       while(fp(u)!=p){\n            link[u]=v;\n            v=match[u];\n  \
    \          if(vis[v]==0){\n                vis[v]=1;\n                q.emplace(v);\n\
    \            }\n            fa[u]=fa[v]=p;\n            u=link[v];\n        }\n\
    \    }\n    int augment(int u){\n        while(!q.empty())q.pop();\n        iota(fa.begin(),fa.end(),0);\n\
    \        fill(vis.begin(),vis.end(),-1);\n        q.emplace(u);\n        vis[u]=1;\n\
    \        dep[u]=0;\n        while(!q.empty()){\n            int u=q.front();\n\
    \            q.pop();\n            for(auto v:adj[u]){\n                if(vis[v]==-1){\n\
    \                    vis[v]=0;\n                    link[v]=u;\n             \
    \       dep[v]=dep[u]+1;\n                    if(match[v]==-1){\n            \
    \            for(int x=v,y=u,z;y!=-1;x=z,y=x==-1?-1:link[x]){\n              \
    \              z=match[y];\n                            match[x]=y;\n        \
    \                    match[y]=x;\n                        }\n                \
    \        return 1;\n                    }\n                    vis[match[v]]=1;\n\
    \                    dep[match[v]]=dep[u]+2;\n                    q.emplace(match[v]);\n\
    \                }else if(vis[v]==1&&fp(u)!=fp(v)){\n                    int p=lca(u,v);\n\
    \                    blossom(u,v,p);\n                    blossom(v,u,p);\n  \
    \              }\n            }\n        }\n        return 0;\n    }\n    int\
    \ max_matching(){\n        int res=0;\n        for(int u=0;u<n;u++){\n       \
    \     if(match[u]!=-1)continue;\n            for(auto v:adj[u]){\n           \
    \     if(match[v]==-1){\n                    match[u]=v;\n                   \
    \ match[v]=u;\n                    res++;\n                    break;\n      \
    \          }\n            }\n        }\n        for(int u=0;u<n;u++){\n      \
    \      if(match[u]==-1){\n                res+=augment(u);\n            }\n  \
    \      }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/general-matching.hpp
  requiredBy: []
  timestamp: '2026-04-04 10:42:17+05:30'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/general-matching.hpp
layout: document
redirect_from:
- /library/flow/general-matching.hpp
- /library/flow/general-matching.hpp.html
title: flow/general-matching.hpp
---
