---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segment-tree/lazy-segment-tree.hpp\"\n\n\
    /**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Segment Tree with\
    \ Lazy Propagation\n */\n\ntemplate<class MonoidAction>\nstruct LazySegmentTree{\n\
    \    using InfoMonoid = typename MonoidAction::InfoMonoid;\n    using TagMonoid\
    \ = typename MonoidAction::TagMonoid;\n    using Info = typename MonoidAction::Info;\n\
    \    using Tag = typename MonoidAction::Tag;\n    int n;\n    vector<Info> t;\n\
    \    vector<Tag> lz;\n    LazySegmentTree(){}\n    LazySegmentTree(int n,function<Info(int)>\
    \ create){init(n,create);}\n    LazySegmentTree(int n,Info v=InfoMonoid::unit()){init(n,[&](int){return\
    \ v;});}\n    template<class T>\n    LazySegmentTree(const vector<T> &a){init((int)a.size(),[&](int\
    \ i){return Info(a[i]);});}\n    void init(int _n,function<Info(int)> create){\n\
    \        n=_n;\n        int m=4<<(31-__builtin_clz(n));\n        t.assign(m,InfoMonoid::unit());\n\
    \        lz.assign(m,TagMonoid::unit());\n        function<void(int,int,int)>\
    \ build=[&](int l,int r,int i){\n            if(l==r)return void(t[i]=create(l));\n\
    \            int m=(l+r)/2;\n            build(l,m,i*2);\n            build(m+1,r,i*2+1);\n\
    \            pull(i);\n        };\n        build(0,n-1,1);\n    }\n    void pull(int\
    \ i){\n        t[i]=InfoMonoid::op(t[i*2],t[i*2+1]);\n    }\n    void apply(int\
    \ i,const Tag &v){\n        t[i]=MonoidAction::op(t[i],v);\n        lz[i]=TagMonoid::op(lz[i],v);\n\
    \    }\n    void push(int i){\n        apply(i*2,lz[i]);\n        apply(i*2+1,lz[i]);\n\
    \        lz[i]=TagMonoid::unit();\n    }\n    void modify(int l,int r,int i,int\
    \ x,const Info &v){\n        if(x<l||r<x)return;\n        if(l==r)return void(t[i]=v);\n\
    \        int m=(l+r)/2;\n        push(i);\n        modify(l,m,i*2,x,v);\n    \
    \    modify(m+1,r,i*2+1,x,v);\n        pull(i);\n    }\n    void modify(int x,const\
    \ Info &v){\n        modify(0,n-1,1,x,v);\n    }\n    void update(int l,int r,int\
    \ i,int x,int y,const Tag &v){\n        if(y<l||r<x)return;\n        if(x<=l&&r<=y)return\
    \ apply(i,v);\n        int m=(l+r)/2;\n        push(i);\n        update(l,m,i*2,x,y,v);\n\
    \        update(m+1,r,i*2+1,x,y,v);\n        pull(i);\n    }\n    void update(int\
    \ x,int y,const Tag &v){\n        update(0,n-1,1,x,y,v);\n    }\n    Info query(int\
    \ l,int r,int i,int x,int y){\n        if(y<l||r<x)return InfoMonoid::unit();\n\
    \        if(x<=l&&r<=y)return t[i];\n        int m=(l+r)/2;\n        push(i);\n\
    \        return InfoMonoid::op(query(l,m,i*2,x,y),query(m+1,r,i*2+1,x,y));\n \
    \   }\n    Info query(int x,int y){\n        return query(0,n-1,1,x,y);\n    }\n\
    \    template<class F>\n    int findfirst(int l,int r,int i,int x,int y,const\
    \ F &f){\n        if(y<l||r<x||!f(t[i]))return n;\n        if(l==r)return l;\n\
    \        int m=(l+r)/2;\n        push(i);\n        int res=findfirst(l,m,i*2,x,y,f);\n\
    \        if(res==n)res=findfirst(m+1,r,i*2+1,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    int findfirst(int x,int y,const F &f){\n    \
    \    return findfirst(0,n-1,1,x,y,f);\n    }\n    template<class F>\n    int findlast(int\
    \ l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ -1;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        push(i);\n \
    \       int res=findlast(m+1,r,i*2+1,x,y,f);\n        if(res==-1)res=findlast(l,m,i*2,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    int findlast(int x,int\
    \ y,const F &f){\n        return findlast(0,n-1,1,x,y,f);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description:\
    \ Segment Tree with Lazy Propagation\n */\n\ntemplate<class MonoidAction>\nstruct\
    \ LazySegmentTree{\n    using InfoMonoid = typename MonoidAction::InfoMonoid;\n\
    \    using TagMonoid = typename MonoidAction::TagMonoid;\n    using Info = typename\
    \ MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n    int n;\n\
    \    vector<Info> t;\n    vector<Tag> lz;\n    LazySegmentTree(){}\n    LazySegmentTree(int\
    \ n,function<Info(int)> create){init(n,create);}\n    LazySegmentTree(int n,Info\
    \ v=InfoMonoid::unit()){init(n,[&](int){return v;});}\n    template<class T>\n\
    \    LazySegmentTree(const vector<T> &a){init((int)a.size(),[&](int i){return\
    \ Info(a[i]);});}\n    void init(int _n,function<Info(int)> create){\n       \
    \ n=_n;\n        int m=4<<(31-__builtin_clz(n));\n        t.assign(m,InfoMonoid::unit());\n\
    \        lz.assign(m,TagMonoid::unit());\n        function<void(int,int,int)>\
    \ build=[&](int l,int r,int i){\n            if(l==r)return void(t[i]=create(l));\n\
    \            int m=(l+r)/2;\n            build(l,m,i*2);\n            build(m+1,r,i*2+1);\n\
    \            pull(i);\n        };\n        build(0,n-1,1);\n    }\n    void pull(int\
    \ i){\n        t[i]=InfoMonoid::op(t[i*2],t[i*2+1]);\n    }\n    void apply(int\
    \ i,const Tag &v){\n        t[i]=MonoidAction::op(t[i],v);\n        lz[i]=TagMonoid::op(lz[i],v);\n\
    \    }\n    void push(int i){\n        apply(i*2,lz[i]);\n        apply(i*2+1,lz[i]);\n\
    \        lz[i]=TagMonoid::unit();\n    }\n    void modify(int l,int r,int i,int\
    \ x,const Info &v){\n        if(x<l||r<x)return;\n        if(l==r)return void(t[i]=v);\n\
    \        int m=(l+r)/2;\n        push(i);\n        modify(l,m,i*2,x,v);\n    \
    \    modify(m+1,r,i*2+1,x,v);\n        pull(i);\n    }\n    void modify(int x,const\
    \ Info &v){\n        modify(0,n-1,1,x,v);\n    }\n    void update(int l,int r,int\
    \ i,int x,int y,const Tag &v){\n        if(y<l||r<x)return;\n        if(x<=l&&r<=y)return\
    \ apply(i,v);\n        int m=(l+r)/2;\n        push(i);\n        update(l,m,i*2,x,y,v);\n\
    \        update(m+1,r,i*2+1,x,y,v);\n        pull(i);\n    }\n    void update(int\
    \ x,int y,const Tag &v){\n        update(0,n-1,1,x,y,v);\n    }\n    Info query(int\
    \ l,int r,int i,int x,int y){\n        if(y<l||r<x)return InfoMonoid::unit();\n\
    \        if(x<=l&&r<=y)return t[i];\n        int m=(l+r)/2;\n        push(i);\n\
    \        return InfoMonoid::op(query(l,m,i*2,x,y),query(m+1,r,i*2+1,x,y));\n \
    \   }\n    Info query(int x,int y){\n        return query(0,n-1,1,x,y);\n    }\n\
    \    template<class F>\n    int findfirst(int l,int r,int i,int x,int y,const\
    \ F &f){\n        if(y<l||r<x||!f(t[i]))return n;\n        if(l==r)return l;\n\
    \        int m=(l+r)/2;\n        push(i);\n        int res=findfirst(l,m,i*2,x,y,f);\n\
    \        if(res==n)res=findfirst(m+1,r,i*2+1,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    int findfirst(int x,int y,const F &f){\n    \
    \    return findfirst(0,n-1,1,x,y,f);\n    }\n    template<class F>\n    int findlast(int\
    \ l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ -1;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        push(i);\n \
    \       int res=findlast(m+1,r,i*2+1,x,y,f);\n        if(res==-1)res=findlast(l,m,i*2,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    int findlast(int x,int\
    \ y,const F &f){\n        return findlast(0,n-1,1,x,y,f);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2024-07-29 18:56:36+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/range_affine_range_sum.test.cpp
documentation_of: data-structure/segment-tree/lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/segment-tree/lazy-segment-tree.hpp
- /library/data-structure/segment-tree/lazy-segment-tree.hpp.html
title: data-structure/segment-tree/lazy-segment-tree.hpp
---
