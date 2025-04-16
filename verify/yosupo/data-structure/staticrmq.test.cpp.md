---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/min.hpp
    title: group/monoid/min.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo/data-structure/staticrmq.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"template.hpp\"\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"data-structure/sparse-table.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-12\n * Description: Sparse Table\
    \ class.\n */\n\ntemplate<class Monoid>\nstruct SparseTable{\n    using T = typename\
    \ Monoid::value_type;\n    int n;\n    vector<vector<T>> t;\n    SparseTable(){}\n\
    \    SparseTable(const vector<T> &a){init(a);}\n    void init(const vector<T>\
    \ &a){\n        n=(int)a.size();\n        int lg=31-__builtin_clz(n);\n      \
    \  t.assign(lg+1,vector<T>(n,Monoid::unit()));\n        t[0]=a;\n        for(int\
    \ i=0;i<lg;i++){\n            for(int j=0;j+(2<<i)<=n;j++){\n                t[i+1][j]=Monoid::op(t[i][j],t[i][j+(1<<i)]);\n\
    \            }\n        }\n    }\n    T query(int l,int r){\n        int lg=31-__builtin_clz(r-l+1);\n\
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
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/staticrmq.test.cpp
- /verify/verify/yosupo/data-structure/staticrmq.test.cpp.html
title: verify/yosupo/data-structure/staticrmq.test.cpp
---
