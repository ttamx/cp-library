---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/lcm-convolution.hpp
    title: convolution/lcm-convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"verify/yosupo/convolution/lcm_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n#include<ext/pb_ds/tree_policy.hpp>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;\n\nusing ll = long long;\n\
    using db = long double;\nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing\
    \ vd = vector<db>;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing\
    \ pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
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
    \n#line 2 \"convolution/lcm-convolution.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-07-29\n * Description: LCM Convolution.\n * Divisor Zeta Transform:\
    \ $A^\\prime[n]=\\sum_{d|n}A[d]$.\n * Divisor Mobius Transform: $A[n]=\\sum_{d|n}\\\
    mu(n/d)A^\\prime[d]$.\n * Time: $O(N\\log\\log N)$.\n */\n\ntemplate<class T>\n\
    void divisor_zeta(vector<T> &a){\n    int n=(int)a.size();\n    vector<bool> is_prime(n,true);\n\
    \    for(int p=2;p<n;p++){\n        if(!is_prime[p])continue;\n        for(int\
    \ i=1;i*p<n;i++){\n            is_prime[i*p]=false;\n            a[i*p]+=a[i];\n\
    \        }\n    }\n}\n\ntemplate<class T>\nvoid divisor_mobius(vector<T> &a){\n\
    \    int n=(int)a.size();\n    vector<bool> is_prime(n,true);\n    for(int p=2;p<n;p++){\n\
    \        if(!is_prime[p])continue;\n        for(int i=(n-1)/p;i>=1;i--){\n   \
    \         is_prime[i*p]=false;\n            a[i*p]-=a[i];\n        }\n    }\n\
    }\n\ntemplate<class T>\nvector<T> lcm_convolution(vector<T> a,vector<T> b){\n\
    \    divisor_zeta(a);\n    divisor_zeta(b);\n    for(int i=0;i<(int)a.size();i++)a[i]*=b[i];\n\
    \    divisor_mobius(a);\n    return a;\n}\n\n#line 5 \"verify/yosupo/convolution/lcm_convolution.test.cpp\"\
    \n\nusing mint = mint998;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    vector<mint> a(n+1),b(n+1);\n    for(int i=1;i<=n;i++)cin\
    \ >> a[i];\n    for(int i=1;i<=n;i++)cin >> b[i];\n    auto c=lcm_convolution(a,b);\n\
    \    for(int i=1;i<=n;i++)cout << c[i] << \" \\n\"[i==n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#include\
    \ \"template.hpp\"\n#include \"modular-arithmetic/montgomery-modint.hpp\"\n#include\
    \ \"convolution/lcm-convolution.hpp\"\n\nusing mint = mint998;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    cin >> n;\n  \
    \  vector<mint> a(n+1),b(n+1);\n    for(int i=1;i<=n;i++)cin >> a[i];\n    for(int\
    \ i=1;i<=n;i++)cin >> b[i];\n    auto c=lcm_convolution(a,b);\n    for(int i=1;i<=n;i++)cout\
    \ << c[i] << \" \\n\"[i==n];\n}"
  dependsOn:
  - template.hpp
  - modular-arithmetic/montgomery-modint.hpp
  - convolution/lcm-convolution.hpp
  isVerificationFile: true
  path: verify/yosupo/convolution/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/convolution/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/convolution/lcm_convolution.test.cpp
- /verify/verify/yosupo/convolution/lcm_convolution.test.cpp.html
title: verify/yosupo/convolution/lcm_convolution.test.cpp
---
