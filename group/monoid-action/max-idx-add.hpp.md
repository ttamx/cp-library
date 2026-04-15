---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
  - icon: ':warning:'
    path: group/monoid/max-idx.hpp
    title: group/monoid/max-idx.hpp
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
    \ -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n#line 2 \"group/monoid/max-idx.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-07-21\n * Description: Max Index\
    \ Monoid class.\n */\n\ntemplate<class T,class IDX=int,bool tie_is_left=true>\n\
    struct MaxIdxMonoid{\n    using P = pair<T,IDX>;\n    using value_type = P;\n\
    \    static constexpr P op(const P &x,const P &y){\n        if(x.first>y.first)return\
    \ x;\n        if(x.first<y.first)return y;\n        return tie_is_left?x:y;\n\
    \    }\n    static constexpr P unit(){return P(numeric_limits<T>::min(),IDX(-1));}\n\
    };\n\n#line 4 \"group/monoid-action/max-idx-add.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-04-14\n * Description: Add to Max Action class.\n */\n\ntemplate<class\
    \ T,class IDX=int,bool tie_is_left=true>\nstruct MaxAddIdxAction{\n    using InfoMonoid\
    \ = MaxIdxMonoid<T,IDX,tie_is_left>;\n    using TagMonoid = AddMonoid<T>;\n  \
    \  using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return (a==InfoMonoid::unit()?a:Info(a.first+b,a.second));\n\
    \    }\n};\n\n"
  code: "#pragma once\n#include \"group/monoid/add.hpp\"\n#include \"group/monoid/max-idx.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Max\
    \ Action class.\n */\n\ntemplate<class T,class IDX=int,bool tie_is_left=true>\n\
    struct MaxAddIdxAction{\n    using InfoMonoid = MaxIdxMonoid<T,IDX,tie_is_left>;\n\
    \    using TagMonoid = AddMonoid<T>;\n    using Info = typename InfoMonoid::value_type;\n\
    \    using Tag = typename TagMonoid::value_type;\n    static constexpr Info op(const\
    \ Info &a,const Tag &b){\n        return (a==InfoMonoid::unit()?a:Info(a.first+b,a.second));\n\
    \    }\n};\n\n"
  dependsOn:
  - group/monoid/add.hpp
  - group/monoid/max-idx.hpp
  isVerificationFile: false
  path: group/monoid-action/max-idx-add.hpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: group/monoid-action/max-idx-add.hpp
layout: document
redirect_from:
- /library/group/monoid-action/max-idx-add.hpp
- /library/group/monoid-action/max-idx-add.hpp.html
title: group/monoid-action/max-idx-add.hpp
---
