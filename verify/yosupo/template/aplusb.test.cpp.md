---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/yosupo/template/aplusb.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\
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
    }\n\ntemplate<class T,size_t D=0>\nstruct VecBuilder{\n    array<size_t,D> d;\n\
    \    VecBuilder<T,D+1> operator[](size_t n)const{\n        VecBuilder<T,D+1> res{};\n\
    \        for(size_t i=0;i<D;i++)res.d[i]=d[i];\n        res.d[D]=n;\n        return\
    \ res;\n    }\n    template<size_t I=0>\n    auto build(const T &x)const{\n  \
    \      if constexpr(I+1==D)return vector<T>(d[I],x);\n        else return vector<decltype(build<I+1>(x))>(d[I],build<I+1>(x));\n\
    \    }\n    auto operator()(const T &x=T())const{\n        static_assert(D>0);\n\
    \        return build(x);\n    }\n};\ntemplate<class T>\ninline constexpr VecBuilder<T>\
    \ VEC{};\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 3 \"verify/yosupo/template/aplusb.test.cpp\"\n\nvoid test_macros(){\n    vector<int>\
    \ a{3,1,4,1,5};\n    assert(SZ(a)==5);\n    assert(FIND(a,4)==2&&FIND(a,9)==SZ(a));\n\
    \    assert(COUNT(a,1)==2&&COUNT(a,7)==0);\n    assert(MIN(a)==1&&MAX(a)==5);\n\
    \    SORT(a);\n    assert(a==vector<int>({1,1,3,4,5}));\n    UNI(a);\n    assert(a==vector<int>({1,3,4,5}));\n\
    \    assert(LB(a,3)==1&&UB(a,3)==2&&LB(a,6)==4);\n    RSORT(a);\n    assert(a==vector<int>({5,4,3,1}));\n\
    \    REV(a);\n    assert(a==vector<int>({1,3,4,5}));\n}\n\nvoid test_chmin_chmax(){\n\
    \    ll x=5;\n    assert(chmin(x,3)&&x==3);\n    assert(!chmin(x,4)&&x==3);\n\
    \    assert(chmax(x,7)&&x==7);\n    assert(!chmax(x,7)&&x==7);\n}\n\nvoid test_floor_ceil(){\n\
    \    for(ll a=-50;a<=50;a++){\n        for(ll b=-7;b<=7;b++){\n            if(b==0)continue;\n\
    \            assert(floor(a,b)==(ll)std::floor((db)a/b));\n            assert(ceil(a,b)==(ll)std::ceil((db)a/b));\n\
    \        }\n    }\n}\n\nvoid test_bits(){\n    assert(popcnt(0)==0&&popcnt(13)==3&&popcnt((1LL<<62)|1)==2);\n\
    \    assert(topbit(0)==-1&&topbit(1)==0&&topbit(13)==3&&topbit(1LL<<62)==62);\n\
    \    assert(lowbit(0)==-1&&lowbit(1)==0&&lowbit(12)==2&&lowbit(1LL<<62)==62);\n\
    }\n\nvoid test_sum_argsort(){\n    vector<int> a(3,2000000000);\n    assert(SUM<ll>(a)==6000000000LL);\n\
    \    vector<int> b{30,10,20,10};\n    assert(argsort(b)==vector<int>({1,3,2,0}));\n\
    }\n\nvoid test_vec(){\n    auto a=VEC<pair<int,int>>[2][3][4]();\n    static_assert(is_same_v<decltype(a),vector<vector<vector<pair<int,int>>>>>);\n\
    \    assert(SZ(a)==2&&SZ(a[0])==3&&SZ(a[0][0])==4&&a[1][2][3]==pair(0,0));\n \
    \   auto b=VEC<ll>[2][3](LINF);\n    assert(b[1][2]==LINF);\n}\n\nint main(){\n\
    \    test_macros();\n    test_chmin_chmax();\n    test_floor_ceil();\n    test_bits();\n\
    \    test_sum_argsort();\n    test_vec();\n    ll a,b;\n    cin >> a >> b;\n \
    \   cout << a+b << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"template.hpp\"\
    \n\nvoid test_macros(){\n    vector<int> a{3,1,4,1,5};\n    assert(SZ(a)==5);\n\
    \    assert(FIND(a,4)==2&&FIND(a,9)==SZ(a));\n    assert(COUNT(a,1)==2&&COUNT(a,7)==0);\n\
    \    assert(MIN(a)==1&&MAX(a)==5);\n    SORT(a);\n    assert(a==vector<int>({1,1,3,4,5}));\n\
    \    UNI(a);\n    assert(a==vector<int>({1,3,4,5}));\n    assert(LB(a,3)==1&&UB(a,3)==2&&LB(a,6)==4);\n\
    \    RSORT(a);\n    assert(a==vector<int>({5,4,3,1}));\n    REV(a);\n    assert(a==vector<int>({1,3,4,5}));\n\
    }\n\nvoid test_chmin_chmax(){\n    ll x=5;\n    assert(chmin(x,3)&&x==3);\n  \
    \  assert(!chmin(x,4)&&x==3);\n    assert(chmax(x,7)&&x==7);\n    assert(!chmax(x,7)&&x==7);\n\
    }\n\nvoid test_floor_ceil(){\n    for(ll a=-50;a<=50;a++){\n        for(ll b=-7;b<=7;b++){\n\
    \            if(b==0)continue;\n            assert(floor(a,b)==(ll)std::floor((db)a/b));\n\
    \            assert(ceil(a,b)==(ll)std::ceil((db)a/b));\n        }\n    }\n}\n\
    \nvoid test_bits(){\n    assert(popcnt(0)==0&&popcnt(13)==3&&popcnt((1LL<<62)|1)==2);\n\
    \    assert(topbit(0)==-1&&topbit(1)==0&&topbit(13)==3&&topbit(1LL<<62)==62);\n\
    \    assert(lowbit(0)==-1&&lowbit(1)==0&&lowbit(12)==2&&lowbit(1LL<<62)==62);\n\
    }\n\nvoid test_sum_argsort(){\n    vector<int> a(3,2000000000);\n    assert(SUM<ll>(a)==6000000000LL);\n\
    \    vector<int> b{30,10,20,10};\n    assert(argsort(b)==vector<int>({1,3,2,0}));\n\
    }\n\nvoid test_vec(){\n    auto a=VEC<pair<int,int>>[2][3][4]();\n    static_assert(is_same_v<decltype(a),vector<vector<vector<pair<int,int>>>>>);\n\
    \    assert(SZ(a)==2&&SZ(a[0])==3&&SZ(a[0][0])==4&&a[1][2][3]==pair(0,0));\n \
    \   auto b=VEC<ll>[2][3](LINF);\n    assert(b[1][2]==LINF);\n}\n\nint main(){\n\
    \    test_macros();\n    test_chmin_chmax();\n    test_floor_ceil();\n    test_bits();\n\
    \    test_sum_argsort();\n    test_vec();\n    ll a,b;\n    cin >> a >> b;\n \
    \   cout << a+b << \"\\n\";\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: true
  path: verify/yosupo/template/aplusb.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/template/aplusb.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/template/aplusb.test.cpp
- /verify/verify/yosupo/template/aplusb.test.cpp.html
title: verify/yosupo/template/aplusb.test.cpp
---
