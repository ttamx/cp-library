---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/segment_add_get_min_online.test.cpp
    title: verify/yosupo/data-structure/segment_add_get_min_online.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/convex/dynamic-li-chao-tree.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Date: 2024-06-12\n * Description: Dynamic Li-Chao Tree\
    \ (minimize).\n */\n\ntemplate<class T>\nstruct DynamicLiChaoTree{\n    static\
    \ const T INF=numeric_limits<T>::max()/2;\n    struct Line{\n        T m,c;\n\
    \        Line(T _m,T _c):m(_m),c(_c){}\n        inline T eval(T x)const{return\
    \ m*x+c;}\n    };\n    struct Node;\n    using Ptr = Node*;\n    struct Node{\n\
    \        Line v;\n        Ptr l,r;\n        Node():v(0,INF),l(nullptr),r(nullptr){}\n\
    \        Node(Line _v):v(_v),l(nullptr),r(nullptr){}\n    };\n    ll lb,ub;\n\
    \    Ptr root;\n    DynamicLiChaoTree(ll _lb,ll _ub):lb(_lb),ub(_ub),root(nullptr){}\n\
    \    void insert(T l,T r,Ptr &t,Line v){\n        if(!t)return void(t=new Node(v));\n\
    \        T m=l+(r-l)/2;\n        if(v.eval(m)<t->v.eval(m))swap(t->v,v);\n   \
    \     if(v.eval(l)<t->v.eval(l))insert(l,m,t->l,v);\n        if(v.eval(r)<t->v.eval(r))insert(m+1,r,t->r,v);\n\
    \    }\n    inline void insert(T m,T c){\n        insert(lb,ub,root,Line(m,c));\n\
    \    }\n    void insert_range(T l,T r,Ptr &t,T x,T y,Line v){\n        if(y<l||r<x)return;\n\
    \        if(!t)t=new Node();\n        if(x<=l&&r<=y)return insert(l,r,t,v);\n\
    \        T m=l+(r-l)/2;\n        insert_range(l,m,t->l,x,y,v);\n        insert_range(m+1,r,t->r,x,y,v);\n\
    \    }\n    inline void insert_range(T m,T c,T x,T y){\n        insert_range(lb,ub,root,x,y,Line(m,c));\n\
    \    }\n    T query(T l,T r,Ptr t,T x){\n        if(!t)return INF;\n        T\
    \ m=l+(r-l)/2;\n        if(x<=m)return min(t->v.eval(x),query(l,m,t->l,x));\n\
    \        return min(t->v.eval(x),query(m+1,r,t->r,x));\n    }\n    inline T query(T\
    \ x){\n        return query(lb,ub,root,x);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-12\n * Description:\
    \ Dynamic Li-Chao Tree (minimize).\n */\n\ntemplate<class T>\nstruct DynamicLiChaoTree{\n\
    \    static const T INF=numeric_limits<T>::max()/2;\n    struct Line{\n      \
    \  T m,c;\n        Line(T _m,T _c):m(_m),c(_c){}\n        inline T eval(T x)const{return\
    \ m*x+c;}\n    };\n    struct Node;\n    using Ptr = Node*;\n    struct Node{\n\
    \        Line v;\n        Ptr l,r;\n        Node():v(0,INF),l(nullptr),r(nullptr){}\n\
    \        Node(Line _v):v(_v),l(nullptr),r(nullptr){}\n    };\n    ll lb,ub;\n\
    \    Ptr root;\n    DynamicLiChaoTree(ll _lb,ll _ub):lb(_lb),ub(_ub),root(nullptr){}\n\
    \    void insert(T l,T r,Ptr &t,Line v){\n        if(!t)return void(t=new Node(v));\n\
    \        T m=l+(r-l)/2;\n        if(v.eval(m)<t->v.eval(m))swap(t->v,v);\n   \
    \     if(v.eval(l)<t->v.eval(l))insert(l,m,t->l,v);\n        if(v.eval(r)<t->v.eval(r))insert(m+1,r,t->r,v);\n\
    \    }\n    inline void insert(T m,T c){\n        insert(lb,ub,root,Line(m,c));\n\
    \    }\n    void insert_range(T l,T r,Ptr &t,T x,T y,Line v){\n        if(y<l||r<x)return;\n\
    \        if(!t)t=new Node();\n        if(x<=l&&r<=y)return insert(l,r,t,v);\n\
    \        T m=l+(r-l)/2;\n        insert_range(l,m,t->l,x,y,v);\n        insert_range(m+1,r,t->r,x,y,v);\n\
    \    }\n    inline void insert_range(T m,T c,T x,T y){\n        insert_range(lb,ub,root,x,y,Line(m,c));\n\
    \    }\n    T query(T l,T r,Ptr t,T x){\n        if(!t)return INF;\n        T\
    \ m=l+(r-l)/2;\n        if(x<=m)return min(t->v.eval(x),query(l,m,t->l,x));\n\
    \        return min(t->v.eval(x),query(m+1,r,t->r,x));\n    }\n    inline T query(T\
    \ x){\n        return query(lb,ub,root,x);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/convex/dynamic-li-chao-tree.hpp
  requiredBy: []
  timestamp: '2024-06-12 17:31:48+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/segment_add_get_min_online.test.cpp
documentation_of: data-structure/convex/dynamic-li-chao-tree.hpp
layout: document
redirect_from:
- /library/data-structure/convex/dynamic-li-chao-tree.hpp
- /library/data-structure/convex/dynamic-li-chao-tree.hpp.html
title: data-structure/convex/dynamic-li-chao-tree.hpp
---
