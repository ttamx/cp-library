---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: group/monoid-action/add-count-affine.hpp
    title: group/monoid-action/add-count-affine.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_range_composite.test.cpp
    title: verify/yosupo/data-structure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
    title: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/affine.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-04-14\n * Description: Affine Transfomation Monoid class.\n */\n\
    \ntemplate<class T>\nstruct AffineMonoid{\n    using P = pair<T,T>;\n    using\
    \ value_type = P;\n    static constexpr P op(const P &x,const P &y){\n       \
    \ return P(x.first*y.first,x.second*y.first+y.second);\n    }\n    static constexpr\
    \ P unit(){return P(T(1),T(0));}\n    static constexpr T eval(const P &f,const\
    \ T &x){\n        return f.first*x+f.second;\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Affine Transfomation Monoid class.\n */\n\ntemplate<class T>\nstruct AffineMonoid{\n\
    \    using P = pair<T,T>;\n    using value_type = P;\n    static constexpr P op(const\
    \ P &x,const P &y){\n        return P(x.first*y.first,x.second*y.first+y.second);\n\
    \    }\n    static constexpr P unit(){return P(T(1),T(0));}\n    static constexpr\
    \ T eval(const P &f,const T &x){\n        return f.first*x+f.second;\n    }\n\
    };\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/affine.hpp
  requiredBy:
  - group/monoid-action/add-count-affine.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  - verify/yosupo/data-structure/point_set_range_composite.test.cpp
  - verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  - verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo/data-structure/range_affine_range_sum.test.cpp
documentation_of: group/monoid/affine.hpp
layout: document
redirect_from:
- /library/group/monoid/affine.hpp
- /library/group/monoid/affine.hpp.html
title: group/monoid/affine.hpp
---
