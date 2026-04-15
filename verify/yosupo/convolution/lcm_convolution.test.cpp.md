---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/lcm-convolution.hpp
    title: convolution/lcm-convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"verify/yosupo/convolution/lcm_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#line 1 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#define pb push_back\n#define\
    \ eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define fi first\n\
    #define se second\n\n#define ALL(a) a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n\
    #define SORT(a) sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
    #define UNI(a) a.erase(unique(ALL(a)),a.end())\n#define SZ(a) (int)(a.size())\n\
    #define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n\
    #define MIN(a) *min_element(ALL(a))\n#define MAX(a) *max_element(ALL(a))\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\n\nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class\
    \ T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\n#define vv(T,a,n,...)\
    \ vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define vvv(T,a,n,m,...) vector<vector<vector<T>>>\
    \ a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n#define vvvv(T,a,n,m,k,...)\
    \ vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
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
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 2 \"convolution/lcm-convolution.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description: LCM Convolution.\n\
    \ * Divisor Zeta Transform: $A^\\prime[n]=\\sum_{d|n}A[d]$.\n * Divisor Mobius\
    \ Transform: $A[n]=\\sum_{d|n}\\mu(n/d)A^\\prime[d]$.\n * Time: $O(N\\log\\log\
    \ N)$.\n */\n\ntemplate<class T>\nvoid divisor_zeta(vector<T> &a){\n    int n=(int)a.size();\n\
    \    vector<bool> is_prime(n,true);\n    for(int p=2;p<n;p++){\n        if(!is_prime[p])continue;\n\
    \        for(int i=1;i*p<n;i++){\n            is_prime[i*p]=false;\n         \
    \   a[i*p]+=a[i];\n        }\n    }\n}\n\ntemplate<class T>\nvoid divisor_mobius(vector<T>\
    \ &a){\n    int n=(int)a.size();\n    vector<bool> is_prime(n,true);\n    for(int\
    \ p=2;p<n;p++){\n        if(!is_prime[p])continue;\n        for(int i=(n-1)/p;i>=1;i--){\n\
    \            is_prime[i*p]=false;\n            a[i*p]-=a[i];\n        }\n    }\n\
    }\n\ntemplate<class T>\nvector<T> lcm_convolution(vector<T> a,vector<T> b){\n\
    \    divisor_zeta(a);\n    divisor_zeta(b);\n    for(int i=0;i<(int)a.size();i++)a[i]*=b[i];\n\
    \    divisor_mobius(a);\n    return a;\n}\n\n#line 5 \"verify/yosupo/convolution/lcm_convolution.test.cpp\"\
    \n\nusing mint = mint998;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    vector<mint> a(n+1),b(n+1);\n    for(int i=1;i<=n;i++)cin\
    \ >> a[i];\n    for(int i=1;i<=n;i++)cin >> b[i];\n    auto c=lcm_convolution(a,b);\n\
    \    for(int i=1;i<=n;i++)cout << c[i] << \" \\n\"[i==n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#include\
    \ \"template.hpp\"\n#include \"modular-arithmetic/modint.hpp\"\n#include \"convolution/lcm-convolution.hpp\"\
    \n\nusing mint = mint998;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    vector<mint> a(n+1),b(n+1);\n    for(int i=1;i<=n;i++)cin\
    \ >> a[i];\n    for(int i=1;i<=n;i++)cin >> b[i];\n    auto c=lcm_convolution(a,b);\n\
    \    for(int i=1;i<=n;i++)cout << c[i] << \" \\n\"[i==n];\n}"
  dependsOn:
  - template.hpp
  - modular-arithmetic/modint.hpp
  - convolution/lcm-convolution.hpp
  isVerificationFile: true
  path: verify/yosupo/convolution/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 21:45:25+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/convolution/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/convolution/lcm_convolution.test.cpp
- /verify/verify/yosupo/convolution/lcm_convolution.test.cpp.html
title: verify/yosupo/convolution/lcm_convolution.test.cpp
---
