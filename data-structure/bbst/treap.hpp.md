---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
    title: verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/bbst/treap.hpp\"\n\ntemplate<class Monoid>\n\
    struct Treap{\n    using T = typename Monoid::value_type;\n    struct Node{\n\
    \        int l,r,sz,prio;\n        bool rev;\n        T val,sum,revsum;\n    };\n\
    \    vector<Node> t;\n\n    Treap(int n=0){\n        t.reserve(n+1);\n       \
    \ t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});\n\
    \    }\n    int new_node(const T &v){\n        t.push_back(Node{0,0,1,rng(),false,v,v,v});\n\
    \        return SZ(t)-1;\n    }\n    int size(int x){return t[x].sz;}\n    T sum(int\
    \ x){return t[x].sum;}\n\n    void pull(int x){\n        Node &v=t[x];\n     \
    \   v.sz=t[v.l].sz+1+t[v.r].sz;\n        v.sum=Monoid::op(Monoid::op(t[v.l].sum,v.val),t[v.r].sum);\n\
    \        v.revsum=Monoid::op(Monoid::op(t[v.r].revsum,v.val),t[v.l].revsum);\n\
    \    }\n    void toggle(int x){\n        if(!x)return;\n        swap(t[x].l,t[x].r);\n\
    \        swap(t[x].sum,t[x].revsum);\n        t[x].rev^=1;\n    }\n    void push(int\
    \ x){\n        if(t[x].rev){\n            toggle(t[x].l);\n            toggle(t[x].r);\n\
    \            t[x].rev=false;\n        }\n    }\n    int build(const vector<T>\
    \ &a){\n        vector<int> st;\n        for(auto &v:a){\n            int x=new_node(v),last=0;\n\
    \            while(!st.empty()&&t[st.back()].prio<t[x].prio){\n              \
    \  last=st.back();\n                pull(last);\n                st.pop_back();\n\
    \            }\n            t[x].l=last;\n            if(!st.empty())t[st.back()].r=x;\n\
    \            st.push_back(x);\n        }\n        for(int i=SZ(st)-1;i>=0;i--)pull(st[i]);\n\
    \        return st.empty()?0:st[0];\n    }\n    int merge(int a,int b){\n    \
    \    if(!a||!b)return a|b;\n        if(t[a].prio>t[b].prio){\n            push(a);\n\
    \            t[a].r=merge(t[a].r,b);\n            pull(a);\n            return\
    \ a;\n        }else{\n            push(b);\n            t[b].l=merge(a,t[b].l);\n\
    \            pull(b);\n            return b;\n        }\n    }\n    pair<int,int>\
    \ split(int x,int k){\n        if(!x)return {0,0};\n        push(x);\n       \
    \ int ls=t[t[x].l].sz;\n        if(k<=ls){\n            auto [a,b]=split(t[x].l,k);\n\
    \            t[x].l=b;\n            pull(x);\n            return {a,x};\n    \
    \    }else{\n            auto [a,b]=split(t[x].r,k-ls-1);\n            t[x].r=a;\n\
    \            pull(x);\n            return {x,b};\n        }\n    }\n    T query(int\
    \ &x,int l,int r){\n        if(l>r)return Monoid::unit();\n        auto [a,b]=split(x,l);\n\
    \        auto [c,d]=split(b,r-l+1);\n        T res=sum(c);\n        x=merge(a,merge(c,d));\n\
    \        return res;\n    }\n    void reverse(int &x,int l,int r){\n        if(l>=r)return;\n\
    \        auto [a,b]=split(x,l);\n        auto [c,d]=split(b,r-l+1);\n        toggle(c);\n\
    \        x=merge(a,merge(c,d));\n    }\n    T get(int &x,int k){\n        auto\
    \ [a,b]=split(x,k);\n        auto [c,d]=split(b,1);\n        T res=t[c].val;\n\
    \        x=merge(a,merge(c,d));\n        return res;\n    }\n    void set(int\
    \ &x,int k,const T &v){\n        auto [a,b]=split(x,k);\n        auto [c,d]=split(b,1);\n\
    \        t[c].val=v;\n        pull(c);\n        x=merge(a,merge(c,d));\n    }\n\
    \    void insert(int &x,int k,const T &v){\n        auto [a,b]=split(x,k);\n \
    \       x=merge(merge(a,new_node(v)),b);\n    }\n    void erase(int &x,int k){\n\
    \        auto [a,b]=split(x,k);\n        auto [c,d]=split(b,1);\n        x=merge(a,d);\n\
    \    }\n};\n"
  code: "#pragma once\n\ntemplate<class Monoid>\nstruct Treap{\n    using T = typename\
    \ Monoid::value_type;\n    struct Node{\n        int l,r,sz,prio;\n        bool\
    \ rev;\n        T val,sum,revsum;\n    };\n    vector<Node> t;\n\n    Treap(int\
    \ n=0){\n        t.reserve(n+1);\n        t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});\n\
    \    }\n    int new_node(const T &v){\n        t.push_back(Node{0,0,1,rng(),false,v,v,v});\n\
    \        return SZ(t)-1;\n    }\n    int size(int x){return t[x].sz;}\n    T sum(int\
    \ x){return t[x].sum;}\n\n    void pull(int x){\n        Node &v=t[x];\n     \
    \   v.sz=t[v.l].sz+1+t[v.r].sz;\n        v.sum=Monoid::op(Monoid::op(t[v.l].sum,v.val),t[v.r].sum);\n\
    \        v.revsum=Monoid::op(Monoid::op(t[v.r].revsum,v.val),t[v.l].revsum);\n\
    \    }\n    void toggle(int x){\n        if(!x)return;\n        swap(t[x].l,t[x].r);\n\
    \        swap(t[x].sum,t[x].revsum);\n        t[x].rev^=1;\n    }\n    void push(int\
    \ x){\n        if(t[x].rev){\n            toggle(t[x].l);\n            toggle(t[x].r);\n\
    \            t[x].rev=false;\n        }\n    }\n    int build(const vector<T>\
    \ &a){\n        vector<int> st;\n        for(auto &v:a){\n            int x=new_node(v),last=0;\n\
    \            while(!st.empty()&&t[st.back()].prio<t[x].prio){\n              \
    \  last=st.back();\n                pull(last);\n                st.pop_back();\n\
    \            }\n            t[x].l=last;\n            if(!st.empty())t[st.back()].r=x;\n\
    \            st.push_back(x);\n        }\n        for(int i=SZ(st)-1;i>=0;i--)pull(st[i]);\n\
    \        return st.empty()?0:st[0];\n    }\n    int merge(int a,int b){\n    \
    \    if(!a||!b)return a|b;\n        if(t[a].prio>t[b].prio){\n            push(a);\n\
    \            t[a].r=merge(t[a].r,b);\n            pull(a);\n            return\
    \ a;\n        }else{\n            push(b);\n            t[b].l=merge(a,t[b].l);\n\
    \            pull(b);\n            return b;\n        }\n    }\n    pair<int,int>\
    \ split(int x,int k){\n        if(!x)return {0,0};\n        push(x);\n       \
    \ int ls=t[t[x].l].sz;\n        if(k<=ls){\n            auto [a,b]=split(t[x].l,k);\n\
    \            t[x].l=b;\n            pull(x);\n            return {a,x};\n    \
    \    }else{\n            auto [a,b]=split(t[x].r,k-ls-1);\n            t[x].r=a;\n\
    \            pull(x);\n            return {x,b};\n        }\n    }\n    T query(int\
    \ &x,int l,int r){\n        if(l>r)return Monoid::unit();\n        auto [a,b]=split(x,l);\n\
    \        auto [c,d]=split(b,r-l+1);\n        T res=sum(c);\n        x=merge(a,merge(c,d));\n\
    \        return res;\n    }\n    void reverse(int &x,int l,int r){\n        if(l>=r)return;\n\
    \        auto [a,b]=split(x,l);\n        auto [c,d]=split(b,r-l+1);\n        toggle(c);\n\
    \        x=merge(a,merge(c,d));\n    }\n    T get(int &x,int k){\n        auto\
    \ [a,b]=split(x,k);\n        auto [c,d]=split(b,1);\n        T res=t[c].val;\n\
    \        x=merge(a,merge(c,d));\n        return res;\n    }\n    void set(int\
    \ &x,int k,const T &v){\n        auto [a,b]=split(x,k);\n        auto [c,d]=split(b,1);\n\
    \        t[c].val=v;\n        pull(c);\n        x=merge(a,merge(c,d));\n    }\n\
    \    void insert(int &x,int k,const T &v){\n        auto [a,b]=split(x,k);\n \
    \       x=merge(merge(a,new_node(v)),b);\n    }\n    void erase(int &x,int k){\n\
    \        auto [a,b]=split(x,k);\n        auto [c,d]=split(b,1);\n        x=merge(a,d);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bbst/treap.hpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:06+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
documentation_of: data-structure/bbst/treap.hpp
layout: document
redirect_from:
- /library/data-structure/bbst/treap.hpp
- /library/data-structure/bbst/treap.hpp.html
title: data-structure/bbst/treap.hpp
---
