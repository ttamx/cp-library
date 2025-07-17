---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: group/monoid/add-count.hpp
    title: group/monoid/add-count.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
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
    \ -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n#line 2 \"group/monoid/add-count.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add & Count\
    \ Monoid class.\n */\n\ntemplate<class T>\nstruct AddCountMonoid{\n    using P\
    \ = pair<T,ll>;\n    using value_type = P;\n    static constexpr P op(const P\
    \ &x,const P &y){\n        return P(x.first+y.first,x.second+y.second);\n    }\n\
    \    static constexpr P inverse(const P &x){return P(-x.first,-x.second);}\n \
    \   static constexpr P unit(){return P(T(0),0LL);}\n    static constexpr P make(const\
    \ T &x){return P(x,1LL);}\n};\n\n#line 4 \"group/monoid-action/add-count-add.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Add\
    \ & Count Monoid class.\n */\n\ntemplate<class T>\nstruct AddCountAddAction{\n\
    \    using InfoMonoid = AddCountMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return Info(a.first+a.second*b,a.second);\n\
    \    }\n};\n\n"
  code: "#pragma once\n#include \"group/monoid/add.hpp\"\n#include \"group/monoid/add-count.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Add\
    \ & Count Monoid class.\n */\n\ntemplate<class T>\nstruct AddCountAddAction{\n\
    \    using InfoMonoid = AddCountMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return Info(a.first+a.second*b,a.second);\n\
    \    }\n};\n\n"
  dependsOn:
  - group/monoid/add.hpp
  - group/monoid/add-count.hpp
  isVerificationFile: false
  path: group/monoid-action/add-count-add.hpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid-action/add-count-add.hpp
layout: document
redirect_from:
- /library/group/monoid-action/add-count-add.hpp
- /library/group/monoid-action/add-count-add.hpp.html
title: group/monoid-action/add-count-add.hpp
---
