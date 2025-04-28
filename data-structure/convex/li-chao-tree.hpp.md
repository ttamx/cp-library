---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/line_add_get_min.test.cpp
    title: verify/yosupo/data-structure/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/segment_add_get_min.test.cpp
    title: verify/yosupo/data-structure/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/convex/li-chao-tree.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-06-12\n * Description: Li-Chao Tree (minimize).\n */\n\
    \ntemplate<class T>\nstruct LiChaoTree{\n    static const T INF=numeric_limits<T>::max()/2;\n\
    \    struct Line{\n        T m,c;\n        Line(T _m,T _c):m(_m),c(_c){}\n   \
    \     inline T eval(T x)const{return m*x+c;}\n    };\n    vector<T> xs;\n    vector<Line>\
    \ t;\n    LiChaoTree(){}\n    LiChaoTree(const vector<T> &x):xs(x){init(x);}\n\
    \    LiChaoTree(int n):xs(n){\n        vector<T> x(n);\n        iota(x.begin(),x.end(),0);\n\
    \        init(x);\n    }\n    void init(const vector<T> &x){\n        xs=x;\n\
    \        sort(xs.begin(),xs.end());\n        xs.erase(unique(xs.begin(),xs.end()),xs.end());\n\
    \        t.assign(4<<(31-__builtin_clz(xs.size())),Line(0,INF));\n    }\n    void\
    \ insert(int l,int r,int i,Line v){\n        int m=(l+r)/2;\n        if(v.eval(xs[m])<t[i].eval(xs[m]))swap(t[i],v);\n\
    \        if(v.eval(xs[l])<t[i].eval(xs[l]))insert(l,m,i*2,v);\n        if(v.eval(xs[r])<t[i].eval(xs[r]))insert(m+1,r,i*2+1,v);\n\
    \    }\n    inline void insert(T m,T c){\n        insert(0,(int)xs.size()-1,1,Line(m,c));\n\
    \    }\n    void insert_range(int l,int r,int i,T x,T y,Line v){\n        if(y<xs[l]||xs[r]<x)return;\n\
    \        if(x<=xs[l]&&xs[r]<=y)return insert(l,r,i,v);\n        int m=(l+r)/2;\n\
    \        insert_range(l,m,i*2,x,y,v);\n        insert_range(m+1,r,i*2+1,x,y,v);\n\
    \    }\n    inline void insert_range(T m,T c,T x,T y){\n        insert_range(0,(int)xs.size()-1,1,x,y,Line(m,c));\n\
    \    }\n    T query(int l,int r,int i,T x){\n        if(l==r)return t[i].eval(x);\n\
    \        int m=(l+r)/2;\n        if(x<=xs[m])return min(t[i].eval(x),query(l,m,i*2,x));\n\
    \        return min(t[i].eval(x),query(m+1,r,i*2+1,x));\n    }\n    inline T query(T\
    \ x){\n        return query(0,(int)xs.size()-1,1,x);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-12\n * Description:\
    \ Li-Chao Tree (minimize).\n */\n\ntemplate<class T>\nstruct LiChaoTree{\n   \
    \ static const T INF=numeric_limits<T>::max()/2;\n    struct Line{\n        T\
    \ m,c;\n        Line(T _m,T _c):m(_m),c(_c){}\n        inline T eval(T x)const{return\
    \ m*x+c;}\n    };\n    vector<T> xs;\n    vector<Line> t;\n    LiChaoTree(){}\n\
    \    LiChaoTree(const vector<T> &x):xs(x){init(x);}\n    LiChaoTree(int n):xs(n){\n\
    \        vector<T> x(n);\n        iota(x.begin(),x.end(),0);\n        init(x);\n\
    \    }\n    void init(const vector<T> &x){\n        xs=x;\n        sort(xs.begin(),xs.end());\n\
    \        xs.erase(unique(xs.begin(),xs.end()),xs.end());\n        t.assign(4<<(31-__builtin_clz(xs.size())),Line(0,INF));\n\
    \    }\n    void insert(int l,int r,int i,Line v){\n        int m=(l+r)/2;\n \
    \       if(v.eval(xs[m])<t[i].eval(xs[m]))swap(t[i],v);\n        if(v.eval(xs[l])<t[i].eval(xs[l]))insert(l,m,i*2,v);\n\
    \        if(v.eval(xs[r])<t[i].eval(xs[r]))insert(m+1,r,i*2+1,v);\n    }\n   \
    \ inline void insert(T m,T c){\n        insert(0,(int)xs.size()-1,1,Line(m,c));\n\
    \    }\n    void insert_range(int l,int r,int i,T x,T y,Line v){\n        if(y<xs[l]||xs[r]<x)return;\n\
    \        if(x<=xs[l]&&xs[r]<=y)return insert(l,r,i,v);\n        int m=(l+r)/2;\n\
    \        insert_range(l,m,i*2,x,y,v);\n        insert_range(m+1,r,i*2+1,x,y,v);\n\
    \    }\n    inline void insert_range(T m,T c,T x,T y){\n        insert_range(0,(int)xs.size()-1,1,x,y,Line(m,c));\n\
    \    }\n    T query(int l,int r,int i,T x){\n        if(l==r)return t[i].eval(x);\n\
    \        int m=(l+r)/2;\n        if(x<=xs[m])return min(t[i].eval(x),query(l,m,i*2,x));\n\
    \        return min(t[i].eval(x),query(m+1,r,i*2+1,x));\n    }\n    inline T query(T\
    \ x){\n        return query(0,(int)xs.size()-1,1,x);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/convex/li-chao-tree.hpp
  requiredBy: []
  timestamp: '2024-06-12 17:31:48+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/line_add_get_min.test.cpp
  - verify/yosupo/data-structure/segment_add_get_min.test.cpp
documentation_of: data-structure/convex/li-chao-tree.hpp
layout: document
redirect_from:
- /library/data-structure/convex/li-chao-tree.hpp
- /library/data-structure/convex/li-chao-tree.hpp.html
title: data-structure/convex/li-chao-tree.hpp
---
