---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: group/monoid-action/add-count-add.hpp
    title: group/monoid-action/add-count-add.hpp
  - icon: ':question:'
    path: group/monoid-action/add-count-affine.hpp
    title: group/monoid-action/add-count-affine.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/add-count.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-04-14\n * Description: Add & Count Monoid class.\n */\n\ntemplate<class\
    \ T>\nstruct AddCountMonoid{\n    using P = pair<T,ll>;\n    using value_type\
    \ = P;\n    static constexpr P op(const P &x,const P &y){\n        return P(x.first+y.first,x.second+y.second);\n\
    \    }\n    static constexpr P inverse(const P &x){return P(-x.first,-x.second);}\n\
    \    static constexpr P unit(){return P(T(0),0LL);}\n    static constexpr P make(const\
    \ T &x){return P(x,1LL);}\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Add & Count Monoid class.\n */\n\ntemplate<class T>\nstruct AddCountMonoid{\n\
    \    using P = pair<T,ll>;\n    using value_type = P;\n    static constexpr P\
    \ op(const P &x,const P &y){\n        return P(x.first+y.first,x.second+y.second);\n\
    \    }\n    static constexpr P inverse(const P &x){return P(-x.first,-x.second);}\n\
    \    static constexpr P unit(){return P(T(0),0LL);}\n    static constexpr P make(const\
    \ T &x){return P(x,1LL);}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/add-count.hpp
  requiredBy:
  - group/monoid-action/add-count-add.hpp
  - group/monoid-action/add-count-affine.hpp
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  - verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo/data-structure/range_affine_range_sum.test.cpp
documentation_of: group/monoid/add-count.hpp
layout: document
redirect_from:
- /library/group/monoid/add-count.hpp
- /library/group/monoid/add-count.hpp.html
title: group/monoid/add-count.hpp
---
