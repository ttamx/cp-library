---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/link-cut-tree/lazy-link-cut-tree.hpp
    title: data-structure/link-cut-tree/lazy-link-cut-tree.hpp
  - icon: ':question:'
    path: data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
    title: data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/link-cut-tree/lazy-reversible-bbst.hpp\"\n\
    \n/**\n * Author: Teetat Info.\n * Date: 2024-04-13\n * Description: Lazy Reversible\
    \ BBST Base.\n */\n\ntemplate<class Tree,class Node,class MonoidAction>\nstruct\
    \ LazyReversibleBBST:Tree{\n    using Tree::merge;\n    using Tree::split;\n \
    \   using typename Tree::Ptr;\n    using InfoMonoid = typename MonoidAction::InfoMonoid;\n\
    \    using TagMonoid = typename MonoidAction::TagMonoid;\n    using Info = typename\
    \ MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n\n    LazyReversibleBBST()=default;\n\
    \n    Info sum(Ptr t){\n        return t?t->sum:InfoMonoid::unit();\n    }\n \
    \   void pull(Ptr t){\n        if(!t)return;\n        push(t);\n        t->size=1;\n\
    \        t->sum=t->val;\n        t->revsum=t->val;\n        if(t->l){\n      \
    \      t->size+=t->l->size;\n            t->sum=InfoMonoid::op(t->l->sum,t->sum);\n\
    \            t->revsum=InfoMonoid::op(t->revsum,t->l->revsum);\n        }\n  \
    \      if(t->r){\n            t->size+=t->r->size;\n            t->sum=InfoMonoid::op(t->sum,t->r->sum);\n\
    \            t->revsum=InfoMonoid::op(t->r->revsum,t->revsum);\n        }\n  \
    \  }\n    void push(Ptr t){\n        if(!t)return;\n        if(t->rev){\n    \
    \        toggle(t->l);\n            toggle(t->r);\n            t->rev=false;\n\
    \        }\n        if(t->lz!=TagMonoid::unit()){\n            propagate(t->l,t->lz);\n\
    \            propagate(t->r,t->lz);\n            t->lz=TagMonoid::unit();\n  \
    \      }\n    }\n    void toggle(Ptr t){\n        if(!t)return;\n        swap(t->l,t->r);\n\
    \        swap(t->sum,t->revsum);\n        t->rev^=true;\n    }\n    void propagate(Ptr\
    \ t,const Tag &v){\n        if(!t)return;\n        t->val=MonoidAction::op(t->val,v);\n\
    \        t->sum=MonoidAction::op(t->sum,v);\n        t->revsum=MonoidAction::op(t->revsum,v);\n\
    \        t->lz=TagMonoid::op(t->lz,v);\n    }\n    void apply(Ptr &t,int l,int\
    \ r,const Tag &v){\n        if(l>r)return;\n        auto x=split(t,l);\n     \
    \   auto y=split(x.second,r-l+1);\n        propagate(y.first,v);\n        t=merge(x.first,merge(y.first,y.second));\n\
    \    }\n    Info query(Ptr &t,int l,int r){\n        if(l>r)return InfoMonoid::unit();\n\
    \        auto x=split(t,l);\n        auto y=split(x.second,r-l+1);\n        Info\
    \ res=sum(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n     \
    \   return res;\n    }\n    void reverse(Ptr &t,int l,int r){\n        if(l>r)return;\n\
    \        auto x=split(t,l);\n        auto y=split(x.second,r-l+1);\n        toggle(y.first);\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat Info.\n * Date: 2024-04-13\n * Description:\
    \ Lazy Reversible BBST Base.\n */\n\ntemplate<class Tree,class Node,class MonoidAction>\n\
    struct LazyReversibleBBST:Tree{\n    using Tree::merge;\n    using Tree::split;\n\
    \    using typename Tree::Ptr;\n    using InfoMonoid = typename MonoidAction::InfoMonoid;\n\
    \    using TagMonoid = typename MonoidAction::TagMonoid;\n    using Info = typename\
    \ MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n\n    LazyReversibleBBST()=default;\n\
    \n    Info sum(Ptr t){\n        return t?t->sum:InfoMonoid::unit();\n    }\n \
    \   void pull(Ptr t){\n        if(!t)return;\n        push(t);\n        t->size=1;\n\
    \        t->sum=t->val;\n        t->revsum=t->val;\n        if(t->l){\n      \
    \      t->size+=t->l->size;\n            t->sum=InfoMonoid::op(t->l->sum,t->sum);\n\
    \            t->revsum=InfoMonoid::op(t->revsum,t->l->revsum);\n        }\n  \
    \      if(t->r){\n            t->size+=t->r->size;\n            t->sum=InfoMonoid::op(t->sum,t->r->sum);\n\
    \            t->revsum=InfoMonoid::op(t->r->revsum,t->revsum);\n        }\n  \
    \  }\n    void push(Ptr t){\n        if(!t)return;\n        if(t->rev){\n    \
    \        toggle(t->l);\n            toggle(t->r);\n            t->rev=false;\n\
    \        }\n        if(t->lz!=TagMonoid::unit()){\n            propagate(t->l,t->lz);\n\
    \            propagate(t->r,t->lz);\n            t->lz=TagMonoid::unit();\n  \
    \      }\n    }\n    void toggle(Ptr t){\n        if(!t)return;\n        swap(t->l,t->r);\n\
    \        swap(t->sum,t->revsum);\n        t->rev^=true;\n    }\n    void propagate(Ptr\
    \ t,const Tag &v){\n        if(!t)return;\n        t->val=MonoidAction::op(t->val,v);\n\
    \        t->sum=MonoidAction::op(t->sum,v);\n        t->revsum=MonoidAction::op(t->revsum,v);\n\
    \        t->lz=TagMonoid::op(t->lz,v);\n    }\n    void apply(Ptr &t,int l,int\
    \ r,const Tag &v){\n        if(l>r)return;\n        auto x=split(t,l);\n     \
    \   auto y=split(x.second,r-l+1);\n        propagate(y.first,v);\n        t=merge(x.first,merge(y.first,y.second));\n\
    \    }\n    Info query(Ptr &t,int l,int r){\n        if(l>r)return InfoMonoid::unit();\n\
    \        auto x=split(t,l);\n        auto y=split(x.second,r-l+1);\n        Info\
    \ res=sum(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n     \
    \   return res;\n    }\n    void reverse(Ptr &t,int l,int r){\n        if(l>r)return;\n\
    \        auto x=split(t,l);\n        auto y=split(x.second,r-l+1);\n        toggle(y.first);\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/link-cut-tree/lazy-reversible-bbst.hpp
  requiredBy:
  - data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
  - data-structure/link-cut-tree/lazy-link-cut-tree.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  - verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: data-structure/link-cut-tree/lazy-reversible-bbst.hpp
layout: document
redirect_from:
- /library/data-structure/link-cut-tree/lazy-reversible-bbst.hpp
- /library/data-structure/link-cut-tree/lazy-reversible-bbst.hpp.html
title: data-structure/link-cut-tree/lazy-reversible-bbst.hpp
---
