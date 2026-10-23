---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/xor-convolution.hpp
    title: convolution/xor-convolution.hpp
  - icon: ':question:'
    path: modular-arithmetic/modint.hpp
    title: modular-arithmetic/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"verify/yosupo/convolution/xor-convolution/bitwise_xor_convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\
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
    \ 2 \"modular-arithmetic/modint.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n\
    \ * Description: modular arithmetic operations\n */\n\ntemplate<int mod,int root=0>\n\
    struct ModInt{\n    using mint = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must\
    \ be positive\");\n\n    int x;\n\n    constexpr ModInt():x(0){}\n    constexpr\
    \ ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n    constexpr explicit operator int()const{return\
    \ x;}\n    constexpr int val()const{return x;}\n    constexpr static int get_mod(){return\
    \ mod;}\n    constexpr static mint get_root(){return mint(root);}\n    \n    constexpr\
    \ mint operator-()const{\n        mint res;\n        res.x=x?mod-x:0;\n      \
    \  return res;\n    }\n    constexpr mint operator+()const{return *this;}\n\n\
    \    constexpr mint inv()const{\n        int a=x,b=mod,u=1,v=0,q=0;\n        while(b>0){\n\
    \            q=a/b;\n            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n\
    \        }\n        return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n\
    \        mint res=1,a=*this;\n        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n   \
    \     return res;\n    }\n    constexpr mint &operator+=(const mint &o){\n   \
    \     if((x+=o.x)>=mod)x-=mod;\n        return *this;\n    }\n    constexpr mint\
    \ &operator-=(const mint &o){\n        if((x-=o.x)<0)x+=mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator*=(const mint &o){\n        x=(ll(x)*o.x)%mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator/=(const mint &o){\n\
    \        return *this*=o.inv();\n    }\n\n    constexpr mint operator+(const mint\
    \ &o)const{return mint(*this)+=o;}\n    constexpr mint operator-(const mint &o)const{return\
    \ mint(*this)-=o;}\n    constexpr mint operator*(const mint &o)const{return mint(*this)*=o;}\n\
    \    constexpr mint operator/(const mint &o)const{return mint(*this)/=o;}\n\n\
    \    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){mint\
    \ res=*this;*this+=mint(1);return res;}\n    constexpr mint operator--(int){mint\
    \ res=*this;*this-=mint(1);return res;}\n    \n    constexpr bool operator==(const\
    \ mint &o)const{return x==o.x;}\n    constexpr bool operator!=(const mint &o)const{return\
    \ x!=o.x;}\n    constexpr bool operator<(const mint &o)const{return x<o.x;}\n\
    \    \n    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    };\nusing mint998 = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n\
    #line 2 \"convolution/xor-convolution.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-07-29\n * Description: Bitwise XOR Convolution.\n * Fast Walsh-Hadamard\
    \ Transform: $A^\\prime[S]=\\sum_T(-1)^{|S\\&T|}A[T]$.\n * Time: $O(N\\log N)$.\n\
    \ */\n\ntemplate<class T>\nvoid fwht(vector<T> &a){\n    int n=(int)a.size();\n\
    \    assert(n==(n&-n));\n    for(int i=1;i<n;i<<=1){\n        for(int j=0;j<n;j++){\n\
    \            if(j&i){\n                T &u=a[j^i],&v=a[j];\n                tie(u,v)=make_pair(u+v,u-v);\n\
    \            }\n        }\n    }\n}\n\ntemplate<class T>\nvector<T> xor_convolution(vector<T>\
    \ a,vector<T> b){\n    int n=(int)a.size();\n    fwht(a);\n    fwht(b);\n    for(int\
    \ i=0;i<n;i++)a[i]*=b[i];\n    fwht(a);\n    T div=T(1)/T(n);\n    if(div==T(0)){\n\
    \        for(auto &x:a)x/=n;\n    }else{\n        for(auto &x:a)x*=div;\n    }\n\
    \    return a;\n}\n\n#line 5 \"verify/yosupo/convolution/xor-convolution/bitwise_xor_convolution.test.cpp\"\
    \n\nusing mint = mint998;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    n=1<<n;\n    vector<mint> a(n),b(n);\n    for(auto\
    \ &x:a)cin >> x;\n    for(auto &x:b)cin >> x;\n    auto c=xor_convolution(a,b);\n\
    \    for(auto x:c)cout << x << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n#include \"template.hpp\"\n#include \"modular-arithmetic/modint.hpp\"\n#include\
    \ \"convolution/xor-convolution.hpp\"\n\nusing mint = mint998;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    cin >> n;\n  \
    \  n=1<<n;\n    vector<mint> a(n),b(n);\n    for(auto &x:a)cin >> x;\n    for(auto\
    \ &x:b)cin >> x;\n    auto c=xor_convolution(a,b);\n    for(auto x:c)cout << x\
    \ << \" \";\n}"
  dependsOn:
  - template.hpp
  - modular-arithmetic/modint.hpp
  - convolution/xor-convolution.hpp
  isVerificationFile: true
  path: verify/yosupo/convolution/xor-convolution/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/convolution/xor-convolution/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/convolution/xor-convolution/bitwise_xor_convolution.test.cpp
- /verify/verify/yosupo/convolution/xor-convolution/bitwise_xor_convolution.test.cpp.html
title: verify/yosupo/convolution/xor-convolution/bitwise_xor_convolution.test.cpp
---
