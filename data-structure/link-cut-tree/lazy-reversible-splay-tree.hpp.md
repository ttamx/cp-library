---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/link-cut-tree/lazy-reversible-bbst.hpp
    title: data-structure/link-cut-tree/lazy-reversible-bbst.hpp
  - icon: ':question:'
    path: data-structure/link-cut-tree/splay-tree-base.hpp
    title: data-structure/link-cut-tree/splay-tree-base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/link-cut-tree/lazy-link-cut-tree.hpp
    title: data-structure/link-cut-tree/lazy-link-cut-tree.hpp
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
  bundledCode: "#line 2 \"data-structure/link-cut-tree/splay-tree-base.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Date: 2024-04-13\n * Description: Splay Tree. splay(u)\
    \ will make node u be the root of the tree in amortized O(log n) time.\n */\n\n\
    template<class Node>\nstruct SplayTreeBase{\n    using Ptr = Node*;\n    bool\
    \ is_root(Ptr t){\n        return !(t->p)||(t->p->l!=t&&t->p->r!=t);\n    } //\
    \ The parent of the root stores the path parant in link cut tree.\n    int size(Ptr\
    \ t){\n        return t?t->size:0;\n    }\n    virtual void push(Ptr t){};\n \
    \   virtual void pull(Ptr t){};\n    int pos(Ptr t){\n        if(t->p){\n    \
    \        if(t->p->l==t)return -1;\n            if(t->p->r==t)return 1;\n     \
    \   }\n        return 0;\n    }\n    void rotate(Ptr t){\n        Ptr x=t->p,y=x->p;\n\
    \        if(pos(t)==-1){\n            if((x->l=t->r))t->r->p=x;\n            t->r=x,x->p=t;\n\
    \        }else{\n            if((x->r=t->l))t->l->p=x;\n            t->l=x,x->p=t;\n\
    \        }\n        pull(x),pull(t);\n        if((t->p=y)){\n            if(y->l==x)y->l=t;\n\
    \            if(y->r==x)y->r=t;\n        }\n    }\n    void splay(Ptr t){\n  \
    \      if(!t)return;\n        push(t);\n        while(!is_root(t)){\n        \
    \    Ptr x=t->p;\n            if(is_root(x)){\n                push(x),push(t);\n\
    \                rotate(t);\n            }else{\n                Ptr y=x->p;\n\
    \                push(y),push(x),push(t);\n                if(pos(x)==pos(t))rotate(x),rotate(t);\n\
    \                else rotate(t),rotate(t);\n            }\n        }\n    }\n\
    \    Ptr get_first(Ptr t){\n        while(t->l)push(t),t=t->l;\n        splay(t);\n\
    \        return t;\n    }\n    Ptr get_last(Ptr t){\n        while(t->r)push(t),t=t->r;\n\
    \        splay(t);\n        return t;\n    }\n    Ptr merge(Ptr l,Ptr r){\n  \
    \      splay(l),splay(r);\n        if(!l)return r;\n        if(!r)return l;\n\
    \        l=get_last(l);\n        l->r=r;\n        r->p=l;\n        pull(l);\n\
    \        return l;\n    }\n    pair<Ptr,Ptr> split(Ptr t,int k){\n        if(!t)return\
    \ {nullptr,nullptr};\n        if(k==0)return {nullptr,t};\n        if(k==size(t))return\
    \ {t,nullptr};\n        push(t);\n        if(k<=size(t->l)){\n            auto\
    \ x=split(t->l,k);\n            t->l=x.second;\n            t->p=nullptr;\n  \
    \          if(x.second)x.second->p=t;\n            pull(t);\n            return\
    \ {x.first,t};\n        }else{\n            auto x=split(t->r,k-size(t->l)-1);\n\
    \            t->r=x.first;\n            t->p=nullptr;\n            if(x.first)x.first->p=t;\n\
    \            pull(t);\n            return {t,x.second};\n        }\n    }\n  \
    \  void insert(Ptr &t,int k,Ptr v){\n        splay(t);\n        auto x=split(t,k);\n\
    \        t=merge(merge(x.first,v),x.second);\n    }\n    void erase(Ptr &t,int\
    \ k){\n        splay(t);\n        auto x=split(t,k);\n        auto y=split(x.second,1);\n\
    \        // delete y.first;\n        t=merge(x.first,y.second);\n    }\n    template<class\
    \ T>\n    Ptr build(const vector<T> &v){\n        if(v.empty())return nullptr;\n\
    \        function<Ptr(int,int)> build=[&](int l,int r){\n            if(l==r)return\
    \ new Node(v[l]);\n            int m=(l+r)/2;\n            return merge(build(l,m),build(m+1,r));\n\
    \        };\n        return build(0,v.size()-1);\n    }\n};\n\n#line 2 \"data-structure/link-cut-tree/lazy-reversible-bbst.hpp\"\
    \n\n/**\n * Author: Teetat Info.\n * Date: 2024-04-13\n * Description: Lazy Reversible\
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
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n};\n\n#line 4 \"data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-13\n * Description: Lazy Reversible\
    \ Splay Tree.\n */\n\ntemplate<class MonoidAction>\nstruct LazyReversibleSplayTreeNode{\n\
    \    using Ptr = LazyReversibleSplayTreeNode*;\n    using InfoMonoid = typename\
    \ MonoidAction::InfoMonoid;\n    using TagMonoid = typename MonoidAction::TagMonoid;\n\
    \    using Info = typename MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n\
    \    using value_type = Info;\n    Ptr l,r,p;\n    Info val,sum,revsum;\n    Tag\
    \ lz;\n    int size;\n    bool rev;\n    LazyReversibleSplayTreeNode(const Info\
    \ &_val=InfoMonoid::unit(),const Tag &_lz=TagMonoid::unit())\n        :l(),r(),p(),val(_val),sum(_val),revsum(_val),lz(_lz),size(1),rev(false){}\n\
    };\n\ntemplate<class MonoidAction>\nstruct LazyReversibleSplayTree\n    : LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<MonoidAction>>,\n\
    \      LazyReversibleSplayTreeNode<MonoidAction>,MonoidAction>{\n    using Node\
    \ = LazyReversibleSplayTreeNode<MonoidAction>;\n};\n\n"
  code: "#pragma once\n#include \"data-structure/link-cut-tree/splay-tree-base.hpp\"\
    \n#include \"data-structure/link-cut-tree/lazy-reversible-bbst.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Date: 2024-04-13\n * Description: Lazy Reversible Splay\
    \ Tree.\n */\n\ntemplate<class MonoidAction>\nstruct LazyReversibleSplayTreeNode{\n\
    \    using Ptr = LazyReversibleSplayTreeNode*;\n    using InfoMonoid = typename\
    \ MonoidAction::InfoMonoid;\n    using TagMonoid = typename MonoidAction::TagMonoid;\n\
    \    using Info = typename MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n\
    \    using value_type = Info;\n    Ptr l,r,p;\n    Info val,sum,revsum;\n    Tag\
    \ lz;\n    int size;\n    bool rev;\n    LazyReversibleSplayTreeNode(const Info\
    \ &_val=InfoMonoid::unit(),const Tag &_lz=TagMonoid::unit())\n        :l(),r(),p(),val(_val),sum(_val),revsum(_val),lz(_lz),size(1),rev(false){}\n\
    };\n\ntemplate<class MonoidAction>\nstruct LazyReversibleSplayTree\n    : LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<MonoidAction>>,\n\
    \      LazyReversibleSplayTreeNode<MonoidAction>,MonoidAction>{\n    using Node\
    \ = LazyReversibleSplayTreeNode<MonoidAction>;\n};\n\n"
  dependsOn:
  - data-structure/link-cut-tree/splay-tree-base.hpp
  - data-structure/link-cut-tree/lazy-reversible-bbst.hpp
  isVerificationFile: false
  path: data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
  requiredBy:
  - data-structure/link-cut-tree/lazy-link-cut-tree.hpp
  timestamp: '2024-06-10 16:05:09+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  - verify/yosupo/data-structure/dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
layout: document
redirect_from:
- /library/data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
- /library/data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp.html
title: data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
---
