---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dsu.hpp
    title: data-structure/dsu.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo/data-structure/unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"template.hpp\"\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"data-structure/dsu.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n * Description: Disjoint Set\
    \ Union.\n */\n\nstruct DSU{\n    vector<int> p,sz;\n    DSU(){}\n    DSU(int\
    \ n){init(n);}\n    void init(int n){\n        p.resize(n);\n        iota(p.begin(),p.end(),0);\n\
    \        sz.assign(n,1);\n    }\n    int find(int u){\n        return p[u]==u?u:p[u]=find(p[u]);\n\
    \    }\n    bool same(int u,int v){\n        return find(u)==find(v);\n    }\n\
    \    bool merge(int u,int v){\n        u=find(u),v=find(v);\n        if(u==v)return\
    \ false;\n        sz[u]+=sz[v];\n        p[v]=u;\n        return true;\n    }\n\
    \    int size(int u){\n        return sz[find(u)];\n    }\n};\n\n#line 4 \"verify/yosupo/data-structure/unionfind.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    DSU dsu(n);\n    while(q--){\n        int t,u,v;\n  \
    \      cin >> t >> u >> v;\n        if(t==0)dsu.merge(u,v);\n        else cout\
    \ << dsu.same(u,v) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    template.hpp\"\n#include \"data-structure/dsu.hpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    DSU dsu(n);\n    while(q--){\n        int\
    \ t,u,v;\n        cin >> t >> u >> v;\n        if(t==0)dsu.merge(u,v);\n     \
    \   else cout << dsu.same(u,v) << \"\\n\";\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/dsu.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/unionfind.test.cpp
- /verify/verify/yosupo/data-structure/unionfind.test.cpp.html
title: verify/yosupo/data-structure/unionfind.test.cpp
---
