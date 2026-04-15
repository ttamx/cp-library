---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modular-arithmetic/binpow.hpp
    title: modular-arithmetic/binpow.hpp
  - icon: ':question:'
    path: modular-arithmetic/modint.hpp
    title: modular-arithmetic/modint.hpp
  - icon: ':question:'
    path: polynomial/formal-power-series.hpp
    title: polynomial/formal-power-series.hpp
  - icon: ':question:'
    path: polynomial/ntt.hpp
    title: polynomial/ntt.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
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
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 2 \"modular-arithmetic/binpow.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: n-th power\
    \ using divide and conquer\n * Time: $O(\\log b)$\n */\n\ntemplate<class T>\n\
    constexpr T binpow(T a,ll b){\n    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n\
    \    return res;\n}\n\n#line 3 \"polynomial/ntt.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: Number Theoretic Transform\n * Time: $O(N \\log N)$\n */\n\
    \ntemplate<class mint>\nstruct NTT{\n\tusing vm = vector<mint>;\n\t\n\tstatic\
    \ constexpr mint root=mint::get_root();\n    static_assert(root!=0, \"root must\
    \ be nonzero\");\n\n\tstatic void ntt(vm &a){\n\t\tint n=a.size(),L=31-__builtin_clz(n);\n\
    \t\tvm rt(n);\n\t\trt[1]=1;\n\t\tfor(int k=2,s=2;k<n;k*=2,s++){\n\t\t\tmint z[]={1,binpow(root,MOD>>s)};\n\
    \t\t\tfor(int i=k;i<2*k;i++)rt[i]=rt[i/2]*z[i&1];\n\t\t}\n\t\tvector<int> rev(n);\n\
    \t\tfor(int i=1;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<L)/2;\n\t\tfor(int i=1;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);\n\
    \t\tfor(int k=1;k<n;k*=2)for(int i=0;i<n;i+=2*k)for(int j=0;j<k;j++){\n\t\t\t\
    mint z=rt[j+k]*a[i+j+k];\n\t\t\ta[i+j+k]=a[i+j]-z;\n\t\t\ta[i+j]+=z;\n\t\t}\n\t\
    }\n\tstatic vm conv(const vm &a,const vm &b){\n\t\tif(a.empty()||b.empty())return\
    \ {};\n\t\tint s=a.size()+b.size()-1,n=1<<(32-__builtin_clz(s));\n\t\tmint inv=mint(n).inv();\n\
    \t\tvm in1(a),in2(b),out(n);\n\t\tin1.resize(n),in2.resize(n);\n\t\tntt(in1),ntt(in2);\n\
    \t\tfor(int i=0;i<n;i++)out[-i&(n-1)]=in1[i]*in2[i]*inv;\n\t\tntt(out);\n\t\t\
    return vm(out.begin(),out.begin()+s);\n\t}\n\tvm operator()(const vm &a,const\
    \ vm &b){\n\t\treturn conv(a,b);\n\t}\n};\n\n#line 3 \"polynomial/formal-power-series.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description: basic operations\
    \ of formal power series\n */\n\ntemplate<class mint>\nstruct FormalPowerSeries:vector<mint>{\n\
    \    using vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n\n    FPS\
    \ &operator+=(const FPS &rhs){\n        if(rhs.size()>this->size())this->resize(rhs.size());\n\
    \        for(int i=0;i<rhs.size();i++)(*this)[i]+=rhs[i];\n        return *this;\n\
    \    }\n    FPS &operator+=(const mint &rhs){\n        if(this->empty())this->resize(1);\n\
    \        (*this)[0]+=rhs;\n        return *this;\n    }\n    FPS &operator-=(const\
    \ FPS &rhs){\n        if(rhs.size()>this->size())this->resize(rhs.size());\n \
    \       for(int i=0;i<rhs.size();i++)(*this)[i]-=rhs[i];\n        return *this;\n\
    \    }\n    FPS &operator-=(const mint &rhs){\n        if(this->empty())this->resize(1);\n\
    \        (*this)[0]-=rhs;\n        return *this;\n    }\n    FPS &operator*=(const\
    \ FPS &rhs){\n        auto res=NTT<mint>()(*this,rhs);\n        return *this=FPS(res.begin(),res.end());\n\
    \    }\n    FPS &operator*=(const mint &rhs){\n        for(auto &a:*this)a*=rhs;\n\
    \        return *this;\n    }\n    friend FPS operator+(FPS lhs,const FPS &rhs){return\
    \ lhs+=rhs;}\n    friend FPS operator+(FPS lhs,const mint &rhs){return lhs+=rhs;}\n\
    \    friend FPS operator+(const mint &lhs,FPS &rhs){return rhs+=lhs;}\n    friend\
    \ FPS operator-(FPS lhs,const FPS &rhs){return lhs-=rhs;}\n    friend FPS operator-(FPS\
    \ lhs,const mint &rhs){return lhs-=rhs;}\n    friend FPS operator-(const mint\
    \ &lhs,FPS rhs){return -(rhs-lhs);}\n    friend FPS operator*(FPS lhs,const FPS\
    \ &rhs){return lhs*=rhs;}\n    friend FPS operator*(FPS lhs,const mint &rhs){return\
    \ lhs*=rhs;}\n    friend FPS operator*(const mint &lhs,FPS rhs){return rhs*=lhs;}\n\
    \    \n    FPS operator-(){return (*this)*-1;}\n\n    FPS rev(){\n        FPS\
    \ res(*this);\n        reverse(res.beign(),res.end());\n        return res;\n\
    \    }\n    FPS pre(int sz){\n        FPS res(this->begin(),this->begin()+min((int)this->size(),sz));\n\
    \        if(res.size()<sz)res.resize(sz);\n        return res;\n    }\n    FPS\
    \ shrink(){\n        FPS res(*this);\n        while(!res.empty()&&res.back()==mint{})res.pop_back();\n\
    \        return res;\n    }\n    FPS operator>>(int sz){\n        if(this->size()<=sz)return\
    \ {};\n        FPS res(*this);\n        res.erase(res.begin(),res.begin()+sz);\n\
    \        return res;\n    }\n    FPS operator<<(int sz){\n        FPS res(*this);\n\
    \        res.insert(res.begin(),sz,mint{});\n        return res;\n    }\n    FPS\
    \ diff(){\n        const int n=this->size();\n        FPS res(max(0,n-1));\n \
    \       for(int i=1;i<n;i++)res[i-1]=(*this)[i]*mint(i);\n        return res;\n\
    \    }\n    FPS integral(){\n        const int n=this->size();\n        FPS res(n+1);\n\
    \        res[0]=0;\n        if(n>0)res[1]=1;\n        ll mod=mint::get_mod();\n\
    \        for(int i=2;i<=n;i++)res[i]=(-res[mod%i])*(mod/i);\n        for(int i=0;i<n;i++)res[i+1]*=(*this)[i];\n\
    \        return res;\n    }\n    mint eval(const mint &x){\n        mint res=0,w=1;\n\
    \        for(auto &a:*this)res+=a*w,w*=x;\n        return res;\n    }\n\n    FPS\
    \ inv(int deg=-1){\n        assert(!this->empty()&&(*this)[0]!=mint(0));\n   \
    \     if(deg==-1)deg=this->size();\n        FPS res{mint(1)/(*this)[0]};\n   \
    \     for(int i=2;i>>1<deg;i<<=1){\n            res=(res*(mint(2)-res*pre(i))).pre(i);\n\
    \        }\n        return res.pre(deg);\n    }\n    FPS log(int deg=-1){\n  \
    \      assert(!this->empty()&&(*this)[0]==mint(1));\n        if(deg==-1)deg=this->size();\n\
    \        return (pre(deg).diff()*inv(deg)).pre(deg-1).integral();\n    }\n   \
    \ FPS exp(int deg=-1){\n        assert(this->empty()||(*this)[0]==mint(0));\n\
    \        if(deg==-1)deg=this->size();\n        FPS res{mint(1)};\n        for(int\
    \ i=2;i>>1<deg;i<<=1){\n            res=(res*(pre(i)-res.log(i)+mint(1))).pre(i);\n\
    \        }\n        return res.pre(deg);\n    }\n    FPS pow(ll k,int deg=-1){\n\
    \        const int n=this->size();\n        if(deg==-1)deg=n;\n        if(k==0){\n\
    \            FPS res(deg);\n            if(deg)res[0]=mint(1);\n            return\
    \ res;\n        }\n        for(int i=0;i<n;i++){\n            if(__int128_t(i)*k>=deg)return\
    \ FPS(deg,mint(0));\n            if((*this)[i]==mint(0))continue;\n          \
    \  mint rev=mint(1)/(*this)[i];\n            FPS res=(((*this*rev)>>i).log(deg)*k).exp(deg);\n\
    \            res=((res*binpow((*this)[i],k))<<(i*k)).pre(deg);\n            return\
    \ res;\n        }\n        return FPS(deg,mint(0));\n    }\n};\n#line 5 \"verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp\"\
    \n\n\nusing mint = mint998;\nusing FPS = FormalPowerSeries<mint>;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    ll m;\n    cin\
    \ >> n >> m;\n    FPS a(n);\n    for(auto &x:a)cin >> x;\n    a=a.pow(m);\n  \
    \  for(auto x:a)cout << x << \" \";\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n#include \"template.hpp\"\n#include \"modular-arithmetic/modint.hpp\"\n#include\
    \ \"polynomial/formal-power-series.hpp\"\n\n\nusing mint = mint998;\nusing FPS\
    \ = FormalPowerSeries<mint>;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n;\n    ll m;\n    cin >> n >> m;\n    FPS a(n);\n    for(auto &x:a)cin\
    \ >> x;\n    a=a.pow(m);\n    for(auto x:a)cout << x << \" \";\n    cout << \"\
    \\n\";\n}"
  dependsOn:
  - template.hpp
  - modular-arithmetic/modint.hpp
  - polynomial/formal-power-series.hpp
  - polynomial/ntt.hpp
  - modular-arithmetic/binpow.hpp
  isVerificationFile: true
  path: verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 22:12:04+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
- /verify/verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp.html
title: verify/yosupo/polynomial/pow_of_formal_power_series.test.cpp
---
