---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: data-structure/fenwick-tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo/data-structure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n#define\
    \ RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
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
    \ 2 \"data-structure/fenwick-tree.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-01-15\n * Description: Fenwick / Binary Indexed Tree\n */\n\ntemplate<class\
    \ T>\nstruct Fenwick{\n    int n,logn;\n    vector<T> t;\n    Fenwick(){}\n  \
    \  Fenwick(int _n){init(vector<T>(_n,T{}));}\n    template<class U>\n    Fenwick(const\
    \ vector<U> &a){init(a);}\n    template<class U>\n    void init(const vector<U>\
    \ &a){\n        n=(int)a.size();\n        logn=31-__builtin_clz(n);\n        t.assign(n+1,T{});\n\
    \        for(int i=1;i<=n;i++){\n            t[i]=t[i]+a[i-1];\n            int\
    \ j=i+(i&-i);\n            if(j<=n)t[j]=t[j]+t[i];\n        }\n    }\n    void\
    \ update(int x,const T &v){\n        for(int i=x+1;i<=n;i+=i&-i)t[i]=t[i]+v;\n\
    \    }\n    void update(int l,int r,const T &v){\n        update(l,v),update(r+1,-v);\n\
    \    }\n    T query(int x){\n        T res{};\n        for(int i=x+1;i>0;i-=i&-i)res=res+t[i];\n\
    \        return res;\n    }\n    T query(int l,int r){\n        return query(r)-query(l-1);\n\
    \    }\n    int find(const T &k){\n        int x=0;\n        T cur{};\n      \
    \  for(int i=1<<logn;i>0;i>>=1)\n            if(x+i<=n&&cur+t[x+i]<=k)x+=i,cur=cur+t[x];\n\
    \        return x;\n    }\n};\n\n#line 4 \"verify/yosupo/data-structure/point_add_range_sum.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<int> a(n);\n    for(auto &x:a)cin >> x;\n    Fenwick<ll>\
    \ f(a);\n    while(q--){\n        int op;\n        cin >> op;\n        if(op){\n\
    \            int l,r;\n            cin >> l >> r;\n            cout << f.query(l,r-1)\
    \ << \"\\n\";\n        }else{\n            int p,x;\n            cin >> p >> x;\n\
    \            f.update(p,x);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"template.hpp\"\n#include \"data-structure/fenwick-tree.hpp\"\n\nint\
    \ main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin\
    \ >> n >> q;\n    vector<int> a(n);\n    for(auto &x:a)cin >> x;\n    Fenwick<ll>\
    \ f(a);\n    while(q--){\n        int op;\n        cin >> op;\n        if(op){\n\
    \            int l,r;\n            cin >> l >> r;\n            cout << f.query(l,r-1)\
    \ << \"\\n\";\n        }else{\n            int p,x;\n            cin >> p >> x;\n\
    \            f.update(p,x);\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 17:32:38+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/point_add_range_sum.test.cpp
- /verify/verify/yosupo/data-structure/point_add_range_sum.test.cpp.html
title: verify/yosupo/data-structure/point_add_range_sum.test.cpp
---
