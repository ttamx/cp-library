---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/convex/dynamic-li-chao-tree.hpp
    title: data-structure/convex/dynamic-li-chao-tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"verify/yosupo/data-structure/segment_add_get_min_online.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\nusing\
    \ vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst\
    \ int MOD=998244353;\nconst int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    template<class T>\nusing ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"data-structure/convex/dynamic-li-chao-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-12\n * Description: Dynamic Li-Chao\
    \ Tree (minimize).\n */\n\ntemplate<class T>\nstruct DynamicLiChaoTree{\n    static\
    \ const T INF=numeric_limits<T>::max()/2;\n    struct Line{\n        T m,c;\n\
    \        Line(T _m,T _c):m(_m),c(_c){}\n        inline T eval(T x)const{return\
    \ m*x+c;}\n    };\n    struct Node;\n    using Ptr = Node*;\n    struct Node{\n\
    \        Line v;\n        Ptr l,r;\n        Node():v(0,INF),l(nullptr),r(nullptr){}\n\
    \        Node(Line _v):v(_v),l(nullptr),r(nullptr){}\n    };\n    ll lb,ub;\n\
    \    Ptr root;\n    DynamicLiChaoTree(ll _lb,ll _ub):lb(_lb),ub(_ub),root(nullptr){}\n\
    \    void insert(T l,T r,Ptr &t,Line v){\n        if(!t)return void(t=new Node(v));\n\
    \        T m=l+(r-l)/2;\n        if(v.eval(m)<t->v.eval(m))swap(t->v,v);\n   \
    \     if(v.eval(l)<t->v.eval(l))insert(l,m,t->l,v);\n        if(v.eval(r)<t->v.eval(r))insert(m+1,r,t->r,v);\n\
    \    }\n    inline void insert(T m,T c){\n        insert(lb,ub,root,Line(m,c));\n\
    \    }\n    void insert_range(T l,T r,Ptr &t,T x,T y,Line v){\n        if(y<l||r<x)return;\n\
    \        if(!t)t=new Node();\n        if(x<=l&&r<=y)return insert(l,r,t,v);\n\
    \        T m=l+(r-l)/2;\n        insert_range(l,m,t->l,x,y,v);\n        insert_range(m+1,r,t->r,x,y,v);\n\
    \    }\n    inline void insert_range(T m,T c,T x,T y){\n        insert_range(lb,ub,root,x,y,Line(m,c));\n\
    \    }\n    T query(T l,T r,Ptr t,T x){\n        if(!t)return INF;\n        T\
    \ m=l+(r-l)/2;\n        if(x<=m)return min(t->v.eval(x),query(l,m,t->l,x));\n\
    \        return min(t->v.eval(x),query(m+1,r,t->r,x));\n    }\n    inline T query(T\
    \ x){\n        return query(lb,ub,root,x);\n    }\n};\n\n#line 4 \"verify/yosupo/data-structure/segment_add_get_min_online.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    const int X=1e9;\n    DynamicLiChaoTree<ll> lct(-X,X);\n\
    \    while(n--){\n        ll l,r,a,b;\n        cin >> l >> r >> a >> b;\n    \
    \    lct.insert_range(a,b,l,r-1);\n    }\n    while(q--){\n        int op;\n \
    \       cin >> op;\n        if(op){\n            ll x;\n            cin >> x;\n\
    \            ll res=lct.query(x);\n            if(res>=lct.INF)cout << \"INFINITY\\\
    n\";\n            else cout << res << \"\\n\";\n        }else{\n            ll\
    \ l,r,a,b;\n            cin >> l >> r >> a >> b;\n            lct.insert_range(a,b,l,r-1);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"template.hpp\"\n#include \"data-structure/convex/dynamic-li-chao-tree.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    const int X=1e9;\n    DynamicLiChaoTree<ll> lct(-X,X);\n\
    \    while(n--){\n        ll l,r,a,b;\n        cin >> l >> r >> a >> b;\n    \
    \    lct.insert_range(a,b,l,r-1);\n    }\n    while(q--){\n        int op;\n \
    \       cin >> op;\n        if(op){\n            ll x;\n            cin >> x;\n\
    \            ll res=lct.query(x);\n            if(res>=lct.INF)cout << \"INFINITY\\\
    n\";\n            else cout << res << \"\\n\";\n        }else{\n            ll\
    \ l,r,a,b;\n            cin >> l >> r >> a >> b;\n            lct.insert_range(a,b,l,r-1);\n\
    \        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/convex/dynamic-li-chao-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/segment_add_get_min_online.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/segment_add_get_min_online.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/segment_add_get_min_online.test.cpp
- /verify/verify/yosupo/data-structure/segment_add_get_min_online.test.cpp.html
title: verify/yosupo/data-structure/segment_add_get_min_online.test.cpp
---
