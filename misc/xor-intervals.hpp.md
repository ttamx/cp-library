---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/misc/xor-intervals/aplusb.test.cpp
    title: verify/yosupo/misc/xor-intervals/aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qoj.ac/contest/4538/problem/22840
  bundledCode: "#line 2 \"misc/xor-intervals.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2026-10-26\n * Source: https://qoj.ac/contest/4538/problem/22840\n *\
    \ Description: Returns $\\{x \\oplus y \\mid l_1 \\le x < r_1,\\ l_2 \\le y <\
    \ r_2\\}$\n * as a sorted list of disjoint, merged half-open intervals $[a, b)$.\
    \ The output\n * has $O(\\log V)$ intervals, at most $8$ per bit. Requires $r_1,\
    \ r_2 \\le 2^{63}$.\n * Time: O(\\log V)\n */\n\nauto xor_intervals(u64 l1,u64\
    \ r1,u64 l2,u64 r2){\n    using VP = vector<pair<u64,u64>>;\n    VP res;\n   \
    \ if(l1>=r1||l2>=r2)return res;\n    auto in=[](u64 x,u64 s,u64 l,u64 r){return\
    \ l<=x&&x+s<=r;};\n    auto ov=[](u64 x,u64 s,u64 l,u64 r){return x<r&&l<x+s;};\n\
    \    auto rec=[&](auto &self,u64 s,u64 z,const VP &a)->void {\n        if(a.empty())return;\n\
    \        for(auto [x,y]:a)if(in(x,s,l1,r1)||in(y,s,l2,r2)){\n            if(!res.empty()&&res.back().second==z)\n\
    \                res.back().second=z+s;\n            else res.emplace_back(z,z+s);\n\
    \            return;\n        }\n        s>>=1;\n        VP b[2];\n        for(auto\
    \ [x,y]:a)for(u64 u:{x,x|s})if(ov(u,s,l1,r1))\n            for(u64 v:{y,y|s})if(ov(v,s,l2,r2))\n\
    \                b[((u^v)&s)!=0].emplace_back(u,v);\n        self(self,s,z,b[0]);\n\
    \        self(self,s,z|s,b[1]);\n    };\n    rec(rec,1ULL<<63,0,{{0,0}});\n  \
    \  return res;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2026-10-26\n * Source:\
    \ https://qoj.ac/contest/4538/problem/22840\n * Description: Returns $\\{x \\\
    oplus y \\mid l_1 \\le x < r_1,\\ l_2 \\le y < r_2\\}$\n * as a sorted list of\
    \ disjoint, merged half-open intervals $[a, b)$. The output\n * has $O(\\log V)$\
    \ intervals, at most $8$ per bit. Requires $r_1, r_2 \\le 2^{63}$.\n * Time: O(\\\
    log V)\n */\n\nauto xor_intervals(u64 l1,u64 r1,u64 l2,u64 r2){\n    using VP\
    \ = vector<pair<u64,u64>>;\n    VP res;\n    if(l1>=r1||l2>=r2)return res;\n \
    \   auto in=[](u64 x,u64 s,u64 l,u64 r){return l<=x&&x+s<=r;};\n    auto ov=[](u64\
    \ x,u64 s,u64 l,u64 r){return x<r&&l<x+s;};\n    auto rec=[&](auto &self,u64 s,u64\
    \ z,const VP &a)->void {\n        if(a.empty())return;\n        for(auto [x,y]:a)if(in(x,s,l1,r1)||in(y,s,l2,r2)){\n\
    \            if(!res.empty()&&res.back().second==z)\n                res.back().second=z+s;\n\
    \            else res.emplace_back(z,z+s);\n            return;\n        }\n \
    \       s>>=1;\n        VP b[2];\n        for(auto [x,y]:a)for(u64 u:{x,x|s})if(ov(u,s,l1,r1))\n\
    \            for(u64 v:{y,y|s})if(ov(v,s,l2,r2))\n                b[((u^v)&s)!=0].emplace_back(u,v);\n\
    \        self(self,s,z,b[0]);\n        self(self,s,z|s,b[1]);\n    };\n    rec(rec,1ULL<<63,0,{{0,0}});\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/xor-intervals.hpp
  requiredBy: []
  timestamp: '2026-10-26 14:01:53+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/misc/xor-intervals/aplusb.test.cpp
documentation_of: misc/xor-intervals.hpp
layout: document
redirect_from:
- /library/misc/xor-intervals.hpp
- /library/misc/xor-intervals.hpp.html
title: misc/xor-intervals.hpp
---
