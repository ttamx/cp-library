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
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
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
    }\n#line 2 \"data-structure/segment-tree/dynamic-segment-tree.hpp\"\n\n/**\n *\
    \ Author: Teetat T.\n * Date: 2024-01-15\n * Description: Dynamic Segment Tree\n\
    \ */\n\ntemplate<class MonoidAction>\nstruct DynamicSegmentTree{\n    using InfoMonoid\
    \ = typename MonoidAction::InfoMonoid;\n    using TagMonoid = typename MonoidAction::TagMonoid;\n\
    \    using Info = typename MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n\
    \    struct Node{\n        Info val;\n        Tag lz;\n        int l,r;\n    \
    \    Node(Info v):val(v),lz(TagMonoid::unit()),l(-1),r(-1){}\n    };\n    ll lb,ub;\n\
    \    vector<Node> t;\n    function<Info(ll,ll)> create;\n    DynamicSegmentTree(){init(0,0);}\n\
    \    DynamicSegmentTree(ll n){init(0,n-1);}\n    DynamicSegmentTree(ll lb,ll ub){init(lb,ub);}\n\
    \    DynamicSegmentTree(ll lb,ll ub,function<Info(ll,ll)> create){init(lb,ub,create);}\n\
    \    void init(ll _lb,ll _ub,function<Info(ll,ll)> _create=[](ll l,ll r){return\
    \ InfoMonoid::unit();}){\n        lb=_lb,ub=_ub;\n        create=_create;\n  \
    \      t.clear();\n        new_node(create(lb,ub));\n    }\n    int new_node(const\
    \ Info &v){\n        t.emplace_back(v);\n        return t.size()-1;\n    }\n \
    \   void pull(int u){\n        t[u].val=InfoMonoid::op(t[t[u].l].val,t[t[u].r].val);\n\
    \    }\n    void apply(int u,const Tag &v){\n        t[u].val=MonoidAction::op(t[u].val,v);\n\
    \        t[u].lz=TagMonoid::op(t[u].lz,v);\n    }\n    void push(int u,ll l,ll\
    \ m,ll r){\n        if(t[u].l==-1){int c=new_node(create(l,m));t[u].l=c;}\n  \
    \      if(t[u].r==-1){int c=new_node(create(m+1,r));t[u].r=c;}\n        apply(t[u].l,t[u].lz);\n\
    \        apply(t[u].r,t[u].lz);\n        t[u].lz=TagMonoid::unit();\n    }\n \
    \   void modify(ll l,ll r,int u,ll x,const Info &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[u].val=v);\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        modify(l,m,t[u].l,x,v);\n        modify(m+1,r,t[u].r,x,v);\n        pull(u);\n\
    \    }\n    void modify(ll x,const Info &v){\n        modify(lb,ub,0,x,v);\n \
    \   }\n    void update(ll l,ll r,int u,ll x,ll y,const Tag &v){\n        if(y<l||r<x)return;\n\
    \        if(x<=l&&r<=y)return apply(u,v);\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        update(l,m,t[u].l,x,y,v);\n        update(m+1,r,t[u].r,x,y,v);\n    \
    \    pull(u);\n    }\n    void update(ll x,ll y,const Tag &v){\n        update(lb,ub,0,x,y,v);\n\
    \    }\n    Info query(ll l,ll r,int u,ll x,ll y){\n        if(y<l||r<x)return\
    \ InfoMonoid::unit();\n        if(x<=l&&r<=y)return t[u].val;\n        ll m=l+(r-l)/2;\n\
    \        push(u,l,m,r);\n        return InfoMonoid::op(query(l,m,t[u].l,x,y),query(m+1,r,t[u].r,x,y));\n\
    \    }\n    Info query(ll x,ll y){\n        return query(lb,ub,0,x,y);\n    }\n\
    \    template<class F>\n    ll findfirst(ll l,ll r,int u,ll x,ll y,const F &f){\n\
    \        if(y<l||r<x||!f(t[u].val))return ub+1;\n        if(l==r)return l;\n \
    \       ll m=l+(r-l)/2;\n        push(u,l,m,r);\n        ll res=findfirst(l,m,t[u].l,x,y,f);\n\
    \        if(res==ub+1)res=findfirst(m+1,r,t[u].r,x,y,f);\n        return res;\n\
    \    }\n    template<class F>\n    ll findfirst(ll x,ll y,const F &f){\n     \
    \   return findfirst(lb,ub,0,x,y,f);\n    }\n    template<class F>\n    ll findlast(ll\
    \ l,ll r,int u,ll x,ll y,const F &f){\n        if(y<l||r<x||!f(t[u].val))return\
    \ lb-1;\n        if(l==r)return l;\n        ll m=l+(r-l)/2;\n        push(u,l,m,r);\n\
    \        ll res=findlast(m+1,r,t[u].r,x,y,f);\n        if(res==lb-1)res=findlast(l,m,t[u].l,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    ll findlast(ll x,ll y,const\
    \ F &f){\n        return findlast(lb,ub,0,x,y,f);\n    }\n};\n#line 2 \"group/monoid/add.hpp\"\
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
    \ a;\n        return Info(a.first+b,a.second);\n    }\n};\n\n#line 5 \"verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp\"\
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
  path: verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 17:59:55+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp
- /verify/verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp.html
title: verify/yosupo/data-structure/segment-tree/dynamic-segment-tree/area_of_union_of_rectangles.test.cpp
---
