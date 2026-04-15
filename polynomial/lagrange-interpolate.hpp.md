---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/lagrange-interpolate.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Lagrange interpolation. Given f(0)...f(n) return\
    \ a polynomial with degree n.\n * Time: $O(N)$\n */\n\ntemplate<class mint>\n\
    mint lagrange_interpolate(vector<mint> &f,mint c){\n    int n=f.size();\n    if(c.val()<n)return\
    \ f[c.val()];\n    vector<mint> l(n+1),r(n+1);\n    l[0]=r[n]=1;\n    for(int\
    \ i=0;i<n;i++)l[i+1]=l[i]*(c-i);\n    for(int i=n-1;i>=0;i--)r[i]=r[i+1]*(c-i);\n\
    \    mint ans=0;\n    for(int i=0;i<n;i++){\n        mint cur=f[i]*comb.ifac(i)*comb.ifac(n-i-1);\n\
    \        if((n-i-1)&1)cur*=-1;\n        ans+=cur*l[i]*r[i+1];\n    }\n    return\
    \ ans;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Lagrange interpolation.\
    \ Given f(0)...f(n) return a polynomial with degree n.\n * Time: $O(N)$\n */\n\
    \ntemplate<class mint>\nmint lagrange_interpolate(vector<mint> &f,mint c){\n \
    \   int n=f.size();\n    if(c.val()<n)return f[c.val()];\n    vector<mint> l(n+1),r(n+1);\n\
    \    l[0]=r[n]=1;\n    for(int i=0;i<n;i++)l[i+1]=l[i]*(c-i);\n    for(int i=n-1;i>=0;i--)r[i]=r[i+1]*(c-i);\n\
    \    mint ans=0;\n    for(int i=0;i<n;i++){\n        mint cur=f[i]*comb.ifac(i)*comb.ifac(n-i-1);\n\
    \        if((n-i-1)&1)cur*=-1;\n        ans+=cur*l[i]*r[i+1];\n    }\n    return\
    \ ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/lagrange-interpolate.hpp
  requiredBy: []
  timestamp: '2026-04-04 10:38:14+05:30'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: polynomial/lagrange-interpolate.hpp
layout: document
redirect_from:
- /library/polynomial/lagrange-interpolate.hpp
- /library/polynomial/lagrange-interpolate.hpp.html
title: polynomial/lagrange-interpolate.hpp
---
