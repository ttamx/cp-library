---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segment-tree/lazy-segment-tree.hpp
    title: data-structure/segment-tree/lazy-segment-tree.hpp
  - icon: ':x:'
    path: group/monoid-action/add-count-affine.hpp
    title: group/monoid-action/add-count-affine.hpp
  - icon: ':x:'
    path: group/monoid/add-count.hpp
    title: group/monoid/add-count.hpp
  - icon: ':question:'
    path: group/monoid/affine.hpp
    title: group/monoid/affine.hpp
  - icon: ':question:'
    path: modular-arithmetic/modint.hpp
    title: modular-arithmetic/modint.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo/data-structure/range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #line 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 2 \"modular-arithmetic/modint.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n\
    \ * Description: modular arithmetic operations\n */\n\ntemplate<int mod,int root=0>\n\
    struct ModInt{\n    using mint = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must\
    \ be positive\");\n\n    int x;\n\n    constexpr ModInt():x(0){}\n    constexpr\
    \ ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n    constexpr explicit operator int()const{return\
    \ x;}\n    constexpr static int get_mod(){return mod;}\n    constexpr static mint\
    \ get_root(){return mint(root);}\n    \n    constexpr mint operator-()const{\n\
    \        mint res;\n        res.x=x?mod-x:0;\n        return res;\n    }\n   \
    \ constexpr mint operator+()const{return *this;}\n\n    constexpr mint inv()const{\n\
    \        int a=x,b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n\
    \            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n        }\n       \
    \ return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n        mint res=1,a=*this;\n\
    \        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n        return res;\n    }\n    constexpr\
    \ mint &operator+=(const mint &o){\n        if((x+=o.x)>=mod)x-=mod;\n       \
    \ return *this;\n    }\n    constexpr mint &operator-=(const mint &o){\n     \
    \   if((x-=o.x)<0)x+=mod;\n        return *this;\n    }\n    constexpr mint &operator*=(const\
    \ mint &o){\n        x=(ll(x)*o.x)%mod;\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &o){\n        return *this*=o.inv();\n    }\n\n\
    \    constexpr mint operator+(const mint &o)const{return mint(*this)+=o;}\n  \
    \  constexpr mint operator-(const mint &o)const{return mint(*this)-=o;}\n    constexpr\
    \ mint operator*(const mint &o)const{return mint(*this)*=o;}\n    constexpr mint\
    \ operator/(const mint &o)const{return mint(*this)/=o;}\n\n    constexpr mint\
    \ &operator++(){return *this+=mint(1);}\n    constexpr mint &operator--(){return\
    \ *this-=mint(1);}\n    constexpr mint operator++(int){mint res=*this;*this+=mint(1);return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=mint(1);return\
    \ res;}\n    \n    constexpr bool operator==(const mint &o)const{return x==o.x;}\n\
    \    constexpr bool operator!=(const mint &o)const{return x!=o.x;}\n    constexpr\
    \ bool operator<(const mint &o)const{return x<o.x;}\n    \n    friend istream\
    \ &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return is;}\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n};\nusing mint998\
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 2 \"data-structure/segment-tree/lazy-segment-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Segment Tree\
    \ with Lazy Propagation\n */\n\ntemplate<class MonoidAction>\nstruct LazySegmentTree{\n\
    \    using InfoMonoid = typename MonoidAction::InfoMonoid;\n    using TagMonoid\
    \ = typename MonoidAction::TagMonoid;\n    using Info = typename MonoidAction::Info;\n\
    \    using Tag = typename MonoidAction::Tag;\n    int n;\n    vector<Info> t;\n\
    \    vector<Tag> lz;\n    LazySegmentTree(){}\n    LazySegmentTree(int n,function<Info(int)>\
    \ create){init(n,create);}\n    LazySegmentTree(int n,Info v=InfoMonoid::unit()){init(n,[&](int){return\
    \ v;});}\n    template<class T>\n    LazySegmentTree(const vector<T> &a){init((int)a.size(),[&](int\
    \ i){return Info(a[i]);});}\n    void init(int _n,function<Info(int)> create){\n\
    \        n=_n;\n        int m=4<<(31-__builtin_clz(n));\n        t.assign(m,InfoMonoid::unit());\n\
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
    \n#include \"template.hpp\"\n#include \"modular-arithmetic/modint.hpp\"\n#include\
    \ \"data-structure/segment-tree/lazy-segment-tree.hpp\"\n#include \"group/monoid-action/add-count-affine.hpp\"\
    \n\nusing mint = mint998;\nusing Monoid = AddCountMonoid<mint>;\nusing Action\
    \ = AddCountAffineAction<mint>;\nusing T = Monoid::value_type;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin >> n >>\
    \ q;\n    vector<mint> a(n);\n    for(auto &x:a)cin >> x;\n    LazySegmentTree<Action>\
    \ s(n,[&](int i){return Monoid::make(a[i]);});\n    while(q--){\n        int op;\n\
    \        cin >> op;\n        if(op){\n            int l,r;\n            cin >>\
    \ l >> r;\n            cout << s.query(l,r-1).first << \"\\n\";\n        }else{\n\
    \            int l,r,b,c;\n            cin >> l >> r >> b >> c;\n            s.update(l,r-1,T(b,c));\n\
    \        }\n    }\n}"
  dependsOn:
  - template.hpp
  - modular-arithmetic/modint.hpp
  - data-structure/segment-tree/lazy-segment-tree.hpp
  - group/monoid-action/add-count-affine.hpp
  - group/monoid/affine.hpp
  - group/monoid/add-count.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 21:45:25+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/range_affine_range_sum.test.cpp
- /verify/verify/yosupo/data-structure/range_affine_range_sum.test.cpp.html
title: verify/yosupo/data-structure/range_affine_range_sum.test.cpp
---
