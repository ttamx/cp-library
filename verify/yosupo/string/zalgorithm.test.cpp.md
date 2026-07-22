---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z-algorithm.hpp
    title: string/z-algorithm.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/yosupo/string/zalgorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\n\
    #define ALL(a) a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n#define\
    \ SORT(a) sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
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
    \ 2 \"string/z-algorithm.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n\
    \ * Description: Z Algorithm. z[i] := the length of the longest common prefix\
    \ between s and s[i:].\n */\n\ntemplate<class STR>\nvector<int> z_algorithm(const\
    \ STR &s){\n    int n=(int)s.size();\n    vector<int> z(n);\n    z[0]=n;\n   \
    \ for(int i=1,l=0,r=1;i<n;i++){\n        if(i<r)z[i]=min(r-i,z[i-l]);\n      \
    \  while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;\n        if(i+z[i]>r)l=i,r=i+z[i];\n\
    \    }\n    return z;\n}\n\n#line 4 \"verify/yosupo/string/zalgorithm.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin >> s;\n    for(auto x:z_algorithm(s))cout\
    \ << x << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"template.hpp\"\n#include \"string/z-algorithm.hpp\"\n\nint main(){\n    string\
    \ s;\n    cin >> s;\n    for(auto x:z_algorithm(s))cout << x << \" \";\n}"
  dependsOn:
  - template.hpp
  - string/z-algorithm.hpp
  isVerificationFile: true
  path: verify/yosupo/string/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 22:12:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/string/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/string/zalgorithm.test.cpp
- /verify/verify/yosupo/string/zalgorithm.test.cpp.html
title: verify/yosupo/string/zalgorithm.test.cpp
---
