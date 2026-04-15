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
  bundledCode: "#line 2 \"flow/hopcroft-karp.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-03-31\n * Description: Fast bipartite matching algorithm.\n * Time:\
    \ $O(E\\sqrt{V})$\n */\n\nstruct HopcroftKarp{\n    int n,m;\n    vector<int>\
    \ match,lv,ptr;\n    vector<vector<int>> adj;\n    HopcroftKarp(){}\n    HopcroftKarp(int\
    \ _n,int _m){init(_n,_m);}\n    void init(int _n,int _m){\n        n=_n,m=_m;\n\
    \        adj.assign(n+m,vector<int>{});\n    }\n    void add_edge(int u,int v){\n\
    \        adj[u].emplace_back(v+n);\n    }\n    void bfs(){\n        lv.assign(n,-1);\n\
    \        queue<int> q;\n        for(int i=0;i<n;i++)if(match[i]==-1){\n      \
    \      lv[i]=0;\n            q.emplace(i);\n        }\n        while(!q.empty()){\n\
    \            int u=q.front();\n            q.pop();\n            for(int v:adj[u])if(match[v]!=-1&&lv[match[v]]==-1){\n\
    \                lv[match[v]]=lv[u]+1;\n                q.emplace(match[v]);\n\
    \            }\n        }\n    }\n    bool dfs(int u){\n        for(int &i=ptr[u];i<adj[u].size();i++){\n\
    \            int v=adj[u][i];\n            if(match[v]==-1||(lv[match[v]]==lv[u]+1&&dfs(match[v]))){\n\
    \                match[u]=v,match[v]=u;\n                return true;\n      \
    \      }\n        }\n        return false;\n    }\n    int max_matching(){\n \
    \       int ans=0,cnt=0;\n        match.assign(n+m,-1);\n        do{\n       \
    \     ptr.assign(n,0);\n            bfs();\n            cnt=0;\n            for(int\
    \ i=0;i<n;i++)if(match[i]==-1&&dfs(i))cnt++;\n            ans+=cnt;\n        }while(cnt);\n\
    \        return ans;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-03-31\n * Description:\
    \ Fast bipartite matching algorithm.\n * Time: $O(E\\sqrt{V})$\n */\n\nstruct\
    \ HopcroftKarp{\n    int n,m;\n    vector<int> match,lv,ptr;\n    vector<vector<int>>\
    \ adj;\n    HopcroftKarp(){}\n    HopcroftKarp(int _n,int _m){init(_n,_m);}\n\
    \    void init(int _n,int _m){\n        n=_n,m=_m;\n        adj.assign(n+m,vector<int>{});\n\
    \    }\n    void add_edge(int u,int v){\n        adj[u].emplace_back(v+n);\n \
    \   }\n    void bfs(){\n        lv.assign(n,-1);\n        queue<int> q;\n    \
    \    for(int i=0;i<n;i++)if(match[i]==-1){\n            lv[i]=0;\n           \
    \ q.emplace(i);\n        }\n        while(!q.empty()){\n            int u=q.front();\n\
    \            q.pop();\n            for(int v:adj[u])if(match[v]!=-1&&lv[match[v]]==-1){\n\
    \                lv[match[v]]=lv[u]+1;\n                q.emplace(match[v]);\n\
    \            }\n        }\n    }\n    bool dfs(int u){\n        for(int &i=ptr[u];i<adj[u].size();i++){\n\
    \            int v=adj[u][i];\n            if(match[v]==-1||(lv[match[v]]==lv[u]+1&&dfs(match[v]))){\n\
    \                match[u]=v,match[v]=u;\n                return true;\n      \
    \      }\n        }\n        return false;\n    }\n    int max_matching(){\n \
    \       int ans=0,cnt=0;\n        match.assign(n+m,-1);\n        do{\n       \
    \     ptr.assign(n,0);\n            bfs();\n            cnt=0;\n            for(int\
    \ i=0;i<n;i++)if(match[i]==-1&&dfs(i))cnt++;\n            ans+=cnt;\n        }while(cnt);\n\
    \        return ans;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/hopcroft-karp.hpp
  requiredBy: []
  timestamp: '2026-04-04 10:42:17+05:30'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/hopcroft-karp.hpp
layout: document
redirect_from:
- /library/flow/hopcroft-karp.hpp
- /library/flow/hopcroft-karp.hpp.html
title: flow/hopcroft-karp.hpp
---
