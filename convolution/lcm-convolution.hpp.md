---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/lcm_convolution.test.cpp
    title: verify/yosupo/convolution/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/lcm-convolution.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-07-29\n * Description: LCM Convolution.\n * Divisor Zeta Transform:\
    \ $A^\\prime[n]=\\sum_{d|n}A[d]$.\n * Divisor Mobius Transform: $A[n]=\\sum_{d|n}\\\
    mu(n/d)A^\\prime[d]$.\n * Time: $O(N\\log\\log N)$.\n */\n\ntemplate<class T>\n\
    void divisor_zeta(vector<T> &a){\n    int n=(int)a.size();\n    vector<bool> is_prime(n,true);\n\
    \    for(int p=2;p<n;p++){\n        if(!is_prime[p])continue;\n        for(int\
    \ i=1;i*p<n;i++){\n            is_prime[i*p]=false;\n            a[i*p]+=a[i];\n\
    \        }\n    }\n}\n\ntemplate<class T>\nvoid divisor_mobius(vector<T> &a){\n\
    \    int n=(int)a.size();\n    vector<bool> is_prime(n,true);\n    for(int p=2;p<n;p++){\n\
    \        if(!is_prime[p])continue;\n        for(int i=(n-1)/p;i>=1;i--){\n   \
    \         is_prime[i*p]=false;\n            a[i*p]-=a[i];\n        }\n    }\n\
    }\n\ntemplate<class T>\nvector<T> lcm_convolution(vector<T> a,vector<T> b){\n\
    \    divisor_zeta(a);\n    divisor_zeta(b);\n    for(int i=0;i<(int)a.size();i++)a[i]*=b[i];\n\
    \    divisor_mobius(a);\n    return a;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ LCM Convolution.\n * Divisor Zeta Transform: $A^\\prime[n]=\\sum_{d|n}A[d]$.\n\
    \ * Divisor Mobius Transform: $A[n]=\\sum_{d|n}\\mu(n/d)A^\\prime[d]$.\n * Time:\
    \ $O(N\\log\\log N)$.\n */\n\ntemplate<class T>\nvoid divisor_zeta(vector<T> &a){\n\
    \    int n=(int)a.size();\n    vector<bool> is_prime(n,true);\n    for(int p=2;p<n;p++){\n\
    \        if(!is_prime[p])continue;\n        for(int i=1;i*p<n;i++){\n        \
    \    is_prime[i*p]=false;\n            a[i*p]+=a[i];\n        }\n    }\n}\n\n\
    template<class T>\nvoid divisor_mobius(vector<T> &a){\n    int n=(int)a.size();\n\
    \    vector<bool> is_prime(n,true);\n    for(int p=2;p<n;p++){\n        if(!is_prime[p])continue;\n\
    \        for(int i=(n-1)/p;i>=1;i--){\n            is_prime[i*p]=false;\n    \
    \        a[i*p]-=a[i];\n        }\n    }\n}\n\ntemplate<class T>\nvector<T> lcm_convolution(vector<T>\
    \ a,vector<T> b){\n    divisor_zeta(a);\n    divisor_zeta(b);\n    for(int i=0;i<(int)a.size();i++)a[i]*=b[i];\n\
    \    divisor_mobius(a);\n    return a;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/lcm-convolution.hpp
  requiredBy: []
  timestamp: '2024-07-30 03:30:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/convolution/lcm_convolution.test.cpp
documentation_of: convolution/lcm-convolution.hpp
layout: document
redirect_from:
- /library/convolution/lcm-convolution.hpp
- /library/convolution/lcm-convolution.hpp.html
title: convolution/lcm-convolution.hpp
---
