---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
  - icon: ':warning:'
    path: group/monoid/max-count.hpp
    title: group/monoid/max-count.hpp
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
    \ -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n#line 2 \"group/monoid/max-count.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Max & Count\
    \ Monoid class.\n */\n\ntemplate<class T>\nstruct MaxCountMonoid{\n    using P\
    \ = pair<T,int>;\n    using value_type = P;\n    static constexpr P op(const P\
    \ &x,const P &y){\n        if(x.first>y.first)return x;\n        if(y.first>x.first)return\
    \ y;\n        return P(x.first,x.second+y.second);\n    }\n    static constexpr\
    \ P unit(){return P(numeric_limits<T>::min(),0);}\n    static constexpr P make(const\
    \ T &x){return P(x,1);}\n};\n\n#line 4 \"group/monoid-action/max-count-add.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Max\
    \ & Count Action class.\n */\n\ntemplate<class T>\nstruct MaxCountAddAction{\n\
    \    using InfoMonoid = MaxCountMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        if(a.first==InfoMonoid::unit().first)return\
    \ a;\n        return Info(a.first+b,a.second);\n    }\n};\n\n"
  code: "#pragma once\n#include \"group/monoid/add.hpp\"\n#include \"group/monoid/max-count.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Max\
    \ & Count Action class.\n */\n\ntemplate<class T>\nstruct MaxCountAddAction{\n\
    \    using InfoMonoid = MaxCountMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        if(a.first==InfoMonoid::unit().first)return\
    \ a;\n        return Info(a.first+b,a.second);\n    }\n};\n\n"
  dependsOn:
  - group/monoid/add.hpp
  - group/monoid/max-count.hpp
  isVerificationFile: false
  path: group/monoid-action/max-count-add.hpp
  requiredBy: []
  timestamp: '2024-06-10 17:34:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid-action/max-count-add.hpp
layout: document
redirect_from:
- /library/group/monoid-action/max-count-add.hpp
- /library/group/monoid-action/max-count-add.hpp.html
title: group/monoid-action/max-count-add.hpp
---
