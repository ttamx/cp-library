---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/convex/li-chao-tree.hpp
    title: data-structure/convex/li-chao-tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"verify/yosupo/data-structure/line_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#define\
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
    \ 2 \"data-structure/convex/li-chao-tree.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-06-12\n * Description: Li-Chao Tree (minimize).\n */\n\ntemplate<class\
    \ T>\nstruct LiChaoTree{\n    static const T INF=numeric_limits<T>::max()/2;\n\
    \    struct Line{\n        T m,c;\n        Line(T _m,T _c):m(_m),c(_c){}\n   \
    \     inline T eval(T x)const{return m*x+c;}\n    };\n    vector<T> xs;\n    vector<Line>\
    \ t;\n    LiChaoTree(){}\n    LiChaoTree(const vector<T> &x):xs(x){init(x);}\n\
    \    LiChaoTree(int n):xs(n){\n        vector<T> x(n);\n        iota(x.begin(),x.end(),0);\n\
    \        init(x);\n    }\n    void init(const vector<T> &x){\n        xs=x;\n\
    \        sort(xs.begin(),xs.end());\n        xs.erase(unique(xs.begin(),xs.end()),xs.end());\n\
    \        t.assign(4<<(31-__builtin_clz(xs.size())),Line(0,INF));\n    }\n    void\
    \ insert(int l,int r,int i,Line v){\n        int m=(l+r)/2;\n        if(v.eval(xs[m])<t[i].eval(xs[m]))swap(t[i],v);\n\
    \        if(v.eval(xs[l])<t[i].eval(xs[l]))insert(l,m,i*2,v);\n        if(v.eval(xs[r])<t[i].eval(xs[r]))insert(m+1,r,i*2+1,v);\n\
    \    }\n    inline void insert(T m,T c){\n        insert(0,(int)xs.size()-1,1,Line(m,c));\n\
    \    }\n    void insert_range(int l,int r,int i,T x,T y,Line v){\n        if(y<xs[l]||xs[r]<x)return;\n\
    \        if(x<=xs[l]&&xs[r]<=y)return insert(l,r,i,v);\n        int m=(l+r)/2;\n\
    \        insert_range(l,m,i*2,x,y,v);\n        insert_range(m+1,r,i*2+1,x,y,v);\n\
    \    }\n    inline void insert_range(T m,T c,T x,T y){\n        insert_range(0,(int)xs.size()-1,1,x,y,Line(m,c));\n\
    \    }\n    T query(int l,int r,int i,T x){\n        if(l==r)return t[i].eval(x);\n\
    \        int m=(l+r)/2;\n        if(x<=xs[m])return min(t[i].eval(x),query(l,m,i*2,x));\n\
    \        return min(t[i].eval(x),query(m+1,r,i*2+1,x));\n    }\n    inline T query(T\
    \ x){\n        return query(0,(int)xs.size()-1,1,x);\n    }\n};\n\n#line 4 \"\
    verify/yosupo/data-structure/line_add_get_min.test.cpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    vector<pair<ll,ll>> lines(n);\n    for(auto\
    \ &[a,b]:lines)cin >> a >> b;\n    vector<tuple<int,ll,ll>> qrs(q);\n    vector<ll>\
    \ xs;\n    for(auto &[op,a,b]:qrs){\n        cin >> op;\n        if(op){\n   \
    \         cin >> a;\n            xs.emplace_back(a);\n        }else{\n       \
    \     cin >> a >> b;\n        }\n    }\n    if(xs.empty()){\n        exit(0);\n\
    \    }\n    LiChaoTree<ll> lct(xs);\n    for(auto [a,b]:lines)lct.insert(a,b);\n\
    \    for(auto [op,a,b]:qrs){\n        if(op){\n            cout << lct.query(a)\
    \ << \"\\n\";\n        }else{\n            lct.insert(a,b);\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"template.hpp\"\n#include \"data-structure/convex/li-chao-tree.hpp\"\n\nint\
    \ main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin\
    \ >> n >> q;\n    vector<pair<ll,ll>> lines(n);\n    for(auto &[a,b]:lines)cin\
    \ >> a >> b;\n    vector<tuple<int,ll,ll>> qrs(q);\n    vector<ll> xs;\n    for(auto\
    \ &[op,a,b]:qrs){\n        cin >> op;\n        if(op){\n            cin >> a;\n\
    \            xs.emplace_back(a);\n        }else{\n            cin >> a >> b;\n\
    \        }\n    }\n    if(xs.empty()){\n        exit(0);\n    }\n    LiChaoTree<ll>\
    \ lct(xs);\n    for(auto [a,b]:lines)lct.insert(a,b);\n    for(auto [op,a,b]:qrs){\n\
    \        if(op){\n            cout << lct.query(a) << \"\\n\";\n        }else{\n\
    \            lct.insert(a,b);\n        }\n    }\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/convex/li-chao-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 22:12:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/line_add_get_min.test.cpp
- /verify/verify/yosupo/data-structure/line_add_get_min.test.cpp.html
title: verify/yosupo/data-structure/line_add_get_min.test.cpp
---
