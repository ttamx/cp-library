---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/dsu.hpp
    title: data-structure/dsu.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo/data-structure/unionfind.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing db = long double;\nusing\
    \ vi = vector<int>;\nusing vl = vector<ll>;\nusing vd = vector<db>;\nusing pii\
    \ = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst\
    \ int INF=INT_MAX/2;\nconst int MOD=998244353;\nconst int MOD2=1000000007;\nconst\
    \ ll LINF=LLONG_MAX/2;\nconst db DINF=numeric_limits<db>::infinity();\nconst db\
    \ EPS=1e-9;\nconst db PI=acos(db(-1));\n\n#line 2 \"data-structure/dsu.hpp\"\n\
    \n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n * Description: Disjoint Set\
    \ Union.\n */\n\nstruct DSU{\n    vector<int> p,sz;\n    DSU(){}\n    DSU(int\
    \ n){init(n);}\n    void init(int n){\n        p.resize(n);\n        iota(p.begin(),p.end(),0);\n\
    \        sz.assign(n,1);\n    }\n    int find(int u){\n        return p[u]==u?u:p[u]=find(p[u]);\n\
    \    }\n    bool same(int u,int v){\n        return find(u)==find(v);\n    }\n\
    \    bool merge(int u,int v){\n        u=find(u),v=find(v);\n        if(u==v)return\
    \ false;\n        sz[u]+=sz[v];\n        p[v]=u;\n        return true;\n    }\n\
    \    int size(int u){\n        return sz[find(u)];\n    }\n};\n\n#line 4 \"verify/yosupo/data-structure/unionfind.cpp\"\
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
  isVerificationFile: false
  path: verify/yosupo/data-structure/unionfind.cpp
  requiredBy: []
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/unionfind.cpp
layout: document
redirect_from:
- /library/verify/yosupo/data-structure/unionfind.cpp
- /library/verify/yosupo/data-structure/unionfind.cpp.html
title: verify/yosupo/data-structure/unionfind.cpp
---
