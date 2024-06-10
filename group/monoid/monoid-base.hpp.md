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
  bundledCode: "#line 2 \"group/monoid/monoid-base.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-05-16\n * Description: Monoid Base class.\n */\n\ntemplate<class\
    \ T,T (*combine)(T,T),T (*identity)()>\nstruct MonoidBase{\n    using value_type\
    \ = T;\n    static constexpr T op(const T &x,const T &y){return combine(x,y);}\n\
    \    static constexpr T unit(){return identity();}\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-05-16\n * Description:\
    \ Monoid Base class.\n */\n\ntemplate<class T,T (*combine)(T,T),T (*identity)()>\n\
    struct MonoidBase{\n    using value_type = T;\n    static constexpr T op(const\
    \ T &x,const T &y){return combine(x,y);}\n    static constexpr T unit(){return\
    \ identity();}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/monoid-base.hpp
  requiredBy: []
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid/monoid-base.hpp
layout: document
redirect_from:
- /library/group/monoid/monoid-base.hpp
- /library/group/monoid/monoid-base.hpp.html
title: group/monoid/monoid-base.hpp
---
