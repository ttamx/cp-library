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
  bundledCode: "#line 2 \"group/monoid-action/monoid-action-base.hpp\"\n\n/**\n *\
    \ Author: Teetat T.\n * Date: 2024-05-16\n * Description: Monoid Action Base class.\n\
    \ */\n\ntemplate<class MInfo,class MTag,typename MInfo::value_type\n    (*apply)(typename\
    \ MInfo::value_type,typename MTag::value_type)>\nstruct MonoidActionBase{\n  \
    \  using InfoMonoid = MInfo;\n    using TagMonoid = MTag;\n    using Info = typename\
    \ InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n \
    \   static constexpr Info op(const Info &a,const Tag &b){\n        return combine(a,b);\n\
    \    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-05-16\n * Description:\
    \ Monoid Action Base class.\n */\n\ntemplate<class MInfo,class MTag,typename MInfo::value_type\n\
    \    (*apply)(typename MInfo::value_type,typename MTag::value_type)>\nstruct MonoidActionBase{\n\
    \    using InfoMonoid = MInfo;\n    using TagMonoid = MTag;\n    using Info =\
    \ typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return combine(a,b);\n\
    \    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: group/monoid-action/monoid-action-base.hpp
  requiredBy: []
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid-action/monoid-action-base.hpp
layout: document
redirect_from:
- /library/group/monoid-action/monoid-action-base.hpp
- /library/group/monoid-action/monoid-action-base.hpp.html
title: group/monoid-action/monoid-action-base.hpp
---
