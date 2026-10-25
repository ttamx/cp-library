---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp
    title: verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp
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
    \  using Tag = typename MonoidAction::Tag;\n    struct Node{\n        Info val;\n\
    \        Tag lz;\n        int l,r;\n        Node(Info v):val(v),lz(TagMonoid::unit()),l(-1),r(-1){}\n\
    \    };\n    ll lb,ub;\n    vector<Node> t;\n    function<Info(ll,ll)> create;\n\
    \    DynamicSegmentTree(){init(0,0);}\n    DynamicSegmentTree(ll n){init(0,n-1);}\n\
    \    DynamicSegmentTree(ll lb,ll ub){init(lb,ub);}\n    DynamicSegmentTree(ll\
    \ lb,ll ub,function<Info(ll,ll)> create){init(lb,ub,create);}\n    void init(ll\
    \ _lb,ll _ub,function<Info(ll,ll)> _create=[](ll l,ll r){return InfoMonoid::unit();}){\n\
    \        lb=_lb,ub=_ub;\n        create=_create;\n        t.clear();\n       \
    \ new_node(create(lb,ub));\n    }\n    int new_node(const Info &v){\n        t.emplace_back(v);\n\
    \        return t.size()-1;\n    }\n    void pull(int u){\n        t[u].val=InfoMonoid::op(t[t[u].l].val,t[t[u].r].val);\n\
    \    }\n    void apply(int u,const Tag &v){\n        t[u].val=MonoidAction::op(t[u].val,v);\n\
    \        t[u].lz=TagMonoid::op(t[u].lz,v);\n    }\n    void push(int u,ll l,ll\
    \ m,ll r){\n        if(t[u].l==-1){int c=new_node(create(l,m));t[u].l=c;}\n  \
    \      if(t[u].r==-1){int c=new_node(create(m+1,r));t[u].r=c;}\n        apply(t[u].l,t[u].lz);\n\
    \        apply(t[u].r,t[u].lz);\n        t[u].lz=TagMonoid::unit();\n    }\n \
    \   void modify(ll l,ll r,int u,ll x,const Info &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[u].val=v);\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        modify(l,m,t[u].l,x,v);\n        modify(m+1,r,t[u].r,x,v);\n        pull(u);\n\
    \    }\n    void modify(ll x,const Info &v){\n        modify(lb,ub,0,x,v);\n \
    \   }\n    void update(ll l,ll r,int u,ll x,ll y,const Tag &v){\n        if(y<l||r<x)return;\n\
    \        if(x<=l&&r<=y)return apply(u,v);\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        update(l,m,t[u].l,x,y,v);\n        update(m+1,r,t[u].r,x,y,v);\n    \
    \    pull(u);\n    }\n    void update(ll x,ll y,const Tag &v){\n        update(lb,ub,0,x,y,v);\n\
    \    }\n    Info query(ll l,ll r,int u,ll x,ll y){\n        if(y<l||r<x)return\
    \ InfoMonoid::unit();\n        if(x<=l&&r<=y)return t[u].val;\n        ll m=l+(r-l)/2;\n\
    \        push(u,l,m,r);\n        return InfoMonoid::op(query(l,m,t[u].l,x,y),query(m+1,r,t[u].r,x,y));\n\
    \    }\n    Info query(ll x,ll y){\n        return query(lb,ub,0,x,y);\n    }\n\
    \    template<class F>\n    ll findfirst(ll l,ll r,int u,ll x,ll y,const F &f){\n\
    \        if(y<l||r<x||!f(t[u].val))return ub+1;\n        if(l==r)return l;\n \
    \       ll m=l+(r-l)/2;\n        push(u,l,m,r);\n        ll res=findfirst(l,m,t[u].l,x,y,f);\n\
    \        if(res==ub+1)res=findfirst(m+1,r,t[u].r,x,y,f);\n        return res;\n\
    \    }\n    template<class F>\n    ll findfirst(ll x,ll y,const F &f){\n     \
    \   return findfirst(lb,ub,0,x,y,f);\n    }\n    template<class F>\n    ll findlast(ll\
    \ l,ll r,int u,ll x,ll y,const F &f){\n        if(y<l||r<x||!f(t[u].val))return\
    \ lb-1;\n        if(l==r)return l;\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        ll res=findlast(m+1,r,t[u].r,x,y,f);\n        if(res==lb-1)res=findlast(l,m,t[u].l,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    ll findlast(ll x,ll y,const\
    \ F &f){\n        return findlast(lb,ub,0,x,y,f);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description:\
    \ Dynamic Segment Tree\n */\n\ntemplate<class MonoidAction>\nstruct DynamicSegmentTree{\n\
    \    using InfoMonoid = typename MonoidAction::InfoMonoid;\n    using TagMonoid\
    \ = typename MonoidAction::TagMonoid;\n    using Info = typename MonoidAction::Info;\n\
    \    using Tag = typename MonoidAction::Tag;\n    struct Node{\n        Info val;\n\
    \        Tag lz;\n        int l,r;\n        Node(Info v):val(v),lz(TagMonoid::unit()),l(-1),r(-1){}\n\
    \    };\n    ll lb,ub;\n    vector<Node> t;\n    function<Info(ll,ll)> create;\n\
    \    DynamicSegmentTree(){init(0,0);}\n    DynamicSegmentTree(ll n){init(0,n-1);}\n\
    \    DynamicSegmentTree(ll lb,ll ub){init(lb,ub);}\n    DynamicSegmentTree(ll\
    \ lb,ll ub,function<Info(ll,ll)> create){init(lb,ub,create);}\n    void init(ll\
    \ _lb,ll _ub,function<Info(ll,ll)> _create=[](ll l,ll r){return InfoMonoid::unit();}){\n\
    \        lb=_lb,ub=_ub;\n        create=_create;\n        t.clear();\n       \
    \ new_node(create(lb,ub));\n    }\n    int new_node(const Info &v){\n        t.emplace_back(v);\n\
    \        return t.size()-1;\n    }\n    void pull(int u){\n        t[u].val=InfoMonoid::op(t[t[u].l].val,t[t[u].r].val);\n\
    \    }\n    void apply(int u,const Tag &v){\n        t[u].val=MonoidAction::op(t[u].val,v);\n\
    \        t[u].lz=TagMonoid::op(t[u].lz,v);\n    }\n    void push(int u,ll l,ll\
    \ m,ll r){\n        if(t[u].l==-1){int c=new_node(create(l,m));t[u].l=c;}\n  \
    \      if(t[u].r==-1){int c=new_node(create(m+1,r));t[u].r=c;}\n        apply(t[u].l,t[u].lz);\n\
    \        apply(t[u].r,t[u].lz);\n        t[u].lz=TagMonoid::unit();\n    }\n \
    \   void modify(ll l,ll r,int u,ll x,const Info &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[u].val=v);\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        modify(l,m,t[u].l,x,v);\n        modify(m+1,r,t[u].r,x,v);\n        pull(u);\n\
    \    }\n    void modify(ll x,const Info &v){\n        modify(lb,ub,0,x,v);\n \
    \   }\n    void update(ll l,ll r,int u,ll x,ll y,const Tag &v){\n        if(y<l||r<x)return;\n\
    \        if(x<=l&&r<=y)return apply(u,v);\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        update(l,m,t[u].l,x,y,v);\n        update(m+1,r,t[u].r,x,y,v);\n    \
    \    pull(u);\n    }\n    void update(ll x,ll y,const Tag &v){\n        update(lb,ub,0,x,y,v);\n\
    \    }\n    Info query(ll l,ll r,int u,ll x,ll y){\n        if(y<l||r<x)return\
    \ InfoMonoid::unit();\n        if(x<=l&&r<=y)return t[u].val;\n        ll m=l+(r-l)/2;\n\
    \        push(u,l,m,r);\n        return InfoMonoid::op(query(l,m,t[u].l,x,y),query(m+1,r,t[u].r,x,y));\n\
    \    }\n    Info query(ll x,ll y){\n        return query(lb,ub,0,x,y);\n    }\n\
    \    template<class F>\n    ll findfirst(ll l,ll r,int u,ll x,ll y,const F &f){\n\
    \        if(y<l||r<x||!f(t[u].val))return ub+1;\n        if(l==r)return l;\n \
    \       ll m=l+(r-l)/2;\n        push(u,l,m,r);\n        ll res=findfirst(l,m,t[u].l,x,y,f);\n\
    \        if(res==ub+1)res=findfirst(m+1,r,t[u].r,x,y,f);\n        return res;\n\
    \    }\n    template<class F>\n    ll findfirst(ll x,ll y,const F &f){\n     \
    \   return findfirst(lb,ub,0,x,y,f);\n    }\n    template<class F>\n    ll findlast(ll\
    \ l,ll r,int u,ll x,ll y,const F &f){\n        if(y<l||r<x||!f(t[u].val))return\
    \ lb-1;\n        if(l==r)return l;\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        ll res=findlast(m+1,r,t[u].r,x,y,f);\n        if(res==lb-1)res=findlast(l,m,t[u].l,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    ll findlast(ll x,ll y,const\
    \ F &f){\n        return findlast(lb,ub,0,x,y,f);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/dynamic-segment-tree.hpp
  requiredBy: []
  timestamp: '2026-10-25 17:59:55+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp
documentation_of: data-structure/segment-tree/dynamic-segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/segment-tree/dynamic-segment-tree.hpp
- /library/data-structure/segment-tree/dynamic-segment-tree.hpp.html
title: data-structure/segment-tree/dynamic-segment-tree.hpp
---
