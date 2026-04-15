---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/manacher.hpp
    title: string/manacher.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/yosupo/string/enumerate_palindromes.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n#define\
    \ RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
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
    \ 2 \"string/manacher.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n\
    \ * Description: Manacher's Algorithm. pal[i] := the length of the longest palindrome\
    \ centered at i/2.\n */\n\ntemplate<class STR>\nvector<int> manacher(const STR\
    \ &s){\n    int n=(int)s.size();\n    if(n==0)return {};\n    vector<int> pal(2*n-1);\n\
    \    for(int p=0,l=-1,r=-1;p<2*n-1;p++){\n        int i=(p+1)>>1,j=p>>1;\n   \
    \     int k=(i>=r?0:min(r-i,pal[2*(l+r)-p]));\n        while(j+k+1<n&&i-k-1>=0&&s[j+k+1]==s[i-k-1])k++;\n\
    \        pal[p]=k;\n        if(j+k>r)l=i-k,r=j+k;\n    }\n    for(int i=0;i<2*n-1;i++)pal[i]=pal[i]<<1|(i&1^1);\n\
    \    return pal;\n}\n\n#line 4 \"verify/yosupo/string/enumerate_palindromes.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin >> s;\n    for(auto x:manacher(s))cout\
    \ << x << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"template.hpp\"\n#include \"string/manacher.hpp\"\n\nint main(){\n\
    \    string s;\n    cin >> s;\n    for(auto x:manacher(s))cout << x << \" \";\n\
    }"
  dependsOn:
  - template.hpp
  - string/manacher.hpp
  isVerificationFile: true
  path: verify/yosupo/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 22:12:04+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/string/enumerate_palindromes.test.cpp
- /verify/verify/yosupo/string/enumerate_palindromes.test.cpp.html
title: verify/yosupo/string/enumerate_palindromes.test.cpp
---
