---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random.hpp
    title: random.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
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
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SZ(a) (int)(a.size())\n#define SORT(a)\
    \ sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
    #define UNI(a) a.erase(unique(ALL(a)),a.end())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define FIND(a,x) (int)(find(ALL(a),x)-a.begin())\n\
    #define COUNT(a,x) (int)count(ALL(a),x)\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\ntemplate<class T,class U>\nbool chmin(T\
    \ &a,U b){return b<a?a=b,1:0;}\ntemplate<class T,class U>\nbool chmax(T &a,U b){return\
    \ a<b?a=b,1:0;}\n\ntemplate<class T>\nT floor(T a,T b){return a/b-((a^b)<0&&a%b);}\n\
    template<class T>\nT ceil(T a,T b){return a/b+((a^b)>=0&&a%b);}\n\nint popcnt(ll\
    \ x){return __builtin_popcountll(x);}\nint topbit(ll x){return x==0?-1:63-__builtin_clzll(x);}\n\
    int lowbit(ll x){return x==0?-1:__builtin_ctzll(x);}\n\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\ntemplate<class T>\nvector<int>\
    \ argsort(const vector<T> &a){\n    vector<int> p(SZ(a));\n    iota(ALL(p),0);\n\
    \    stable_sort(ALL(p),[&](int i,int j){return a[i]<a[j];});\n    return p;\n\
    }\n#line 3 \"random.hpp\"\n\nstruct SplitMix64{\n    using result_type = u64;\n\
    \    u64 x;\n    SplitMix64(u64 seed=chrono::steady_clock::now().time_since_epoch().count()):x(seed){}\n\
    \    static constexpr u64 min(){return 0;}\n    static constexpr u64 max(){return\
    \ numeric_limits<u64>::max();}\n    u64 operator()(){\n        u64 z=(x+=0x9e3779b97f4a7c15);\n\
    \        z=(z^(z>>30))*0xbf58476d1ce4e5b9;\n        z=(z^(z>>27))*0x94d049bb133111eb;\n\
    \        return z^(z>>31);\n    }\n};\n\nSplitMix64 rng;\n\nu64 rnd(u64 n){\n\
    \    return rng()%n;\n}\nll rnd(ll l,ll r){\n    assert(l<=r);\n    return l+rng()%(r-l+1);\n\
    }\ndb rnd_real(db l,db r){\n    return l+(r-l)*(rng()>>11)*0x1p-53;\n}\n#line\
    \ 3 \"data-structure/bbst/treap.hpp\"\n\ntemplate<class Monoid>\nstruct Treap{\n\
    \    using T = typename Monoid::value_type;\n    struct Node{\n        int l,r,sz,prio;\n\
    \        bool rev;\n        T val,sum,revsum;\n    };\n    vector<Node> t;\n\n\
    \    Treap(int n=0){\n        t.reserve(n+1);\n        t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});\n\
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
  code: "#pragma once\n#include \"random.hpp\"\n\ntemplate<class Monoid>\nstruct Treap{\n\
    \    using T = typename Monoid::value_type;\n    struct Node{\n        int l,r,sz,prio;\n\
    \        bool rev;\n        T val,sum,revsum;\n    };\n    vector<Node> t;\n\n\
    \    Treap(int n=0){\n        t.reserve(n+1);\n        t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});\n\
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
  dependsOn:
  - random.hpp
  - template.hpp
  isVerificationFile: false
  path: data-structure/bbst/treap.hpp
  requiredBy: []
  timestamp: '2026-10-25 14:43:57+07:00'
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
