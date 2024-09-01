---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: group/monoid-action/min-add.hpp
    title: group/monoid-action/min-add.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix-array.hpp
    title: string/suffix-array.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/staticrmq.test.cpp
    title: verify/yosupo/data-structure/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/string/number_of_substrings2.test.cpp
    title: verify/yosupo/string/number_of_substrings2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/string/suffixarray.test.cpp
    title: verify/yosupo/string/suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/min.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-14\n * Description: Min Monoid class.\n */\n\ntemplate<class T>\n\
    struct MinMonoid{\n    using value_type = T;\n    static constexpr T op(const\
    \ T &x,const T &y){return min(x,y);}\n    static constexpr T unit(){return numeric_limits<T>::max();}\n\
    };\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Min Monoid class.\n */\n\ntemplate<class T>\nstruct MinMonoid{\n    using value_type\
    \ = T;\n    static constexpr T op(const T &x,const T &y){return min(x,y);}\n \
    \   static constexpr T unit(){return numeric_limits<T>::max();}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/min.hpp
  requiredBy:
  - string/suffix-array.hpp
  - group/monoid-action/min-add.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/string/number_of_substrings2.test.cpp
  - verify/yosupo/string/suffixarray.test.cpp
  - verify/yosupo/data-structure/staticrmq.test.cpp
documentation_of: group/monoid/min.hpp
layout: document
redirect_from:
- /library/group/monoid/min.hpp
- /library/group/monoid/min.hpp.html
title: group/monoid/min.hpp
---
