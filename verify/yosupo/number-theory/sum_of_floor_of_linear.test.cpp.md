---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number-theory/floor-sum.hpp
    title: number-theory/floor-sum.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\
    #line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\nusing\
    \ vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst\
    \ int MOD=998244353;\nconst int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    template<class T>\nusing ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"number-theory/floor-sum.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-09-21\n * Description: Floor sum\
    \ function.\n *  $f(a, b, c, n) = \\sum_{x=0}^n \\lfloor \\frac{ax+b}{c} \\rfloor$\n\
    \ *  becareful when a,b,c are negetive (use custom floor division and mod instead)\n\
    \ * Time: $O(\\log a)$\n */\n\nll floor_sum(ll a,ll b,ll c,ll n){\n    ll res=n*(n+1)/2*(a/c)+(n+1)*(b/c);\n\
    \    a%=c,b%=c;\n    if(a==0)return res;\n    ll m=(a*n+b)/c;\n    return res+n*m-floor_sum(c,c-b-1,a,m-1);\n\
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
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp
- /verify/verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp.html
title: verify/yosupo/number-theory/sum_of_floor_of_linear.test.cpp
---
