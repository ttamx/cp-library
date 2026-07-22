---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/graph/general_matching.test.cpp
    title: verify/yosupo/graph/general_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/general-matching.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2025-09-03\n * Description: General matching using blossom algorithm.\n\
    \ * Time: O(E V \\alpha(V)).\n */\n\ntemplate<int N>\nstruct GeneralMatching{\n\
    \nint n,m;\nvector<int> adj[N+1];\nint fa[N+1],link[N+1],match[N+1],vis[N+1],dep[N+1];\n\
    queue<int> q;\n\nint find(int u){\n    while(fa[u]!=u)u=fa[u]=fa[fa[u]];\n   \
    \ return u;\n}\nint get_lca(int u,int v){\n    u=find(u),v=find(v);\n    while(u!=v){\n\
    \        if(dep[u]<dep[v])swap(u,v);\n        u=find(link[match[u]]);\n    }\n\
    \    return u;\n}\nvoid blossom(int u,int v,int lca){\n    while(find(u)!=lca){\n\
    \        link[u]=v;\n        v=match[u];\n        if(vis[v]==0){\n           \
    \ vis[v]=1;\n            q.emplace(v);\n        }\n        fa[u]=fa[v]=lca;\n\
    \        u=link[v];\n    }\n}\nbool augment(int st){\n    for(int i=1;i<=n;i++)fa[i]=i;\n\
    \    for(int i=1;i<=n;i++)vis[i]=-1;\n    vis[st]=1;\n    dep[st]=0;\n    q=queue<int>();\n\
    \    q.emplace(st);\n    while(!q.empty()){\n        int u=q.front();\n      \
    \  q.pop();\n        for(auto v:adj[u]){\n            if(vis[v]==-1){\n      \
    \          vis[v]=0;\n                link[v]=u;\n                dep[v]=dep[u]+1;\n\
    \                if(!match[v]){\n                    for(int x=v,y=u,z;y;y=link[x=z]){\n\
    \                        z=match[y];\n                        match[x]=y;\n  \
    \                      match[y]=x;\n                    }\n                  \
    \  return 1;\n                }\n                vis[match[v]]=1;\n          \
    \      dep[match[v]]=dep[u]+2;\n                q.emplace(match[v]);\n       \
    \     }else if(vis[v]==1&&find(u)!=find(v)){\n                int lca=get_lca(u,v);\n\
    \                blossom(u,v,lca);\n                blossom(v,u,lca);\n      \
    \      }\n        }\n    }\n    return 0;\n}\nint solve(){\n    int ans=0;\n \
    \   for(int u=1;u<=n;u++)if(!match[u]){\n        for(auto v:adj[u])if(!match[v]){\n\
    \            match[u]=v;\n            match[v]=u;\n            ans++;\n      \
    \      break;\n        }\n    }\n    for(int u=1;u<=n;u++)if(!match[u])ans+=augment(u);\n\
    \    return ans;\n}\nvoid init(int _n){\n    n=_n;\n    for(int i=1;i<=n;i++)match[i]=0;\n\
    \    for(int i=1;i<=n;i++)adj[i].clear();\n}\nvoid add_edge(int u,int v){\n  \
    \  adj[u].emplace_back(v);\n    adj[v].emplace_back(u);\n}\n\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2025-09-03\n * Description:\
    \ General matching using blossom algorithm.\n * Time: O(E V \\alpha(V)).\n */\n\
    \ntemplate<int N>\nstruct GeneralMatching{\n\nint n,m;\nvector<int> adj[N+1];\n\
    int fa[N+1],link[N+1],match[N+1],vis[N+1],dep[N+1];\nqueue<int> q;\n\nint find(int\
    \ u){\n    while(fa[u]!=u)u=fa[u]=fa[fa[u]];\n    return u;\n}\nint get_lca(int\
    \ u,int v){\n    u=find(u),v=find(v);\n    while(u!=v){\n        if(dep[u]<dep[v])swap(u,v);\n\
    \        u=find(link[match[u]]);\n    }\n    return u;\n}\nvoid blossom(int u,int\
    \ v,int lca){\n    while(find(u)!=lca){\n        link[u]=v;\n        v=match[u];\n\
    \        if(vis[v]==0){\n            vis[v]=1;\n            q.emplace(v);\n  \
    \      }\n        fa[u]=fa[v]=lca;\n        u=link[v];\n    }\n}\nbool augment(int\
    \ st){\n    for(int i=1;i<=n;i++)fa[i]=i;\n    for(int i=1;i<=n;i++)vis[i]=-1;\n\
    \    vis[st]=1;\n    dep[st]=0;\n    q=queue<int>();\n    q.emplace(st);\n   \
    \ while(!q.empty()){\n        int u=q.front();\n        q.pop();\n        for(auto\
    \ v:adj[u]){\n            if(vis[v]==-1){\n                vis[v]=0;\n       \
    \         link[v]=u;\n                dep[v]=dep[u]+1;\n                if(!match[v]){\n\
    \                    for(int x=v,y=u,z;y;y=link[x=z]){\n                     \
    \   z=match[y];\n                        match[x]=y;\n                       \
    \ match[y]=x;\n                    }\n                    return 1;\n        \
    \        }\n                vis[match[v]]=1;\n                dep[match[v]]=dep[u]+2;\n\
    \                q.emplace(match[v]);\n            }else if(vis[v]==1&&find(u)!=find(v)){\n\
    \                int lca=get_lca(u,v);\n                blossom(u,v,lca);\n  \
    \              blossom(v,u,lca);\n            }\n        }\n    }\n    return\
    \ 0;\n}\nint solve(){\n    int ans=0;\n    for(int u=1;u<=n;u++)if(!match[u]){\n\
    \        for(auto v:adj[u])if(!match[v]){\n            match[u]=v;\n         \
    \   match[v]=u;\n            ans++;\n            break;\n        }\n    }\n  \
    \  for(int u=1;u<=n;u++)if(!match[u])ans+=augment(u);\n    return ans;\n}\nvoid\
    \ init(int _n){\n    n=_n;\n    for(int i=1;i<=n;i++)match[i]=0;\n    for(int\
    \ i=1;i<=n;i++)adj[i].clear();\n}\nvoid add_edge(int u,int v){\n    adj[u].emplace_back(v);\n\
    \    adj[v].emplace_back(u);\n}\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/general-matching.hpp
  requiredBy: []
  timestamp: '2026-07-22 11:58:01+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/graph/general_matching.test.cpp
documentation_of: flow/general-matching.hpp
layout: document
redirect_from:
- /library/flow/general-matching.hpp
- /library/flow/general-matching.hpp.html
title: flow/general-matching.hpp
---
