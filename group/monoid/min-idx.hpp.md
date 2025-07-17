---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: group/monoid-action/min-idx-add.hpp
    title: group/monoid-action/min-idx-add.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/min-idx.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-07-21\n * Description: Min Index Monoid class.\n */\n\ntemplate<class\
    \ T,class IDX=int,bool tie_is_left=true>\nstruct MinIdxMonoid{\n    using P =\
    \ pair<T,IDX>;\n    using value_type = P;\n    static constexpr P op(const P &x,const\
    \ P &y){\n        if(x.first<y.first)return x;\n        if(x.first>y.first)return\
    \ y;\n        return tie_is_left?x:y;\n    }\n    static constexpr P unit(){return\
    \ P(numeric_limits<T>::max(),IDX(-1));}\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-21\n * Description:\
    \ Min Index Monoid class.\n */\n\ntemplate<class T,class IDX=int,bool tie_is_left=true>\n\
    struct MinIdxMonoid{\n    using P = pair<T,IDX>;\n    using value_type = P;\n\
    \    static constexpr P op(const P &x,const P &y){\n        if(x.first<y.first)return\
    \ x;\n        if(x.first>y.first)return y;\n        return tie_is_left?x:y;\n\
    \    }\n    static constexpr P unit(){return P(numeric_limits<T>::max(),IDX(-1));}\n\
    };\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/min-idx.hpp
  requiredBy:
  - group/monoid-action/min-idx-add.hpp
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid/min-idx.hpp
layout: document
redirect_from:
- /library/group/monoid/min-idx.hpp
- /library/group/monoid/min-idx.hpp.html
title: group/monoid/min-idx.hpp
---
