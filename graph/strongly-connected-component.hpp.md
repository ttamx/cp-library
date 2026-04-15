---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/graph/scc.test.cpp
    title: verify/yosupo/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/strongly-connected-component.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-06-28\n * Description: Strongly Connected Component.\n\
    \ */\n\ntemplate<class G>\npair<int,vector<int>> strongly_connected_component(G\
    \ &g){\n    static_assert(G::is_directed);\n    int n=g.n;\n    vector<int> disc(n,-1),low(n),scc(n,-1);\n\
    \    stack<int> st;\n    vector<bool> in_st(n);\n    int t=0,scc_cnt=0;\n    function<void(int,int)>\
    \ dfs=[&](int u,int p){\n        disc[u]=low[u]=t++;\n        st.emplace(u);\n\
    \        in_st[u]=true;\n        for(int v:g[u]){\n            if(disc[v]==-1){\n\
    \                dfs(v,u);\n                low[u]=min(low[u],low[v]);\n     \
    \       }else if(in_st[v]){\n                low[u]=min(low[u],disc[v]);\n   \
    \         }\n        }\n        if(disc[u]==low[u]){\n            while(true){\n\
    \                int v=st.top();\n                st.pop();\n                in_st[v]=false;\n\
    \                scc[v]=scc_cnt;\n                if(v==u)break;\n           \
    \ }\n            scc_cnt++;\n        }\n    };\n    for(int i=0;i<n;i++)if(disc[i]==-1)dfs(i,-1);\n\
    \    return {scc_cnt,scc};\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n * Description:\
    \ Strongly Connected Component.\n */\n\ntemplate<class G>\npair<int,vector<int>>\
    \ strongly_connected_component(G &g){\n    static_assert(G::is_directed);\n  \
    \  int n=g.n;\n    vector<int> disc(n,-1),low(n),scc(n,-1);\n    stack<int> st;\n\
    \    vector<bool> in_st(n);\n    int t=0,scc_cnt=0;\n    function<void(int,int)>\
    \ dfs=[&](int u,int p){\n        disc[u]=low[u]=t++;\n        st.emplace(u);\n\
    \        in_st[u]=true;\n        for(int v:g[u]){\n            if(disc[v]==-1){\n\
    \                dfs(v,u);\n                low[u]=min(low[u],low[v]);\n     \
    \       }else if(in_st[v]){\n                low[u]=min(low[u],disc[v]);\n   \
    \         }\n        }\n        if(disc[u]==low[u]){\n            while(true){\n\
    \                int v=st.top();\n                st.pop();\n                in_st[v]=false;\n\
    \                scc[v]=scc_cnt;\n                if(v==u)break;\n           \
    \ }\n            scc_cnt++;\n        }\n    };\n    for(int i=0;i<n;i++)if(disc[i]==-1)dfs(i,-1);\n\
    \    return {scc_cnt,scc};\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly-connected-component.hpp
  requiredBy: []
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/graph/scc.test.cpp
documentation_of: graph/strongly-connected-component.hpp
layout: document
redirect_from:
- /library/graph/strongly-connected-component.hpp
- /library/graph/strongly-connected-component.hpp.html
title: graph/strongly-connected-component.hpp
---
