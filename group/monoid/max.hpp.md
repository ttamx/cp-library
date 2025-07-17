---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: group/monoid-action/max-add.hpp
    title: group/monoid-action/max-add.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/max.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-14\n * Description: Max Monoid class.\n */\n\ntemplate<class T>\n\
    struct MaxMonoid{\n    using value_type = T;\n    static constexpr T op(const\
    \ T &x,const T &y){return max(x,y);}\n    static constexpr T unit(){return numeric_limits<T>::min();}\n\
    };\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Max Monoid class.\n */\n\ntemplate<class T>\nstruct MaxMonoid{\n    using value_type\
    \ = T;\n    static constexpr T op(const T &x,const T &y){return max(x,y);}\n \
    \   static constexpr T unit(){return numeric_limits<T>::min();}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/max.hpp
  requiredBy:
  - group/monoid-action/max-add.hpp
  timestamp: '2024-12-12 23:59:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid/max.hpp
layout: document
redirect_from:
- /library/group/monoid/max.hpp
- /library/group/monoid/max.hpp.html
title: group/monoid/max.hpp
---
