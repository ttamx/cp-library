---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/dynamic-segment-tree.hpp
    title: data-structure/segment-tree/dynamic-segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid-action/min-count-add.hpp
    title: group/monoid-action/min-count-add.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/add.hpp
    title: group/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/min-count.hpp
    title: group/monoid/min-count.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\nusing\
    \ vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst\
    \ int MOD=998244353;\nconst int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    template<class T>\nusing ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"data-structure/segment-tree/dynamic-segment-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Dynamic Segment\
    \ Tree\n */\n\ntemplate<class MonoidAction>\nstruct DynamicSegmentTree{\n    using\
    \ InfoMonoid = typename MonoidAction::InfoMonoid;\n    using TagMonoid = typename\
    \ MonoidAction::TagMonoid;\n    using Info = typename MonoidAction::Info;\n  \
    \  using Tag = typename MonoidAction::Tag;\n    struct Node;\n    using Ptr =\
    \ Node*;\n    struct Node{\n        Info val;\n        Tag lz;\n        Ptr l,r;\n\
    \        Node(Info v):val(v),lz(TagMonoid::unit()),l(nullptr),r(nullptr){}\n \
    \       Node(Info v,Tag t):val(v),lz(t),l(nullptr),r(nullptr){}\n    };\n    ll\
    \ lb,ub;\n    Ptr rt;\n    function<Info(ll,ll)> create;\n    DynamicSegmentTree(){init(0,0);}\n\
    \    DynamicSegmentTree(ll n){init(0,n-1);}\n    DynamicSegmentTree(ll lb,ll ub){init(lb,ub);}\n\
    \    DynamicSegmentTree(ll lb,ll ub,function<Info(ll,ll)> create){init(lb,ub,create);}\n\
    \    void init(ll _lb,ll _ub,function<Info(ll,ll)> _create=[](ll l,ll r){return\
    \ InfoMonoid::unit();}){\n        lb=_lb,ub=_ub;\n        create=_create;\n  \
    \      rt=new Node(create(lb,ub));\n    }\n    Info val(Ptr t){\n        return\
    \ t?t->val:InfoMonoid::unit();\n    }\n    void pull(Ptr &t){\n        t->val=InfoMonoid::op(val(t->l),val(t->r));\n\
    \    }\n    void apply(Ptr &t,const Tag &v,ll l,ll r){\n        if(!t)t=new Node(create(l,r));\n\
    \        t->val=MonoidAction::op(t->val,v);\n        t->lz=TagMonoid::op(t->lz,v);\n\
    \    }\n    void push(Ptr &t,ll l,ll m,ll r){\n        apply(t->l,t->lz,l,m);\n\
    \        apply(t->r,t->lz,m+1,r);\n        t->lz=TagMonoid::unit();\n    }\n \
    \   void modify(ll l,ll r,Ptr &t,ll x,const Info &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t->val=v);\n        ll m=l+(r-l)/2;\n        push(t,l,m,r);\n\
    \        modify(l,m,t->l,x,v);\n        modify(m+1,r,t->r,x,v);\n        pull(t);\n\
    \    }\n    void modify(ll x,const Info &v){\n        modify(lb,ub,rt,x,v);\n\
    \    }\n    void update(ll l,ll r,Ptr &t,ll x,ll y,const Tag &v){\n        if(y<l||r<x)return;\n\
    \        if(x<=l&&r<=y)return apply(t,v,l,r);\n        ll m=l+(r-l)/2;\n     \
    \   push(t,l,m,r);\n        update(l,m,t->l,x,y,v);\n        update(m+1,r,t->r,x,y,v);\n\
    \        pull(t);\n    }\n    void update(ll x,ll y,const Tag &v){\n        update(lb,ub,rt,x,y,v);\n\
    \    }\n    Info query(ll l,ll r,Ptr &t,ll x,ll y){\n        if(y<l||r<x)return\
    \ InfoMonoid::unit();\n        if(x<=l&&r<=y)return t->val;\n        ll m=l+(r-l)/2;\n\
    \        push(t,l,m,r);\n        return InfoMonoid::op(query(l,m,t->l,x,y),query(m+1,r,t->r,x,y));\n\
    \    }\n    Info query(ll x,ll y){\n        return query(lb,ub,rt,x,y);\n    }\n\
    \    template<class F>\n    ll findfirst(ll l,ll r,Ptr t,ll x,ll y,const F &f){\n\
    \        if(y<l||r<x||!f(t->val))return -1;\n        if(l==r)return l;\n     \
    \   ll m=l+(r-l)/2;\n        push(t,l,m,r);\n        ll res=findfirst(l,m,t->l,x,y,f);\n\
    \        if(res==-1)res=findfirst(m+1,r,t->r,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    ll findfirst(ll x,ll y,const F &f){\n       \
    \ return findfirst(lb,ub,rt,x,y,f);\n    }\n    template<class F>\n    ll findlast(ll\
    \ l,ll r,Ptr t,ll x,ll y,const F &f){\n        if(y<l||r<x||!t||!f(t->val))return\
    \ -1;\n        if(l==r)return l;\n        ll m=l+(r-l)/2;\n        push(t,l,m,r);\n\
    \        ll res=findlast(m+1,r,t->r,x,y,f);\n        if(res==-1)res=findlast(l,m,t->l,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    ll findlast(ll x,ll y,const\
    \ F &f){\n        return findlast(lb,ub,rt,x,y,f);\n    }\n};\n\n#line 2 \"group/monoid/add.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add Monoid\
    \ class.\n */\n\ntemplate<class T>\nstruct AddMonoid{\n    using value_type =\
    \ T;\n    static constexpr T op(const T &x,const T &y){return x+y;}\n    static\
    \ constexpr T inverse(const T &x){return -x;}\n    static constexpr T unit(){return\
    \ T(0);}\n};\n\n#line 2 \"group/monoid/min-count.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-04-14\n * Description: Min & Count Monoid class.\n */\n\n\
    template<class T>\nstruct MinCountMonoid{\n    using P = pair<T,int>;\n    using\
    \ value_type = P;\n    static constexpr P op(const P &x,const P &y){\n       \
    \ if(x.first<y.first)return x;\n        if(y.first<x.first)return y;\n       \
    \ return P(x.first,x.second+y.second);\n    }\n    static constexpr P unit(){return\
    \ P(numeric_limits<T>::max(),0);}\n    static constexpr P make(const T &x){return\
    \ P(x,1);}\n};\n\n#line 4 \"group/monoid-action/min-count-add.hpp\"\n\n/**\n *\
    \ Author: Teetat T.\n * Date: 2024-04-14\n * Description: Add to Min & Count Action\
    \ class.\n */\n\ntemplate<class T>\nstruct MinCountAddAction{\n    using InfoMonoid\
    \ = MinCountMonoid<T>;\n    using TagMonoid = AddMonoid<T>;\n    using Info =\
    \ typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        if(a.first==InfoMonoid::unit().first)return\
    \ a;\n        return Info(a.first+b,a.second);\n    }\n};\n\n#line 5 \"verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n \
    \   cin >> n;\n    map<int,vector<tuple<int,int,int>>> qr;\n    for(int i=0;i<n;++i){\n\
    \        int lx,ly,rx,ry;\n        cin >> lx >> ly >> rx >> ry;\n        ry--;\n\
    \        qr[lx].emplace_back(ly,ry,1);\n        qr[rx].emplace_back(ly,ry,-1);\n\
    \    }\n    const int X=1e9;\n    DynamicSegmentTree<MinCountAddAction<int>> s(0,X-1,[](int\
    \ l,int r){\n        return make_pair(0,r-l+1);\n    });\n    ll ans=0,pre=0;\n\
    \    for(auto &[x,v]:qr){\n        auto [val,cnt]=s.query(0,X);\n        if(val>0)cnt=0;\n\
    \        ans+=(X-cnt)*(x-pre);\n        for(auto &[l,r,d]:v)s.update(l,r,d);\n\
    \        pre=x;\n    }\n    cout << ans;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n#include \"template.hpp\"\n#include \"data-structure/segment-tree/dynamic-segment-tree.hpp\"\
    \n#include \"group/monoid-action/min-count-add.hpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    map<int,vector<tuple<int,int,int>>> qr;\n    for(int\
    \ i=0;i<n;++i){\n        int lx,ly,rx,ry;\n        cin >> lx >> ly >> rx >> ry;\n\
    \        ry--;\n        qr[lx].emplace_back(ly,ry,1);\n        qr[rx].emplace_back(ly,ry,-1);\n\
    \    }\n    const int X=1e9;\n    DynamicSegmentTree<MinCountAddAction<int>> s(0,X-1,[](int\
    \ l,int r){\n        return make_pair(0,r-l+1);\n    });\n    ll ans=0,pre=0;\n\
    \    for(auto &[x,v]:qr){\n        auto [val,cnt]=s.query(0,X);\n        if(val>0)cnt=0;\n\
    \        ans+=(X-cnt)*(x-pre);\n        for(auto &[l,r,d]:v)s.update(l,r,d);\n\
    \        pre=x;\n    }\n    cout << ans;\n}"
  dependsOn:
  - template.hpp
  - data-structure/segment-tree/dynamic-segment-tree.hpp
  - group/monoid-action/min-count-add.hpp
  - group/monoid/add.hpp
  - group/monoid/min-count.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
- /verify/verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp.html
title: verify/yosupo/data-structure/area_of_union_of_rectangles.test.cpp
---
