---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
    title: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/monoid-reverse.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-06-16\n * Description: Monoid Reverse class.\n */\n\ntemplate<class\
    \ Monoid>\nstruct MonoidReverse{\n    using value_type = typename Monoid::value_type;\n\
    \    static constexpr value_type op(const value_type &x,const value_type &y){return\
    \ Monoid::op(y,x);}\n    static constexpr value_type unit(){return Monoid::unit();}\n\
    };\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-16\n * Description:\
    \ Monoid Reverse class.\n */\n\ntemplate<class Monoid>\nstruct MonoidReverse{\n\
    \    using value_type = typename Monoid::value_type;\n    static constexpr value_type\
    \ op(const value_type &x,const value_type &y){return Monoid::op(y,x);}\n    static\
    \ constexpr value_type unit(){return Monoid::unit();}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/monoid-reverse.hpp
  requiredBy: []
  timestamp: '2024-06-16 02:15:01+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
documentation_of: group/monoid/monoid-reverse.hpp
layout: document
redirect_from:
- /library/group/monoid/monoid-reverse.hpp
- /library/group/monoid/monoid-reverse.hpp.html
title: group/monoid/monoid-reverse.hpp
---
