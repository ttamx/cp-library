---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid-action/default-action.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-04-14\n * Description: Default Action class.\n */\n\
    \ntemplate<class Monoid>\nstruct DefaultAction{\n    using InfoMonoid = Monoid;\n\
    \    using TagMonoid = Monoid;\n    using Info = typename Monoid::value_type;\n\
    \    using Tag = typename Monoid::value_type;\n    static constexpr Info op(const\
    \ Info &a,const Tag &b){\n        return Monoid::op(a,b);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Default Action class.\n */\n\ntemplate<class Monoid>\nstruct DefaultAction{\n\
    \    using InfoMonoid = Monoid;\n    using TagMonoid = Monoid;\n    using Info\
    \ = typename Monoid::value_type;\n    using Tag = typename Monoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return Monoid::op(a,b);\n\
    \    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid-action/default-action.hpp
  requiredBy: []
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid-action/default-action.hpp
layout: document
redirect_from:
- /library/group/monoid-action/default-action.hpp
- /library/group/monoid-action/default-action.hpp.html
title: group/monoid-action/default-action.hpp
---
