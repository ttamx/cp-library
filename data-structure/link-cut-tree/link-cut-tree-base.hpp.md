---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/link-cut-tree/lazy-link-cut-tree.hpp
    title: data-structure/link-cut-tree/lazy-link-cut-tree.hpp
  - icon: ':warning:'
    path: data-structure/link-cut-tree/link-cut-tree.hpp
    title: data-structure/link-cut-tree/link-cut-tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
    title: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/link-cut-tree/link-cut-tree-base.hpp\"\n\n\
    /**\n * Author: Teetat T.\n * Date: 2024-05-19\n * Description: Link Cut Tree\
    \ Base.\n * Usage:\n *  evert(u): make u be the root of the tree.\n *  link(u,v):\
    \ attach u to v.\n *  cut(u,v): remove edge between u and v.\n *  get_root(u):\
    \ get the root of the tree containing u.\n *  lca(u,v): get the lowest common\
    \ ancestor of u and v.\n *  fold(u,v): get the value of the path from u to v.\n\
    \ */\n\ntemplate<class Splay>\nstruct LinkCutTreeBase:Splay{\n    using Node =\
    \ typename Splay::Node;\n    using Ptr = Node*;\n    using T = typename Node::value_type;\n\
    \    Ptr expose(Ptr t){\n        Ptr pc=nullptr; // preferred child\n        for(Ptr\
    \ cur=t;cur;cur=cur->p){\n            this->splay(cur);\n            cur->r=pc;\n\
    \            this->pull(cur);\n            pc=cur;\n        }\n        this->splay(t);\n\
    \        return pc;\n    }\n    void evert(Ptr t){ // make t be the root of the\
    \ tree\n        expose(t);\n        this->toggle(t);\n        this->push(t);\n\
    \    }\n    void link(Ptr u,Ptr v){ // attach u to v\n        evert(u);\n    \
    \    expose(v);\n        u->p=v;\n    }\n    void cut(Ptr u,Ptr v){ // cut edge\
    \ between u and v\n        evert(u);\n        expose(v);\n        assert(u->p==v);\n\
    \        v->l=u->p=nullptr;\n        this->pull(v);\n    }\n    Ptr get_root(Ptr\
    \ t){\n        expose(t);\n        while(t->l)this->push(t),t=t->l;\n        this->splay(t);\n\
    \        return t;\n    }\n    Ptr lca(Ptr u,Ptr v){\n        if(get_root(u)!=get_root(v))return\
    \ nullptr;\n        expose(u);\n        return expose(v);\n    }\n    void set_val(Ptr\
    \ t,const T &val){\n        this->evert(t);\n        t->val=val;\n        this->pull(t);\n\
    \    }\n    T get_val(Ptr t){\n        this->evert(t);\n        return t->val;\n\
    \    }\n    T fold(Ptr u,Ptr v){\n        evert(u);\n        expose(v);\n    \
    \    return v->sum;\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-05-19\n * Description:\
    \ Link Cut Tree Base.\n * Usage:\n *  evert(u): make u be the root of the tree.\n\
    \ *  link(u,v): attach u to v.\n *  cut(u,v): remove edge between u and v.\n *\
    \  get_root(u): get the root of the tree containing u.\n *  lca(u,v): get the\
    \ lowest common ancestor of u and v.\n *  fold(u,v): get the value of the path\
    \ from u to v.\n */\n\ntemplate<class Splay>\nstruct LinkCutTreeBase:Splay{\n\
    \    using Node = typename Splay::Node;\n    using Ptr = Node*;\n    using T =\
    \ typename Node::value_type;\n    Ptr expose(Ptr t){\n        Ptr pc=nullptr;\
    \ // preferred child\n        for(Ptr cur=t;cur;cur=cur->p){\n            this->splay(cur);\n\
    \            cur->r=pc;\n            this->pull(cur);\n            pc=cur;\n \
    \       }\n        this->splay(t);\n        return pc;\n    }\n    void evert(Ptr\
    \ t){ // make t be the root of the tree\n        expose(t);\n        this->toggle(t);\n\
    \        this->push(t);\n    }\n    void link(Ptr u,Ptr v){ // attach u to v\n\
    \        evert(u);\n        expose(v);\n        u->p=v;\n    }\n    void cut(Ptr\
    \ u,Ptr v){ // cut edge between u and v\n        evert(u);\n        expose(v);\n\
    \        assert(u->p==v);\n        v->l=u->p=nullptr;\n        this->pull(v);\n\
    \    }\n    Ptr get_root(Ptr t){\n        expose(t);\n        while(t->l)this->push(t),t=t->l;\n\
    \        this->splay(t);\n        return t;\n    }\n    Ptr lca(Ptr u,Ptr v){\n\
    \        if(get_root(u)!=get_root(v))return nullptr;\n        expose(u);\n   \
    \     return expose(v);\n    }\n    void set_val(Ptr t,const T &val){\n      \
    \  this->evert(t);\n        t->val=val;\n        this->pull(t);\n    }\n    T\
    \ get_val(Ptr t){\n        this->evert(t);\n        return t->val;\n    }\n  \
    \  T fold(Ptr u,Ptr v){\n        evert(u);\n        expose(v);\n        return\
    \ v->sum;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/link-cut-tree/link-cut-tree-base.hpp
  requiredBy:
  - data-structure/link-cut-tree/link-cut-tree.hpp
  - data-structure/link-cut-tree/lazy-link-cut-tree.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
documentation_of: data-structure/link-cut-tree/link-cut-tree-base.hpp
layout: document
redirect_from:
- /library/data-structure/link-cut-tree/link-cut-tree-base.hpp
- /library/data-structure/link-cut-tree/link-cut-tree-base.hpp.html
title: data-structure/link-cut-tree/link-cut-tree-base.hpp
---
