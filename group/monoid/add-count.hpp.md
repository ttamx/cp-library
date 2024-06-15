---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: group/monoid-action/add-count-add.hpp
    title: group/monoid-action/add-count-add.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid-action/add-count-affine.hpp
    title: group/monoid-action/add-count-affine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/add-count.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-04-14\n * Description: Add & Count Monoid class.\n */\n\ntemplate<class\
    \ T>\nstruct AddCountMonoid{\n    using P = pair<T,int>;\n    using value_type\
    \ = P;\n    static constexpr P op(const P &x,const P &y){\n        return P(x.first+y.first,x.second+y.second);\n\
    \    }\n    static constexpr P inverse(const P &x){return P(-x.first,-x.second);}\n\
    \    static constexpr P unit(){return P(T(0),0);}\n    static constexpr P make(const\
    \ T &x){return P(x,1);}\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Add & Count Monoid class.\n */\n\ntemplate<class T>\nstruct AddCountMonoid{\n\
    \    using P = pair<T,int>;\n    using value_type = P;\n    static constexpr P\
    \ op(const P &x,const P &y){\n        return P(x.first+y.first,x.second+y.second);\n\
    \    }\n    static constexpr P inverse(const P &x){return P(-x.first,-x.second);}\n\
    \    static constexpr P unit(){return P(T(0),0);}\n    static constexpr P make(const\
    \ T &x){return P(x,1);}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/add-count.hpp
  requiredBy:
  - group/monoid-action/add-count-affine.hpp
  - group/monoid-action/add-count-add.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo/data-structure/range_affine_range_sum.test.cpp
documentation_of: group/monoid/add-count.hpp
layout: document
redirect_from:
- /library/group/monoid/add-count.hpp
- /library/group/monoid/add-count.hpp.html
title: group/monoid/add-count.hpp
---