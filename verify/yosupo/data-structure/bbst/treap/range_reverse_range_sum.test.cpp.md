---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bbst/treap.hpp
    title: data-structure/bbst/treap.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp\"\
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
    \ 2 \"data-structure/bbst/treap.hpp\"\n\ntemplate<class Monoid>\nstruct Treap{\n\
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
    \    }\n};\n#line 2 \"group/monoid/add.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-14\n * Description: Add Monoid class.\n */\n\ntemplate<class T>\n\
    struct AddMonoid{\n    using value_type = T;\n    static constexpr T op(const\
    \ T &x,const T &y){return x+y;}\n    static constexpr T inverse(const T &x){return\
    \ -x;}\n    static constexpr T unit(){return T(0);}\n};\n\n#line 5 \"verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<ll> a(n);\n    for(auto &x:a)cin >> x;\n    Treap<AddMonoid<ll>>\
    \ s(n);\n    int root=s.build(a);\n    while(q--){\n        int op,l,r;\n    \
    \    cin >> op >> l >> r;\n        if(op)cout << s.query(root,l,r-1) << \"\\n\"\
    ;\n        else s.reverse(root,l,r-1);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n#include \"template.hpp\"\n#include \"data-structure/bbst/treap.hpp\"\n#include\
    \ \"group/monoid/add.hpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    vector<ll> a(n);\n    for(auto &x:a)cin\
    \ >> x;\n    Treap<AddMonoid<ll>> s(n);\n    int root=s.build(a);\n    while(q--){\n\
    \        int op,l,r;\n        cin >> op >> l >> r;\n        if(op)cout << s.query(root,l,r-1)\
    \ << \"\\n\";\n        else s.reverse(root,l,r-1);\n    }\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/bbst/treap.hpp
  - group/monoid/add.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
- /verify/verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp.html
title: verify/yosupo/data-structure/bbst/treap/range_reverse_range_sum.test.cpp
---
