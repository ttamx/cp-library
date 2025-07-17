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
  bundledCode: "#line 2 \"group/monoid/minmax.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-04-14\n * Description: Min Max Monoid class.\n */\n\ntemplate<class\
    \ T>\nstruct MinMaxMonoid{\n    using P = pair<T,T>;\n    using value_type = P;\n\
    \    static constexpr P op(const P &x,const P &y){return P(min(x.first,y.first),max(x.second,y.second));}\n\
    \    static constexpr P unit(){return P(numeric_limits<T>::max(),numeric_limits<T>::min());}\n\
    };\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Min Max Monoid class.\n */\n\ntemplate<class T>\nstruct MinMaxMonoid{\n    using\
    \ P = pair<T,T>;\n    using value_type = P;\n    static constexpr P op(const P\
    \ &x,const P &y){return P(min(x.first,y.first),max(x.second,y.second));}\n   \
    \ static constexpr P unit(){return P(numeric_limits<T>::max(),numeric_limits<T>::min());}\n\
    };\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/minmax.hpp
  requiredBy: []
  timestamp: '2024-12-12 23:59:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid/minmax.hpp
layout: document
redirect_from:
- /library/group/monoid/minmax.hpp
- /library/group/monoid/minmax.hpp.html
title: group/monoid/minmax.hpp
---
