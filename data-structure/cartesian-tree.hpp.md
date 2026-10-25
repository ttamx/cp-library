---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/cartesian-tree/cartesian_tree.test.cpp
    title: verify/yosupo/data-structure/cartesian-tree/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SZ(a) (int)(a.size())\n#define SORT(a)\
    \ sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
    #define UNI(a) a.erase(unique(ALL(a)),a.end())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define FIND(a,x) (int)(find(ALL(a),x)-a.begin())\n\
    #define COUNT(a,x) (int)count(ALL(a),x)\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\ntemplate<class T,class U>\nbool chmin(T\
    \ &a,U b){return b<a?a=b,1:0;}\ntemplate<class T,class U>\nbool chmax(T &a,U b){return\
    \ a<b?a=b,1:0;}\n\ntemplate<class T>\nT floor(T a,T b){return a/b-((a^b)<0&&a%b);}\n\
    template<class T>\nT ceil(T a,T b){return a/b+((a^b)>=0&&a%b);}\n\nint popcnt(ll\
    \ x){return __builtin_popcountll(x);}\nint topbit(ll x){return x==0?-1:63-__builtin_clzll(x);}\n\
    int lowbit(ll x){return x==0?-1:__builtin_ctzll(x);}\n\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\ntemplate<class T>\nvector<int>\
    \ argsort(const vector<T> &a){\n    vector<int> p(SZ(a));\n    iota(ALL(p),0);\n\
    \    stable_sort(ALL(p),[&](int i,int j){return a[i]<a[j];});\n    return p;\n\
    }\n#line 3 \"data-structure/cartesian-tree.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2025-10-12\n * Description: Cartesian Tree.\n */\n\ntemplate<class T,bool\
    \ IS_MIN>\nstruct CartesianTree{\n    int n;\n    vector<T> &a;\n    vector<pair<int,int>>\
    \ range;\n    vector<int> lch,rch,par;\n    int root;\n\n    CartesianTree(vector<T>\
    \ &_a):n((int)_a.size()),a(_a){\n        range.assign(n,{-1,-1});\n        lch=rch=par=vector<int>(n,-1);\n\
    \        auto cmp=[&](int i,int j)->bool {\n            if(IS_MIN)return a[i]<a[j]||(a[i]==a[j]&&i<j);\n\
    \            return a[i]>a[j]||(a[i]==a[j]&&i<j);\n        };\n        vector<int>\
    \ st;\n        for(int i=0;i<n;i++){\n            while(!st.empty()&&cmp(i,st.back())){\n\
    \                lch[i]=st.back();\n                st.pop_back();\n         \
    \   }\n            range[i].first=(st.empty()?-1:st.back())+1;\n            st.emplace_back(i);\n\
    \        }\n        st.clear();\n        for(int i=n-1;i>=0;i--){\n          \
    \  while(!st.empty()&&cmp(i,st.back())){\n                rch[i]=st.back();\n\
    \                st.pop_back();\n            }\n            range[i].second=(st.empty()?n:st.back())-1;\n\
    \            st.emplace_back(i);\n        }\n        for(int i=0;i<n;i++)if(lch[i]!=-1)par[lch[i]]=i;\n\
    \        for(int i=0;i<n;i++)if(rch[i]!=-1)par[rch[i]]=i;\n        for(int i=0;i<n;i++)if(par[i]==-1)root=i;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2025-10-12\n * Description: Cartesian Tree.\n */\n\ntemplate<class T,bool\
    \ IS_MIN>\nstruct CartesianTree{\n    int n;\n    vector<T> &a;\n    vector<pair<int,int>>\
    \ range;\n    vector<int> lch,rch,par;\n    int root;\n\n    CartesianTree(vector<T>\
    \ &_a):n((int)_a.size()),a(_a){\n        range.assign(n,{-1,-1});\n        lch=rch=par=vector<int>(n,-1);\n\
    \        auto cmp=[&](int i,int j)->bool {\n            if(IS_MIN)return a[i]<a[j]||(a[i]==a[j]&&i<j);\n\
    \            return a[i]>a[j]||(a[i]==a[j]&&i<j);\n        };\n        vector<int>\
    \ st;\n        for(int i=0;i<n;i++){\n            while(!st.empty()&&cmp(i,st.back())){\n\
    \                lch[i]=st.back();\n                st.pop_back();\n         \
    \   }\n            range[i].first=(st.empty()?-1:st.back())+1;\n            st.emplace_back(i);\n\
    \        }\n        st.clear();\n        for(int i=n-1;i>=0;i--){\n          \
    \  while(!st.empty()&&cmp(i,st.back())){\n                rch[i]=st.back();\n\
    \                st.pop_back();\n            }\n            range[i].second=(st.empty()?n:st.back())-1;\n\
    \            st.emplace_back(i);\n        }\n        for(int i=0;i<n;i++)if(lch[i]!=-1)par[lch[i]]=i;\n\
    \        for(int i=0;i<n;i++)if(rch[i]!=-1)par[rch[i]]=i;\n        for(int i=0;i<n;i++)if(par[i]==-1)root=i;\n\
    \    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data-structure/cartesian-tree.hpp
  requiredBy: []
  timestamp: '2026-10-25 14:43:57+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/cartesian-tree/cartesian_tree.test.cpp
documentation_of: data-structure/cartesian-tree.hpp
layout: document
redirect_from:
- /library/data-structure/cartesian-tree.hpp
- /library/data-structure/cartesian-tree.hpp.html
title: data-structure/cartesian-tree.hpp
---
