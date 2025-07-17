---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: flow/binary-optimization.hpp
    title: flow/binary-optimization.hpp
  - icon: ':warning:'
    path: flow/k-ary-optimization.hpp
    title: flow/k-ary-optimization.hpp
  - icon: ':warning:'
    path: verify/atcoder/abc193_f.cpp
    title: verify/atcoder/abc193_f.cpp
  - icon: ':warning:'
    path: verify/atcoder/abc259_g.cpp
    title: verify/atcoder/abc259_g.cpp
  - icon: ':warning:'
    path: verify/atcoder/abc347_g.cpp
    title: verify/atcoder/abc347_g.cpp
  - icon: ':warning:'
    path: verify/kattis/thekingofthenorth.cpp
    title: verify/kattis/thekingofthenorth.cpp
  - icon: ':warning:'
    path: verify/spoj/FASTFLOW.cpp
    title: verify/spoj/FASTFLOW.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/dinic.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-07-15\n * Description: Dinic's Algorithm for finding the maximum flow.\n\
    \ * Time: O(V E \\log U) where U is the maximum flow.\n */\n\ntemplate<class T,bool\
    \ directed=true,bool scaling=true>\nstruct Dinic{\n    static constexpr T INF=numeric_limits<T>::max()/2;\n\
    \    struct Edge{\n        int to;\n        T flow,cap;\n        Edge(int _to,T\
    \ _cap):to(_to),flow(0),cap(_cap){}\n        T remain(){return cap-flow;}\n  \
    \  };\n    int n,s,t;\n    T U;\n    vector<Edge> e;\n    vector<vector<int>>\
    \ g;\n    vector<int> ptr,lv;\n    bool calculated;\n    T max_flow;\n    Dinic(){}\n\
    \    Dinic(int n,int s,int t){init(n,s,t);}\n    void init(int _n,int _s,int _t){\n\
    \        n=_n,s=_s,t=_t;\n        U=0;\n        e.clear();\n        g.assign(n,{});\n\
    \        calculated=false;\n    }\n    void add_edge(int from,int to,T cap){\n\
    \        assert(0<=from&&from<n&&0<=to&&to<n);\n        g[from].emplace_back(e.size());\n\
    \        e.emplace_back(to,cap);\n        g[to].emplace_back(e.size());\n    \
    \    e.emplace_back(from,directed?0:cap);\n        U=max(U,cap);\n    }\n    bool\
    \ bfs(T scale){\n        lv.assign(n,-1);\n        vector<int> q{s};\n       \
    \ lv[s]=0;\n        for(int i=0;i<(int)q.size();i++){\n            int u=q[i];\n\
    \            for(int j:g[u]){\n                int v=e[j].to;\n              \
    \  if(lv[v]==-1&&e[j].remain()>=scale){\n                    q.emplace_back(v);\n\
    \                    lv[v]=lv[u]+1;\n                }\n            }\n      \
    \  }\n        return lv[t]!=-1;\n    }\n    T dfs(int u,int t,T f){\n        if(u==t||f==0)return\
    \ f;\n        for(int &i=ptr[u];i<(int)g[u].size();i++){\n            int j=g[u][i];\n\
    \            int v=e[j].to;\n            if(lv[v]==lv[u]+1){\n               \
    \ T res=dfs(v,t,min(f,e[j].remain()));\n                if(res>0){\n         \
    \           e[j].flow+=res;\n                    e[j^1].flow-=res;\n         \
    \           return res;\n                }\n            }\n        }\n       \
    \ return 0;\n    }\n    T flow(){\n        if(calculated)return max_flow;\n  \
    \      calculated=true;\n        max_flow=0;\n        for(T scale=scaling?1LL<<(63-__builtin_clzll(U)):1LL;scale>0;scale>>=1){\n\
    \            while(bfs(scale)){\n                ptr.assign(n,0);\n          \
    \      while(true){\n                    T f=dfs(s,t,INF);\n                 \
    \   if(f==0)break;\n                    max_flow+=f;\n                }\n    \
    \        }\n        }\n        return max_flow;\n    }\n    pair<T,vector<int>>\
    \ cut(){\n        flow();\n        vector<int> res(n);\n        for(int i=0;i<n;i++)res[i]=(lv[i]==-1);\n\
    \        return {max_flow,res};\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-15\n * Description:\
    \ Dinic's Algorithm for finding the maximum flow.\n * Time: O(V E \\log U) where\
    \ U is the maximum flow.\n */\n\ntemplate<class T,bool directed=true,bool scaling=true>\n\
    struct Dinic{\n    static constexpr T INF=numeric_limits<T>::max()/2;\n    struct\
    \ Edge{\n        int to;\n        T flow,cap;\n        Edge(int _to,T _cap):to(_to),flow(0),cap(_cap){}\n\
    \        T remain(){return cap-flow;}\n    };\n    int n,s,t;\n    T U;\n    vector<Edge>\
    \ e;\n    vector<vector<int>> g;\n    vector<int> ptr,lv;\n    bool calculated;\n\
    \    T max_flow;\n    Dinic(){}\n    Dinic(int n,int s,int t){init(n,s,t);}\n\
    \    void init(int _n,int _s,int _t){\n        n=_n,s=_s,t=_t;\n        U=0;\n\
    \        e.clear();\n        g.assign(n,{});\n        calculated=false;\n    }\n\
    \    void add_edge(int from,int to,T cap){\n        assert(0<=from&&from<n&&0<=to&&to<n);\n\
    \        g[from].emplace_back(e.size());\n        e.emplace_back(to,cap);\n  \
    \      g[to].emplace_back(e.size());\n        e.emplace_back(from,directed?0:cap);\n\
    \        U=max(U,cap);\n    }\n    bool bfs(T scale){\n        lv.assign(n,-1);\n\
    \        vector<int> q{s};\n        lv[s]=0;\n        for(int i=0;i<(int)q.size();i++){\n\
    \            int u=q[i];\n            for(int j:g[u]){\n                int v=e[j].to;\n\
    \                if(lv[v]==-1&&e[j].remain()>=scale){\n                    q.emplace_back(v);\n\
    \                    lv[v]=lv[u]+1;\n                }\n            }\n      \
    \  }\n        return lv[t]!=-1;\n    }\n    T dfs(int u,int t,T f){\n        if(u==t||f==0)return\
    \ f;\n        for(int &i=ptr[u];i<(int)g[u].size();i++){\n            int j=g[u][i];\n\
    \            int v=e[j].to;\n            if(lv[v]==lv[u]+1){\n               \
    \ T res=dfs(v,t,min(f,e[j].remain()));\n                if(res>0){\n         \
    \           e[j].flow+=res;\n                    e[j^1].flow-=res;\n         \
    \           return res;\n                }\n            }\n        }\n       \
    \ return 0;\n    }\n    T flow(){\n        if(calculated)return max_flow;\n  \
    \      calculated=true;\n        max_flow=0;\n        for(T scale=scaling?1LL<<(63-__builtin_clzll(U)):1LL;scale>0;scale>>=1){\n\
    \            while(bfs(scale)){\n                ptr.assign(n,0);\n          \
    \      while(true){\n                    T f=dfs(s,t,INF);\n                 \
    \   if(f==0)break;\n                    max_flow+=f;\n                }\n    \
    \        }\n        }\n        return max_flow;\n    }\n    pair<T,vector<int>>\
    \ cut(){\n        flow();\n        vector<int> res(n);\n        for(int i=0;i<n;i++)res[i]=(lv[i]==-1);\n\
    \        return {max_flow,res};\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/dinic.hpp
  requiredBy:
  - verify/atcoder/abc193_f.cpp
  - verify/atcoder/abc347_g.cpp
  - verify/atcoder/abc259_g.cpp
  - verify/spoj/FASTFLOW.cpp
  - verify/kattis/thekingofthenorth.cpp
  - flow/binary-optimization.hpp
  - flow/k-ary-optimization.hpp
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/dinic.hpp
layout: document
redirect_from:
- /library/flow/dinic.hpp
- /library/flow/dinic.hpp.html
title: flow/dinic.hpp
---
