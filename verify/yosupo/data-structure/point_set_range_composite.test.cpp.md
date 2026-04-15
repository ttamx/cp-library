---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/segment-tree.hpp
    title: data-structure/segment-tree/segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/affine.hpp
    title: group/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: modular-arithmetic/modint.hpp
    title: modular-arithmetic/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/yosupo/data-structure/point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
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
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 2 \"data-structure/segment-tree/segment-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Segment Tree\n\
    \ */\n\ntemplate<class Monoid>\nstruct SegmentTree{\n    using T = typename Monoid::value_type;\n\
    \    int n;\n    vector<T> t;\n    SegmentTree(){}\n    SegmentTree(int n,function<T(int)>\
    \ create){init(n,create);}\n    SegmentTree(int n,T v=Monoid::unit()){init(n,[&](int){return\
    \ v;});}\n    template<class U>\n    SegmentTree(const vector<U> &a){init((int)a.size(),[&](int\
    \ i){return T(a[i]);});}\n    void init(int _n,function<T(int)> create){\n   \
    \     n=_n;\n        t.assign(4<<(31-__builtin_clz(n)),Monoid::unit());\n    \
    \    function<void(int,int,int)> build=[&](int l,int r,int i){\n            if(l==r)return\
    \ void(t[i]=create(l));\n            int m=(l+r)/2;\n            build(l,m,i*2);\n\
    \            build(m+1,r,i*2+1);\n            pull(i);\n        };\n        build(0,n-1,1);\n\
    \    }\n    void pull(int i){\n        t[i]=Monoid::op(t[i*2],t[i*2+1]);\n   \
    \ }\n    void modify(int l,int r,int i,int x,const T &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[i]=v);\n        int m=(l+r)/2;\n        modify(l,m,i*2,x,v);\n\
    \        modify(m+1,r,i*2+1,x,v);\n        pull(i);\n    }\n    void modify(int\
    \ x,const T &v){\n        modify(0,n-1,1,x,v);\n    }\n    template<class U>\n\
    \    void update(int l,int r,int i,int x,const U &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[i]=Monoid::op(t[i],v));\n        int m=(l+r)/2;\n\
    \        update(l,m,i*2,x,v);\n        update(m+1,r,i*2+1,x,v);\n        pull(i);\n\
    \    }\n    template<class U>\n    void update(int x,const U &v){\n        update(0,n-1,1,x,v);\n\
    \    }\n    T query(int l,int r,int i,int x,int y){\n        if(y<l||r<x)return\
    \ Monoid::unit();\n        if(x<=l&&r<=y)return t[i];\n        int m=(l+r)/2;\n\
    \        return Monoid::op(query(l,m,i*2,x,y),query(m+1,r,i*2+1,x,y));\n    }\n\
    \    T query(int x,int y){\n        return query(0,n-1,1,x,y);\n    }\n    template<class\
    \ F>\n    int findfirst(int l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ n;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        int res=findfirst(l,m,i*2,x,y,f);\n\
    \        if(res==n)res=findfirst(m+1,r,i*2+1,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    int findfirst(int x,int y,const F &f){\n    \
    \    return findfirst(0,n-1,1,x,y,f);\n    }\n    template<class F>\n    int findlast(int\
    \ l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ -1;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        int res=findlast(m+1,r,i*2+1,x,y,f);\n\
    \        if(res==-1)res=findlast(l,m,i*2,x,y,f);\n        return res;\n    }\n\
    \    template<class F>\n    int findlast(int x,int y,const F &f){\n        return\
    \ findlast(0,n-1,1,x,y,f);\n    }\n};\n\n#line 2 \"group/monoid/affine.hpp\"\n\
    \n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Affine Transfomation\
    \ Monoid class.\n */\n\ntemplate<class T>\nstruct AffineMonoid{\n    using P =\
    \ pair<T,T>;\n    using value_type = P;\n    static constexpr P op(const P &x,const\
    \ P &y){\n        return P(x.first*y.first,x.second*y.first+y.second);\n    }\n\
    \    static constexpr P unit(){return P(T(1),T(0));}\n    static constexpr T eval(const\
    \ P &f,const T &x){\n        return f.first*x+f.second;\n    }\n};\n\n#line 6\
    \ \"verify/yosupo/data-structure/point_set_range_composite.test.cpp\"\n\nusing\
    \ mint = mint998;\nusing Monoid = AffineMonoid<mint>;\nusing T = Monoid::value_type;\n\
    \nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n \
    \   cin >> n >> q;\n    vector<T> a(n);\n    for(auto &[x,y]:a)cin >> x >> y;\n\
    \    SegmentTree<Monoid> s(a);\n    while(q--){\n        int op;\n        cin\
    \ >> op;\n        if(op){\n            int l,r,x;\n            cin >> l >> r >>\
    \ x;\n            cout << Monoid::eval(s.query(l,r-1),x) << \"\\n\";\n       \
    \ }else{\n            int p,a,b;\n            cin >> p >> a >> b;\n          \
    \  s.modify(p,T(a,b));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"template.hpp\"\n#include \"modular-arithmetic/modint.hpp\"\n#include\
    \ \"data-structure/segment-tree/segment-tree.hpp\"\n#include \"group/monoid/affine.hpp\"\
    \n\nusing mint = mint998;\nusing Monoid = AffineMonoid<mint>;\nusing T = Monoid::value_type;\n\
    \nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n \
    \   cin >> n >> q;\n    vector<T> a(n);\n    for(auto &[x,y]:a)cin >> x >> y;\n\
    \    SegmentTree<Monoid> s(a);\n    while(q--){\n        int op;\n        cin\
    \ >> op;\n        if(op){\n            int l,r,x;\n            cin >> l >> r >>\
    \ x;\n            cout << Monoid::eval(s.query(l,r-1),x) << \"\\n\";\n       \
    \ }else{\n            int p,a,b;\n            cin >> p >> a >> b;\n          \
    \  s.modify(p,T(a,b));\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - modular-arithmetic/modint.hpp
  - data-structure/segment-tree/segment-tree.hpp
  - group/monoid/affine.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 22:12:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/point_set_range_composite.test.cpp
- /verify/verify/yosupo/data-structure/point_set_range_composite.test.cpp.html
title: verify/yosupo/data-structure/point_set_range_composite.test.cpp
---
