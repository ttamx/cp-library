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
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-10-31\n * Description:\
    \ Combinatorics.\n */\n\ntemplate<class mint>\nstruct Combinatorics{\n    int\
    \ n,mod;\n    vector<mint> _inv,_fac,_ifac;\n    Combinatorics():n(1),mod(mint::get_mod()),_inv({1,1}),_fac({1,1}),_ifac({1,1}){}\n\
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
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: modular-arithmetic/combinatorics.hpp
  requiredBy: []
  timestamp: '2024-10-31 23:18:18+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modular-arithmetic/combinatorics.hpp
layout: document
redirect_from:
- /library/modular-arithmetic/combinatorics.hpp
- /library/modular-arithmetic/combinatorics.hpp.html
title: modular-arithmetic/combinatorics.hpp
---
