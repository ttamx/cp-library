---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/min.hpp
    title: group/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/add.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-14\n * Description: Add Monoid class.\n */\n\ntemplate<class T>\n\
    struct AddMonoid{\n    using value_type = T;\n    static constexpr T op(const\
    \ T &x,const T &y){return x+y;}\n    static constexpr T inverse(const T &x){return\
    \ -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n#line 2 \"group/monoid/min.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Min Monoid\
    \ class.\n */\n\ntemplate<class T>\nstruct MinMonoid{\n    using value_type =\
    \ T;\n    static constexpr T op(const T &x,const T &y){return min(x,y);}\n   \
    \ static constexpr T unit(){return numeric_limits<T>::max();}\n};\n\n#line 4 \"\
    group/monoid-action/min-add.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n\
    \ * Description: Add to Min Action class.\n */\n\ntemplate<class T>\nstruct MinAddAction{\n\
    \    using InfoMonoid = MinMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n \
    \   using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return (a==InfoMonoid::unit()?a:(a+b));\n\
    \    }\n};\n\n"
  code: "#pragma once\n#include \"group/monoid/add.hpp\"\n#include \"group/monoid/min.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Min\
    \ Action class.\n */\n\ntemplate<class T>\nstruct MinAddAction{\n    using InfoMonoid\
    \ = MinMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n    using Info = typename\
    \ InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n \
    \   static constexpr Info op(const Info &a,const Tag &b){\n        return (a==InfoMonoid::unit()?a:(a+b));\n\
    \    }\n};\n\n"
  dependsOn:
  - group/monoid/add.hpp
  - group/monoid/min.hpp
  isVerificationFile: false
  path: group/monoid-action/min-add.hpp
  requiredBy: []
  timestamp: '2024-06-10 17:34:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid-action/min-add.hpp
layout: document
redirect_from:
- /library/group/monoid-action/min-add.hpp
- /library/group/monoid-action/min-add.hpp.html
title: group/monoid-action/min-add.hpp
---
