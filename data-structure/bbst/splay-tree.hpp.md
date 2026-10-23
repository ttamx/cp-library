---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp
    title: verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/bbst/splay-tree.hpp\"\n\ntemplate<class Monoid>\n\
    struct SplayTree{\n    using T = typename Monoid::value_type;\n    struct Node{\n\
    \        int l,r,p,sz;\n        bool rev;\n        T val,sum,revsum;\n    };\n\
    \    vector<Node> t;\n\n    SplayTree(int reserve=0){\n        t.reserve(reserve+1);\n\
    \        t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});\n\
    \    }\n    int make(const T &v){\n        t.push_back(Node{0,0,0,1,false,v,v,v});\n\
    \        return SZ(t)-1;\n    }\n    int sz(int x){return t[x].sz;}\n    T sum(int\
    \ x){return t[x].sum;}\n\n    void pull(int x){\n        Node &v=t[x];\n     \
    \   v.sz=t[v.l].sz+1+t[v.r].sz;\n        v.sum=Monoid::op(Monoid::op(t[v.l].sum,v.val),t[v.r].sum);\n\
    \        v.revsum=Monoid::op(Monoid::op(t[v.r].revsum,v.val),t[v.l].revsum);\n\
    \    }\n    void toggle(int x){\n        if(!x)return;\n        swap(t[x].l,t[x].r);\n\
    \        swap(t[x].sum,t[x].revsum);\n        t[x].rev^=1;\n    }\n    void push(int\
    \ x){\n        if(t[x].rev){\n            toggle(t[x].l);\n            toggle(t[x].r);\n\
    \            t[x].rev=false;\n        }\n    }\n    void rotate(int x){\n    \
    \    int p=t[x].p,g=t[p].p;\n        if(t[p].l==x){\n            t[p].l=t[x].r;\n\
    \            if(t[x].r)t[t[x].r].p=p;\n            t[x].r=p;\n        }else{\n\
    \            t[p].r=t[x].l;\n            if(t[x].l)t[t[x].l].p=p;\n          \
    \  t[x].l=p;\n        }\n        t[p].p=x;\n        t[x].p=g;\n        if(g)(t[g].l==p?t[g].l:t[g].r)=x;\n\
    \        pull(p);\n    }\n    void splay(int x){\n        while(int p=t[x].p){\n\
    \            int g=t[p].p;\n            if(g)rotate((t[g].l==p)==(t[p].l==x)?p:x);\n\
    \            rotate(x);\n        }\n        pull(x);\n    }\n    int kth(int x,int\
    \ k){\n        assert(0<=k&&k<sz(x));\n        while(true){\n            push(x);\n\
    \            int ls=t[t[x].l].sz;\n            if(k<ls)x=t[x].l;\n           \
    \ else if(k==ls)break;\n            else k-=ls+1,x=t[x].r;\n        }\n      \
    \  splay(x);\n        return x;\n    }\n    int build(const vector<T> &a){\n \
    \       auto rec=[&](auto &&self,int l,int r)->int{\n            if(l>r)return\
    \ 0;\n            int m=(l+r)/2,x=make(a[m]);\n            int lc=self(self,l,m-1),rc=self(self,m+1,r);\n\
    \            t[x].l=lc,t[x].r=rc;\n            if(lc)t[lc].p=x;\n            if(rc)t[rc].p=x;\n\
    \            pull(x);\n            return x;\n        };\n        return rec(rec,0,SZ(a)-1);\n\
    \    }\n    int merge(int a,int b){\n        if(!a||!b)return a|b;\n        a=kth(a,sz(a)-1);\n\
    \        t[a].r=b;\n        t[b].p=a;\n        pull(a);\n        return a;\n \
    \   }\n    pair<int,int> split(int x,int k){\n        if(k<=0)return {0,x};\n\
    \        if(k>=sz(x))return {x,0};\n        x=kth(x,k-1);\n        int y=t[x].r;\n\
    \        t[x].r=0;\n        t[y].p=0;\n        pull(x);\n        return {x,y};\n\
    \    }\n    T query(int &x,int l,int r){\n        if(l>r)return Monoid::unit();\n\
    \        auto [a,b]=split(x,l);\n        auto [c,d]=split(b,r-l+1);\n        T\
    \ res=sum(c);\n        x=merge(a,merge(c,d));\n        return res;\n    }\n  \
    \  void reverse(int &x,int l,int r){\n        if(l>=r)return;\n        auto [a,b]=split(x,l);\n\
    \        auto [c,d]=split(b,r-l+1);\n        toggle(c);\n        x=merge(a,merge(c,d));\n\
    \    }\n    T get(int &x,int k){\n        x=kth(x,k);\n        return t[x].val;\n\
    \    }\n    void set(int &x,int k,const T &v){\n        x=kth(x,k);\n        t[x].val=v;\n\
    \        pull(x);\n    }\n    void insert(int &x,int k,const T &v){\n        auto\
    \ [a,b]=split(x,k);\n        x=merge(merge(a,make(v)),b);\n    }\n    void erase(int\
    \ &x,int k){\n        auto [a,b]=split(x,k);\n        auto [c,d]=split(b,1);\n\
    \        x=merge(a,d);\n    }\n};\n"
  code: "#pragma once\n\ntemplate<class Monoid>\nstruct SplayTree{\n    using T =\
    \ typename Monoid::value_type;\n    struct Node{\n        int l,r,p,sz;\n    \
    \    bool rev;\n        T val,sum,revsum;\n    };\n    vector<Node> t;\n\n   \
    \ SplayTree(int reserve=0){\n        t.reserve(reserve+1);\n        t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});\n\
    \    }\n    int make(const T &v){\n        t.push_back(Node{0,0,0,1,false,v,v,v});\n\
    \        return SZ(t)-1;\n    }\n    int sz(int x){return t[x].sz;}\n    T sum(int\
    \ x){return t[x].sum;}\n\n    void pull(int x){\n        Node &v=t[x];\n     \
    \   v.sz=t[v.l].sz+1+t[v.r].sz;\n        v.sum=Monoid::op(Monoid::op(t[v.l].sum,v.val),t[v.r].sum);\n\
    \        v.revsum=Monoid::op(Monoid::op(t[v.r].revsum,v.val),t[v.l].revsum);\n\
    \    }\n    void toggle(int x){\n        if(!x)return;\n        swap(t[x].l,t[x].r);\n\
    \        swap(t[x].sum,t[x].revsum);\n        t[x].rev^=1;\n    }\n    void push(int\
    \ x){\n        if(t[x].rev){\n            toggle(t[x].l);\n            toggle(t[x].r);\n\
    \            t[x].rev=false;\n        }\n    }\n    void rotate(int x){\n    \
    \    int p=t[x].p,g=t[p].p;\n        if(t[p].l==x){\n            t[p].l=t[x].r;\n\
    \            if(t[x].r)t[t[x].r].p=p;\n            t[x].r=p;\n        }else{\n\
    \            t[p].r=t[x].l;\n            if(t[x].l)t[t[x].l].p=p;\n          \
    \  t[x].l=p;\n        }\n        t[p].p=x;\n        t[x].p=g;\n        if(g)(t[g].l==p?t[g].l:t[g].r)=x;\n\
    \        pull(p);\n    }\n    void splay(int x){\n        while(int p=t[x].p){\n\
    \            int g=t[p].p;\n            if(g)rotate((t[g].l==p)==(t[p].l==x)?p:x);\n\
    \            rotate(x);\n        }\n        pull(x);\n    }\n    int kth(int x,int\
    \ k){\n        assert(0<=k&&k<sz(x));\n        while(true){\n            push(x);\n\
    \            int ls=t[t[x].l].sz;\n            if(k<ls)x=t[x].l;\n           \
    \ else if(k==ls)break;\n            else k-=ls+1,x=t[x].r;\n        }\n      \
    \  splay(x);\n        return x;\n    }\n    int build(const vector<T> &a){\n \
    \       auto rec=[&](auto &&self,int l,int r)->int{\n            if(l>r)return\
    \ 0;\n            int m=(l+r)/2,x=make(a[m]);\n            int lc=self(self,l,m-1),rc=self(self,m+1,r);\n\
    \            t[x].l=lc,t[x].r=rc;\n            if(lc)t[lc].p=x;\n            if(rc)t[rc].p=x;\n\
    \            pull(x);\n            return x;\n        };\n        return rec(rec,0,SZ(a)-1);\n\
    \    }\n    int merge(int a,int b){\n        if(!a||!b)return a|b;\n        a=kth(a,sz(a)-1);\n\
    \        t[a].r=b;\n        t[b].p=a;\n        pull(a);\n        return a;\n \
    \   }\n    pair<int,int> split(int x,int k){\n        if(k<=0)return {0,x};\n\
    \        if(k>=sz(x))return {x,0};\n        x=kth(x,k-1);\n        int y=t[x].r;\n\
    \        t[x].r=0;\n        t[y].p=0;\n        pull(x);\n        return {x,y};\n\
    \    }\n    T query(int &x,int l,int r){\n        if(l>r)return Monoid::unit();\n\
    \        auto [a,b]=split(x,l);\n        auto [c,d]=split(b,r-l+1);\n        T\
    \ res=sum(c);\n        x=merge(a,merge(c,d));\n        return res;\n    }\n  \
    \  void reverse(int &x,int l,int r){\n        if(l>=r)return;\n        auto [a,b]=split(x,l);\n\
    \        auto [c,d]=split(b,r-l+1);\n        toggle(c);\n        x=merge(a,merge(c,d));\n\
    \    }\n    T get(int &x,int k){\n        x=kth(x,k);\n        return t[x].val;\n\
    \    }\n    void set(int &x,int k,const T &v){\n        x=kth(x,k);\n        t[x].val=v;\n\
    \        pull(x);\n    }\n    void insert(int &x,int k,const T &v){\n        auto\
    \ [a,b]=split(x,k);\n        x=merge(merge(a,make(v)),b);\n    }\n    void erase(int\
    \ &x,int k){\n        auto [a,b]=split(x,k);\n        auto [c,d]=split(b,1);\n\
    \        x=merge(a,d);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bbst/splay-tree.hpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:06+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp
documentation_of: data-structure/bbst/splay-tree.hpp
layout: document
redirect_from:
- /library/data-structure/bbst/splay-tree.hpp
- /library/data-structure/bbst/splay-tree.hpp.html
title: data-structure/bbst/splay-tree.hpp
---
