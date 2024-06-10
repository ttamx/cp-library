---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: group/monoid-action/max-count-add.hpp
    title: group/monoid-action/max-count-add.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"group/monoid/max-count.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-04-14\n * Description: Max & Count Monoid class.\n */\n\ntemplate<class\
    \ T>\nstruct MaxCountMonoid{\n    using P = pair<T,int>;\n    using value_type\
    \ = P;\n    static constexpr P op(const P &x,const P &y){\n        if(x.first>y.first)return\
    \ x;\n        if(y.first>x.first)return y;\n        return P(x.first,x.second+y.second);\n\
    \    }\n    static constexpr P unit(){return P(numeric_limits<T>::min(),0);}\n\
    \    static constexpr P make(const T &x){return P(x,1);}\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description:\
    \ Max & Count Monoid class.\n */\n\ntemplate<class T>\nstruct MaxCountMonoid{\n\
    \    using P = pair<T,int>;\n    using value_type = P;\n    static constexpr P\
    \ op(const P &x,const P &y){\n        if(x.first>y.first)return x;\n        if(y.first>x.first)return\
    \ y;\n        return P(x.first,x.second+y.second);\n    }\n    static constexpr\
    \ P unit(){return P(numeric_limits<T>::min(),0);}\n    static constexpr P make(const\
    \ T &x){return P(x,1);}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid/max-count.hpp
  requiredBy:
  - group/monoid-action/max-count-add.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid/max-count.hpp
layout: document
redirect_from:
- /library/group/monoid/max-count.hpp
- /library/group/monoid/max-count.hpp.html
title: group/monoid/max-count.hpp
---
