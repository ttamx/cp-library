---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/bbst/treap.hpp
    title: data-structure/bbst/treap.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
    title: verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
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
    }\n#line 3 \"random.hpp\"\n\nstruct SplitMix64{\n    using result_type = u64;\n\
    \    u64 x;\n    SplitMix64(u64 seed=chrono::steady_clock::now().time_since_epoch().count()):x(seed){}\n\
    \    static constexpr u64 min(){return 0;}\n    static constexpr u64 max(){return\
    \ numeric_limits<u64>::max();}\n    u64 operator()(){\n        u64 z=(x+=0x9e3779b97f4a7c15);\n\
    \        z=(z^(z>>30))*0xbf58476d1ce4e5b9;\n        z=(z^(z>>27))*0x94d049bb133111eb;\n\
    \        return z^(z>>31);\n    }\n};\n\nSplitMix64 rng;\n\nu64 rnd(u64 n){\n\
    \    return rng()%n;\n}\nll rnd(ll l,ll r){\n    assert(l<=r);\n    return l+rng()%(r-l+1);\n\
    }\ndb rnd_real(db l,db r){\n    return l+(r-l)*(rng()>>11)*0x1p-53;\n}\n"
  code: "#pragma once\n#include \"template.hpp\"\n\nstruct SplitMix64{\n    using\
    \ result_type = u64;\n    u64 x;\n    SplitMix64(u64 seed=chrono::steady_clock::now().time_since_epoch().count()):x(seed){}\n\
    \    static constexpr u64 min(){return 0;}\n    static constexpr u64 max(){return\
    \ numeric_limits<u64>::max();}\n    u64 operator()(){\n        u64 z=(x+=0x9e3779b97f4a7c15);\n\
    \        z=(z^(z>>30))*0xbf58476d1ce4e5b9;\n        z=(z^(z>>27))*0x94d049bb133111eb;\n\
    \        return z^(z>>31);\n    }\n};\n\nSplitMix64 rng;\n\nu64 rnd(u64 n){\n\
    \    return rng()%n;\n}\nll rnd(ll l,ll r){\n    assert(l<=r);\n    return l+rng()%(r-l+1);\n\
    }\ndb rnd_real(db l,db r){\n    return l+(r-l)*(rng()>>11)*0x1p-53;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: random.hpp
  requiredBy:
  - data-structure/bbst/treap.hpp
  timestamp: '2026-10-25 14:43:57+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
documentation_of: random.hpp
layout: document
redirect_from:
- /library/random.hpp
- /library/random.hpp.html
title: random.hpp
---
