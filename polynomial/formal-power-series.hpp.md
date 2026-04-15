---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modular-arithmetic/binpow.hpp
    title: modular-arithmetic/binpow.hpp
  - icon: ':question:'
    path: polynomial/ntt.hpp
    title: polynomial/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modular-arithmetic/binpow.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-01-15\n * Description: n-th power using divide and conquer\n\
    \ * Time: $O(\\log b)$\n */\n\ntemplate<class T>\nconstexpr T binpow(T a,ll b){\n\
    \    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n    return res;\n}\n\n\
    #line 3 \"polynomial/ntt.hpp\"\n\n/**\n * Author: Teetat T.\n * Description: Number\
    \ Theoretic Transform\n * Time: $O(N \\log N)$\n */\n\ntemplate<class mint>\n\
    struct NTT{\n\tusing vm = vector<mint>;\n\t\n\tstatic constexpr mint root=mint::get_root();\n\
    \    static_assert(root!=0, \"root must be nonzero\");\n\n\tstatic void ntt(vm\
    \ &a){\n\t\tint n=a.size(),L=31-__builtin_clz(n);\n\t\tvm rt(n);\n\t\trt[1]=1;\n\
    \t\tfor(int k=2,s=2;k<n;k*=2,s++){\n\t\t\tmint z[]={1,binpow(root,MOD>>s)};\n\t\
    \t\tfor(int i=k;i<2*k;i++)rt[i]=rt[i/2]*z[i&1];\n\t\t}\n\t\tvector<int> rev(n);\n\
    \t\tfor(int i=1;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<L)/2;\n\t\tfor(int i=1;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);\n\
    \t\tfor(int k=1;k<n;k*=2)for(int i=0;i<n;i+=2*k)for(int j=0;j<k;j++){\n\t\t\t\
    mint z=rt[j+k]*a[i+j+k];\n\t\t\ta[i+j+k]=a[i+j]-z;\n\t\t\ta[i+j]+=z;\n\t\t}\n\t\
    }\n\tstatic vm conv(const vm &a,const vm &b){\n\t\tif(a.empty()||b.empty())return\
    \ {};\n\t\tint s=a.size()+b.size()-1,n=1<<(32-__builtin_clz(s));\n\t\tmint inv=mint(n).inv();\n\
    \t\tvm in1(a),in2(b),out(n);\n\t\tin1.resize(n),in2.resize(n);\n\t\tntt(in1),ntt(in2);\n\
    \t\tfor(int i=0;i<n;i++)out[-i&(n-1)]=in1[i]*in2[i]*inv;\n\t\tntt(out);\n\t\t\
    return vm(out.begin(),out.begin()+s);\n\t}\n\tvm operator()(const vm &a,const\
    \ vm &b){\n\t\treturn conv(a,b);\n\t}\n};\n\n#line 3 \"polynomial/formal-power-series.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description: basic operations\
    \ of formal power series\n */\n\ntemplate<class mint>\nstruct FormalPowerSeries:vector<mint>{\n\
    \    using vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n\n    FPS\
    \ &operator+=(const FPS &rhs){\n        if(rhs.size()>this->size())this->resize(rhs.size());\n\
    \        for(int i=0;i<rhs.size();i++)(*this)[i]+=rhs[i];\n        return *this;\n\
    \    }\n    FPS &operator+=(const mint &rhs){\n        if(this->empty())this->resize(1);\n\
    \        (*this)[0]+=rhs;\n        return *this;\n    }\n    FPS &operator-=(const\
    \ FPS &rhs){\n        if(rhs.size()>this->size())this->resize(rhs.size());\n \
    \       for(int i=0;i<rhs.size();i++)(*this)[i]-=rhs[i];\n        return *this;\n\
    \    }\n    FPS &operator-=(const mint &rhs){\n        if(this->empty())this->resize(1);\n\
    \        (*this)[0]-=rhs;\n        return *this;\n    }\n    FPS &operator*=(const\
    \ FPS &rhs){\n        auto res=NTT<mint>()(*this,rhs);\n        return *this=FPS(res.begin(),res.end());\n\
    \    }\n    FPS &operator*=(const mint &rhs){\n        for(auto &a:*this)a*=rhs;\n\
    \        return *this;\n    }\n    friend FPS operator+(FPS lhs,const FPS &rhs){return\
    \ lhs+=rhs;}\n    friend FPS operator+(FPS lhs,const mint &rhs){return lhs+=rhs;}\n\
    \    friend FPS operator+(const mint &lhs,FPS &rhs){return rhs+=lhs;}\n    friend\
    \ FPS operator-(FPS lhs,const FPS &rhs){return lhs-=rhs;}\n    friend FPS operator-(FPS\
    \ lhs,const mint &rhs){return lhs-=rhs;}\n    friend FPS operator-(const mint\
    \ &lhs,FPS rhs){return -(rhs-lhs);}\n    friend FPS operator*(FPS lhs,const FPS\
    \ &rhs){return lhs*=rhs;}\n    friend FPS operator*(FPS lhs,const mint &rhs){return\
    \ lhs*=rhs;}\n    friend FPS operator*(const mint &lhs,FPS rhs){return rhs*=lhs;}\n\
    \    \n    FPS operator-(){return (*this)*-1;}\n\n    FPS rev(){\n        FPS\
    \ res(*this);\n        reverse(res.beign(),res.end());\n        return res;\n\
    \    }\n    FPS pre(int sz){\n        FPS res(this->begin(),this->begin()+min((int)this->size(),sz));\n\
    \        if(res.size()<sz)res.resize(sz);\n        return res;\n    }\n    FPS\
    \ shrink(){\n        FPS res(*this);\n        while(!res.empty()&&res.back()==mint{})res.pop_back();\n\
    \        return res;\n    }\n    FPS operator>>(int sz){\n        if(this->size()<=sz)return\
    \ {};\n        FPS res(*this);\n        res.erase(res.begin(),res.begin()+sz);\n\
    \        return res;\n    }\n    FPS operator<<(int sz){\n        FPS res(*this);\n\
    \        res.insert(res.begin(),sz,mint{});\n        return res;\n    }\n    FPS\
    \ diff(){\n        const int n=this->size();\n        FPS res(max(0,n-1));\n \
    \       for(int i=1;i<n;i++)res[i-1]=(*this)[i]*mint(i);\n        return res;\n\
    \    }\n    FPS integral(){\n        const int n=this->size();\n        FPS res(n+1);\n\
    \        res[0]=0;\n        if(n>0)res[1]=1;\n        ll mod=mint::get_mod();\n\
    \        for(int i=2;i<=n;i++)res[i]=(-res[mod%i])*(mod/i);\n        for(int i=0;i<n;i++)res[i+1]*=(*this)[i];\n\
    \        return res;\n    }\n    mint eval(const mint &x){\n        mint res=0,w=1;\n\
    \        for(auto &a:*this)res+=a*w,w*=x;\n        return res;\n    }\n\n    FPS\
    \ inv(int deg=-1){\n        assert(!this->empty()&&(*this)[0]!=mint(0));\n   \
    \     if(deg==-1)deg=this->size();\n        FPS res{mint(1)/(*this)[0]};\n   \
    \     for(int i=2;i>>1<deg;i<<=1){\n            res=(res*(mint(2)-res*pre(i))).pre(i);\n\
    \        }\n        return res.pre(deg);\n    }\n    FPS log(int deg=-1){\n  \
    \      assert(!this->empty()&&(*this)[0]==mint(1));\n        if(deg==-1)deg=this->size();\n\
    \        return (pre(deg).diff()*inv(deg)).pre(deg-1).integral();\n    }\n   \
    \ FPS exp(int deg=-1){\n        assert(this->empty()||(*this)[0]==mint(0));\n\
    \        if(deg==-1)deg=this->size();\n        FPS res{mint(1)};\n        for(int\
    \ i=2;i>>1<deg;i<<=1){\n            res=(res*(pre(i)-res.log(i)+mint(1))).pre(i);\n\
    \        }\n        return res.pre(deg);\n    }\n    FPS pow(ll k,int deg=-1){\n\
    \        const int n=this->size();\n        if(deg==-1)deg=n;\n        if(k==0){\n\
    \            FPS res(deg);\n            if(deg)res[0]=mint(1);\n            return\
    \ res;\n        }\n        for(int i=0;i<n;i++){\n            if(__int128_t(i)*k>=deg)return\
    \ FPS(deg,mint(0));\n            if((*this)[i]==mint(0))continue;\n          \
    \  mint rev=mint(1)/(*this)[i];\n            FPS res=(((*this*rev)>>i).log(deg)*k).exp(deg);\n\
    \            res=((res*binpow((*this)[i],k))<<(i*k)).pre(deg);\n            return\
    \ res;\n        }\n        return FPS(deg,mint(0));\n    }\n};\n"
  code: "#pragma once\n#include \"polynomial/ntt.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-03-17\n * Description: basic operations of formal power series\n\
    \ */\n\ntemplate<class mint>\nstruct FormalPowerSeries:vector<mint>{\n    using\
    \ vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n\n    FPS &operator+=(const\
    \ FPS &rhs){\n        if(rhs.size()>this->size())this->resize(rhs.size());\n \
    \       for(int i=0;i<rhs.size();i++)(*this)[i]+=rhs[i];\n        return *this;\n\
    \    }\n    FPS &operator+=(const mint &rhs){\n        if(this->empty())this->resize(1);\n\
    \        (*this)[0]+=rhs;\n        return *this;\n    }\n    FPS &operator-=(const\
    \ FPS &rhs){\n        if(rhs.size()>this->size())this->resize(rhs.size());\n \
    \       for(int i=0;i<rhs.size();i++)(*this)[i]-=rhs[i];\n        return *this;\n\
    \    }\n    FPS &operator-=(const mint &rhs){\n        if(this->empty())this->resize(1);\n\
    \        (*this)[0]-=rhs;\n        return *this;\n    }\n    FPS &operator*=(const\
    \ FPS &rhs){\n        auto res=NTT<mint>()(*this,rhs);\n        return *this=FPS(res.begin(),res.end());\n\
    \    }\n    FPS &operator*=(const mint &rhs){\n        for(auto &a:*this)a*=rhs;\n\
    \        return *this;\n    }\n    friend FPS operator+(FPS lhs,const FPS &rhs){return\
    \ lhs+=rhs;}\n    friend FPS operator+(FPS lhs,const mint &rhs){return lhs+=rhs;}\n\
    \    friend FPS operator+(const mint &lhs,FPS &rhs){return rhs+=lhs;}\n    friend\
    \ FPS operator-(FPS lhs,const FPS &rhs){return lhs-=rhs;}\n    friend FPS operator-(FPS\
    \ lhs,const mint &rhs){return lhs-=rhs;}\n    friend FPS operator-(const mint\
    \ &lhs,FPS rhs){return -(rhs-lhs);}\n    friend FPS operator*(FPS lhs,const FPS\
    \ &rhs){return lhs*=rhs;}\n    friend FPS operator*(FPS lhs,const mint &rhs){return\
    \ lhs*=rhs;}\n    friend FPS operator*(const mint &lhs,FPS rhs){return rhs*=lhs;}\n\
    \    \n    FPS operator-(){return (*this)*-1;}\n\n    FPS rev(){\n        FPS\
    \ res(*this);\n        reverse(res.beign(),res.end());\n        return res;\n\
    \    }\n    FPS pre(int sz){\n        FPS res(this->begin(),this->begin()+min((int)this->size(),sz));\n\
    \        if(res.size()<sz)res.resize(sz);\n        return res;\n    }\n    FPS\
    \ shrink(){\n        FPS res(*this);\n        while(!res.empty()&&res.back()==mint{})res.pop_back();\n\
    \        return res;\n    }\n    FPS operator>>(int sz){\n        if(this->size()<=sz)return\
    \ {};\n        FPS res(*this);\n        res.erase(res.begin(),res.begin()+sz);\n\
    \        return res;\n    }\n    FPS operator<<(int sz){\n        FPS res(*this);\n\
    \        res.insert(res.begin(),sz,mint{});\n        return res;\n    }\n    FPS\
    \ diff(){\n        const int n=this->size();\n        FPS res(max(0,n-1));\n \
    \       for(int i=1;i<n;i++)res[i-1]=(*this)[i]*mint(i);\n        return res;\n\
    \    }\n    FPS integral(){\n        const int n=this->size();\n        FPS res(n+1);\n\
    \        res[0]=0;\n        if(n>0)res[1]=1;\n        ll mod=mint::get_mod();\n\
    \        for(int i=2;i<=n;i++)res[i]=(-res[mod%i])*(mod/i);\n        for(int i=0;i<n;i++)res[i+1]*=(*this)[i];\n\
    \        return res;\n    }\n    mint eval(const mint &x){\n        mint res=0,w=1;\n\
    \        for(auto &a:*this)res+=a*w,w*=x;\n        return res;\n    }\n\n    FPS\
    \ inv(int deg=-1){\n        assert(!this->empty()&&(*this)[0]!=mint(0));\n   \
    \     if(deg==-1)deg=this->size();\n        FPS res{mint(1)/(*this)[0]};\n   \
    \     for(int i=2;i>>1<deg;i<<=1){\n            res=(res*(mint(2)-res*pre(i))).pre(i);\n\
    \        }\n        return res.pre(deg);\n    }\n    FPS log(int deg=-1){\n  \
    \      assert(!this->empty()&&(*this)[0]==mint(1));\n        if(deg==-1)deg=this->size();\n\
    \        return (pre(deg).diff()*inv(deg)).pre(deg-1).integral();\n    }\n   \
    \ FPS exp(int deg=-1){\n        assert(this->empty()||(*this)[0]==mint(0));\n\
    \        if(deg==-1)deg=this->size();\n        FPS res{mint(1)};\n        for(int\
    \ i=2;i>>1<deg;i<<=1){\n            res=(res*(pre(i)-res.log(i)+mint(1))).pre(i);\n\
    \        }\n        return res.pre(deg);\n    }\n    FPS pow(ll k,int deg=-1){\n\
    \        const int n=this->size();\n        if(deg==-1)deg=n;\n        if(k==0){\n\
    \            FPS res(deg);\n            if(deg)res[0]=mint(1);\n            return\
    \ res;\n        }\n        for(int i=0;i<n;i++){\n            if(__int128_t(i)*k>=deg)return\
    \ FPS(deg,mint(0));\n            if((*this)[i]==mint(0))continue;\n          \
    \  mint rev=mint(1)/(*this)[i];\n            FPS res=(((*this*rev)>>i).log(deg)*k).exp(deg);\n\
    \            res=((res*binpow((*this)[i],k))<<(i*k)).pre(deg);\n            return\
    \ res;\n        }\n        return FPS(deg,mint(0));\n    }\n};"
  dependsOn:
  - polynomial/ntt.hpp
  - modular-arithmetic/binpow.hpp
  isVerificationFile: false
  path: polynomial/formal-power-series.hpp
  requiredBy: []
  timestamp: '2026-04-15 21:45:25+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/polynomial/exp_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/log_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/inv_of_formal_power_series.test.cpp
documentation_of: polynomial/formal-power-series.hpp
layout: document
redirect_from:
- /library/polynomial/formal-power-series.hpp
- /library/polynomial/formal-power-series.hpp.html
title: polynomial/formal-power-series.hpp
---
