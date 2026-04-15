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
  bundledCode: "#line 2 \"modular-arithmetic/dynamic-modint.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2026-04-15\n * Description: modular arithmetic operations\n\
    \ */\n\nstruct Barrett{\n    u32 _m;\n    u64 im;\n\n    explicit Barrett(u32\
    \ m):_m(m),im((u64)(-1)/m+1){}\n\n    u32 umod()const{return _m;}\n    u32 mul(u32\
    \ a,u32 b)const{\n        u64 z=a;\n        z*=b;\n        u64 x=(u64)(((unsigned\
    \ __int128)(z)*im)>>64);\n        u64 y=x*_m;\n        return (u32)(z-y+(z<y?_m:0));\n\
    \    }\n};\n\ntemplate<int id>\nstruct DynamicModInt{\n    using mint = DynamicModInt;\n\
    \n    u32 x;\n    static Barrett bt;\n\n    constexpr DynamicModInt():x(0){}\n\
    \    constexpr DynamicModInt(ll x):x((x%=get_mod())<0?x+get_mod():x){}\n    constexpr\
    \ explicit operator int()const{return (int)x;}\n    constexpr static u32 umod(){return\
    \ bt.umod();}\n    constexpr static int get_mod(){return (int)bt.umod();}\n  \
    \  static void set_mod(u32 m){\n        assert(m>=1);\n        bt=Barrett(m);\n\
    \    }\n    \n    constexpr mint operator-()const{\n        mint res;\n      \
    \  res.val=x?umod()-x:0;\n        return res;\n    }\n    constexpr mint operator+()const{return\
    \ *this;}\n\n    constexpr mint inv()const{\n        int a=x,b=get_mod(),u=1,v=0,q=0;\n\
    \        while(b>0){\n            q=a/b;\n            swap(a-=q*b,b);\n      \
    \      swap(u-=q*v,v);\n        }\n        return mint(u);\n    }\n    constexpr\
    \ mint pow(ll n)const{\n        mint res=1,a=*this;\n        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n\
    \        return res;\n    }\n    constexpr mint &operator+=(const mint &o){\n\
    \        if((x+=o.x)>=umod())x-=umod();\n        return *this;\n    }\n    constexpr\
    \ mint &operator-=(const mint &o){\n        if((x-=o.x)>=umod())x+=umod();\n \
    \       return *this;\n    }\n    constexpr mint &operator*=(const mint &o){\n\
    \        x=bt.mul(x,o.x);\n        return *this;\n    }\n    constexpr mint &operator/=(const\
    \ mint &o){\n        return *this*=o.inv();\n    }\n\n    constexpr mint operator+(const\
    \ mint &o)const{return mint(*this)+=o;}\n    constexpr mint operator-(const mint\
    \ &o)const{return mint(*this)-=o;}\n    constexpr mint operator*(const mint &o)const{return\
    \ mint(*this)*=o;}\n    constexpr mint operator/(const mint &o)const{return mint(*this)/=o;}\n\
    \n    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){mint\
    \ res=*this;*this+=mint(1);return res;}\n    constexpr mint operator--(int){mint\
    \ res=*this;*this-=mint(1);return res;}\n    \n    constexpr bool operator==(const\
    \ mint &o)const{return x==o.x;}\n    constexpr bool operator!=(const mint &o)const{return\
    \ x!=o.x;}\n    constexpr bool operator<(const mint &o)const{return x<o.x;}\n\
    \    \n    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    };\ntemplate<int id>\nBarrett DynamicModInt<id>::bt=Barrett(998244353);\nusing\
    \ dmint = DynamicModInt<0>;\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n * Description:\
    \ modular arithmetic operations\n */\n\nstruct Barrett{\n    u32 _m;\n    u64\
    \ im;\n\n    explicit Barrett(u32 m):_m(m),im((u64)(-1)/m+1){}\n\n    u32 umod()const{return\
    \ _m;}\n    u32 mul(u32 a,u32 b)const{\n        u64 z=a;\n        z*=b;\n    \
    \    u64 x=(u64)(((unsigned __int128)(z)*im)>>64);\n        u64 y=x*_m;\n    \
    \    return (u32)(z-y+(z<y?_m:0));\n    }\n};\n\ntemplate<int id>\nstruct DynamicModInt{\n\
    \    using mint = DynamicModInt;\n\n    u32 x;\n    static Barrett bt;\n\n   \
    \ constexpr DynamicModInt():x(0){}\n    constexpr DynamicModInt(ll x):x((x%=get_mod())<0?x+get_mod():x){}\n\
    \    constexpr explicit operator int()const{return (int)x;}\n    constexpr static\
    \ u32 umod(){return bt.umod();}\n    constexpr static int get_mod(){return (int)bt.umod();}\n\
    \    static void set_mod(u32 m){\n        assert(m>=1);\n        bt=Barrett(m);\n\
    \    }\n    \n    constexpr mint operator-()const{\n        mint res;\n      \
    \  res.val=x?umod()-x:0;\n        return res;\n    }\n    constexpr mint operator+()const{return\
    \ *this;}\n\n    constexpr mint inv()const{\n        int a=x,b=get_mod(),u=1,v=0,q=0;\n\
    \        while(b>0){\n            q=a/b;\n            swap(a-=q*b,b);\n      \
    \      swap(u-=q*v,v);\n        }\n        return mint(u);\n    }\n    constexpr\
    \ mint pow(ll n)const{\n        mint res=1,a=*this;\n        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n\
    \        return res;\n    }\n    constexpr mint &operator+=(const mint &o){\n\
    \        if((x+=o.x)>=umod())x-=umod();\n        return *this;\n    }\n    constexpr\
    \ mint &operator-=(const mint &o){\n        if((x-=o.x)>=umod())x+=umod();\n \
    \       return *this;\n    }\n    constexpr mint &operator*=(const mint &o){\n\
    \        x=bt.mul(x,o.x);\n        return *this;\n    }\n    constexpr mint &operator/=(const\
    \ mint &o){\n        return *this*=o.inv();\n    }\n\n    constexpr mint operator+(const\
    \ mint &o)const{return mint(*this)+=o;}\n    constexpr mint operator-(const mint\
    \ &o)const{return mint(*this)-=o;}\n    constexpr mint operator*(const mint &o)const{return\
    \ mint(*this)*=o;}\n    constexpr mint operator/(const mint &o)const{return mint(*this)/=o;}\n\
    \n    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){mint\
    \ res=*this;*this+=mint(1);return res;}\n    constexpr mint operator--(int){mint\
    \ res=*this;*this-=mint(1);return res;}\n    \n    constexpr bool operator==(const\
    \ mint &o)const{return x==o.x;}\n    constexpr bool operator!=(const mint &o)const{return\
    \ x!=o.x;}\n    constexpr bool operator<(const mint &o)const{return x<o.x;}\n\
    \    \n    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    };\ntemplate<int id>\nBarrett DynamicModInt<id>::bt=Barrett(998244353);\nusing\
    \ dmint = DynamicModInt<0>;"
  dependsOn: []
  isVerificationFile: false
  path: modular-arithmetic/dynamic-modint.hpp
  requiredBy: []
  timestamp: '2026-04-15 21:45:25+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modular-arithmetic/dynamic-modint.hpp
layout: document
redirect_from:
- /library/modular-arithmetic/dynamic-modint.hpp
- /library/modular-arithmetic/dynamic-modint.hpp.html
title: modular-arithmetic/dynamic-modint.hpp
---
