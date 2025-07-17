---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/string/zalgorithm.test.cpp
    title: verify/yosupo/string/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z-algorithm.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-06-14\n * Description: Z Algorithm. z[i] := the length of the longest\
    \ common prefix between s and s[i:].\n */\n\ntemplate<class STR>\nvector<int>\
    \ z_algorithm(const STR &s){\n    int n=(int)s.size();\n    vector<int> z(n);\n\
    \    z[0]=n;\n    for(int i=1,l=0,r=1;i<n;i++){\n        if(i<r)z[i]=min(r-i,z[i-l]);\n\
    \        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;\n        if(i+z[i]>r)l=i,r=i+z[i];\n\
    \    }\n    return z;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description:\
    \ Z Algorithm. z[i] := the length of the longest common prefix between s and s[i:].\n\
    \ */\n\ntemplate<class STR>\nvector<int> z_algorithm(const STR &s){\n    int n=(int)s.size();\n\
    \    vector<int> z(n);\n    z[0]=n;\n    for(int i=1,l=0,r=1;i<n;i++){\n     \
    \   if(i<r)z[i]=min(r-i,z[i-l]);\n        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;\n\
    \        if(i+z[i]>r)l=i,r=i+z[i];\n    }\n    return z;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z-algorithm.hpp
  requiredBy: []
  timestamp: '2024-06-15 00:08:38+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/string/zalgorithm.test.cpp
documentation_of: string/z-algorithm.hpp
layout: document
redirect_from:
- /library/string/z-algorithm.hpp
- /library/string/z-algorithm.hpp.html
title: string/z-algorithm.hpp
---
