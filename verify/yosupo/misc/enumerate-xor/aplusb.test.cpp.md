---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/enumerate-xor.hpp
    title: misc/enumerate-xor.hpp
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
  bundledCode: "#line 1 \"verify/yosupo/misc/enumerate-xor/aplusb.test.cpp\"\n#define\
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
    }\n#line 2 \"misc/enumerate-xor.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-11-27\n\
    \ * Description: enumerate all range of x such that l <= x xor p < r.\n */\n\n\
    template<class F>\nvoid enumerate_xor(ll p,ll l,ll r,const F &query){\n    for(ll\
    \ b=1;l<r;b<<=1){\n        if(l&b)query(l^p,(l^p)+b),l+=b;\n        if(r&b)r-=b,query(r^p,(r^p)+b);\n\
    \        if(p&b)p^=b;\n    }\n}\n#line 4 \"verify/yosupo/misc/enumerate-xor/aplusb.test.cpp\"\
    \n\nmt19937_64 gen(12345);\n\nvoid test_small(){\n    for(int it=0;it<5000;it++){\n\
    \        ll p=gen()%128,l=gen()%129,r=gen()%129;\n        if(l>r)swap(l,r);\n\
    \        vector<int> cnt(256);\n        enumerate_xor(p,l,r,[&](ll a,ll b){\n\
    \            assert(0<=a&&a<b&&b<=256);\n            for(ll x=a;x<b;x++)cnt[x]++;\n\
    \        });\n        for(ll x=0;x<256;x++){\n            assert(cnt[x]==(l<=(x^p)&&(x^p)<r));\n\
    \        }\n    }\n}\n\nvoid test_large(){\n    for(int it=0;it<5000;it++){\n\
    \        int k=1+gen()%62;\n        ll mask=(1LL<<k)-1;\n        ll p=gen()&mask,l=gen()&mask,r=gen()&mask;\n\
    \        if(l>r)swap(l,r);\n        vector<pair<ll,ll>> img;\n        int calls=0;\n\
    \        enumerate_xor(p,l,r,[&](ll a,ll b){\n            ll len=b-a;\n      \
    \      assert(len>0&&(len&(len-1))==0&&a%len==0);\n            ll lo=(a^p)&~(len-1);\n\
    \            img.emplace_back(lo,lo+len);\n            calls++;\n        });\n\
    \        assert(calls<=2*64);\n        sort(img.begin(),img.end());\n        ll\
    \ cur=l;\n        for(auto [lo,hi]:img){\n            assert(lo==cur);\n     \
    \       cur=hi;\n        }\n        assert(cur==r);\n    }\n}\n\nint main(){\n\
    \    test_small();\n    test_large();\n    ll a,b;\n    cin >> a >> b;\n    cout\
    \ << a+b << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"template.hpp\"\
    \n#include \"misc/enumerate-xor.hpp\"\n\nmt19937_64 gen(12345);\n\nvoid test_small(){\n\
    \    for(int it=0;it<5000;it++){\n        ll p=gen()%128,l=gen()%129,r=gen()%129;\n\
    \        if(l>r)swap(l,r);\n        vector<int> cnt(256);\n        enumerate_xor(p,l,r,[&](ll\
    \ a,ll b){\n            assert(0<=a&&a<b&&b<=256);\n            for(ll x=a;x<b;x++)cnt[x]++;\n\
    \        });\n        for(ll x=0;x<256;x++){\n            assert(cnt[x]==(l<=(x^p)&&(x^p)<r));\n\
    \        }\n    }\n}\n\nvoid test_large(){\n    for(int it=0;it<5000;it++){\n\
    \        int k=1+gen()%62;\n        ll mask=(1LL<<k)-1;\n        ll p=gen()&mask,l=gen()&mask,r=gen()&mask;\n\
    \        if(l>r)swap(l,r);\n        vector<pair<ll,ll>> img;\n        int calls=0;\n\
    \        enumerate_xor(p,l,r,[&](ll a,ll b){\n            ll len=b-a;\n      \
    \      assert(len>0&&(len&(len-1))==0&&a%len==0);\n            ll lo=(a^p)&~(len-1);\n\
    \            img.emplace_back(lo,lo+len);\n            calls++;\n        });\n\
    \        assert(calls<=2*64);\n        sort(img.begin(),img.end());\n        ll\
    \ cur=l;\n        for(auto [lo,hi]:img){\n            assert(lo==cur);\n     \
    \       cur=hi;\n        }\n        assert(cur==r);\n    }\n}\n\nint main(){\n\
    \    test_small();\n    test_large();\n    ll a,b;\n    cin >> a >> b;\n    cout\
    \ << a+b << \"\\n\";\n}\n"
  dependsOn:
  - template.hpp
  - misc/enumerate-xor.hpp
  isVerificationFile: true
  path: verify/yosupo/misc/enumerate-xor/aplusb.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 14:09:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/misc/enumerate-xor/aplusb.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/misc/enumerate-xor/aplusb.test.cpp
- /verify/verify/yosupo/misc/enumerate-xor/aplusb.test.cpp.html
title: verify/yosupo/misc/enumerate-xor/aplusb.test.cpp
---
