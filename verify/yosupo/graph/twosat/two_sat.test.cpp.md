---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/twosat.hpp
    title: graph/twosat.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"verify/yosupo/graph/twosat/two_sat.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing db = long double;\nusing\
    \ i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\ntemplate<class\
    \ T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\nconst int INF=INT_MAX/2;\n\
    const ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\nconst\
    \ db EPS=1e-9;\nconst db PI=acos(db(-1));\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SZ(a) (int)(a.size())\n#define SORT(a)\
    \ sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
    #define UNI(a) a.erase(unique(ALL(a)),a.end())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define FIND(a,x) (int)(find(ALL(a),x)-a.begin())\n\
    #define COUNT(a,x) (int)count(ALL(a),x)\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\ntemplate<class T,class U>\nbool chmin(T\
    \ &a,U b){return b<a?a=b,1:0;}\ntemplate<class T,class U>\nbool chmax(T &a,U b){return\
    \ a<b?a=b,1:0;}\n\ntemplate<class T>\nT floor(T a,T b){return a/b-((a^b)<0&&a%b);}\n\
    template<class T>\nT ceil(T a,T b){return a/b+((a^b)>=0&&a%b);}\n\nint popcnt(ll\
    \ x){return __builtin_popcountll(x);}\nint topbit(ll x){return x==0?-1:63-__builtin_clzll(x);}\n\
    int lowbit(ll x){return x==0?-1:__builtin_ctzll(x);}\n\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\ntemplate<class T>\nvector<int>\
    \ argsort(const vector<T> &a){\n    vector<int> p(SZ(a));\n    iota(ALL(p),0);\n\
    \    stable_sort(ALL(p),[&](int i,int j){return a[i]<a[j];});\n    return p;\n\
    }\n#line 3 \"graph/twosat.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2025-02-20\n\
    \ * Description: Cartesian Tree.\n */\n\nstruct TwoSAT{\n    int n;\n    vector<vector<int>>\
    \ adj,rev;\n    TwoSAT(int _n):n(_n),adj(n*2),rev(n*2){}\n    void add_edge(int\
    \ u,int v){\n        adj[u].emplace_back(v);\n        rev[v].emplace_back(u);\n\
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
    \        }\n        return {true,ans};\n    }\n};\n#line 4 \"verify/yosupo/graph/twosat/two_sat.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    string s;\n\
    \    int n,m;\n    cin >> s >> s >> n >> m;\n    TwoSAT sat(n);\n    for(int i=0;i<m;i++){\n\
    \        int a,b,x;\n        cin >> a >> b >> x;\n        sat.add_clause(abs(a)-1,a<0,abs(b)-1,b<0);\n\
    \    }\n    auto [ok,ans]=sat.solve();\n    if(ok){\n        cout << \"s SATISFIABLE\\\
    n\";\n        cout << \"v \";\n        for(int i=0;i<n;i++)cout << (ans[i]?i+1:-(i+1))\
    \ << \" \";\n        cout << \"0\\n\";\n\n    }else{\n        cout << \"s UNSATISFIABLE\\\
    n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include \"\
    template.hpp\"\n#include \"graph/twosat.hpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    string s;\n    int n,m;\n    cin >> s >> s >> n >> m;\n    TwoSAT sat(n);\n\
    \    for(int i=0;i<m;i++){\n        int a,b,x;\n        cin >> a >> b >> x;\n\
    \        sat.add_clause(abs(a)-1,a<0,abs(b)-1,b<0);\n    }\n    auto [ok,ans]=sat.solve();\n\
    \    if(ok){\n        cout << \"s SATISFIABLE\\n\";\n        cout << \"v \";\n\
    \        for(int i=0;i<n;i++)cout << (ans[i]?i+1:-(i+1)) << \" \";\n        cout\
    \ << \"0\\n\";\n\n    }else{\n        cout << \"s UNSATISFIABLE\\n\";\n    }\n\
    }"
  dependsOn:
  - template.hpp
  - graph/twosat.hpp
  isVerificationFile: true
  path: verify/yosupo/graph/twosat/two_sat.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 14:43:57+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/graph/twosat/two_sat.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/graph/twosat/two_sat.test.cpp
- /verify/verify/yosupo/graph/twosat/two_sat.test.cpp.html
title: verify/yosupo/graph/twosat/two_sat.test.cpp
---
