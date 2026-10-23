---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number-theory/floor-sum.hpp
    title: number-theory/floor-sum.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"verify/yosupo/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\
    #line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing\
    \ u32 = uint32_t;\nusing u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
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
    }\n\ntemplate<class T,size_t D=0>\nstruct VecBuilder{\n    array<size_t,D> d;\n\
    \    VecBuilder<T,D+1> operator[](size_t n)const{\n        VecBuilder<T,D+1> res{};\n\
    \        for(size_t i=0;i<D;i++)res.d[i]=d[i];\n        res.d[D]=n;\n        return\
    \ res;\n    }\n    template<size_t I=0>\n    auto build(const T &x)const{\n  \
    \      if constexpr(I+1==D)return vector<T>(d[I],x);\n        else return vector<decltype(build<I+1>(x))>(d[I],build<I+1>(x));\n\
    \    }\n    auto operator()(const T &x=T())const{\n        static_assert(D>0);\n\
    \        return build(x);\n    }\n};\ntemplate<class T>\ninline constexpr VecBuilder<T>\
    \ VEC{};\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 2 \"number-theory/floor-sum.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-09-21\n\
    \ * Description: Floor sum function.\n *  $f(a, b, c, n) = \\sum_{x=0}^n \\lfloor\
    \ \\frac{ax+b}{c} \\rfloor$\n *  becareful when a,b,c are negetive (use custom\
    \ floor division and mod instead)\n * Time: $O(\\log a)$\n */\n\nll floor_sum(ll\
    \ a,ll b,ll c,ll n){\n    ll res=n*(n+1)/2*(a/c)+(n+1)*(b/c);\n    a%=c,b%=c;\n\
    \    if(a==0)return res;\n    ll m=(a*n+b)/c;\n    return res+n*m-floor_sum(c,c-b-1,a,m-1);\n\
    }\n\n#line 4 \"verify/yosupo/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int t;\n \
    \   cin >> t;\n    while(t--){\n        ll n,m,a,b;\n        cin >> n >> m >>\
    \ a >> b;\n        cout << floor_sum(a,b,m,n-1) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#include \"template.hpp\"\n#include \"number-theory/floor-sum.hpp\"\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int t;\n    cin >> t;\n  \
    \  while(t--){\n        ll n,m,a,b;\n        cin >> n >> m >> a >> b;\n      \
    \  cout << floor_sum(a,b,m,n-1) << \"\\n\";\n    }\n}"
  dependsOn:
  - template.hpp
  - number-theory/floor-sum.hpp
  isVerificationFile: true
  path: verify/yosupo/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
- /verify/verify/yosupo/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp.html
title: verify/yosupo/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
---
