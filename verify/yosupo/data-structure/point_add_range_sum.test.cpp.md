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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"data-structure/fenwick-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Fenwick /\
    \ Binary Indexed Tree\n */\n\ntemplate<class T>\nstruct Fenwick{\n    int n,logn;\n\
    \    vector<T> t;\n    Fenwick(){}\n    Fenwick(int _n){init(vector<T>(_n,T{}));}\n\
    \    template<class U>\n    Fenwick(const vector<U> &a){init(a);}\n    template<class\
    \ U>\n    void init(const vector<U> &a){\n        n=(int)a.size();\n        logn=31-__builtin_clz(n);\n\
    \        t.assign(n+1,T{});\n        for(int i=1;i<=n;i++){\n            t[i]=t[i]+a[i-1];\n\
    \            int j=i+(i&-i);\n            if(j<=n)t[j]=t[j]+t[i];\n        }\n\
    \    }\n    void update(int x,const T &v){\n        for(int i=x+1;i<=n;i+=i&-i)t[i]=t[i]+v;\n\
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
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/point_add_range_sum.test.cpp
- /verify/verify/yosupo/data-structure/point_add_range_sum.test.cpp.html
title: verify/yosupo/data-structure/point_add_range_sum.test.cpp
---
