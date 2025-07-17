---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: group/monoid/add-count.hpp
    title: group/monoid/add-count.hpp
  - icon: ':question:'
    path: group/monoid/affine.hpp
    title: group/monoid/affine.hpp
  _extendedRequiredBy: []
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
  bundledCode: "#line 2 \"group/monoid/affine.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-04-14\n * Description: Affine Transfomation Monoid class.\n */\n\
    \ntemplate<class T>\nstruct AffineMonoid{\n    using P = pair<T,T>;\n    using\
    \ value_type = P;\n    static constexpr P op(const P &x,const P &y){\n       \
    \ return P(x.first*y.first,x.second*y.first+y.second);\n    }\n    static constexpr\
    \ P unit(){return P(T(1),T(0));}\n    static constexpr T eval(const P &f,const\
    \ T &x){\n        return f.first*x+f.second;\n    }\n};\n\n#line 2 \"group/monoid/add-count.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add & Count\
    \ Monoid class.\n */\n\ntemplate<class T>\nstruct AddCountMonoid{\n    using P\
    \ = pair<T,ll>;\n    using value_type = P;\n    static constexpr P op(const P\
    \ &x,const P &y){\n        return P(x.first+y.first,x.second+y.second);\n    }\n\
    \    static constexpr P inverse(const P &x){return P(-x.first,-x.second);}\n \
    \   static constexpr P unit(){return P(T(0),0LL);}\n    static constexpr P make(const\
    \ T &x){return P(x,1LL);}\n};\n\n#line 4 \"group/monoid-action/add-count-affine.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Affine to\
    \ Add & Count Action class.\n */\n\ntemplate<class T>\nstruct AddCountAffineAction{\n\
    \    using InfoMonoid = AddCountMonoid<T>;\n    using TagMonoid = AffineMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return Info(a.first*b.first+a.second*b.second,a.second);\n\
    \    }\n};\n\n"
  code: "#pragma once\n#include \"group/monoid/affine.hpp\"\n#include \"group/monoid/add-count.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Affine to\
    \ Add & Count Action class.\n */\n\ntemplate<class T>\nstruct AddCountAffineAction{\n\
    \    using InfoMonoid = AddCountMonoid<T>;\n    using TagMonoid = AffineMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return Info(a.first*b.first+a.second*b.second,a.second);\n\
    \    }\n};\n\n"
  dependsOn:
  - group/monoid/affine.hpp
  - group/monoid/add-count.hpp
  isVerificationFile: false
  path: group/monoid-action/add-count-affine.hpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  - verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo/data-structure/range_affine_range_sum.test.cpp
documentation_of: group/monoid-action/add-count-affine.hpp
layout: document
redirect_from:
- /library/group/monoid-action/add-count-affine.hpp
- /library/group/monoid-action/add-count-affine.hpp.html
title: group/monoid-action/add-count-affine.hpp
---
