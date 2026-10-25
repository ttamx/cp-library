---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp
    title: verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/convex/dynamic-li-chao-tree.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Date: 2024-06-12\n * Description: Dynamic Li-Chao Tree.\n\
    \ */\n\ntemplate<class T,bool IS_MIN>\nstruct DynamicLiChaoTree{\n    static constexpr\
    \ T INF=numeric_limits<T>::max();\n    struct Line{\n        T m,c;\n        Line(T\
    \ _m,T _c):m(_m),c(_c){}\n        inline T eval(T x)const{return m*x+c;}\n   \
    \ };\n    struct Node{\n        Line v;\n        int l,r;\n        Node(Line _v=Line(0,INF)):v(_v),l(-1),r(-1){}\n\
    \    };\n    ll lb,ub;\n    vector<Node> t;\n    DynamicLiChaoTree(ll _lb,ll _ub):lb(_lb),ub(_ub),t{Node()}{assert(lb<=ub);}\n\
    \    int new_node(Line v=Line(0,INF)){\n        t.emplace_back(v);\n        return\
    \ t.size()-1;\n    }\n    void insert(T l,T r,int u,Line v){\n        T m=l+(r-l)/2;\n\
    \        if(v.eval(m)<t[u].v.eval(m))swap(t[u].v,v);\n        if(v.eval(l)<t[u].v.eval(l)){\n\
    \            if(t[u].l==-1){int c=new_node(v);t[u].l=c;}\n            else insert(l,m,t[u].l,v);\n\
    \        }\n        if(v.eval(r)<t[u].v.eval(r)){\n            if(t[u].r==-1){int\
    \ c=new_node(v);t[u].r=c;}\n            else insert(m+1,r,t[u].r,v);\n       \
    \ }\n    }\n    inline void insert(T m,T c){\n        if constexpr(!IS_MIN)m=-m,c=-c;\n\
    \        insert(lb,ub,0,Line(m,c));\n    }\n    void insert_range(T l,T r,int\
    \ u,T x,T y,Line v){\n        if(y<l||r<x)return;\n        if(x<=l&&r<=y)return\
    \ insert(l,r,u,v);\n        T m=l+(r-l)/2;\n        if(x<=m){\n            if(t[u].l==-1){int\
    \ c=new_node();t[u].l=c;}\n            insert_range(l,m,t[u].l,x,y,v);\n     \
    \   }\n        if(m<y){\n            if(t[u].r==-1){int c=new_node();t[u].r=c;}\n\
    \            insert_range(m+1,r,t[u].r,x,y,v);\n        }\n    }\n    inline void\
    \ insert_range(T m,T c,T x,T y){\n        if constexpr(!IS_MIN)m=-m,c=-c;\n  \
    \      insert_range(lb,ub,0,x,y,Line(m,c));\n    }\n    T query(T l,T r,int u,T\
    \ x){\n        if(u==-1)return INF;\n        T m=l+(r-l)/2;\n        if(x<=m)return\
    \ min(t[u].v.eval(x),query(l,m,t[u].l,x));\n        return min(t[u].v.eval(x),query(m+1,r,t[u].r,x));\n\
    \    }\n    inline T query(T x){\n        T res=query(lb,ub,0,x);\n        return\
    \ IS_MIN?res:-res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-12\n * Description:\
    \ Dynamic Li-Chao Tree.\n */\n\ntemplate<class T,bool IS_MIN>\nstruct DynamicLiChaoTree{\n\
    \    static constexpr T INF=numeric_limits<T>::max();\n    struct Line{\n    \
    \    T m,c;\n        Line(T _m,T _c):m(_m),c(_c){}\n        inline T eval(T x)const{return\
    \ m*x+c;}\n    };\n    struct Node{\n        Line v;\n        int l,r;\n     \
    \   Node(Line _v=Line(0,INF)):v(_v),l(-1),r(-1){}\n    };\n    ll lb,ub;\n   \
    \ vector<Node> t;\n    DynamicLiChaoTree(ll _lb,ll _ub):lb(_lb),ub(_ub),t{Node()}{assert(lb<=ub);}\n\
    \    int new_node(Line v=Line(0,INF)){\n        t.emplace_back(v);\n        return\
    \ t.size()-1;\n    }\n    void insert(T l,T r,int u,Line v){\n        T m=l+(r-l)/2;\n\
    \        if(v.eval(m)<t[u].v.eval(m))swap(t[u].v,v);\n        if(v.eval(l)<t[u].v.eval(l)){\n\
    \            if(t[u].l==-1){int c=new_node(v);t[u].l=c;}\n            else insert(l,m,t[u].l,v);\n\
    \        }\n        if(v.eval(r)<t[u].v.eval(r)){\n            if(t[u].r==-1){int\
    \ c=new_node(v);t[u].r=c;}\n            else insert(m+1,r,t[u].r,v);\n       \
    \ }\n    }\n    inline void insert(T m,T c){\n        if constexpr(!IS_MIN)m=-m,c=-c;\n\
    \        insert(lb,ub,0,Line(m,c));\n    }\n    void insert_range(T l,T r,int\
    \ u,T x,T y,Line v){\n        if(y<l||r<x)return;\n        if(x<=l&&r<=y)return\
    \ insert(l,r,u,v);\n        T m=l+(r-l)/2;\n        if(x<=m){\n            if(t[u].l==-1){int\
    \ c=new_node();t[u].l=c;}\n            insert_range(l,m,t[u].l,x,y,v);\n     \
    \   }\n        if(m<y){\n            if(t[u].r==-1){int c=new_node();t[u].r=c;}\n\
    \            insert_range(m+1,r,t[u].r,x,y,v);\n        }\n    }\n    inline void\
    \ insert_range(T m,T c,T x,T y){\n        if constexpr(!IS_MIN)m=-m,c=-c;\n  \
    \      insert_range(lb,ub,0,x,y,Line(m,c));\n    }\n    T query(T l,T r,int u,T\
    \ x){\n        if(u==-1)return INF;\n        T m=l+(r-l)/2;\n        if(x<=m)return\
    \ min(t[u].v.eval(x),query(l,m,t[u].l,x));\n        return min(t[u].v.eval(x),query(m+1,r,t[u].r,x));\n\
    \    }\n    inline T query(T x){\n        T res=query(lb,ub,0,x);\n        return\
    \ IS_MIN?res:-res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/convex/dynamic-li-chao-tree.hpp
  requiredBy: []
  timestamp: '2026-10-25 17:59:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp
documentation_of: data-structure/convex/dynamic-li-chao-tree.hpp
layout: document
redirect_from:
- /library/data-structure/convex/dynamic-li-chao-tree.hpp
- /library/data-structure/convex/dynamic-li-chao-tree.hpp.html
title: data-structure/convex/dynamic-li-chao-tree.hpp
---
