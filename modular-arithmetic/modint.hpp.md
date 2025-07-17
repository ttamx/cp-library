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
  bundledCode: "#line 2 \"modular-arithmetic/modint.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-03-17\n * Description: modular arithmetic operations\n */\n\
    \ntemplate<int M,int root=0>\nstruct ModInt{\n    using mint = ModInt;\n    int\
    \ x;\n    constexpr ModInt():x(0){}\n    constexpr ModInt(ll x):x(norm(x%get_mod())){}\n\
    \    static int Mod;\n    static constexpr int get_mod(){return M>0?M:Mod;}\n\
    \    static constexpr void set_mod(int Mod_){Mod=Mod_;}\n    static constexpr\
    \ mint get_root(){return mint(root);}\n    constexpr int norm(int x)const{if(x<0)x+=get_mod();if(x>=get_mod())x-=get_mod();return\
    \ x;}\n    explicit constexpr operator int()const{return x;}\n    constexpr mint\
    \ operator-()const{return mint()-mint(*this);};\n    constexpr mint operator+()const{return\
    \ mint(*this);};\n    constexpr mint inv()const{\n        int a=x,b=get_mod(),u=1,v=0,q=0;\n\
    \        while(b>0){\n            q=a/b;\n            a-=q*b;\n            u-=q*v;\n\
    \            swap(a,b);\n            swap(u,v);\n        }\n        return mint(u);\n\
    \    }\n    constexpr int mul(int a,int b)const{return 1LL*a*b%get_mod();}\n \
    \   constexpr mint &operator+=(const mint &rhs){x=norm(x+rhs.x);return *this;}\n\
    \    constexpr mint &operator-=(const mint &rhs){x=norm(x-rhs.x);return *this;}\n\
    \    constexpr mint &operator*=(const mint &rhs){x=mul(x,rhs.x);return *this;}\n\
    \    constexpr mint &operator/=(const mint &rhs){x=mul(x,rhs.inv().x);return *this;}\n\
    \    constexpr mint &operator++(){return *this+=1;}\n    constexpr mint &operator--(){return\
    \ *this-=1;}\n    constexpr mint operator++(int){mint res=*this;*this+=1;return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=1;return res;}\n\
    \    friend constexpr mint operator+(mint lhs,const mint &rhs){return lhs+=rhs;}\n\
    \    friend constexpr mint operator-(mint lhs,const mint &rhs){return lhs-=rhs;}\n\
    \    friend constexpr mint operator*(mint lhs,const mint &rhs){return lhs*=rhs;}\n\
    \    friend constexpr mint operator/(mint lhs,const mint &rhs){return lhs/=rhs;}\n\
    \    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    \    friend constexpr bool operator==(const mint &lhs,const mint &rhs){return\
    \ lhs.x==rhs.x;}\n    friend constexpr bool operator!=(const mint &lhs,const mint\
    \ &rhs){return lhs.x!=rhs.x;}\n    friend constexpr bool operator<(const mint\
    \ &lhs,const mint &rhs){return lhs.x<rhs.x;} // for std::map\n};\nusing mint32\
    \ = ModInt<0>;\ntemplate<>\nint mint32::Mod=int(1e9)+7;\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description:\
    \ modular arithmetic operations\n */\n\ntemplate<int M,int root=0>\nstruct ModInt{\n\
    \    using mint = ModInt;\n    int x;\n    constexpr ModInt():x(0){}\n    constexpr\
    \ ModInt(ll x):x(norm(x%get_mod())){}\n    static int Mod;\n    static constexpr\
    \ int get_mod(){return M>0?M:Mod;}\n    static constexpr void set_mod(int Mod_){Mod=Mod_;}\n\
    \    static constexpr mint get_root(){return mint(root);}\n    constexpr int norm(int\
    \ x)const{if(x<0)x+=get_mod();if(x>=get_mod())x-=get_mod();return x;}\n    explicit\
    \ constexpr operator int()const{return x;}\n    constexpr mint operator-()const{return\
    \ mint()-mint(*this);};\n    constexpr mint operator+()const{return mint(*this);};\n\
    \    constexpr mint inv()const{\n        int a=x,b=get_mod(),u=1,v=0,q=0;\n  \
    \      while(b>0){\n            q=a/b;\n            a-=q*b;\n            u-=q*v;\n\
    \            swap(a,b);\n            swap(u,v);\n        }\n        return mint(u);\n\
    \    }\n    constexpr int mul(int a,int b)const{return 1LL*a*b%get_mod();}\n \
    \   constexpr mint &operator+=(const mint &rhs){x=norm(x+rhs.x);return *this;}\n\
    \    constexpr mint &operator-=(const mint &rhs){x=norm(x-rhs.x);return *this;}\n\
    \    constexpr mint &operator*=(const mint &rhs){x=mul(x,rhs.x);return *this;}\n\
    \    constexpr mint &operator/=(const mint &rhs){x=mul(x,rhs.inv().x);return *this;}\n\
    \    constexpr mint &operator++(){return *this+=1;}\n    constexpr mint &operator--(){return\
    \ *this-=1;}\n    constexpr mint operator++(int){mint res=*this;*this+=1;return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=1;return res;}\n\
    \    friend constexpr mint operator+(mint lhs,const mint &rhs){return lhs+=rhs;}\n\
    \    friend constexpr mint operator-(mint lhs,const mint &rhs){return lhs-=rhs;}\n\
    \    friend constexpr mint operator*(mint lhs,const mint &rhs){return lhs*=rhs;}\n\
    \    friend constexpr mint operator/(mint lhs,const mint &rhs){return lhs/=rhs;}\n\
    \    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    \    friend constexpr bool operator==(const mint &lhs,const mint &rhs){return\
    \ lhs.x==rhs.x;}\n    friend constexpr bool operator!=(const mint &lhs,const mint\
    \ &rhs){return lhs.x!=rhs.x;}\n    friend constexpr bool operator<(const mint\
    \ &lhs,const mint &rhs){return lhs.x<rhs.x;} // for std::map\n};\nusing mint32\
    \ = ModInt<0>;\ntemplate<>\nint mint32::Mod=int(1e9)+7;\n\n"
  dependsOn: []
  isVerificationFile: false
  path: modular-arithmetic/modint.hpp
  requiredBy: []
  timestamp: '2024-06-13 00:00:26+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modular-arithmetic/modint.hpp
layout: document
redirect_from:
- /library/modular-arithmetic/modint.hpp
- /library/modular-arithmetic/modint.hpp.html
title: modular-arithmetic/modint.hpp
---
