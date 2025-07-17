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
  bundledCode: "#line 2 \"group/monoid/set.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-15\n * Description: Set Monoid class.\n */\n\ntemplate<class T>\n\
    struct SetMonoid{\n    using P = pair<T,bool>;\n    using value_type = P;\n  \
    \  static constexpr P op(const P &x,const P &y){return y.second?y:x;}\n    static\
    \ constexpr P unit(){return P(T(),false);}\n    static constexpr P make(const\
    \ T &x){return P(x,true);}\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-15\n * Description:\
    \ Set Monoid class.\n */\n\ntemplate<class T>\nstruct SetMonoid{\n    using P\
    \ = pair<T,bool>;\n    using value_type = P;\n    static constexpr P op(const\
    \ P &x,const P &y){return y.second?y:x;}\n    static constexpr P unit(){return\
    \ P(T(),false);}\n    static constexpr P make(const T &x){return P(x,true);}\n\
    };\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/set.hpp
  requiredBy: []
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid/set.hpp
layout: document
redirect_from:
- /library/group/monoid/set.hpp
- /library/group/monoid/set.hpp.html
title: group/monoid/set.hpp
---
