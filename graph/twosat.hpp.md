---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/other/two_sat.test.cpp
    title: verify/yosupo/other/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\nusing\
    \ vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst\
    \ int MOD=998244353;\nconst int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    template<class T>\nusing ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 3 \"graph/twosat.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2025-02-20\n * Description: Cartesian\
    \ Tree.\n */\n\nstruct TwoSAT{\n    int n;\n    vector<vector<int>> adj,rev;\n\
    \    TwoSAT(int _n):n(_n),adj(n*2),rev(n*2){}\n    void add_edge(int u,int v){\n\
    \        adj[u].emplace_back(v);\n        rev[v].emplace_back(u);\n    }\n   \
    \ void add_clause(int u,bool nu,int v,bool nv){\n        u=(u<<1)|nu,v=(v<<1)|nv;\n\
    \        add_edge(u^1,v);\n        add_edge(v^1,u);\n    }\n    pair<bool,vector<bool>>\
    \ solve(){\n        vector<bool> vis(n*2),ans(n);\n        vector<int> ord,scc(n*2);\n\
    \        int scc_id=0;\n        function<void(int)> dfs=[&](int u){\n        \
    \    if(vis[u])return;\n            vis[u]=true;\n            for(auto v:adj[u])dfs(v);\n\
    \            ord.emplace_back(u);\n        };\n        function<void(int)> dfs2=[&](int\
    \ u){\n            if(scc[u])return;\n            scc[u]=scc_id;\n           \
    \ for(auto v:rev[u])dfs2(v);\n        };\n        for(int i=0;i<2*n;i++)dfs(i);\n\
    \        reverse(ord.begin(),ord.end());\n        for(int i:ord)if(!scc[i]){\n\
    \            scc_id++;\n            dfs2(i);\n        }\n        for(int i=0;i<n;i++){\n\
    \            if(scc[i<<1]==scc[(i<<1)|1])return {false,ans};\n            ans[i]=scc[i<<1]>scc[(i<<1)|1];\n\
    \        }\n        return {true,ans};\n    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2025-02-20\n * Description: Cartesian Tree.\n */\n\nstruct TwoSAT{\n \
    \   int n;\n    vector<vector<int>> adj,rev;\n    TwoSAT(int _n):n(_n),adj(n*2),rev(n*2){}\n\
    \    void add_edge(int u,int v){\n        adj[u].emplace_back(v);\n        rev[v].emplace_back(u);\n\
    \    }\n    void add_clause(int u,bool nu,int v,bool nv){\n        u=(u<<1)|nu,v=(v<<1)|nv;\n\
    \        add_edge(u^1,v);\n        add_edge(v^1,u);\n    }\n    pair<bool,vector<bool>>\
    \ solve(){\n        vector<bool> vis(n*2),ans(n);\n        vector<int> ord,scc(n*2);\n\
    \        int scc_id=0;\n        function<void(int)> dfs=[&](int u){\n        \
    \    if(vis[u])return;\n            vis[u]=true;\n            for(auto v:adj[u])dfs(v);\n\
    \            ord.emplace_back(u);\n        };\n        function<void(int)> dfs2=[&](int\
    \ u){\n            if(scc[u])return;\n            scc[u]=scc_id;\n           \
    \ for(auto v:rev[u])dfs2(v);\n        };\n        for(int i=0;i<2*n;i++)dfs(i);\n\
    \        reverse(ord.begin(),ord.end());\n        for(int i:ord)if(!scc[i]){\n\
    \            scc_id++;\n            dfs2(i);\n        }\n        for(int i=0;i<n;i++){\n\
    \            if(scc[i<<1]==scc[(i<<1)|1])return {false,ans};\n            ans[i]=scc[i<<1]>scc[(i<<1)|1];\n\
    \        }\n        return {true,ans};\n    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/twosat.hpp
  requiredBy: []
  timestamp: '2025-04-16 16:10:29+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/other/two_sat.test.cpp
documentation_of: graph/twosat.hpp
layout: document
redirect_from:
- /library/graph/twosat.hpp
- /library/graph/twosat.hpp.html
title: graph/twosat.hpp
---
