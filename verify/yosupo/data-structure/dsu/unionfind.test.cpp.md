---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dsu.hpp
    title: data-structure/dsu.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo/data-structure/dsu/unionfind.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ db = long double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64\
    \ = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n\n#define ALL(a) a.begin(),a.end()\n\
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
    }\n#line 2 \"data-structure/dsu.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n\
    \ * Description: Disjoint Set Union.\n */\n\nstruct DSU{\n    vector<int> p,sz;\n\
    \    DSU(){}\n    DSU(int n){init(n);}\n    void init(int n){\n        p.resize(n);\n\
    \        iota(p.begin(),p.end(),0);\n        sz.assign(n,1);\n    }\n    int find(int\
    \ u){\n        return p[u]==u?u:p[u]=find(p[u]);\n    }\n    bool same(int u,int\
    \ v){\n        return find(u)==find(v);\n    }\n    bool merge(int u,int v){\n\
    \        u=find(u),v=find(v);\n        if(u==v)return false;\n        if(sz[u]<sz[v])swap(u,v);\n\
    \        sz[u]+=sz[v];\n        p[v]=u;\n        return true;\n    }\n    int\
    \ size(int u){\n        return sz[find(u)];\n    }\n};\n\n#line 4 \"verify/yosupo/data-structure/dsu/unionfind.test.cpp\"\
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
  path: verify/yosupo/data-structure/dsu/unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 14:43:57+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/dsu/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/dsu/unionfind.test.cpp
- /verify/verify/yosupo/data-structure/dsu/unionfind.test.cpp.html
title: verify/yosupo/data-structure/dsu/unionfind.test.cpp
---
