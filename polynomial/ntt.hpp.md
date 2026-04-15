---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modular-arithmetic/binpow.hpp
    title: modular-arithmetic/binpow.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: polynomial/formal-power-series.hpp
    title: polynomial/formal-power-series.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/convolution_mod.test.cpp
    title: verify/yosupo/convolution/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
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
    \ vm &b){\n\t\treturn conv(a,b);\n\t}\n};\n\n"
  code: "#pragma once\n#include \"modular-arithmetic/binpow.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Number Theoretic Transform\n * Time: $O(N \\log N)$\n\
    \ */\n\ntemplate<class mint>\nstruct NTT{\n\tusing vm = vector<mint>;\n\t\n\t\
    static constexpr mint root=mint::get_root();\n    static_assert(root!=0, \"root\
    \ must be nonzero\");\n\n\tstatic void ntt(vm &a){\n\t\tint n=a.size(),L=31-__builtin_clz(n);\n\
    \t\tvm rt(n);\n\t\trt[1]=1;\n\t\tfor(int k=2,s=2;k<n;k*=2,s++){\n\t\t\tmint z[]={1,binpow(root,MOD>>s)};\n\
    \t\t\tfor(int i=k;i<2*k;i++)rt[i]=rt[i/2]*z[i&1];\n\t\t}\n\t\tvector<int> rev(n);\n\
    \t\tfor(int i=1;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<L)/2;\n\t\tfor(int i=1;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);\n\
    \t\tfor(int k=1;k<n;k*=2)for(int i=0;i<n;i+=2*k)for(int j=0;j<k;j++){\n\t\t\t\
    mint z=rt[j+k]*a[i+j+k];\n\t\t\ta[i+j+k]=a[i+j]-z;\n\t\t\ta[i+j]+=z;\n\t\t}\n\t\
    }\n\tstatic vm conv(const vm &a,const vm &b){\n\t\tif(a.empty()||b.empty())return\
    \ {};\n\t\tint s=a.size()+b.size()-1,n=1<<(32-__builtin_clz(s));\n\t\tmint inv=mint(n).inv();\n\
    \t\tvm in1(a),in2(b),out(n);\n\t\tin1.resize(n),in2.resize(n);\n\t\tntt(in1),ntt(in2);\n\
    \t\tfor(int i=0;i<n;i++)out[-i&(n-1)]=in1[i]*in2[i]*inv;\n\t\tntt(out);\n\t\t\
    return vm(out.begin(),out.begin()+s);\n\t}\n\tvm operator()(const vm &a,const\
    \ vm &b){\n\t\treturn conv(a,b);\n\t}\n};\n\n"
  dependsOn:
  - modular-arithmetic/binpow.hpp
  isVerificationFile: false
  path: polynomial/ntt.hpp
  requiredBy:
  - polynomial/formal-power-series.hpp
  timestamp: '2026-04-15 21:45:25+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/polynomial/exp_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/log_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
  - verify/yosupo/polynomial/inv_of_formal_power_series.test.cpp
  - verify/yosupo/convolution/convolution_mod.test.cpp
documentation_of: polynomial/ntt.hpp
layout: document
redirect_from:
- /library/polynomial/ntt.hpp
- /library/polynomial/ntt.hpp.html
title: polynomial/ntt.hpp
---
