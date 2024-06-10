---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/link-cut-tree/link-cut-tree.hpp
    title: data-structure/link-cut-tree/link-cut-tree.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/link-cut-tree/reversible-splay-tree.hpp
    title: data-structure/link-cut-tree/reversible-splay-tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_reverse_range_sum.test.cpp
    title: verify/yosupo/data-structure/range_reverse_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/link-cut-tree/reversible-bbst.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Date: 2024-04-13\n * Description: Revesible BBST Base.\n\
    \ */\n\ntemplate<class Tree,class Node,class Monoid>\nstruct ReversibleBBST:Tree{\n\
    \    using Tree::merge;\n    using Tree::split;\n    using typename Tree::Ptr;\n\
    \    using T = typename Monoid::value_type;\n\n    ReversibleBBST()=default;\n\
    \n    T sum(Ptr t){\n        return t?t->sum:T();\n    }\n    void pull(Ptr t){\n\
    \        if(!t)return;\n        t->size=1;\n        t->sum=t->val;\n        t->revsum=t->val;\n\
    \        if(t->l){\n            t->size+=t->l->size;\n            t->sum=Monoid::op(t->l->sum,t->sum);\n\
    \            t->revsum=Monoid::op(t->revsum,t->l->revsum);\n        }\n      \
    \  if(t->r){\n            t->size+=t->r->size;\n            t->sum=Monoid::op(t->sum,t->r->sum);\n\
    \            t->revsum=Monoid::op(t->r->revsum,t->revsum);\n        }\n    }\n\
    \    void push(Ptr t){\n        if(!t)return;\n        if(t->rev){\n         \
    \   toggle(t->l);\n            toggle(t->r);\n            t->rev=false;\n    \
    \    }\n    }\n    void toggle(Ptr t){\n        if(!t)return;\n        swap(t->l,t->r);\n\
    \        swap(t->sum,t->revsum);\n        t->rev^=true;\n    }\n    T query(Ptr\
    \ &t,int l,int r){\n        if(l>r)return T();\n        auto x=split(t,l);\n \
    \       auto y=split(x.second,r-l+1);\n        T res=sum(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n\
    \        return res;\n    }\n    void reverse(Ptr &t,int l,int r){\n        if(l>r)return;\n\
    \        auto x=split(t,l);\n        auto y=split(x.second,r-l+1);\n        toggle(y.first);\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-13\n * Description:\
    \ Revesible BBST Base.\n */\n\ntemplate<class Tree,class Node,class Monoid>\n\
    struct ReversibleBBST:Tree{\n    using Tree::merge;\n    using Tree::split;\n\
    \    using typename Tree::Ptr;\n    using T = typename Monoid::value_type;\n\n\
    \    ReversibleBBST()=default;\n\n    T sum(Ptr t){\n        return t?t->sum:T();\n\
    \    }\n    void pull(Ptr t){\n        if(!t)return;\n        t->size=1;\n   \
    \     t->sum=t->val;\n        t->revsum=t->val;\n        if(t->l){\n         \
    \   t->size+=t->l->size;\n            t->sum=Monoid::op(t->l->sum,t->sum);\n \
    \           t->revsum=Monoid::op(t->revsum,t->l->revsum);\n        }\n       \
    \ if(t->r){\n            t->size+=t->r->size;\n            t->sum=Monoid::op(t->sum,t->r->sum);\n\
    \            t->revsum=Monoid::op(t->r->revsum,t->revsum);\n        }\n    }\n\
    \    void push(Ptr t){\n        if(!t)return;\n        if(t->rev){\n         \
    \   toggle(t->l);\n            toggle(t->r);\n            t->rev=false;\n    \
    \    }\n    }\n    void toggle(Ptr t){\n        if(!t)return;\n        swap(t->l,t->r);\n\
    \        swap(t->sum,t->revsum);\n        t->rev^=true;\n    }\n    T query(Ptr\
    \ &t,int l,int r){\n        if(l>r)return T();\n        auto x=split(t,l);\n \
    \       auto y=split(x.second,r-l+1);\n        T res=sum(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n\
    \        return res;\n    }\n    void reverse(Ptr &t,int l,int r){\n        if(l>r)return;\n\
    \        auto x=split(t,l);\n        auto y=split(x.second,r-l+1);\n        toggle(y.first);\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/link-cut-tree/reversible-bbst.hpp
  requiredBy:
  - data-structure/link-cut-tree/link-cut-tree.hpp
  - data-structure/link-cut-tree/reversible-splay-tree.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/range_reverse_range_sum.test.cpp
documentation_of: data-structure/link-cut-tree/reversible-bbst.hpp
layout: document
redirect_from:
- /library/data-structure/link-cut-tree/reversible-bbst.hpp
- /library/data-structure/link-cut-tree/reversible-bbst.hpp.html
title: data-structure/link-cut-tree/reversible-bbst.hpp
---
