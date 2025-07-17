---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/tree/cartesian_tree.test.cpp
    title: verify/yosupo/tree/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\nusing\
    \ vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst\
    \ int MOD=998244353;\nconst int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    template<class T>\nusing ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 3 \"data-structure/cartesian-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2025-02-20\n * Description: Cartesian\
    \ Tree.\n */\n\ntemplate<class T,bool IS_MIN>\nstruct CartesianTree{\n    int\
    \ n;\n    vector<T> &a;\n    vector<pair<int,int>> range;\n    vector<int> lch,rch,par;\n\
    \    int root;\n\n    CartesianTree(vector<T> &_a):n((int)_a.size()),a(_a){\n\
    \        range.assign(n,{-1,-1});\n        lch=rch=par=vector<int>(n,-1);\n  \
    \      if(n==1){\n            range[0]={0,1};\n            root=0;\n         \
    \   return;\n        }\n        auto cmp=[&](int i,int j)->bool {\n          \
    \  if(IS_MIN)a[i]>a[j]||(a[i]==a[j]&&i<j);\n            return a[i]<a[j]||(a[i]==a[j]&&i<j);\n\
    \        };\n        vector<int> st;\n        for(int i=0;i<n;i++){\n        \
    \    while(!st.empty()&&cmp(i,st.back())){\n                lch[i]=st.back();\n\
    \                st.pop_back();\n            }\n            range[i].first=(st.empty()?-1:st.back())+1;\n\
    \            st.emplace_back(i);\n        }\n        for(int i=n-1;i>=0;i--){\n\
    \            while(!st.empty()&&cmp(i,st.back())){\n                rch[i]=st.back();\n\
    \                st.pop_back();\n            }\n            range[i].second=(st.empty()?n:st.back())-1;\n\
    \            st.emplace_back(i);\n        }\n        for(int i=0;i<n;i++)if(lch[i]!=-1)par[lch[i]]=i;\n\
    \        for(int i=0;i<n;i++)if(rch[i]!=-1)par[rch[i]]=i;\n        for(int i=0;i<n;i++)if(par[i]==-1)root=i;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2025-02-20\n * Description: Cartesian Tree.\n */\n\ntemplate<class T,bool\
    \ IS_MIN>\nstruct CartesianTree{\n    int n;\n    vector<T> &a;\n    vector<pair<int,int>>\
    \ range;\n    vector<int> lch,rch,par;\n    int root;\n\n    CartesianTree(vector<T>\
    \ &_a):n((int)_a.size()),a(_a){\n        range.assign(n,{-1,-1});\n        lch=rch=par=vector<int>(n,-1);\n\
    \        if(n==1){\n            range[0]={0,1};\n            root=0;\n       \
    \     return;\n        }\n        auto cmp=[&](int i,int j)->bool {\n        \
    \    if(IS_MIN)a[i]>a[j]||(a[i]==a[j]&&i<j);\n            return a[i]<a[j]||(a[i]==a[j]&&i<j);\n\
    \        };\n        vector<int> st;\n        for(int i=0;i<n;i++){\n        \
    \    while(!st.empty()&&cmp(i,st.back())){\n                lch[i]=st.back();\n\
    \                st.pop_back();\n            }\n            range[i].first=(st.empty()?-1:st.back())+1;\n\
    \            st.emplace_back(i);\n        }\n        for(int i=n-1;i>=0;i--){\n\
    \            while(!st.empty()&&cmp(i,st.back())){\n                rch[i]=st.back();\n\
    \                st.pop_back();\n            }\n            range[i].second=(st.empty()?n:st.back())-1;\n\
    \            st.emplace_back(i);\n        }\n        for(int i=0;i<n;i++)if(lch[i]!=-1)par[lch[i]]=i;\n\
    \        for(int i=0;i<n;i++)if(rch[i]!=-1)par[rch[i]]=i;\n        for(int i=0;i<n;i++)if(par[i]==-1)root=i;\n\
    \    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data-structure/cartesian-tree.hpp
  requiredBy: []
  timestamp: '2025-04-16 16:10:29+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/tree/cartesian_tree.test.cpp
documentation_of: data-structure/cartesian-tree.hpp
layout: document
redirect_from:
- /library/data-structure/cartesian-tree.hpp
- /library/data-structure/cartesian-tree.hpp.html
title: data-structure/cartesian-tree.hpp
---
