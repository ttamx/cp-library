---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: number-theory/floor-sum.hpp
    title: number-theory/floor-sum.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\
    #line 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 2 \"number-theory/floor-sum.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-09-21\n\
    \ * Description: Floor sum function.\n *  $f(a, b, c, n) = \\sum_{x=0}^n \\lfloor\
    \ \\frac{ax+b}{c} \\rfloor$\n *  becareful when a,b,c are negetive (use custom\
    \ floor division and mod instead)\n * Time: $O(\\log a)$\n */\n\nll floor_sum(ll\
    \ a,ll b,ll c,ll n){\n    ll res=n*(n+1)/2*(a/c)+(n+1)*(b/c);\n    a%=c,b%=c;\n\
    \    if(a==0)return res;\n    ll m=(a*n+b)/c;\n    return res+n*m-floor_sum(c,c-b-1,a,m-1);\n\
    }\n\n#line 4 \"verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp\"\n\
    \nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int t;\n   \
    \ cin >> t;\n    while(t--){\n        ll n,m,a,b;\n        cin >> n >> m >> a\
    \ >> b;\n        cout << floor_sum(a,b,m,n-1) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#include \"template.hpp\"\n#include \"number-theory/floor-sum.hpp\"\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int t;\n    cin >> t;\n  \
    \  while(t--){\n        ll n,m,a,b;\n        cin >> n >> m >> a >> b;\n      \
    \  cout << floor_sum(a,b,m,n-1) << \"\\n\";\n    }\n}"
  dependsOn:
  - template.hpp
  - number-theory/floor-sum.hpp
  isVerificationFile: true
  path: verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 17:32:38+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp
- /verify/verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp.html
title: verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp
---
