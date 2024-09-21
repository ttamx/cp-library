---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_range_composite.test.cpp
    title: verify/yosupo/data-structure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
    title: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segment-tree/segment-tree.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Segment Tree\n */\n\
    \ntemplate<class Monoid>\nstruct SegmentTree{\n    using T = typename Monoid::value_type;\n\
    \    int n;\n    vector<T> t;\n    SegmentTree(){}\n    SegmentTree(int n,function<T(int)>\
    \ create){init(n,create);}\n    SegmentTree(int n,T v=Monoid::unit()){init(n,[&](int){return\
    \ v;});}\n    template<class U>\n    SegmentTree(const vector<U> &a){init((int)a.size(),[&](int\
    \ i){return T(a[i]);});}\n    void init(int _n,function<T(int)> create){\n   \
    \     n=_n;\n        t.assign(4<<(31-__builtin_clz(n)),Monoid::unit());\n    \
    \    function<void(int,int,int)> build=[&](int l,int r,int i){\n            if(l==r)return\
    \ void(t[i]=create(l));\n            int m=(l+r)/2;\n            build(l,m,i*2);\n\
    \            build(m+1,r,i*2+1);\n            pull(i);\n        };\n        build(0,n-1,1);\n\
    \    }\n    void pull(int i){\n        t[i]=Monoid::op(t[i*2],t[i*2+1]);\n   \
    \ }\n    void modify(int l,int r,int i,int x,const T &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[i]=v);\n        int m=(l+r)/2;\n        modify(l,m,i*2,x,v);\n\
    \        modify(m+1,r,i*2+1,x,v);\n        pull(i);\n    }\n    void modify(int\
    \ x,const T &v){\n        modify(0,n-1,1,x,v);\n    }\n    template<class U>\n\
    \    void update(int l,int r,int i,int x,const U &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[i]=Monoid::op(t[i],v));\n        int m=(l+r)/2;\n\
    \        update(l,m,i*2,x,v);\n        update(m+1,r,i*2+1,x,v);\n        pull(i);\n\
    \    }\n    template<class U>\n    void update(int x,const U &v){\n        update(0,n-1,1,x,v);\n\
    \    }\n    T query(int l,int r,int i,int x,int y){\n        if(y<l||r<x)return\
    \ Monoid::unit();\n        if(x<=l&&r<=y)return t[i];\n        int m=(l+r)/2;\n\
    \        return Monoid::op(query(l,m,i*2,x,y),query(m+1,r,i*2+1,x,y));\n    }\n\
    \    T query(int x,int y){\n        return query(0,n-1,1,x,y);\n    }\n    template<class\
    \ F>\n    int findfirst(int l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ n;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        int res=findfirst(l,m,i*2,x,y,f);\n\
    \        if(res==n)res=findfirst(m+1,r,i*2+1,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    int findfirst(int x,int y,const F &f){\n    \
    \    return findfirst(0,n-1,1,x,y,f);\n    }\n    template<class F>\n    int findlast(int\
    \ l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ -1;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        int res=findlast(m+1,r,i*2+1,x,y,f);\n\
    \        if(res==-1)res=findlast(l,m,i*2,x,y,f);\n        return res;\n    }\n\
    \    template<class F>\n    int findlast(int x,int y,const F &f){\n        return\
    \ findlast(0,n-1,1,x,y,f);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description:\
    \ Segment Tree\n */\n\ntemplate<class Monoid>\nstruct SegmentTree{\n    using\
    \ T = typename Monoid::value_type;\n    int n;\n    vector<T> t;\n    SegmentTree(){}\n\
    \    SegmentTree(int n,function<T(int)> create){init(n,create);}\n    SegmentTree(int\
    \ n,T v=Monoid::unit()){init(n,[&](int){return v;});}\n    template<class U>\n\
    \    SegmentTree(const vector<U> &a){init((int)a.size(),[&](int i){return T(a[i]);});}\n\
    \    void init(int _n,function<T(int)> create){\n        n=_n;\n        t.assign(4<<(31-__builtin_clz(n)),Monoid::unit());\n\
    \        function<void(int,int,int)> build=[&](int l,int r,int i){\n         \
    \   if(l==r)return void(t[i]=create(l));\n            int m=(l+r)/2;\n       \
    \     build(l,m,i*2);\n            build(m+1,r,i*2+1);\n            pull(i);\n\
    \        };\n        build(0,n-1,1);\n    }\n    void pull(int i){\n        t[i]=Monoid::op(t[i*2],t[i*2+1]);\n\
    \    }\n    void modify(int l,int r,int i,int x,const T &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[i]=v);\n        int m=(l+r)/2;\n        modify(l,m,i*2,x,v);\n\
    \        modify(m+1,r,i*2+1,x,v);\n        pull(i);\n    }\n    void modify(int\
    \ x,const T &v){\n        modify(0,n-1,1,x,v);\n    }\n    template<class U>\n\
    \    void update(int l,int r,int i,int x,const U &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[i]=Monoid::op(t[i],v));\n        int m=(l+r)/2;\n\
    \        update(l,m,i*2,x,v);\n        update(m+1,r,i*2+1,x,v);\n        pull(i);\n\
    \    }\n    template<class U>\n    void update(int x,const U &v){\n        update(0,n-1,1,x,v);\n\
    \    }\n    T query(int l,int r,int i,int x,int y){\n        if(y<l||r<x)return\
    \ Monoid::unit();\n        if(x<=l&&r<=y)return t[i];\n        int m=(l+r)/2;\n\
    \        return Monoid::op(query(l,m,i*2,x,y),query(m+1,r,i*2+1,x,y));\n    }\n\
    \    T query(int x,int y){\n        return query(0,n-1,1,x,y);\n    }\n    template<class\
    \ F>\n    int findfirst(int l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ n;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        int res=findfirst(l,m,i*2,x,y,f);\n\
    \        if(res==n)res=findfirst(m+1,r,i*2+1,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    int findfirst(int x,int y,const F &f){\n    \
    \    return findfirst(0,n-1,1,x,y,f);\n    }\n    template<class F>\n    int findlast(int\
    \ l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ -1;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        int res=findlast(m+1,r,i*2+1,x,y,f);\n\
    \        if(res==-1)res=findlast(l,m,i*2,x,y,f);\n        return res;\n    }\n\
    \    template<class F>\n    int findlast(int x,int y,const F &f){\n        return\
    \ findlast(0,n-1,1,x,y,f);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/segment-tree.hpp
  requiredBy: []
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  - verify/yosupo/data-structure/point_set_range_composite.test.cpp
documentation_of: data-structure/segment-tree/segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/segment-tree/segment-tree.hpp
- /library/data-structure/segment-tree/segment-tree.hpp.html
title: data-structure/segment-tree/segment-tree.hpp
---
