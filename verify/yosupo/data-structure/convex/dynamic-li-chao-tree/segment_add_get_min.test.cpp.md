---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/convex/dynamic-li-chao-tree.hpp
    title: data-structure/convex/dynamic-li-chao-tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
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
    }\n#line 2 \"data-structure/convex/dynamic-li-chao-tree.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-06-12\n * Description: Dynamic Li-Chao Tree.\n */\n\
    \ntemplate<class T,bool IS_MIN>\nstruct DynamicLiChaoTree{\n    static constexpr\
    \ T INF=numeric_limits<T>::max();\n    struct Line{\n        T m,c;\n        Line(T\
    \ _m,T _c):m(_m),c(_c){}\n        inline T eval(T x)const{return m*x+c;}\n   \
    \ };\n    struct Node{\n        Line v;\n        int l,r;\n        Node(Line _v=Line(0,INF)):v(_v),l(-1),r(-1){}\n\
    \    };\n    ll lb,ub;\n    vector<Node> t;\n    DynamicLiChaoTree(ll _lb,ll _ub):lb(_lb),ub(_ub),t{Node()}{assert(lb<=ub);}\n\
    \    int new_node(Line v=Line(0,INF)){\n        t.emplace_back(v);\n        return\
    \ t.size()-1;\n    }\n    void insert(T l,T r,int u,Line v){\n        T m=l+(r-l)/2;\n\
    \        if(v.eval(m)<t[u].v.eval(m))swap(t[u].v,v);\n        if(v.eval(l)<t[u].v.eval(l)){\n\
    \            if(t[u].l==-1){int c=new_node(v);t[u].l=c;}\n            else insert(l,m,t[u].l,v);\n\
    \        }\n        if(v.eval(r)<t[u].v.eval(r)){\n            if(t[u].r==-1){int\
    \ c=new_node(v);t[u].r=c;}\n            else insert(m+1,r,t[u].r,v);\n       \
    \ }\n    }\n    inline void insert(T m,T c){\n        if constexpr(!IS_MIN)m=-m,c=-c;\n\
    \        insert(lb,ub,0,Line(m,c));\n    }\n    void insert_range(T l,T r,int\
    \ u,T x,T y,Line v){\n        if(y<l||r<x)return;\n        if(x<=l&&r<=y)return\
    \ insert(l,r,u,v);\n        T m=l+(r-l)/2;\n        if(x<=m){\n            if(t[u].l==-1){int\
    \ c=new_node();t[u].l=c;}\n            insert_range(l,m,t[u].l,x,y,v);\n     \
    \   }\n        if(m<y){\n            if(t[u].r==-1){int c=new_node();t[u].r=c;}\n\
    \            insert_range(m+1,r,t[u].r,x,y,v);\n        }\n    }\n    inline void\
    \ insert_range(T m,T c,T x,T y){\n        if constexpr(!IS_MIN)m=-m,c=-c;\n  \
    \      insert_range(lb,ub,0,x,y,Line(m,c));\n    }\n    T query(T l,T r,int u,T\
    \ x){\n        if(u==-1)return INF;\n        T m=l+(r-l)/2;\n        if(x<=m)return\
    \ min(t[u].v.eval(x),query(l,m,t[u].l,x));\n        return min(t[u].v.eval(x),query(m+1,r,t[u].r,x));\n\
    \    }\n    inline T query(T x){\n        T res=query(lb,ub,0,x);\n        return\
    \ IS_MIN?res:-res;\n    }\n};\n#line 4 \"verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    const int X=1e9;\n    DynamicLiChaoTree<ll,true> lct(-X,X);\n\
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
    \    cin >> n >> q;\n    const int X=1e9;\n    DynamicLiChaoTree<ll,true> lct(-X,X);\n\
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
  path: verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 17:59:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp
- /verify/verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp.html
title: verify/yosupo/data-structure/convex/dynamic-li-chao-tree/segment_add_get_min.test.cpp
---
