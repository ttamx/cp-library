---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/misc/enumerate-xor/aplusb.test.cpp
    title: verify/yosupo/misc/enumerate-xor/aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/enumerate-xor.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-11-27\n * Description: enumerate all range of x such that l <=\
    \ x xor p < r.\n */\n\ntemplate<class F>\nvoid enumerate_xor(ll p,ll l,ll r,const\
    \ F &query){\n    for(ll b=1;l<r;b<<=1){\n        if(l&b)query(l^p,(l^p)+b),l+=b;\n\
    \        if(r&b)r-=b,query(r^p,(r^p)+b);\n        if(p&b)p^=b;\n    }\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-11-27\n * Description:\
    \ enumerate all range of x such that l <= x xor p < r.\n */\n\ntemplate<class\
    \ F>\nvoid enumerate_xor(ll p,ll l,ll r,const F &query){\n    for(ll b=1;l<r;b<<=1){\n\
    \        if(l&b)query(l^p,(l^p)+b),l+=b;\n        if(r&b)r-=b,query(r^p,(r^p)+b);\n\
    \        if(p&b)p^=b;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/enumerate-xor.hpp
  requiredBy: []
  timestamp: '2026-10-26 14:01:53+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/misc/enumerate-xor/aplusb.test.cpp
documentation_of: misc/enumerate-xor.hpp
layout: document
redirect_from:
- /library/misc/enumerate-xor.hpp
- /library/misc/enumerate-xor.hpp.html
title: misc/enumerate-xor.hpp
---
