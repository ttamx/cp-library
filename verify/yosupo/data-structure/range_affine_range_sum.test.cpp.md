---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/lazy-segment-tree.hpp
    title: data-structure/segment-tree/lazy-segment-tree.hpp
  - icon: ':question:'
    path: group/monoid-action/add-count-affine.hpp
    title: group/monoid-action/add-count-affine.hpp
  - icon: ':question:'
    path: group/monoid/add-count.hpp
    title: group/monoid/add-count.hpp
  - icon: ':question:'
    path: group/monoid/affine.hpp
    title: group/monoid/affine.hpp
  - icon: ':question:'
    path: modular-arithmetic/montgomery-modint.hpp
    title: modular-arithmetic/montgomery-modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo/data-structure/range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\nusing\
    \ vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst\
    \ int MOD=998244353;\nconst int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    template<class T>\nusing ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"modular-arithmetic/montgomery-modint.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description: modular arithmetic\
    \ operators using Montgomery space\n */\n\ntemplate<uint32_t mod,uint32_t root=0>\n\
    struct MontgomeryModInt{\n    using mint = MontgomeryModInt;\n    using i32 =\
    \ int32_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static\
    \ constexpr u32 get_r(){\n        u32 res=1;\n        for(i32 i=0;i<5;i++)res*=2-mod*res;\n\
    \        return res;\n    }\n\n    static const u32 r=get_r();\n    static const\
    \ u32 n2=-u64(mod)%mod;\n    static_assert(mod<(1<<30));\n    static_assert((mod&1)==1);\n\
    \    static_assert(r*mod==1);\n\n    u32 x;\n\n    constexpr MontgomeryModInt():x(0){}\n\
    \    constexpr MontgomeryModInt(const int64_t &v):x(reduce(u64(v%mod+mod)*n2)){}\n\
    \n    static constexpr u32 get_mod(){return mod;}\n    static constexpr mint get_root(){return\
    \ mint(root);}\n    explicit constexpr operator int64_t()const{return val();}\n\
    \n    static constexpr u32 reduce(const u64 &v){\n        return (v+u64(u32(v)*u32(-r))*mod)>>32;\n\
    \    }\n\n    constexpr u32 val()const{\n        u32 res=reduce(x);\n        return\
    \ res>=mod?res-mod:res;\n    }\n\n    constexpr mint inv()const{\n        int\
    \ a=val(),b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n      \
    \      a-=q*b;\n            u-=q*v;\n            swap(a,b);\n            swap(u,v);\n\
    \        }\n        return mint(u);\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &rhs){\n        if(i32(x+=rhs.x-2*mod)<0)x+=2*mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator-=(const mint &rhs){\n        if(i32(x-=rhs.x)<0)x+=2*mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator*=(const mint &rhs){\n\
    \        x=reduce(u64(x)*rhs.x);\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &rhs){\n        return *this*=rhs.inv();\n    }\n\
    \n    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){\n\
    \        mint res=*this;\n        return *this+=mint(1),res;\n    }\n    constexpr\
    \ mint operator--(int){\n        mint res=*this;\n        return *this-=mint(1),res;\n\
    \    }\n\n    constexpr mint operator-()const{return mint()-mint(*this);};\n \
    \   constexpr mint operator+()const{return mint(*this);};\n\n    friend constexpr\
    \ mint operator+(const mint &lhs,const mint &rhs){return mint(lhs)+=rhs;}\n  \
    \  friend constexpr mint operator-(const mint &lhs,const mint &rhs){return mint(lhs)-=rhs;}\n\
    \    friend constexpr mint operator*(const mint &lhs,const mint &rhs){return mint(lhs)*=rhs;}\n\
    \    friend constexpr mint operator/(const mint &lhs,const mint &rhs){return mint(lhs)/=rhs;}\n\
    \    friend constexpr bool operator==(const mint &lhs,const mint &rhs){\n    \
    \    return (lhs.x>=mod?lhs.x-mod:lhs.x)==(rhs.x>=mod?rhs.x-mod:rhs.x);\n    }\n\
    \    friend constexpr bool operator!=(const mint &lhs,const mint &rhs){\n    \
    \    return (lhs.x>=mod?lhs.x-mod:lhs.x)!=(rhs.x>=mod?rhs.x-mod:rhs.x);\n    }\n\
    \    friend constexpr bool operator<(const mint &lhs,const mint &rhs){\n     \
    \   return (lhs.x>=mod?lhs.x-mod:lhs.x)<(rhs.x>=mod?rhs.x-mod:rhs.x); // for std::map\n\
    \    }\n\n    friend istream &operator>>(istream &is,mint &o){\n        int64_t\
    \ v;\n        is >> v;\n        o=mint(v);\n        return is;\n    }\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){\n        return os << o.val();\n\
    \    }\n};\nusing mint998 = MontgomeryModInt<998244353,3>;\nusing mint107 = MontgomeryModInt<1000000007>;\n\
    \n#line 2 \"data-structure/segment-tree/lazy-segment-tree.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-01-15\n * Description: Segment Tree with Lazy Propagation\n\
    \ */\n\ntemplate<class MonoidAction>\nstruct LazySegmentTree{\n    using InfoMonoid\
    \ = typename MonoidAction::InfoMonoid;\n    using TagMonoid = typename MonoidAction::TagMonoid;\n\
    \    using Info = typename MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n\
    \    int n;\n    vector<Info> t;\n    vector<Tag> lz;\n    LazySegmentTree(){}\n\
    \    LazySegmentTree(int n,function<Info(int)> create){init(n,create);}\n    LazySegmentTree(int\
    \ n,Info v=InfoMonoid::unit()){init(n,[&](int){return v;});}\n    template<class\
    \ T>\n    LazySegmentTree(const vector<T> &a){init((int)a.size(),[&](int i){return\
    \ Info(a[i]);});}\n    void init(int _n,function<Info(int)> create){\n       \
    \ n=_n;\n        int m=4<<(31-__builtin_clz(n));\n        t.assign(m,InfoMonoid::unit());\n\
    \        lz.assign(m,TagMonoid::unit());\n        function<void(int,int,int)>\
    \ build=[&](int l,int r,int i){\n            if(l==r)return void(t[i]=create(l));\n\
    \            int m=(l+r)/2;\n            build(l,m,i*2);\n            build(m+1,r,i*2+1);\n\
    \            pull(i);\n        };\n        build(0,n-1,1);\n    }\n    void pull(int\
    \ i){\n        t[i]=InfoMonoid::op(t[i*2],t[i*2+1]);\n    }\n    void apply(int\
    \ i,const Tag &v){\n        t[i]=MonoidAction::op(t[i],v);\n        lz[i]=TagMonoid::op(lz[i],v);\n\
    \    }\n    void push(int i){\n        apply(i*2,lz[i]);\n        apply(i*2+1,lz[i]);\n\
    \        lz[i]=TagMonoid::unit();\n    }\n    void modify(int l,int r,int i,int\
    \ x,const Info &v){\n        if(x<l||r<x)return;\n        if(l==r)return void(t[i]=v);\n\
    \        int m=(l+r)/2;\n        push(i);\n        modify(l,m,i*2,x,v);\n    \
    \    modify(m+1,r,i*2+1,x,v);\n        pull(i);\n    }\n    void modify(int x,const\
    \ Info &v){\n        modify(0,n-1,1,x,v);\n    }\n    void update(int l,int r,int\
    \ i,int x,int y,const Tag &v){\n        if(y<l||r<x)return;\n        if(x<=l&&r<=y)return\
    \ apply(i,v);\n        int m=(l+r)/2;\n        push(i);\n        update(l,m,i*2,x,y,v);\n\
    \        update(m+1,r,i*2+1,x,y,v);\n        pull(i);\n    }\n    void update(int\
    \ x,int y,const Tag &v){\n        update(0,n-1,1,x,y,v);\n    }\n    Info query(int\
    \ l,int r,int i,int x,int y){\n        if(y<l||r<x)return InfoMonoid::unit();\n\
    \        if(x<=l&&r<=y)return t[i];\n        int m=(l+r)/2;\n        push(i);\n\
    \        return InfoMonoid::op(query(l,m,i*2,x,y),query(m+1,r,i*2+1,x,y));\n \
    \   }\n    Info query(int x,int y){\n        return query(0,n-1,1,x,y);\n    }\n\
    \    template<class F>\n    int findfirst(int l,int r,int i,int x,int y,const\
    \ F &f){\n        if(y<l||r<x||!f(t[i]))return n;\n        if(l==r)return l;\n\
    \        int m=(l+r)/2;\n        push(i);\n        int res=findfirst(l,m,i*2,x,y,f);\n\
    \        if(res==n)res=findfirst(m+1,r,i*2+1,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    int findfirst(int x,int y,const F &f){\n    \
    \    return findfirst(0,n-1,1,x,y,f);\n    }\n    template<class F>\n    int findlast(int\
    \ l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ -1;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        push(i);\n \
    \       int res=findlast(m+1,r,i*2+1,x,y,f);\n        if(res==-1)res=findlast(l,m,i*2,x,y,f);\n\
    \        return res;\n    }\n    template<class F>\n    int findlast(int x,int\
    \ y,const F &f){\n        return findlast(0,n-1,1,x,y,f);\n    }\n};\n\n#line\
    \ 2 \"group/monoid/affine.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n\
    \ * Description: Affine Transfomation Monoid class.\n */\n\ntemplate<class T>\n\
    struct AffineMonoid{\n    using P = pair<T,T>;\n    using value_type = P;\n  \
    \  static constexpr P op(const P &x,const P &y){\n        return P(x.first*y.first,x.second*y.first+y.second);\n\
    \    }\n    static constexpr P unit(){return P(T(1),T(0));}\n    static constexpr\
    \ T eval(const P &f,const T &x){\n        return f.first*x+f.second;\n    }\n\
    };\n\n#line 2 \"group/monoid/add-count.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-14\n * Description: Add & Count Monoid class.\n */\n\ntemplate<class\
    \ T>\nstruct AddCountMonoid{\n    using P = pair<T,ll>;\n    using value_type\
    \ = P;\n    static constexpr P op(const P &x,const P &y){\n        return P(x.first+y.first,x.second+y.second);\n\
    \    }\n    static constexpr P inverse(const P &x){return P(-x.first,-x.second);}\n\
    \    static constexpr P unit(){return P(T(0),0LL);}\n    static constexpr P make(const\
    \ T &x){return P(x,1LL);}\n};\n\n#line 4 \"group/monoid-action/add-count-affine.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Affine to\
    \ Add & Count Action class.\n */\n\ntemplate<class T>\nstruct AddCountAffineAction{\n\
    \    using InfoMonoid = AddCountMonoid<T>;\n    using TagMonoid = AffineMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return Info(a.first*b.first+a.second*b.second,a.second);\n\
    \    }\n};\n\n#line 6 \"verify/yosupo/data-structure/range_affine_range_sum.test.cpp\"\
    \n\nusing mint = mint998;\nusing Monoid = AddCountMonoid<mint>;\nusing Action\
    \ = AddCountAffineAction<mint>;\nusing T = Monoid::value_type;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin >> n >>\
    \ q;\n    vector<mint> a(n);\n    for(auto &x:a)cin >> x;\n    LazySegmentTree<Action>\
    \ s(n,[&](int i){return Monoid::make(a[i]);});\n    while(q--){\n        int op;\n\
    \        cin >> op;\n        if(op){\n            int l,r;\n            cin >>\
    \ l >> r;\n            cout << s.query(l,r-1).first << \"\\n\";\n        }else{\n\
    \            int l,r,b,c;\n            cin >> l >> r >> b >> c;\n            s.update(l,r-1,T(b,c));\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"template.hpp\"\n#include \"modular-arithmetic/montgomery-modint.hpp\"\
    \n#include \"data-structure/segment-tree/lazy-segment-tree.hpp\"\n#include \"\
    group/monoid-action/add-count-affine.hpp\"\n\nusing mint = mint998;\nusing Monoid\
    \ = AddCountMonoid<mint>;\nusing Action = AddCountAffineAction<mint>;\nusing T\
    \ = Monoid::value_type;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    vector<mint> a(n);\n    for(auto &x:a)cin\
    \ >> x;\n    LazySegmentTree<Action> s(n,[&](int i){return Monoid::make(a[i]);});\n\
    \    while(q--){\n        int op;\n        cin >> op;\n        if(op){\n     \
    \       int l,r;\n            cin >> l >> r;\n            cout << s.query(l,r-1).first\
    \ << \"\\n\";\n        }else{\n            int l,r,b,c;\n            cin >> l\
    \ >> r >> b >> c;\n            s.update(l,r-1,T(b,c));\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - modular-arithmetic/montgomery-modint.hpp
  - data-structure/segment-tree/lazy-segment-tree.hpp
  - group/monoid-action/add-count-affine.hpp
  - group/monoid/affine.hpp
  - group/monoid/add-count.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/range_affine_range_sum.test.cpp
- /verify/verify/yosupo/data-structure/range_affine_range_sum.test.cpp.html
title: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
---
