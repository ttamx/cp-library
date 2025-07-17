---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: group/monoid-action/min-count-add.hpp
    title: group/monoid-action/min-count-add.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
    title: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/min-count.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-04-14\n * Description: Min & Count Monoid class.\n */\n\ntemplate<class\
    \ T>\nstruct MinCountMonoid{\n    using P = pair<T,int>;\n    using value_type\
    \ = P;\n    static constexpr P op(const P &x,const P &y){\n        if(x.first<y.first)return\
    \ x;\n        if(y.first<x.first)return y;\n        return P(x.first,x.second+y.second);\n\
    \    }\n    static constexpr P unit(){return P(numeric_limits<T>::max(),0);}\n\
    \    static constexpr P make(const T &x){return P(x,1);}\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Min & Count Monoid class.\n */\n\ntemplate<class T>\nstruct MinCountMonoid{\n\
    \    using P = pair<T,int>;\n    using value_type = P;\n    static constexpr P\
    \ op(const P &x,const P &y){\n        if(x.first<y.first)return x;\n        if(y.first<x.first)return\
    \ y;\n        return P(x.first,x.second+y.second);\n    }\n    static constexpr\
    \ P unit(){return P(numeric_limits<T>::max(),0);}\n    static constexpr P make(const\
    \ T &x){return P(x,1);}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/min-count.hpp
  requiredBy:
  - group/monoid-action/min-count-add.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
documentation_of: group/monoid/min-count.hpp
layout: document
redirect_from:
- /library/group/monoid/min-count.hpp
- /library/group/monoid/min-count.hpp.html
title: group/monoid/min-count.hpp
---
