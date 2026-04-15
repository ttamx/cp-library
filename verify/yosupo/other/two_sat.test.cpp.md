---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/twosat.hpp
    title: graph/twosat.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"verify/yosupo/other/two_sat.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\n\
    #define ALL(a) a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n#define\
    \ SORT(a) sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
    #define UNI(a) a.erase(unique(ALL(a)),a.end())\n#define SZ(a) (int)(a.size())\n\
    #define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n\
    #define MIN(a) *min_element(ALL(a))\n#define MAX(a) *max_element(ALL(a))\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\n\nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class\
    \ T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\n#define vv(T,a,n,...)\
    \ vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define vvv(T,a,n,m,...) vector<vector<vector<T>>>\
    \ a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n#define vvvv(T,a,n,m,k,...)\
    \ vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 2 \"template.hpp\"\n\nusing namespace std;\n\n#define pb push_back\n#define\
    \ eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define fi first\n\
    #define se second\n\n#define ALL(a) a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n\
    #define SORT(a) sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
    #define UNI(a) a.erase(unique(ALL(a)),a.end())\n#define SZ(a) (int)(a.size())\n\
    #define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n\
    #define MIN(a) *min_element(ALL(a))\n#define MAX(a) *max_element(ALL(a))\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\n\nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class\
    \ T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\n#define vv(T,a,n,...)\
    \ vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define vvv(T,a,n,m,...) vector<vector<vector<T>>>\
    \ a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n#define vvvv(T,a,n,m,k,...)\
    \ vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 3 \"graph/twosat.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2025-02-20\n *\
    \ Description: Cartesian Tree.\n */\n\nstruct TwoSAT{\n    int n;\n    vector<vector<int>>\
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
    \        }\n        return {true,ans};\n    }\n};\n#line 4 \"verify/yosupo/other/two_sat.test.cpp\"\
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
  path: verify/yosupo/other/two_sat.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 17:32:38+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/other/two_sat.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/other/two_sat.test.cpp
- /verify/verify/yosupo/other/two_sat.test.cpp.html
title: verify/yosupo/other/two_sat.test.cpp
---
