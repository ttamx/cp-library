---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/predecessor_problem.test.cpp
    title: verify/yosupo/data-structure/predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 3 \"data-structure/fast-set.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2026-04-16\n\
    \ * Description: Fast Set\n */\n\nstruct FastSet{\n    using u64 = uint64_t;\n\
    \n    int n,len;\n    vector<u64> t;\n\n    FastSet(){}\n    FastSet(int n){build(n);}\n\
    \n    int size(){return n;}\n    void build(int _n){\n        assert(_n>=0);\n\
    \        n=_n;\n        len=1;\n        while((len<<6)<n)len<<=6;\n        len/=63;\n\
    \        t.resize(len+(n+63)/64);\n    }\n\n    bool count(int i)const{\n    \
    \    assert(0<=i&&i<n);\n        return t[len+(i>>6)]>>(i&63)&1;\n    }\n    void\
    \ insert(int x){\n        assert(0<=x&&x<n);\n        int i=len+(x>>6),j=x&63;\n\
    \        while(true){\n            if(t[i]>>j&1ULL)return;\n            t[i]|=1ULL<<j;\n\
    \            if(!i)return;\n            j=(--i)&63;\n            i>>=6;\n    \
    \    }\n    }\n    void erase(int x){\n        assert(0<=x&&x<n);\n        int\
    \ i=len+(x>>6),j=x&63;\n        while(true){\n            t[i]&=~(1ULL<<j);\n\
    \            if(!i||t[i])return;\n            j=(--i)&63;\n            i>>=6;\n\
    \        }\n    }\n    int next(int x){\n        if(x>=n)return n;\n        if(x<0)x=0;\n\
    \        if(count(x))return x;\n        int i=len+(x>>6),j=x&63;\n        while(true){\n\
    \            if(t[i]&((~1ULL)<<j)){\n                j=__builtin_ctzll(t[i]&((~1ULL)<<j));\n\
    \                if(i>=len)return (i-len)*64+j;\n                break;\n    \
    \        }\n            if(!i)return n;\n            j=(--i)&63;\n           \
    \ i>>=6;\n        }\n        i=i*64+j+1;\n        while(i<len)i=i*64+__builtin_ctzll(t[i])+1;\n\
    \        return (i-len)*64+__builtin_ctzll(t[i]);\n    }\n    int prev(int x){\n\
    \        if(x<0)return -1;\n        if(x>=n)x=n-1;\n        if(count(x))return\
    \ x;\n        int i=len+(x>>6),j=x&63;\n        while(true){\n            if(t[i]&((1ULL<<j)-1ULL)){\n\
    \                j=63-__builtin_clzll(t[i]&((1ULL<<j)-1ULL));\n              \
    \  if(i>=len)return (i-len)*64+j;\n                break;\n            }\n   \
    \         if(!i)return -1;\n            j=(--i)&63;\n            i>>=6;\n    \
    \    }\n        i=i*64+j+1;\n        while(i<len)i=i*64+64-__builtin_clzll(t[i]);\n\
    \        return (i-len)*64+63-__builtin_clzll(t[i]);\n    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2026-04-16\n * Description: Fast Set\n */\n\nstruct FastSet{\n    using\
    \ u64 = uint64_t;\n\n    int n,len;\n    vector<u64> t;\n\n    FastSet(){}\n \
    \   FastSet(int n){build(n);}\n\n    int size(){return n;}\n    void build(int\
    \ _n){\n        assert(_n>=0);\n        n=_n;\n        len=1;\n        while((len<<6)<n)len<<=6;\n\
    \        len/=63;\n        t.resize(len+(n+63)/64);\n    }\n\n    bool count(int\
    \ i)const{\n        assert(0<=i&&i<n);\n        return t[len+(i>>6)]>>(i&63)&1;\n\
    \    }\n    void insert(int x){\n        assert(0<=x&&x<n);\n        int i=len+(x>>6),j=x&63;\n\
    \        while(true){\n            if(t[i]>>j&1ULL)return;\n            t[i]|=1ULL<<j;\n\
    \            if(!i)return;\n            j=(--i)&63;\n            i>>=6;\n    \
    \    }\n    }\n    void erase(int x){\n        assert(0<=x&&x<n);\n        int\
    \ i=len+(x>>6),j=x&63;\n        while(true){\n            t[i]&=~(1ULL<<j);\n\
    \            if(!i||t[i])return;\n            j=(--i)&63;\n            i>>=6;\n\
    \        }\n    }\n    int next(int x){\n        if(x>=n)return n;\n        if(x<0)x=0;\n\
    \        if(count(x))return x;\n        int i=len+(x>>6),j=x&63;\n        while(true){\n\
    \            if(t[i]&((~1ULL)<<j)){\n                j=__builtin_ctzll(t[i]&((~1ULL)<<j));\n\
    \                if(i>=len)return (i-len)*64+j;\n                break;\n    \
    \        }\n            if(!i)return n;\n            j=(--i)&63;\n           \
    \ i>>=6;\n        }\n        i=i*64+j+1;\n        while(i<len)i=i*64+__builtin_ctzll(t[i])+1;\n\
    \        return (i-len)*64+__builtin_ctzll(t[i]);\n    }\n    int prev(int x){\n\
    \        if(x<0)return -1;\n        if(x>=n)x=n-1;\n        if(count(x))return\
    \ x;\n        int i=len+(x>>6),j=x&63;\n        while(true){\n            if(t[i]&((1ULL<<j)-1ULL)){\n\
    \                j=63-__builtin_clzll(t[i]&((1ULL<<j)-1ULL));\n              \
    \  if(i>=len)return (i-len)*64+j;\n                break;\n            }\n   \
    \         if(!i)return -1;\n            j=(--i)&63;\n            i>>=6;\n    \
    \    }\n        i=i*64+j+1;\n        while(i<len)i=i*64+64-__builtin_clzll(t[i]);\n\
    \        return (i-len)*64+63-__builtin_clzll(t[i]);\n    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data-structure/fast-set.hpp
  requiredBy: []
  timestamp: '2026-04-16 02:00:18+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/predecessor_problem.test.cpp
documentation_of: data-structure/fast-set.hpp
layout: document
redirect_from:
- /library/data-structure/fast-set.hpp
- /library/data-structure/fast-set.hpp.html
title: data-structure/fast-set.hpp
---
