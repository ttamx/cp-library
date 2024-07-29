---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/bitwise_and_convolution.test.cpp
    title: verify/yosupo/convolution/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/and-convolution.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-07-29\n * Description: Bitwise AND Convolution.\n * Superset\
    \ Zeta Transform: $A^\\prime[S]=\\sum_{T\\supseteq S}A[T]$.\n * Superset Mobius\
    \ Transform: $A[T]=\\sum_{S\\supseteq T}(-1)^{|S-T|}A^\\prime[S]$.\n * Time: $O(N\\\
    log N)$.\n */\n\ntemplate<class T>\nvoid superset_zeta(vector<T> &a){\n    int\
    \ n=(int)a.size();\n    assert(n==(n&-n));\n    for(int i=1;i<n;i<<=1){\n    \
    \    for(int j=0;j<n;j++){\n            if(j&i){\n                a[j^i]+=a[j];\n\
    \            }\n        }\n    }\n}\n\ntemplate<class T>\nvoid superset_mobius(vector<T>\
    \ &a){\n    int n=(int)a.size();\n    assert(n==(n&-n));\n    for(int i=n;i>>=1;){\n\
    \        for(int j=0;j<n;j++){\n            if(j&i){\n                a[j^i]-=a[j];\n\
    \            }\n        }\n    }\n}\n\ntemplate<class T>\nvector<T> and_convolution(vector<T>\
    \ a,vector<T> b){\n    superset_zeta(a);\n    superset_zeta(b);\n    for(int i=0;i<(int)a.size();i++)a[i]*=b[i];\n\
    \    superset_mobius(a);\n    return a;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ Bitwise AND Convolution.\n * Superset Zeta Transform: $A^\\prime[S]=\\sum_{T\\\
    supseteq S}A[T]$.\n * Superset Mobius Transform: $A[T]=\\sum_{S\\supseteq T}(-1)^{|S-T|}A^\\\
    prime[S]$.\n * Time: $O(N\\log N)$.\n */\n\ntemplate<class T>\nvoid superset_zeta(vector<T>\
    \ &a){\n    int n=(int)a.size();\n    assert(n==(n&-n));\n    for(int i=1;i<n;i<<=1){\n\
    \        for(int j=0;j<n;j++){\n            if(j&i){\n                a[j^i]+=a[j];\n\
    \            }\n        }\n    }\n}\n\ntemplate<class T>\nvoid superset_mobius(vector<T>\
    \ &a){\n    int n=(int)a.size();\n    assert(n==(n&-n));\n    for(int i=n;i>>=1;){\n\
    \        for(int j=0;j<n;j++){\n            if(j&i){\n                a[j^i]-=a[j];\n\
    \            }\n        }\n    }\n}\n\ntemplate<class T>\nvector<T> and_convolution(vector<T>\
    \ a,vector<T> b){\n    superset_zeta(a);\n    superset_zeta(b);\n    for(int i=0;i<(int)a.size();i++)a[i]*=b[i];\n\
    \    superset_mobius(a);\n    return a;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/and-convolution.hpp
  requiredBy: []
  timestamp: '2024-07-30 03:30:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/convolution/bitwise_and_convolution.test.cpp
documentation_of: convolution/and-convolution.hpp
layout: document
redirect_from:
- /library/convolution/and-convolution.hpp
- /library/convolution/and-convolution.hpp.html
title: convolution/and-convolution.hpp
---
