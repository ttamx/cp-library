---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
    title: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segment-tree/dynamic-segment-tree.hpp\"\n\
    \n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Dynamic Segment\
    \ Tree\n */\n\ntemplate<class MonoidAction>\nstruct DynamicSegmentTree{\n    using\
    \ InfoMonoid = typename MonoidAction::InfoMonoid;\n    using TagMonoid = typename\
    \ MonoidAction::TagMonoid;\n    using Info = typename MonoidAction::Info;\n  \
    \  using Tag = typename MonoidAction::Tag;\n    struct Node;\n    using Ptr =\
    \ Node*;\n    struct Node{\n        Info val;\n        Tag lz;\n        Ptr l,r;\n\
    \        Node(Info v):val(v),lz(TagMonoid::unit()),l(nullptr),r(nullptr){}\n \
    \       Node(Info v,Tag t):val(v),lz(t),l(nullptr),r(nullptr){}\n    };\n    ll\
    \ lb,ub;\n    Ptr rt;\n    function<Info(ll,ll)> create;\n    DynamicSegmentTree(){init(0,0);}\n\
    \    DynamicSegmentTree(ll n){init(0,n-1);}\n    DynamicSegmentTree(ll lb,ll ub){init(lb,ub);}\n\
    \    DynamicSegmentTree(ll lb,ll ub,function<Info(ll,ll)> create){init(lb,ub,create);}\n\
    \    void init(ll _lb,ll _ub,function<Info(ll,ll)> _create=[](ll l,ll r){return\
    \ InfoMonoid::unit();}){\n        lb=_lb,ub=_ub;\n        create=_create;\n  \
    \      rt=new Node(create(lb,ub));\n    }\n    Info val(Ptr t){\n        return\
    \ t?t->val:InfoMonoid::unit();\n    }\n    void pull(Ptr &t){\n        t->val=InfoMonoid::op(val(t->l),val(t->r));\n\
    \    }\n    void apply(Ptr &t,const Tag &v,ll l,ll r){\n        if(!t)t=new Node(create(l,r));\n\
    \        t->val=MonoidAction::op(t->val,v);\n        t->lz=TagMonoid::op(t->lz,v);\n\
    \    }\n    void push(Ptr &t,ll l,ll m,ll r){\n        apply(t->l,t->lz,l,m);\n\
    \        apply(t->r,t->lz,m+1,r);\n        t->lz=TagMonoid::unit();\n    }\n \
    \   void modify(ll l,ll r,Ptr &t,ll x,const Info &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t->val=v);\n        ll m=l+(r-l)/2;\n        push(t,l,m,r);\n\
    \        modify(l,m,t->l,x,v);\n        modify(m+1,r,t->r,x,v);\n        pull(t);\n\
    \    }\n    void modify(ll x,const Info &v){\n        modify(lb,ub,rt,x,v);\n\
    \    }\n    void update(ll l,ll r,Ptr &t,ll x,ll y,const Tag &v){\n        if(y<l||r<x)return;\n\
    \        if(x<=l&&r<=y)return apply(t,v,l,r);\n        ll m=l+(r-l)/2;\n     \
    \   push(t,l,m,r);\n        update(l,m,t->l,x,y,v);\n        update(m+1,r,t->r,x,y,v);\n\
    \        pull(t);\n    }\n    void update(ll x,ll y,const Tag &v){\n        update(lb,ub,rt,x,y,v);\n\
    \    }\n    Info query(ll l,ll r,Ptr &t,ll x,ll y){\n        if(y<l||r<x)return\
    \ InfoMonoid::unit();\n        if(x<=l&&r<=y)return t->val;\n        ll m=l+(r-l)/2;\n\
    \        push(t,l,m,r);\n        return InfoMonoid::op(query(l,m,t->l,x,y),query(m+1,r,t->r,x,y));\n\
    \    }\n    Info query(ll x,ll y){\n        return query(lb,ub,rt,x,y);\n    }\n\
    \    template<class F>\n    ll findfirst(ll l,ll r,Ptr t,ll x,ll y,const F &f){\n\
    \        if(y<l||r<x||!f(t->val))return -1;\n        if(l==r)return l;\n     \
    \   ll m=l+(r-l)/2;\n        push(t,l,m,r);\n        ll res=findfirst(l,m,t->l,x,y,f);\n\
    \        if(res==-1)res=findfirst(m+1,r,t->r,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    ll findfirst(ll x,ll y,const F &f){\n       \
    \ return findfirst(lb,ub,rt,x,y,f);\n    }\n    template<class F>\n    ll findlast(ll\
    \ l,ll r,Ptr t,ll x,ll y,const F &f){\n        if(y<l||r<x||!t||!f(t->val))return\
    \ -1;\n        if(l==r)return l;\n        ll m=l+(r-l)/2;\n        push(t,l,m,r);\n\
    \        ll res=findlast(m+1,r,t->r,x,y,f);\n        if(res==-1)res=findlast(l,m,t->l,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    ll findlast(ll x,ll y,const\
    \ F &f){\n        return findlast(lb,ub,rt,x,y,f);\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description:\
    \ Dynamic Segment Tree\n */\n\ntemplate<class MonoidAction>\nstruct DynamicSegmentTree{\n\
    \    using InfoMonoid = typename MonoidAction::InfoMonoid;\n    using TagMonoid\
    \ = typename MonoidAction::TagMonoid;\n    using Info = typename MonoidAction::Info;\n\
    \    using Tag = typename MonoidAction::Tag;\n    struct Node;\n    using Ptr\
    \ = Node*;\n    struct Node{\n        Info val;\n        Tag lz;\n        Ptr\
    \ l,r;\n        Node(Info v):val(v),lz(TagMonoid::unit()),l(nullptr),r(nullptr){}\n\
    \        Node(Info v,Tag t):val(v),lz(t),l(nullptr),r(nullptr){}\n    };\n   \
    \ ll lb,ub;\n    Ptr rt;\n    function<Info(ll,ll)> create;\n    DynamicSegmentTree(){init(0,0);}\n\
    \    DynamicSegmentTree(ll n){init(0,n-1);}\n    DynamicSegmentTree(ll lb,ll ub){init(lb,ub);}\n\
    \    DynamicSegmentTree(ll lb,ll ub,function<Info(ll,ll)> create){init(lb,ub,create);}\n\
    \    void init(ll _lb,ll _ub,function<Info(ll,ll)> _create=[](ll l,ll r){return\
    \ InfoMonoid::unit();}){\n        lb=_lb,ub=_ub;\n        create=_create;\n  \
    \      rt=new Node(create(lb,ub));\n    }\n    Info val(Ptr t){\n        return\
    \ t?t->val:InfoMonoid::unit();\n    }\n    void pull(Ptr &t){\n        t->val=InfoMonoid::op(val(t->l),val(t->r));\n\
    \    }\n    void apply(Ptr &t,const Tag &v,ll l,ll r){\n        if(!t)t=new Node(create(l,r));\n\
    \        t->val=MonoidAction::op(t->val,v);\n        t->lz=TagMonoid::op(t->lz,v);\n\
    \    }\n    void push(Ptr &t,ll l,ll m,ll r){\n        apply(t->l,t->lz,l,m);\n\
    \        apply(t->r,t->lz,m+1,r);\n        t->lz=TagMonoid::unit();\n    }\n \
    \   void modify(ll l,ll r,Ptr &t,ll x,const Info &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t->val=v);\n        ll m=l+(r-l)/2;\n        push(t,l,m,r);\n\
    \        modify(l,m,t->l,x,v);\n        modify(m+1,r,t->r,x,v);\n        pull(t);\n\
    \    }\n    void modify(ll x,const Info &v){\n        modify(lb,ub,rt,x,v);\n\
    \    }\n    void update(ll l,ll r,Ptr &t,ll x,ll y,const Tag &v){\n        if(y<l||r<x)return;\n\
    \        if(x<=l&&r<=y)return apply(t,v,l,r);\n        ll m=l+(r-l)/2;\n     \
    \   push(t,l,m,r);\n        update(l,m,t->l,x,y,v);\n        update(m+1,r,t->r,x,y,v);\n\
    \        pull(t);\n    }\n    void update(ll x,ll y,const Tag &v){\n        update(lb,ub,rt,x,y,v);\n\
    \    }\n    Info query(ll l,ll r,Ptr &t,ll x,ll y){\n        if(y<l||r<x)return\
    \ InfoMonoid::unit();\n        if(x<=l&&r<=y)return t->val;\n        ll m=l+(r-l)/2;\n\
    \        push(t,l,m,r);\n        return InfoMonoid::op(query(l,m,t->l,x,y),query(m+1,r,t->r,x,y));\n\
    \    }\n    Info query(ll x,ll y){\n        return query(lb,ub,rt,x,y);\n    }\n\
    \    template<class F>\n    ll findfirst(ll l,ll r,Ptr t,ll x,ll y,const F &f){\n\
    \        if(y<l||r<x||!f(t->val))return -1;\n        if(l==r)return l;\n     \
    \   ll m=l+(r-l)/2;\n        push(t,l,m,r);\n        ll res=findfirst(l,m,t->l,x,y,f);\n\
    \        if(res==-1)res=findfirst(m+1,r,t->r,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    ll findfirst(ll x,ll y,const F &f){\n       \
    \ return findfirst(lb,ub,rt,x,y,f);\n    }\n    template<class F>\n    ll findlast(ll\
    \ l,ll r,Ptr t,ll x,ll y,const F &f){\n        if(y<l||r<x||!t||!f(t->val))return\
    \ -1;\n        if(l==r)return l;\n        ll m=l+(r-l)/2;\n        push(t,l,m,r);\n\
    \        ll res=findlast(m+1,r,t->r,x,y,f);\n        if(res==-1)res=findlast(l,m,t->l,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    ll findlast(ll x,ll y,const\
    \ F &f){\n        return findlast(lb,ub,rt,x,y,f);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/dynamic-segment-tree.hpp
  requiredBy: []
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
documentation_of: data-structure/segment-tree/dynamic-segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/segment-tree/dynamic-segment-tree.hpp
- /library/data-structure/segment-tree/dynamic-segment-tree.hpp.html
title: data-structure/segment-tree/dynamic-segment-tree.hpp
---
