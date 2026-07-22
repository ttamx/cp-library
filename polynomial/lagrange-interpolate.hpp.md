---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: modular-arithmetic/combinatorics.hpp
    title: modular-arithmetic/combinatorics.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modular-arithmetic/combinatorics.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-10-31\n * Description: Combinatorics.\n */\n\ntemplate<class\
    \ mint>\nstruct Combinatorics{\n    int n,mod;\n    vector<mint> _inv,_fac,_ifac;\n\
    \    Combinatorics():n(1),mod(mint::get_mod()),_inv({1,1}),_fac({1,1}),_ifac({1,1}){}\n\
    \    void init(int m){\n        if(n>=m)return;\n        _inv.resize(m+1);\n \
    \       _fac.resize(m+1);\n        _ifac.resize(m+1);\n        for(int i=n+1;i<=m;i++){\n\
    \            _inv[i]=_inv[mod%i]*(mod-mod/i);\n            _fac[i]=_fac[i-1]*i;\n\
    \            _ifac[i]=_ifac[i-1]*_inv[i];\n        }\n        n=m;\n    }\n  \
    \  mint inv(int x){\n        init(x);\n        return _inv[x];\n    }\n    mint\
    \ fac(int x){\n        init(x);\n        return _fac[x];\n    }\n    mint ifac(int\
    \ x){\n        init(x);\n        return _ifac[x];\n    }\n    mint C(int n,int\
    \ r){\n        if(n<r||n<0||r<0)return mint(0);\n        init(n);\n        return\
    \ _fac[n]*_ifac[r]*_ifac[n-r];\n    }\n    mint P(int n,int r){\n        if(n<r||n<0||r<0)return\
    \ mint(0);\n        init(n);\n        return _fac[n]*_ifac[n-r];\n    }\n    mint\
    \ H(int n,int r){\n        if(n==0&&r==0)return mint(1);\n        return C(n+r-1,n);\n\
    \    }\n};\n#line 3 \"polynomial/lagrange-interpolate.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Lagrange interpolation. Given f(0)...f(n) return\
    \ a polynomial with degree n.\n * Time: $O(N)$\n */\n\ntemplate<class mint>\n\
    mint lagrange_interpolate(vector<mint> &f,mint c){\n    static Combinatorics<mint>\
    \ comb;\n    int n=f.size();\n    if(c.val()<n)return f[c.val()];\n    vector<mint>\
    \ l(n+1),r(n+1);\n    l[0]=r[n]=1;\n    for(int i=0;i<n;i++)l[i+1]=l[i]*(c-i);\n\
    \    for(int i=n-1;i>=0;i--)r[i]=r[i+1]*(c-i);\n    mint ans=0;\n    for(int i=0;i<n;i++){\n\
    \        mint cur=f[i]*comb.ifac(i)*comb.ifac(n-i-1);\n        if((n-i-1)&1)cur*=-1;\n\
    \        ans+=cur*l[i]*r[i+1];\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include \"modular-arithmetic/combinatorics.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Description: Lagrange interpolation. Given f(0)...f(n)\
    \ return a polynomial with degree n.\n * Time: $O(N)$\n */\n\ntemplate<class mint>\n\
    mint lagrange_interpolate(vector<mint> &f,mint c){\n    static Combinatorics<mint>\
    \ comb;\n    int n=f.size();\n    if(c.val()<n)return f[c.val()];\n    vector<mint>\
    \ l(n+1),r(n+1);\n    l[0]=r[n]=1;\n    for(int i=0;i<n;i++)l[i+1]=l[i]*(c-i);\n\
    \    for(int i=n-1;i>=0;i--)r[i]=r[i+1]*(c-i);\n    mint ans=0;\n    for(int i=0;i<n;i++){\n\
    \        mint cur=f[i]*comb.ifac(i)*comb.ifac(n-i-1);\n        if((n-i-1)&1)cur*=-1;\n\
    \        ans+=cur*l[i]*r[i+1];\n    }\n    return ans;\n}\n"
  dependsOn:
  - modular-arithmetic/combinatorics.hpp
  isVerificationFile: false
  path: polynomial/lagrange-interpolate.hpp
  requiredBy: []
  timestamp: '2026-07-22 11:58:01+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: polynomial/lagrange-interpolate.hpp
layout: document
redirect_from:
- /library/polynomial/lagrange-interpolate.hpp
- /library/polynomial/lagrange-interpolate.hpp.html
title: polynomial/lagrange-interpolate.hpp
---
