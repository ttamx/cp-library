---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bbst/splay-tree.hpp
    title: data-structure/bbst/splay-tree.hpp
  - icon: ':question:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_reverse_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
  bundledCode: "#line 1 \"verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\n\
    #line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing\
    \ u32 = uint32_t;\nusing u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
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
    }\n\ntemplate<class T,size_t D=0>\nstruct VecBuilder{\n    array<size_t,D> d;\n\
    \    VecBuilder<T,D+1> operator[](size_t n)const{\n        VecBuilder<T,D+1> res{};\n\
    \        for(size_t i=0;i<D;i++)res.d[i]=d[i];\n        res.d[D]=n;\n        return\
    \ res;\n    }\n    template<size_t I=0>\n    auto build(const T &x)const{\n  \
    \      if constexpr(I+1==D)return vector<T>(d[I],x);\n        else return vector<decltype(build<I+1>(x))>(d[I],build<I+1>(x));\n\
    \    }\n    auto operator()(const T &x=T())const{\n        static_assert(D>0);\n\
    \        return build(x);\n    }\n};\ntemplate<class T>\ninline constexpr VecBuilder<T>\
    \ VEC{};\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 2 \"data-structure/bbst/splay-tree.hpp\"\n\ntemplate<class Monoid>\nstruct SplayTree{\n\
    \    using T = typename Monoid::value_type;\n    struct Node{\n        int l,r,p,sz;\n\
    \        bool rev;\n        T val,sum,revsum;\n    };\n    vector<Node> t;\n\n\
    \    SplayTree(int reserve=0){\n        t.reserve(reserve+1);\n        t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});\n\
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
    \        x=merge(a,d);\n    }\n};\n#line 2 \"group/monoid/add.hpp\"\n\n/**\n *\
    \ Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add Monoid class.\n\
    \ */\n\ntemplate<class T>\nstruct AddMonoid{\n    using value_type = T;\n    static\
    \ constexpr T op(const T &x,const T &y){return x+y;}\n    static constexpr T inverse(const\
    \ T &x){return -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n#line\
    \ 5 \"verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<ll> a(n);\n    for(auto &x:a)cin >> x;\n    SplayTree<AddMonoid<ll>>\
    \ s(n);\n    int root=s.build(a);\n    while(q--){\n        int op,l,r;\n    \
    \    cin >> op >> l >> r;\n        if(op)cout << s.query(root,l,r-1) << \"\\n\"\
    ;\n        else s.reverse(root,l,r-1);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n#include \"template.hpp\"\n#include \"data-structure/bbst/splay-tree.hpp\"\n\
    #include \"group/monoid/add.hpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    vector<ll> a(n);\n    for(auto &x:a)cin\
    \ >> x;\n    SplayTree<AddMonoid<ll>> s(n);\n    int root=s.build(a);\n    while(q--){\n\
    \        int op,l,r;\n        cin >> op >> l >> r;\n        if(op)cout << s.query(root,l,r-1)\
    \ << \"\\n\";\n        else s.reverse(root,l,r-1);\n    }\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/bbst/splay-tree.hpp
  - group/monoid/add.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp
- /verify/verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp.html
title: verify/yosupo/data-structure/bbst/splay-tree/range_reverse_range_sum.test.cpp
---
