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
  bundledCode: "#line 2 \"flow/min-cost-flow.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-03-31\n * Description: minimum-cost flow algorithm.\n * Time: $O(FE\\\
    log{V})$ where $F$ is max flow.\n */\n\ntemplate<class F,class C>\nstruct MinCostFlow{\n\
    \    struct Edge{\n        int to;\n        F flow,cap;\n        C cost;\n   \
    \     Edge(int _to,F _cap,C _cost):to(_to),flow(0),cap(_cap),cost(_cost){}\n \
    \       F getcap(){\n            return cap-flow;\n        }\n    };\n    int\
    \ n;\n    vector<Edge> e;\n    vector<vector<int>> adj;\n    vector<C> pot,dist;\n\
    \    vector<int> pre;\n    bool neg;\n    const F FINF=numeric_limits<F>::max()/2;\n\
    \    const C CINF=numeric_limits<C>::max()/2;\n    MinCostFlow(){}\n    MinCostFlow(int\
    \ _n){\n        init(_n);\n    }\n    void init(int _n){\n        n=_n;\n    \
    \    e.clear();\n        adj.assign(n,{});\n        neg=false;\n    }\n    void\
    \ addEdge(int u,int v,F cap,C cost){\n        adj[u].emplace_back(e.size());\n\
    \        e.emplace_back(v,cap,cost);\n        adj[v].emplace_back(e.size());\n\
    \        e.emplace_back(u,0,-cost);\n        if(cost<0)neg=true;\n    }\n    bool\
    \ dijkstra(int s,int t){\n        using P = pair<C,int>;\n        dist.assign(n,CINF);\n\
    \        pre.assign(n,-1);\n        priority_queue<P,vector<P>,greater<P>> pq;\n\
    \        dist[s]=0;\n        pq.emplace(0,s);\n        while(!pq.empty()){\n \
    \           auto [d,u]=pq.top();\n            pq.pop();\n            if(dist[u]<d)continue;\n\
    \            for(int i:adj[u]){\n                int v=e[i].to;\n            \
    \    C ndist=d+pot[u]-pot[v]+e[i].cost;\n                if(e[i].getcap()>0&&dist[v]>ndist){\n\
    \                    pre[v]=i;\n                    dist[v]=ndist;\n         \
    \           pq.emplace(ndist,v);\n                }\n            }\n        }\n\
    \        return dist[t]<CINF;\n    }\n    pair<F,C> flow(int s,int t){\n     \
    \   F flow=0;\n        C cost=0;\n        pot.assign(n,0);\n        if(neg)for(int\
    \ t=0;t<n;t++)for(int i=0;i<e.size();i++)if(e[i].getcap()>0){\n            int\
    \ u=e[i^1].to,v=e[i].to;\n            pot[v]=min(pot[v],pot[u]+e[i].cost);\n \
    \       } // Bellman-Ford\n        while(dijkstra(s,t)){\n            for(int\
    \ i=0;i<n;i++)pot[i]+=dist[i];\n            F aug=FINF;\n            for(int u=t;u!=s;u=e[pre[u]^1].to){\n\
    \                aug=min(aug,e[pre[u]].getcap());\n            } // find bottleneck\n\
    \            for(int u=t;u!=s;u=e[pre[u]^1].to){\n                e[pre[u]].flow+=aug;\n\
    \                e[pre[u]^1].flow-=aug;\n            } // push flow\n        \
    \    flow+=aug;\n            cost+=aug*pot[t];\n        }\n        return {flow,cost};\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-03-31\n * Description:\
    \ minimum-cost flow algorithm.\n * Time: $O(FE\\log{V})$ where $F$ is max flow.\n\
    \ */\n\ntemplate<class F,class C>\nstruct MinCostFlow{\n    struct Edge{\n   \
    \     int to;\n        F flow,cap;\n        C cost;\n        Edge(int _to,F _cap,C\
    \ _cost):to(_to),flow(0),cap(_cap),cost(_cost){}\n        F getcap(){\n      \
    \      return cap-flow;\n        }\n    };\n    int n;\n    vector<Edge> e;\n\
    \    vector<vector<int>> adj;\n    vector<C> pot,dist;\n    vector<int> pre;\n\
    \    bool neg;\n    const F FINF=numeric_limits<F>::max()/2;\n    const C CINF=numeric_limits<C>::max()/2;\n\
    \    MinCostFlow(){}\n    MinCostFlow(int _n){\n        init(_n);\n    }\n   \
    \ void init(int _n){\n        n=_n;\n        e.clear();\n        adj.assign(n,{});\n\
    \        neg=false;\n    }\n    void addEdge(int u,int v,F cap,C cost){\n    \
    \    adj[u].emplace_back(e.size());\n        e.emplace_back(v,cap,cost);\n   \
    \     adj[v].emplace_back(e.size());\n        e.emplace_back(u,0,-cost);\n   \
    \     if(cost<0)neg=true;\n    }\n    bool dijkstra(int s,int t){\n        using\
    \ P = pair<C,int>;\n        dist.assign(n,CINF);\n        pre.assign(n,-1);\n\
    \        priority_queue<P,vector<P>,greater<P>> pq;\n        dist[s]=0;\n    \
    \    pq.emplace(0,s);\n        while(!pq.empty()){\n            auto [d,u]=pq.top();\n\
    \            pq.pop();\n            if(dist[u]<d)continue;\n            for(int\
    \ i:adj[u]){\n                int v=e[i].to;\n                C ndist=d+pot[u]-pot[v]+e[i].cost;\n\
    \                if(e[i].getcap()>0&&dist[v]>ndist){\n                    pre[v]=i;\n\
    \                    dist[v]=ndist;\n                    pq.emplace(ndist,v);\n\
    \                }\n            }\n        }\n        return dist[t]<CINF;\n \
    \   }\n    pair<F,C> flow(int s,int t){\n        F flow=0;\n        C cost=0;\n\
    \        pot.assign(n,0);\n        if(neg)for(int t=0;t<n;t++)for(int i=0;i<e.size();i++)if(e[i].getcap()>0){\n\
    \            int u=e[i^1].to,v=e[i].to;\n            pot[v]=min(pot[v],pot[u]+e[i].cost);\n\
    \        } // Bellman-Ford\n        while(dijkstra(s,t)){\n            for(int\
    \ i=0;i<n;i++)pot[i]+=dist[i];\n            F aug=FINF;\n            for(int u=t;u!=s;u=e[pre[u]^1].to){\n\
    \                aug=min(aug,e[pre[u]].getcap());\n            } // find bottleneck\n\
    \            for(int u=t;u!=s;u=e[pre[u]^1].to){\n                e[pre[u]].flow+=aug;\n\
    \                e[pre[u]^1].flow-=aug;\n            } // push flow\n        \
    \    flow+=aug;\n            cost+=aug*pot[t];\n        }\n        return {flow,cost};\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/min-cost-flow.hpp
  requiredBy: []
  timestamp: '2026-04-04 10:42:17+05:30'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/min-cost-flow.hpp
layout: document
redirect_from:
- /library/flow/min-cost-flow.hpp
- /library/flow/min-cost-flow.hpp.html
title: flow/min-cost-flow.hpp
---
