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
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing db = long double;\nusing\
    \ vi = vector<int>;\nusing vl = vector<ll>;\nusing vd = vector<db>;\nusing pii\
    \ = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst\
    \ int INF=INT_MAX/2;\nconst int MOD=998244353;\nconst int MOD2=1000000007;\nconst\
    \ ll LINF=LLONG_MAX/2;\nconst db DINF=numeric_limits<db>::infinity();\nconst db\
    \ EPS=1e-9;\nconst db PI=acos(db(-1));\n\n#line 2 \"string/z-algorithm.hpp\"\n\
    \n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description: Z Algorithm.\
    \ z[i] := the length of the longest common prefix between s and s[i:].\n */\n\n\
    template<class STR>\nvector<int> z_algorithm(const STR &s){\n    int n=(int)s.size();\n\
    \    vector<int> z(n);\n    z[0]=n;\n    for(int i=1,l=0,r=1;i<n;i++){\n     \
    \   if(i<r)z[i]=min(r-i,z[i-l]);\n        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;\n\
    \        if(i+z[i]>r)l=i,r=i+z[i];\n    }\n    return z;\n}\n\n#line 4 \"verify/yosupo/string/zalgorithm.test.cpp\"\
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
  timestamp: '2024-06-15 00:08:38+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/string/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/string/zalgorithm.test.cpp
- /verify/verify/yosupo/string/zalgorithm.test.cpp.html
title: verify/yosupo/string/zalgorithm.test.cpp
---