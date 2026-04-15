---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/bitwise_and_convolution.test.cpp
    title: verify/yosupo/convolution/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/bitwise_or_convolution.test.cpp
    title: verify/yosupo/convolution/bitwise_or_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/bitwise_xor_convolution.test.cpp
    title: verify/yosupo/convolution/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/convolution_mod.test.cpp
    title: verify/yosupo/convolution/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/gcd_convolution.test.cpp
    title: verify/yosupo/convolution/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/lcm_convolution.test.cpp
    title: verify/yosupo/convolution/lcm_convolution.test.cpp
  - icon: ':x:'
    path: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_range_composite.test.cpp
    title: verify/yosupo/data-structure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
    title: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':x:'
    path: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
    title: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  - icon: ':x:'
    path: verify/yosupo/polynomial/exp_of_formal_power_series.test.cpp
    title: verify/yosupo/polynomial/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/polynomial/inv_of_formal_power_series.test.cpp
    title: verify/yosupo/polynomial/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/polynomial/log_of_formal_power_series.test.cpp
    title: verify/yosupo/polynomial/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
    title: verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modular-arithmetic/modint.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2026-04-15\n * Description: modular arithmetic operations\n */\n\
    \ntemplate<int mod,int root=0>\nstruct ModInt{\n    using mint = ModInt;\n   \
    \ \n\tstatic_assert(mod>0,\"mod must be positive\");\n\n    int x;\n\n    constexpr\
    \ ModInt():x(0){}\n    constexpr ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n    constexpr\
    \ explicit operator int()const{return x;}\n    constexpr static int get_mod(){return\
    \ mod;}\n    constexpr static mint get_root(){return mint(root);}\n    \n    constexpr\
    \ mint operator-()const{\n        mint res;\n        res.x=x?mod-x:0;\n      \
    \  return res;\n    }\n    constexpr mint operator+()const{return *this;}\n\n\
    \    constexpr mint inv()const{\n        int a=x,b=mod,u=1,v=0,q=0;\n        while(b>0){\n\
    \            q=a/b;\n            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n\
    \        }\n        return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n\
    \        mint res=1,a=*this;\n        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n   \
    \     return res;\n    }\n    constexpr mint &operator+=(const mint &o){\n   \
    \     if((x+=o.x)>=mod)x-=mod;\n        return *this;\n    }\n    constexpr mint\
    \ &operator-=(const mint &o){\n        if((x-=o.x)<0)x+=mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator*=(const mint &o){\n        x=(ll(x)*o.x)%mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator/=(const mint &o){\n\
    \        return *this*=o.inv();\n    }\n\n    constexpr mint operator+(const mint\
    \ &o)const{return mint(*this)+=o;}\n    constexpr mint operator-(const mint &o)const{return\
    \ mint(*this)-=o;}\n    constexpr mint operator*(const mint &o)const{return mint(*this)*=o;}\n\
    \    constexpr mint operator/(const mint &o)const{return mint(*this)/=o;}\n\n\
    \    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){mint\
    \ res=*this;*this+=mint(1);return res;}\n    constexpr mint operator--(int){mint\
    \ res=*this;*this-=mint(1);return res;}\n    \n    constexpr bool operator==(const\
    \ mint &o)const{return x==o.x;}\n    constexpr bool operator!=(const mint &o)const{return\
    \ x!=o.x;}\n    constexpr bool operator<(const mint &o)const{return x<o.x;}\n\
    \    \n    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    };\nusing mint998 = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n * Description:\
    \ modular arithmetic operations\n */\n\ntemplate<int mod,int root=0>\nstruct ModInt{\n\
    \    using mint = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must be positive\"\
    );\n\n    int x;\n\n    constexpr ModInt():x(0){}\n    constexpr ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n\
    \    constexpr explicit operator int()const{return x;}\n    constexpr static int\
    \ get_mod(){return mod;}\n    constexpr static mint get_root(){return mint(root);}\n\
    \    \n    constexpr mint operator-()const{\n        mint res;\n        res.x=x?mod-x:0;\n\
    \        return res;\n    }\n    constexpr mint operator+()const{return *this;}\n\
    \n    constexpr mint inv()const{\n        int a=x,b=mod,u=1,v=0,q=0;\n       \
    \ while(b>0){\n            q=a/b;\n            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n\
    \        }\n        return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n\
    \        mint res=1,a=*this;\n        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n   \
    \     return res;\n    }\n    constexpr mint &operator+=(const mint &o){\n   \
    \     if((x+=o.x)>=mod)x-=mod;\n        return *this;\n    }\n    constexpr mint\
    \ &operator-=(const mint &o){\n        if((x-=o.x)<0)x+=mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator*=(const mint &o){\n        x=(ll(x)*o.x)%mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator/=(const mint &o){\n\
    \        return *this*=o.inv();\n    }\n\n    constexpr mint operator+(const mint\
    \ &o)const{return mint(*this)+=o;}\n    constexpr mint operator-(const mint &o)const{return\
    \ mint(*this)-=o;}\n    constexpr mint operator*(const mint &o)const{return mint(*this)*=o;}\n\
    \    constexpr mint operator/(const mint &o)const{return mint(*this)/=o;}\n\n\
    \    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){mint\
    \ res=*this;*this+=mint(1);return res;}\n    constexpr mint operator--(int){mint\
    \ res=*this;*this-=mint(1);return res;}\n    \n    constexpr bool operator==(const\
    \ mint &o)const{return x==o.x;}\n    constexpr bool operator!=(const mint &o)const{return\
    \ x!=o.x;}\n    constexpr bool operator<(const mint &o)const{return x<o.x;}\n\
    \    \n    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    };\nusing mint998 = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: modular-arithmetic/modint.hpp
  requiredBy: []
  timestamp: '2026-04-15 21:45:25+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/polynomial/exp_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/log_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/inv_of_formal_power_series.test.cpp
  - verify/yosupo/convolution/bitwise_and_convolution.test.cpp
  - verify/yosupo/convolution/bitwise_or_convolution.test.cpp
  - verify/yosupo/convolution/lcm_convolution.test.cpp
  - verify/yosupo/convolution/gcd_convolution.test.cpp
  - verify/yosupo/convolution/bitwise_xor_convolution.test.cpp
  - verify/yosupo/convolution/convolution_mod.test.cpp
  - verify/yosupo/data-structure/point_set_range_composite.test.cpp
  - verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - verify/yosupo/data-structure/range_affine_range_sum.test.cpp
  - verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  - verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
  - verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  - verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: modular-arithmetic/modint.hpp
layout: document
redirect_from:
- /library/modular-arithmetic/modint.hpp
- /library/modular-arithmetic/modint.hpp.html
title: modular-arithmetic/modint.hpp
---
