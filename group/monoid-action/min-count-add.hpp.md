---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/min-count.hpp
    title: group/monoid/min-count.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
    title: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/add.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-14\n * Description: Add Monoid class.\n */\n\ntemplate<class T>\n\
    struct AddMonoid{\n    using value_type = T;\n    static constexpr T op(const\
    \ T &x,const T &y){return x+y;}\n    static constexpr T inverse(const T &x){return\
    \ -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n#line 2 \"group/monoid/min-count.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Min & Count\
    \ Monoid class.\n */\n\ntemplate<class T>\nstruct MinCountMonoid{\n    using P\
    \ = pair<T,int>;\n    using value_type = P;\n    static constexpr P op(const P\
    \ &x,const P &y){\n        if(x.first<y.first)return x;\n        if(y.first<x.first)return\
    \ y;\n        return P(x.first,x.second+y.second);\n    }\n    static constexpr\
    \ P unit(){return P(numeric_limits<T>::max(),0);}\n    static constexpr P make(const\
    \ T &x){return P(x,1);}\n};\n\n#line 4 \"group/monoid-action/min-count-add.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Min\
    \ & Count Action class.\n */\n\ntemplate<class T>\nstruct MinCountAddAction{\n\
    \    using InfoMonoid = MinCountMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        if(a.first==InfoMonoid::unit().first)return\
    \ a;\n        return Info(a.first+b,a.second);\n    }\n};\n\n"
  code: "#pragma once\n#include \"group/monoid/add.hpp\"\n#include \"group/monoid/min-count.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Min\
    \ & Count Action class.\n */\n\ntemplate<class T>\nstruct MinCountAddAction{\n\
    \    using InfoMonoid = MinCountMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        if(a.first==InfoMonoid::unit().first)return\
    \ a;\n        return Info(a.first+b,a.second);\n    }\n};\n\n"
  dependsOn:
  - group/monoid/add.hpp
  - group/monoid/min-count.hpp
  isVerificationFile: false
  path: group/monoid-action/min-count-add.hpp
  requiredBy: []
  timestamp: '2024-06-10 17:34:10+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
documentation_of: group/monoid-action/min-count-add.hpp
layout: document
redirect_from:
- /library/group/monoid-action/min-count-add.hpp
- /library/group/monoid-action/min-count-add.hpp.html
title: group/monoid-action/min-count-add.hpp
---
