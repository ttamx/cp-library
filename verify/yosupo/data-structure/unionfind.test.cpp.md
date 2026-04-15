---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dsu.hpp
    title: data-structure/dsu.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo/data-structure/unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#define pb push_back\n#define\
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
    \ 2 \"data-structure/dsu.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n\
    \ * Description: Disjoint Set Union.\n */\n\nstruct DSU{\n    vector<int> p,sz;\n\
    \    DSU(){}\n    DSU(int n){init(n);}\n    void init(int n){\n        p.resize(n);\n\
    \        iota(p.begin(),p.end(),0);\n        sz.assign(n,1);\n    }\n    int find(int\
    \ u){\n        return p[u]==u?u:p[u]=find(p[u]);\n    }\n    bool same(int u,int\
    \ v){\n        return find(u)==find(v);\n    }\n    bool merge(int u,int v){\n\
    \        u=find(u),v=find(v);\n        if(u==v)return false;\n        sz[u]+=sz[v];\n\
    \        p[v]=u;\n        return true;\n    }\n    int size(int u){\n        return\
    \ sz[find(u)];\n    }\n};\n\n#line 4 \"verify/yosupo/data-structure/unionfind.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    DSU dsu(n);\n    while(q--){\n        int t,u,v;\n  \
    \      cin >> t >> u >> v;\n        if(t==0)dsu.merge(u,v);\n        else cout\
    \ << dsu.same(u,v) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    template.hpp\"\n#include \"data-structure/dsu.hpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    DSU dsu(n);\n    while(q--){\n        int\
    \ t,u,v;\n        cin >> t >> u >> v;\n        if(t==0)dsu.merge(u,v);\n     \
    \   else cout << dsu.same(u,v) << \"\\n\";\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/dsu.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 17:32:38+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/unionfind.test.cpp
- /verify/verify/yosupo/data-structure/unionfind.test.cpp.html
title: verify/yosupo/data-structure/unionfind.test.cpp
---
