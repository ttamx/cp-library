---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: group/monoid-action/add-count-add.hpp
    title: group/monoid-action/add-count-add.hpp
  - icon: ':warning:'
    path: group/monoid-action/max-add.hpp
    title: group/monoid-action/max-add.hpp
  - icon: ':warning:'
    path: group/monoid-action/max-count-add.hpp
    title: group/monoid-action/max-count-add.hpp
  - icon: ':warning:'
    path: group/monoid-action/max-idx-add.hpp
    title: group/monoid-action/max-idx-add.hpp
  - icon: ':warning:'
    path: group/monoid-action/min-add.hpp
    title: group/monoid-action/min-add.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid-action/min-count-add.hpp
    title: group/monoid-action/min-count-add.hpp
  - icon: ':warning:'
    path: group/monoid-action/min-idx-add.hpp
    title: group/monoid-action/min-idx-add.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
    title: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_reverse_range_sum.test.cpp
    title: verify/yosupo/data-structure/range_reverse_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/add.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-14\n * Description: Add Monoid class.\n */\n\ntemplate<class T>\n\
    struct AddMonoid{\n    using value_type = T;\n    static constexpr T op(const\
    \ T &x,const T &y){return x+y;}\n    static constexpr T inverse(const T &x){return\
    \ -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Add Monoid class.\n */\n\ntemplate<class T>\nstruct AddMonoid{\n    using value_type\
    \ = T;\n    static constexpr T op(const T &x,const T &y){return x+y;}\n    static\
    \ constexpr T inverse(const T &x){return -x;}\n    static constexpr T unit(){return\
    \ T(0);}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/add.hpp
  requiredBy:
  - group/monoid-action/max-idx-add.hpp
  - group/monoid-action/min-count-add.hpp
  - group/monoid-action/add-count-add.hpp
  - group/monoid-action/max-count-add.hpp
  - group/monoid-action/min-idx-add.hpp
  - group/monoid-action/max-add.hpp
  - group/monoid-action/min-add.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/range_reverse_range_sum.test.cpp
  - verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
documentation_of: group/monoid/add.hpp
layout: document
redirect_from:
- /library/group/monoid/add.hpp
- /library/group/monoid/add.hpp.html
title: group/monoid/add.hpp
---
