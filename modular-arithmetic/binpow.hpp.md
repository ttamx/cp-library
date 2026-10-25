---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: polynomial/formal-power-series.hpp
    title: polynomial/formal-power-series.hpp
  - icon: ':x:'
    path: polynomial/ntt.hpp
    title: polynomial/ntt.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/polynomial/formal-power-series/exp_of_formal_power_series.test.cpp
    title: verify/yosupo/polynomial/formal-power-series/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/polynomial/formal-power-series/inv_of_formal_power_series.test.cpp
    title: verify/yosupo/polynomial/formal-power-series/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/polynomial/formal-power-series/log_of_formal_power_series.test.cpp
    title: verify/yosupo/polynomial/formal-power-series/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/polynomial/formal-power-series/pow_of_formal_power_series.test.cpp
    title: verify/yosupo/polynomial/formal-power-series/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/polynomial/ntt/convolution_mod.test.cpp
    title: verify/yosupo/polynomial/ntt/convolution_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modular-arithmetic/binpow.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-01-15\n * Description: n-th power using divide and conquer\n\
    \ * Time: $O(\\log b)$\n */\n\ntemplate<class T>\nconstexpr T binpow(T a,ll b){\n\
    \    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n    return res;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description:\
    \ n-th power using divide and conquer\n * Time: $O(\\log b)$\n */\n\ntemplate<class\
    \ T>\nconstexpr T binpow(T a,ll b){\n    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n\
    \    return res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: modular-arithmetic/binpow.hpp
  requiredBy:
  - polynomial/ntt.hpp
  - polynomial/formal-power-series.hpp
  timestamp: '2026-04-04 10:38:14+05:30'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/polynomial/ntt/convolution_mod.test.cpp
  - verify/yosupo/polynomial/formal-power-series/inv_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/formal-power-series/log_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/formal-power-series/pow_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/formal-power-series/exp_of_formal_power_series.test.cpp
documentation_of: modular-arithmetic/binpow.hpp
layout: document
redirect_from:
- /library/modular-arithmetic/binpow.hpp
- /library/modular-arithmetic/binpow.hpp.html
title: modular-arithmetic/binpow.hpp
---
