---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/z-algorithm.hpp
    title: string/z-algorithm.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/yosupo/string/z-algorithm/zalgorithm.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#line 2 \"template.hpp\"\
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
    }\n#line 2 \"string/z-algorithm.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n\
    \ * Description: Z Algorithm. z[i] := the length of the longest common prefix\
    \ between s and s[i:].\n */\n\ntemplate<class STR>\nvector<int> z_algorithm(const\
    \ STR &s){\n    int n=(int)s.size();\n    vector<int> z(n);\n    z[0]=n;\n   \
    \ for(int i=1,l=0,r=1;i<n;i++){\n        if(i<r)z[i]=min(r-i,z[i-l]);\n      \
    \  while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;\n        if(i+z[i]>r)l=i,r=i+z[i];\n\
    \    }\n    return z;\n}\n\n#line 4 \"verify/yosupo/string/z-algorithm/zalgorithm.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin >> s;\n    for(auto x:z_algorithm(s))cout\
    \ << x << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"template.hpp\"\n#include \"string/z-algorithm.hpp\"\n\nint main(){\n    string\
    \ s;\n    cin >> s;\n    for(auto x:z_algorithm(s))cout << x << \" \";\n}"
  dependsOn:
  - template.hpp
  - string/z-algorithm.hpp
  isVerificationFile: true
  path: verify/yosupo/string/z-algorithm/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 14:43:57+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/string/z-algorithm/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/string/z-algorithm/zalgorithm.test.cpp
- /verify/verify/yosupo/string/z-algorithm/zalgorithm.test.cpp.html
title: verify/yosupo/string/z-algorithm/zalgorithm.test.cpp
---
