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
  bundledCode: "#line 2 \"modular-arithmetic/modint64.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-03-17\n * Description: modular arithmetic operations\n */\n\
    \ntemplate<int64_t M,int64_t root=0>\nstruct ModInt64{\n    using mint = ModInt64;\n\
    \    using i64 = int64_t;\n    i64 x;\n    constexpr ModInt64():x(0){}\n    constexpr\
    \ ModInt64(i64 x):x(norm(x%get_mod())){}\n    static i64 Mod;\n    static constexpr\
    \ i64 get_mod(){return M>0?M:Mod;}\n    static constexpr void set_mod(i64 Mod_){Mod=Mod_;}\n\
    \    static constexpr mint get_root(){return mint(root);}\n    constexpr i64 norm(i64\
    \ x)const{if(x<0)x+=get_mod();if(x>=get_mod())x-=get_mod();return x;}\n    explicit\
    \ constexpr operator i64()const{return x;}\n    constexpr mint operator-()const{return\
    \ mint()-mint(*this);};\n    constexpr mint operator+()const{return mint(*this);};\n\
    \    constexpr mint inv()const{\n        i64 a=x,b=get_mod(),u=1,v=0,q=0;\n  \
    \      while(b>0){\n            q=a/b;\n            a-=q*b;\n            u-=q*v;\n\
    \            swap(a,b);\n            swap(u,v);\n        }\n        return mint(u);\n\
    \    }\n    constexpr i64 mul(i64 a,i64 b)const{\n        i64 mod=get_mod();\n\
    \        i64 res=(a*b-i64(1.l*a*b/mod)*mod)%mod;\n        if(res<0)res+=mod;\n\
    \        return res;\n    }\n    constexpr mint &operator+=(const mint &rhs){x=norm(x+rhs.x);return\
    \ *this;}\n    constexpr mint &operator-=(const mint &rhs){x=norm(x-rhs.x);return\
    \ *this;}\n    constexpr mint &operator*=(const mint &rhs){x=mul(x,rhs.x);return\
    \ *this;}\n    constexpr mint &operator/=(const mint &rhs){x=mul(x,rhs.inv().x);return\
    \ *this;}\n    constexpr mint &operator++(){return *this+=1;}\n    constexpr mint\
    \ &operator--(){return *this-=1;}\n    constexpr mint operator++(int){mint res=*this;*this+=1;return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=1;return res;}\n\
    \    friend constexpr mint operator+(mint lhs,const mint &rhs){return lhs+=rhs;}\n\
    \    friend constexpr mint operator-(mint lhs,const mint &rhs){return lhs-=rhs;}\n\
    \    friend constexpr mint operator*(mint lhs,const mint &rhs){return lhs*=rhs;}\n\
    \    friend constexpr mint operator/(mint lhs,const mint &rhs){return lhs/=rhs;}\n\
    \    friend istream &operator>>(istream &is,mint &o){i64 x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    \    friend constexpr bool operator==(const mint &lhs,const mint &rhs){return\
    \ lhs.x==rhs.x;}\n    friend constexpr bool operator!=(const mint &lhs,const mint\
    \ &rhs){return lhs.x!=rhs.x;}\n    friend constexpr bool operator<(const mint\
    \ &lhs,const mint &rhs){return lhs.x<rhs.x;} // for std::map\n};\nusing mint64\
    \ = ModInt64<0>;\ntemplate<>\nint64_t mint64::Mod=int64_t(1e18)+9;\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description:\
    \ modular arithmetic operations\n */\n\ntemplate<int64_t M,int64_t root=0>\nstruct\
    \ ModInt64{\n    using mint = ModInt64;\n    using i64 = int64_t;\n    i64 x;\n\
    \    constexpr ModInt64():x(0){}\n    constexpr ModInt64(i64 x):x(norm(x%get_mod())){}\n\
    \    static i64 Mod;\n    static constexpr i64 get_mod(){return M>0?M:Mod;}\n\
    \    static constexpr void set_mod(i64 Mod_){Mod=Mod_;}\n    static constexpr\
    \ mint get_root(){return mint(root);}\n    constexpr i64 norm(i64 x)const{if(x<0)x+=get_mod();if(x>=get_mod())x-=get_mod();return\
    \ x;}\n    explicit constexpr operator i64()const{return x;}\n    constexpr mint\
    \ operator-()const{return mint()-mint(*this);};\n    constexpr mint operator+()const{return\
    \ mint(*this);};\n    constexpr mint inv()const{\n        i64 a=x,b=get_mod(),u=1,v=0,q=0;\n\
    \        while(b>0){\n            q=a/b;\n            a-=q*b;\n            u-=q*v;\n\
    \            swap(a,b);\n            swap(u,v);\n        }\n        return mint(u);\n\
    \    }\n    constexpr i64 mul(i64 a,i64 b)const{\n        i64 mod=get_mod();\n\
    \        i64 res=(a*b-i64(1.l*a*b/mod)*mod)%mod;\n        if(res<0)res+=mod;\n\
    \        return res;\n    }\n    constexpr mint &operator+=(const mint &rhs){x=norm(x+rhs.x);return\
    \ *this;}\n    constexpr mint &operator-=(const mint &rhs){x=norm(x-rhs.x);return\
    \ *this;}\n    constexpr mint &operator*=(const mint &rhs){x=mul(x,rhs.x);return\
    \ *this;}\n    constexpr mint &operator/=(const mint &rhs){x=mul(x,rhs.inv().x);return\
    \ *this;}\n    constexpr mint &operator++(){return *this+=1;}\n    constexpr mint\
    \ &operator--(){return *this-=1;}\n    constexpr mint operator++(int){mint res=*this;*this+=1;return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=1;return res;}\n\
    \    friend constexpr mint operator+(mint lhs,const mint &rhs){return lhs+=rhs;}\n\
    \    friend constexpr mint operator-(mint lhs,const mint &rhs){return lhs-=rhs;}\n\
    \    friend constexpr mint operator*(mint lhs,const mint &rhs){return lhs*=rhs;}\n\
    \    friend constexpr mint operator/(mint lhs,const mint &rhs){return lhs/=rhs;}\n\
    \    friend istream &operator>>(istream &is,mint &o){i64 x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    \    friend constexpr bool operator==(const mint &lhs,const mint &rhs){return\
    \ lhs.x==rhs.x;}\n    friend constexpr bool operator!=(const mint &lhs,const mint\
    \ &rhs){return lhs.x!=rhs.x;}\n    friend constexpr bool operator<(const mint\
    \ &lhs,const mint &rhs){return lhs.x<rhs.x;} // for std::map\n};\nusing mint64\
    \ = ModInt64<0>;\ntemplate<>\nint64_t mint64::Mod=int64_t(1e18)+9;\n\n"
  dependsOn: []
  isVerificationFile: false
  path: modular-arithmetic/modint64.hpp
  requiredBy: []
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modular-arithmetic/modint64.hpp
layout: document
redirect_from:
- /library/modular-arithmetic/modint64.hpp
- /library/modular-arithmetic/modint64.hpp.html
title: modular-arithmetic/modint64.hpp
---
