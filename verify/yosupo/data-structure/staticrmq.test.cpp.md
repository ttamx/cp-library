---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/min.hpp
    title: group/monoid/min.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo/data-structure/staticrmq.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"template.hpp\"\
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
    \ 2 \"data-structure/sparse-table.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-06-12\n * Description: Sparse Table class.\n */\n\ntemplate<class Monoid>\n\
    struct SparseTable{\n    using T = typename Monoid::value_type;\n    int n;\n\
    \    vector<vector<T>> t;\n    SparseTable(){}\n    SparseTable(const vector<T>\
    \ &a){init(a);}\n    void init(const vector<T> &a){\n        n=(int)a.size();\n\
    \        int lg=31-__builtin_clz(n);\n        t.assign(lg+1,vector<T>(n,Monoid::unit()));\n\
    \        t[0]=a;\n        for(int i=0;i<lg;i++){\n            for(int j=0;j+(2<<i)<=n;j++){\n\
    \                t[i+1][j]=Monoid::op(t[i][j],t[i][j+(1<<i)]);\n            }\n\
    \        }\n    }\n    T query(int l,int r){\n        int lg=31-__builtin_clz(r-l+1);\n\
    \        return Monoid::op(t[lg][l],t[lg][r-(1<<lg)+1]);\n    }\n};\n\n#line 2\
    \ \"group/monoid/min.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n\
    \ * Description: Min Monoid class.\n */\n\ntemplate<class T>\nstruct MinMonoid{\n\
    \    using value_type = T;\n    static constexpr T op(const T &x,const T &y){return\
    \ min(x,y);}\n    static constexpr T unit(){return numeric_limits<T>::max();}\n\
    };\n\n#line 5 \"verify/yosupo/data-structure/staticrmq.test.cpp\"\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin >> n >>\
    \ q;\n    vector<int> a(n);\n    for(auto &x:a)cin >> x;\n    SparseTable<MinMonoid<int>>\
    \ s(a);\n    while(q--){\n        int l,r;\n        cin >> l >> r;\n        cout\
    \ << s.query(l,r-1) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    template.hpp\"\n#include \"data-structure/sparse-table.hpp\"\n#include \"group/monoid/min.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<int> a(n);\n    for(auto &x:a)cin >> x;\n    SparseTable<MinMonoid<int>>\
    \ s(a);\n    while(q--){\n        int l,r;\n        cin >> l >> r;\n        cout\
    \ << s.query(l,r-1) << \"\\n\";\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/sparse-table.hpp
  - group/monoid/min.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 22:12:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/staticrmq.test.cpp
- /verify/verify/yosupo/data-structure/staticrmq.test.cpp.html
title: verify/yosupo/data-structure/staticrmq.test.cpp
---
