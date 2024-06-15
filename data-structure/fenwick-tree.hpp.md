---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_add_range_sum.test.cpp
    title: verify/yosupo/data-structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
    title: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
    title: verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/fenwick-tree.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-01-15\n * Description: Fenwick / Binary Indexed Tree\n */\n\
    \ntemplate<class T>\nstruct Fenwick{\n    int n,logn;\n    vector<T> t;\n    Fenwick(){}\n\
    \    Fenwick(int _n){init(vector<T>(_n,T{}));}\n    template<class U>\n    Fenwick(const\
    \ vector<U> &a){init(a);}\n    template<class U>\n    void init(const vector<U>\
    \ &a){\n        n=(int)a.size();\n        logn=31-__builtin_clz(n);\n        t.assign(n+1,T{});\n\
    \        for(int i=1;i<=n;i++){\n            t[i]=t[i]+a[i-1];\n            int\
    \ j=i+(i&-i);\n            if(j<=n)t[j]=t[j]+t[i];\n        }\n    }\n    void\
    \ update(int x,const T &v){\n        for(int i=x+1;i<=n;i+=i&-i)t[i]=t[i]+v;\n\
    \    }\n    void update(int l,int r,const T &v){\n        update(l,v),update(r+1,-v);\n\
    \    }\n    T query(int x){\n        T res{};\n        for(int i=x+1;i>0;i-=i&-i)res=res+t[i];\n\
    \        return res;\n    }\n    T query(int l,int r){\n        return query(r)-query(l-1);\n\
    \    }\n    int find(const T &k){\n        int x=0;\n        T cur{};\n      \
    \  for(int i=1<<logn;i>0;i>>=1)\n            if(x+i<=n&&cur+t[x+i]<=k)x+=i,cur=cur+t[x];\n\
    \        return x;\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description:\
    \ Fenwick / Binary Indexed Tree\n */\n\ntemplate<class T>\nstruct Fenwick{\n \
    \   int n,logn;\n    vector<T> t;\n    Fenwick(){}\n    Fenwick(int _n){init(vector<T>(_n,T{}));}\n\
    \    template<class U>\n    Fenwick(const vector<U> &a){init(a);}\n    template<class\
    \ U>\n    void init(const vector<U> &a){\n        n=(int)a.size();\n        logn=31-__builtin_clz(n);\n\
    \        t.assign(n+1,T{});\n        for(int i=1;i<=n;i++){\n            t[i]=t[i]+a[i-1];\n\
    \            int j=i+(i&-i);\n            if(j<=n)t[j]=t[j]+t[i];\n        }\n\
    \    }\n    void update(int x,const T &v){\n        for(int i=x+1;i<=n;i+=i&-i)t[i]=t[i]+v;\n\
    \    }\n    void update(int l,int r,const T &v){\n        update(l,v),update(r+1,-v);\n\
    \    }\n    T query(int x){\n        T res{};\n        for(int i=x+1;i>0;i-=i&-i)res=res+t[i];\n\
    \        return res;\n    }\n    T query(int l,int r){\n        return query(r)-query(l-1);\n\
    \    }\n    int find(const T &k){\n        int x=0;\n        T cur{};\n      \
    \  for(int i=1<<logn;i>0;i>>=1)\n            if(x+i<=n&&cur+t[x+i]<=k)x+=i,cur=cur+t[x];\n\
    \        return x;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2024-06-11 21:32:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/point_add_range_sum.test.cpp
  - verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
  - verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
documentation_of: data-structure/fenwick-tree.hpp
layout: document
redirect_from:
- /library/data-structure/fenwick-tree.hpp
- /library/data-structure/fenwick-tree.hpp.html
title: data-structure/fenwick-tree.hpp
---
