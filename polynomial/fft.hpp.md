---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/convolution_mod_1000000007.test.cpp
    title: verify/yosupo/convolution/convolution_mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/fft.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-03-17\n * Description: Fast Fourier Transform\n * Time: $O(N \\log N)$\n\
    \ */\n\ntemplate<class T=ll,int mod=0>\nstruct FFT{\n\tusing vt = vector<T>;\n\
    \tusing cd = complex<db>;\n\tusing vc = vector<cd>;\n\t\n\tstatic const bool INT=true;\n\
    \n\tstatic void fft(vc &a){\n\t\tint n=a.size(),L=31-__builtin_clz(n);\n\t\tvc\
    \ rt(n);\n\t\trt[1]=1;\n\t\tfor(int k=2;k<n;k*=2){\n\t\t\tcd z=polar(db(1),PI/k);\n\
    \t\t\tfor(int i=k;i<2*k;i++)rt[i]=i&1?rt[i/2]*z:rt[i/2];\n\t\t}\n\t\tvector<int>\
    \ rev(n);\n\t\tfor(int i=1;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<L)/2;\n\t\tfor(int\
    \ i=1;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);\n\t\tfor(int k=1;k<n;k*=2)for(int\
    \ i=0;i<n;i+=2*k)for(int j=0;j<k;j++){\n\t\t\tcd z=rt[j+k]*a[i+j+k];\n\t\t\ta[i+j+k]=a[i+j]-z;\n\
    \t\t\ta[i+j]+=z;\n\t\t}\n\t}\n\ttemplate<class U>\n\tstatic db norm(const U &x){\n\
    \t\treturn INT?round(x):x;\n\t}\n\tstatic vt conv(const vt &a,const vt &b){\n\t\
    \tif(a.empty()||b.empty())return {};\n\t\tvt res(a.size()+b.size()-1);\n\t\tint\
    \ L=32-__builtin_clz(res.size()),n=1<<L;\n\t\tvc in(n),out(n);\n\t\tcopy(a.begin(),a.end(),in.begin());\n\
    \t\tfor(int i=0;i<b.size();i++)in[i].imag(b[i]);\n\t\tfft(in);\n\t\tfor(auto &x:in)x*=x;\n\
    \t\tfor(int i=0;i<n;i++)out[i]=in[-i&(n-1)]-conj(in[i]);\n\t\tfft(out);\n\t\t\
    for(int i=0;i<res.size();i++)res[i]=norm(imag(out[i])/(4*n));\n\t\treturn res;\n\
    \t}\n\tstatic vt convMod(const vt &a,const vt &b){\n\t\tassert(mod>0);\n\t\tif(a.empty()||b.empty())return\
    \ {};\n\t\tvt res(a.size()+b.size()-1);\n\t\tint L=32-__builtin_clz(res.size()),n=1<<L;\n\
    \t\tll cut=int(sqrt(mod));\n\t\tvc in1(n),in2(n),out1(n),out2(n);\n\t\tfor(int\
    \ i=0;i<a.size();i++)in1[i]=cd(ll(a[i])/cut,ll(a[i])%cut); // a1 + i * a2\n\t\t\
    for(int i=0;i<b.size();i++)in2[i]=cd(ll(b[i])/cut,ll(b[i])%cut); // b1 + i * b2\n\
    \t\tfft(in1),fft(in2);\n\t\tfor(int i=0;i<n;i++){\n\t\t\tint j=-i&(n-1);\n\t\t\
    \tout1[j]=(in1[i]+conj(in1[j]))*in2[i]/(2.l*n); // f1 * (g1 + i * g2) = f1 * g1\
    \ + i f1 * g2\n\t\t\tout2[j]=(in1[i]-conj(in1[j]))*in2[i]/cd(0.l,2.l*n); // f2\
    \ * (g1 + i * g2) = f2 * g1 + i f2 * g2\n\t\t}\n\t\tfft(out1),fft(out2);\n\t\t\
    for(int i=0;i<res.size();i++){\n\t\t\tll x=round(real(out1[i])),y=round(imag(out1[i]))+round(real(out2[i])),z=round(imag(out2[i]));\n\
    \t\t\tres[i]=((x%mod*cut+y)%mod*cut+z)%mod; // a1 * b1 * cut^2 + (a1 * b2 + a2\
    \ * b1) * cut + a2 * b2\n\t\t}\n\t\treturn res;\n\t}\n\tvt operator()(const vt\
    \ &a,const vt &b){\n\t\treturn mod>0?convMod(a,b):conv(a,b);\n\t}\n};\ntemplate<>\n\
    struct FFT<db>{\n\tstatic const bool INT=false;\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description:\
    \ Fast Fourier Transform\n * Time: $O(N \\log N)$\n */\n\ntemplate<class T=ll,int\
    \ mod=0>\nstruct FFT{\n\tusing vt = vector<T>;\n\tusing cd = complex<db>;\n\t\
    using vc = vector<cd>;\n\t\n\tstatic const bool INT=true;\n\n\tstatic void fft(vc\
    \ &a){\n\t\tint n=a.size(),L=31-__builtin_clz(n);\n\t\tvc rt(n);\n\t\trt[1]=1;\n\
    \t\tfor(int k=2;k<n;k*=2){\n\t\t\tcd z=polar(db(1),PI/k);\n\t\t\tfor(int i=k;i<2*k;i++)rt[i]=i&1?rt[i/2]*z:rt[i/2];\n\
    \t\t}\n\t\tvector<int> rev(n);\n\t\tfor(int i=1;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<L)/2;\n\
    \t\tfor(int i=1;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);\n\t\tfor(int k=1;k<n;k*=2)for(int\
    \ i=0;i<n;i+=2*k)for(int j=0;j<k;j++){\n\t\t\tcd z=rt[j+k]*a[i+j+k];\n\t\t\ta[i+j+k]=a[i+j]-z;\n\
    \t\t\ta[i+j]+=z;\n\t\t}\n\t}\n\ttemplate<class U>\n\tstatic db norm(const U &x){\n\
    \t\treturn INT?round(x):x;\n\t}\n\tstatic vt conv(const vt &a,const vt &b){\n\t\
    \tif(a.empty()||b.empty())return {};\n\t\tvt res(a.size()+b.size()-1);\n\t\tint\
    \ L=32-__builtin_clz(res.size()),n=1<<L;\n\t\tvc in(n),out(n);\n\t\tcopy(a.begin(),a.end(),in.begin());\n\
    \t\tfor(int i=0;i<b.size();i++)in[i].imag(b[i]);\n\t\tfft(in);\n\t\tfor(auto &x:in)x*=x;\n\
    \t\tfor(int i=0;i<n;i++)out[i]=in[-i&(n-1)]-conj(in[i]);\n\t\tfft(out);\n\t\t\
    for(int i=0;i<res.size();i++)res[i]=norm(imag(out[i])/(4*n));\n\t\treturn res;\n\
    \t}\n\tstatic vt convMod(const vt &a,const vt &b){\n\t\tassert(mod>0);\n\t\tif(a.empty()||b.empty())return\
    \ {};\n\t\tvt res(a.size()+b.size()-1);\n\t\tint L=32-__builtin_clz(res.size()),n=1<<L;\n\
    \t\tll cut=int(sqrt(mod));\n\t\tvc in1(n),in2(n),out1(n),out2(n);\n\t\tfor(int\
    \ i=0;i<a.size();i++)in1[i]=cd(ll(a[i])/cut,ll(a[i])%cut); // a1 + i * a2\n\t\t\
    for(int i=0;i<b.size();i++)in2[i]=cd(ll(b[i])/cut,ll(b[i])%cut); // b1 + i * b2\n\
    \t\tfft(in1),fft(in2);\n\t\tfor(int i=0;i<n;i++){\n\t\t\tint j=-i&(n-1);\n\t\t\
    \tout1[j]=(in1[i]+conj(in1[j]))*in2[i]/(2.l*n); // f1 * (g1 + i * g2) = f1 * g1\
    \ + i f1 * g2\n\t\t\tout2[j]=(in1[i]-conj(in1[j]))*in2[i]/cd(0.l,2.l*n); // f2\
    \ * (g1 + i * g2) = f2 * g1 + i f2 * g2\n\t\t}\n\t\tfft(out1),fft(out2);\n\t\t\
    for(int i=0;i<res.size();i++){\n\t\t\tll x=round(real(out1[i])),y=round(imag(out1[i]))+round(real(out2[i])),z=round(imag(out2[i]));\n\
    \t\t\tres[i]=((x%mod*cut+y)%mod*cut+z)%mod; // a1 * b1 * cut^2 + (a1 * b2 + a2\
    \ * b1) * cut + a2 * b2\n\t\t}\n\t\treturn res;\n\t}\n\tvt operator()(const vt\
    \ &a,const vt &b){\n\t\treturn mod>0?convMod(a,b):conv(a,b);\n\t}\n};\ntemplate<>\n\
    struct FFT<db>{\n\tstatic const bool INT=false;\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/fft.hpp
  requiredBy: []
  timestamp: '2026-04-04 10:38:14+05:30'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/convolution/convolution_mod_1000000007.test.cpp
documentation_of: polynomial/fft.hpp
layout: document
redirect_from:
- /library/polynomial/fft.hpp
- /library/polynomial/fft.hpp.html
title: polynomial/fft.hpp
---
