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
  bundledCode: "#line 2 \"graph/low-link.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-06-28\n * Description: Low Link.\n */\n\ntemplate<class G>\nstruct LowLink{\n\
    \    G &g;\n    int n;\n    vector<int> disc,low,par,ord;\n    vector<pair<int,int>>\
    \ bridge;\n    vector<int> articulation;\n    int t=0;\n    LowLink(G &_g):g(_g),n(g.n),disc(n,-1),low(n),par(n,-1){\n\
    \        for(int i=0;i<n;i++)if(disc[i]==-1)dfs(i);\n    }\n    void dfs(int u){\n\
    \        disc[u]=low[u]=t++;\n        ord.emplace_back(u);\n        int child=0;\n\
    \        bool found_par=false;\n        for(int v:g[u]){\n            if(disc[v]==-1){\n\
    \                par[v]=u;\n                dfs(v);\n                low[u]=min(low[u],low[v]);\n\
    \                if(low[v]>disc[u])bridge.emplace_back(u,v);\n               \
    \ if(par[u]!=-1&&low[v]>=disc[u])articulation.emplace_back(u);\n             \
    \   child++;\n            }else if(v!=par[u]||found_par){\n                low[u]=min(low[u],disc[v]);\n\
    \            }else{\n                found_par=true;\n            }\n        }\n\
    \        if(par[u]==-1&&child>1)articulation.emplace_back(u);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n * Description:\
    \ Low Link.\n */\n\ntemplate<class G>\nstruct LowLink{\n    G &g;\n    int n;\n\
    \    vector<int> disc,low,par,ord;\n    vector<pair<int,int>> bridge;\n    vector<int>\
    \ articulation;\n    int t=0;\n    LowLink(G &_g):g(_g),n(g.n),disc(n,-1),low(n),par(n,-1){\n\
    \        for(int i=0;i<n;i++)if(disc[i]==-1)dfs(i);\n    }\n    void dfs(int u){\n\
    \        disc[u]=low[u]=t++;\n        ord.emplace_back(u);\n        int child=0;\n\
    \        bool found_par=false;\n        for(int v:g[u]){\n            if(disc[v]==-1){\n\
    \                par[v]=u;\n                dfs(v);\n                low[u]=min(low[u],low[v]);\n\
    \                if(low[v]>disc[u])bridge.emplace_back(u,v);\n               \
    \ if(par[u]!=-1&&low[v]>=disc[u])articulation.emplace_back(u);\n             \
    \   child++;\n            }else if(v!=par[u]||found_par){\n                low[u]=min(low[u],disc[v]);\n\
    \            }else{\n                found_par=true;\n            }\n        }\n\
    \        if(par[u]==-1&&child>1)articulation.emplace_back(u);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/low-link.hpp
  requiredBy: []
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/low-link.hpp
layout: document
redirect_from:
- /library/graph/low-link.hpp
- /library/graph/low-link.hpp.html
title: graph/low-link.hpp
---
