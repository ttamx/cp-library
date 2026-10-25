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
  bundledCode: "#line 1 \"verify/yosupo/data-structure/sparse-table/staticrmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ db = long double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64\
    \ = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
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
    }\n#line 2 \"data-structure/sparse-table.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-06-12\n * Description: Sparse Table class.\n */\n\ntemplate<class\
    \ Monoid>\nstruct SparseTable{\n    using T = typename Monoid::value_type;\n \
    \   int n;\n    vector<vector<T>> t;\n    SparseTable(){}\n    SparseTable(const\
    \ vector<T> &a){init(a);}\n    void init(const vector<T> &a){\n        n=(int)a.size();\n\
    \        if(n==0)return t.clear();\n        int lg=31-__builtin_clz(n);\n    \
    \    t.assign(lg+1,vector<T>(n,Monoid::unit()));\n        t[0]=a;\n        for(int\
    \ i=0;i<lg;i++){\n            for(int j=0;j+(2<<i)<=n;j++){\n                t[i+1][j]=Monoid::op(t[i][j],t[i][j+(1<<i)]);\n\
    \            }\n        }\n    }\n    T query(int l,int r){\n        int lg=31-__builtin_clz(r-l+1);\n\
    \        return Monoid::op(t[lg][l],t[lg][r-(1<<lg)+1]);\n    }\n};\n\n#line 2\
    \ \"group/monoid/min.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n\
    \ * Description: Min Monoid class.\n */\n\ntemplate<class T>\nstruct MinMonoid{\n\
    \    using value_type = T;\n    static constexpr T op(const T &x,const T &y){return\
    \ min(x,y);}\n    static constexpr T unit(){return numeric_limits<T>::max();}\n\
    };\n\n#line 5 \"verify/yosupo/data-structure/sparse-table/staticrmq.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<int> a(n);\n    for(auto &x:a)cin >> x;\n    SparseTable<MinMonoid<int>>\
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
  path: verify/yosupo/data-structure/sparse-table/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 17:59:10+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/sparse-table/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/sparse-table/staticrmq.test.cpp
- /verify/verify/yosupo/data-structure/sparse-table/staticrmq.test.cpp.html
title: verify/yosupo/data-structure/sparse-table/staticrmq.test.cpp
---
