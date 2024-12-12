---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
  - icon: ':warning:'
    path: group/monoid/max.hpp
    title: group/monoid/max.hpp
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
    \ -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n#line 2 \"group/monoid/max.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Max Monoid\
    \ class.\n */\n\ntemplate<class T>\nstruct MaxMonoid{\n    using value_type =\
    \ T;\n    static constexpr T op(const T &x,const T &y){return max(x,y);}\n   \
    \ static constexpr T unit(){return numeric_limits<T>::min();}\n};\n\n#line 4 \"\
    group/monoid-action/max-add.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n\
    \ * Description: Add to Max Action class.\n */\n\ntemplate<class T>\nstruct MaxAddAction{\n\
    \    using InfoMonoid = MaxMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n \
    \   using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return (a==InfoMonoid::unit()?a:(a+b));\n\
    \    }\n};\n\n"
  code: "#pragma once\n#include \"group/monoid/add.hpp\"\n#include \"group/monoid/max.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Max\
    \ Action class.\n */\n\ntemplate<class T>\nstruct MaxAddAction{\n    using InfoMonoid\
    \ = MaxMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n    using Info = typename\
    \ InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n \
    \   static constexpr Info op(const Info &a,const Tag &b){\n        return (a==InfoMonoid::unit()?a:(a+b));\n\
    \    }\n};\n\n"
  dependsOn:
  - group/monoid/add.hpp
  - group/monoid/max.hpp
  isVerificationFile: false
  path: group/monoid-action/max-add.hpp
  requiredBy: []
  timestamp: '2024-12-12 23:59:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid-action/max-add.hpp
layout: document
redirect_from:
- /library/group/monoid-action/max-add.hpp
- /library/group/monoid-action/max-add.hpp.html
title: group/monoid-action/max-add.hpp
---
