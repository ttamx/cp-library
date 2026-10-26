---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/xor-intervals.hpp
    title: misc/xor-intervals.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/yosupo/misc/xor-intervals/aplusb.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"template.hpp\"\
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
    }\n#line 2 \"misc/xor-intervals.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2026-10-26\n\
    \ * Source: https://qoj.ac/contest/4538/problem/22840\n * Description: Returns\
    \ $\\{x \\oplus y \\mid l_1 \\le x < r_1,\\ l_2 \\le y < r_2\\}$\n * as a sorted\
    \ list of disjoint, merged half-open intervals $[a, b)$. The output\n * has $O(\\\
    log V)$ intervals, at most $8$ per bit. Requires $r_1, r_2 \\le 2^{63}$.\n * Time:\
    \ O(\\log V)\n */\n\nauto xor_intervals(u64 l1,u64 r1,u64 l2,u64 r2){\n    using\
    \ VP = vector<pair<u64,u64>>;\n    VP res;\n    if(l1>=r1||l2>=r2)return res;\n\
    \    auto in=[](u64 x,u64 s,u64 l,u64 r){return l<=x&&x+s<=r;};\n    auto ov=[](u64\
    \ x,u64 s,u64 l,u64 r){return x<r&&l<x+s;};\n    auto rec=[&](auto &self,u64 s,u64\
    \ z,const VP &a)->void {\n        if(a.empty())return;\n        for(auto [x,y]:a)if(in(x,s,l1,r1)||in(y,s,l2,r2)){\n\
    \            if(!res.empty()&&res.back().second==z)\n                res.back().second=z+s;\n\
    \            else res.emplace_back(z,z+s);\n            return;\n        }\n \
    \       s>>=1;\n        VP b[2];\n        for(auto [x,y]:a)for(u64 u:{x,x|s})if(ov(u,s,l1,r1))\n\
    \            for(u64 v:{y,y|s})if(ov(v,s,l2,r2))\n                b[((u^v)&s)!=0].emplace_back(u,v);\n\
    \        self(self,s,z,b[0]);\n        self(self,s,z|s,b[1]);\n    };\n    rec(rec,1ULL<<63,0,{{0,0}});\n\
    \    return res;\n}\n#line 4 \"verify/yosupo/misc/xor-intervals/aplusb.test.cpp\"\
    \n\nmt19937_64 gen(12345);\n\nvoid check_shape(const vector<pair<u64,u64>> &res){\n\
    \    for(int i=0;i<SZ(res);i++){\n        assert(res[i].first<res[i].second);\n\
    \        if(i>0)assert(res[i-1].second<res[i].first);\n    }\n}\n\nvector<char>\
    \ brute(u64 l1,u64 r1,u64 l2,u64 r2){\n    vector<char> ok(128);\n    for(u64\
    \ x=l1;x<r1;x++)for(u64 y=l2;y<r2;y++)ok[x^y]=1;\n    return ok;\n}\n\nvoid test_small(){\n\
    \    for(int it=0;it<5000;it++){\n        u64 l1=gen()%65,r1=gen()%65,l2=gen()%65,r2=gen()%65;\n\
    \        if(it%4&&l1>r1)swap(l1,r1);\n        if(it%4&&l2>r2)swap(l2,r2);\n  \
    \      auto res=xor_intervals(l1,r1,l2,r2);\n        check_shape(res);\n     \
    \   vector<char> got(128);\n        for(auto [a,b]:res){\n            assert(b<=128);\n\
    \            for(u64 z=a;z<b;z++)got[z]=1;\n        }\n        assert(got==brute(l1,r1,l2,r2));\n\
    \    }\n}\n\n// With values below 2^20 and offsets k1, k2 that are multiples of\
    \ 2^20,\n// (x+k1)^(y+k2) = (x^y)+(k1^k2), so every interval shifts by k1^k2.\n\
    void test_large(){\n    for(int it=0;it<5000;it++){\n        u64 l1=gen()%(1<<20),r1=gen()%(1<<20)+1;\n\
    \        u64 l2=gen()%(1<<20),r2=gen()%(1<<20)+1;\n        if(l1>r1)swap(l1,r1);\n\
    \        if(l2>r2)swap(l2,r2);\n        u64 k1=(gen()%(1ULL<<43))<<20,k2=(gen()%(1ULL<<43))<<20;\n\
    \        auto small=xor_intervals(l1,r1,l2,r2);\n        auto big=xor_intervals(l1+k1,r1+k1,l2+k2,r2+k2);\n\
    \        check_shape(big);\n        u64 k=k1^k2;\n        assert(SZ(small)==SZ(big));\n\
    \        for(int i=0;i<SZ(small);i++){\n            assert(big[i].first==small[i].first+k);\n\
    \            assert(big[i].second==small[i].second+k);\n        }\n    }\n}\n\n\
    int main(){\n    test_small();\n    test_large();\n    ll a,b;\n    cin >> a >>\
    \ b;\n    cout << a+b << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"template.hpp\"\
    \n#include \"misc/xor-intervals.hpp\"\n\nmt19937_64 gen(12345);\n\nvoid check_shape(const\
    \ vector<pair<u64,u64>> &res){\n    for(int i=0;i<SZ(res);i++){\n        assert(res[i].first<res[i].second);\n\
    \        if(i>0)assert(res[i-1].second<res[i].first);\n    }\n}\n\nvector<char>\
    \ brute(u64 l1,u64 r1,u64 l2,u64 r2){\n    vector<char> ok(128);\n    for(u64\
    \ x=l1;x<r1;x++)for(u64 y=l2;y<r2;y++)ok[x^y]=1;\n    return ok;\n}\n\nvoid test_small(){\n\
    \    for(int it=0;it<5000;it++){\n        u64 l1=gen()%65,r1=gen()%65,l2=gen()%65,r2=gen()%65;\n\
    \        if(it%4&&l1>r1)swap(l1,r1);\n        if(it%4&&l2>r2)swap(l2,r2);\n  \
    \      auto res=xor_intervals(l1,r1,l2,r2);\n        check_shape(res);\n     \
    \   vector<char> got(128);\n        for(auto [a,b]:res){\n            assert(b<=128);\n\
    \            for(u64 z=a;z<b;z++)got[z]=1;\n        }\n        assert(got==brute(l1,r1,l2,r2));\n\
    \    }\n}\n\n// With values below 2^20 and offsets k1, k2 that are multiples of\
    \ 2^20,\n// (x+k1)^(y+k2) = (x^y)+(k1^k2), so every interval shifts by k1^k2.\n\
    void test_large(){\n    for(int it=0;it<5000;it++){\n        u64 l1=gen()%(1<<20),r1=gen()%(1<<20)+1;\n\
    \        u64 l2=gen()%(1<<20),r2=gen()%(1<<20)+1;\n        if(l1>r1)swap(l1,r1);\n\
    \        if(l2>r2)swap(l2,r2);\n        u64 k1=(gen()%(1ULL<<43))<<20,k2=(gen()%(1ULL<<43))<<20;\n\
    \        auto small=xor_intervals(l1,r1,l2,r2);\n        auto big=xor_intervals(l1+k1,r1+k1,l2+k2,r2+k2);\n\
    \        check_shape(big);\n        u64 k=k1^k2;\n        assert(SZ(small)==SZ(big));\n\
    \        for(int i=0;i<SZ(small);i++){\n            assert(big[i].first==small[i].first+k);\n\
    \            assert(big[i].second==small[i].second+k);\n        }\n    }\n}\n\n\
    int main(){\n    test_small();\n    test_large();\n    ll a,b;\n    cin >> a >>\
    \ b;\n    cout << a+b << \"\\n\";\n}\n"
  dependsOn:
  - template.hpp
  - misc/xor-intervals.hpp
  isVerificationFile: true
  path: verify/yosupo/misc/xor-intervals/aplusb.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 14:09:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/misc/xor-intervals/aplusb.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/misc/xor-intervals/aplusb.test.cpp
- /verify/verify/yosupo/misc/xor-intervals/aplusb.test.cpp.html
title: verify/yosupo/misc/xor-intervals/aplusb.test.cpp
---
