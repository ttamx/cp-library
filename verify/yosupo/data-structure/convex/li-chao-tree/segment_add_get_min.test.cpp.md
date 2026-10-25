---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/convex/li-chao-tree.hpp
    title: data-structure/convex/li-chao-tree.hpp
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
  bundledCode: "#line 1 \"verify/yosupo/data-structure/convex/li-chao-tree/segment_add_get_min.test.cpp\"\
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
    }\n#line 2 \"data-structure/convex/li-chao-tree.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-06-12\n * Description: Li-Chao Tree.\n */\n\ntemplate<class\
    \ T,bool IS_MIN>\nstruct LiChaoTree{\n    static constexpr T INF=numeric_limits<T>::max();\n\
    \    struct Line{\n        T m,c;\n        Line(T _m,T _c):m(_m),c(_c){}\n   \
    \     inline T eval(T x)const{return m*x+c;}\n    };\n    vector<T> xs;\n    vector<Line>\
    \ t;\n    LiChaoTree(){}\n    LiChaoTree(const vector<T> &x):xs(x){init(x);}\n\
    \    LiChaoTree(int n):xs(n){\n        vector<T> x(n);\n        iota(x.begin(),x.end(),0);\n\
    \        init(x);\n    }\n    void init(const vector<T> &x){\n        xs=x;\n\
    \        sort(xs.begin(),xs.end());\n        xs.erase(unique(xs.begin(),xs.end()),xs.end());\n\
    \        if(xs.empty())return t.clear();\n        t.assign(4<<(31-__builtin_clz(xs.size())),Line(0,INF));\n\
    \    }\n    void insert(int l,int r,int i,Line v){\n        int m=(l+r)/2;\n \
    \       if(v.eval(xs[m])<t[i].eval(xs[m]))swap(t[i],v);\n        if(v.eval(xs[l])<t[i].eval(xs[l]))insert(l,m,i*2,v);\n\
    \        if(v.eval(xs[r])<t[i].eval(xs[r]))insert(m+1,r,i*2+1,v);\n    }\n   \
    \ inline void insert(T m,T c){\n        if(xs.empty())return;\n        if constexpr(!IS_MIN)m=-m,c=-c;\n\
    \        insert(0,(int)xs.size()-1,1,Line(m,c));\n    }\n    void insert_range(int\
    \ l,int r,int i,T x,T y,Line v){\n        if(y<xs[l]||xs[r]<x)return;\n      \
    \  if(x<=xs[l]&&xs[r]<=y)return insert(l,r,i,v);\n        int m=(l+r)/2;\n   \
    \     insert_range(l,m,i*2,x,y,v);\n        insert_range(m+1,r,i*2+1,x,y,v);\n\
    \    }\n    inline void insert_range(T m,T c,T x,T y){\n        if(xs.empty())return;\n\
    \        if constexpr(!IS_MIN)m=-m,c=-c;\n        insert_range(0,(int)xs.size()-1,1,x,y,Line(m,c));\n\
    \    }\n    T query(int l,int r,int i,T x){\n        if(l==r)return t[i].eval(x);\n\
    \        int m=(l+r)/2;\n        if(x<=xs[m])return min(t[i].eval(x),query(l,m,i*2,x));\n\
    \        return min(t[i].eval(x),query(m+1,r,i*2+1,x));\n    }\n    inline T query(T\
    \ x){\n        if(xs.empty())return IS_MIN?INF:-INF;\n        T res=query(0,(int)xs.size()-1,1,x);\n\
    \        return IS_MIN?res:-res;\n    }\n};\n\n#line 4 \"verify/yosupo/data-structure/convex/li-chao-tree/segment_add_get_min.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<tuple<ll,ll,ll,ll>> lines(n);\n    vector<ll>\
    \ xs;\n    for(auto &[a,b,l,r]:lines){\n        cin >> l >> r >> a >> b;\n   \
    \     r--;\n        xs.emplace_back(l);\n        xs.emplace_back(r);\n    }\n\
    \    vector<tuple<int,ll,ll,ll,ll>> qrs(q);\n    for(auto &[op,a,b,l,r]:qrs){\n\
    \        cin >> op;\n        if(op){\n            cin >> a;\n            xs.emplace_back(a);\n\
    \        }else{\n            cin >> l >> r >> a >> b;\n            r--;\n    \
    \        xs.emplace_back(l);\n            xs.emplace_back(r);\n        }\n   \
    \ }\n    LiChaoTree<ll,true> lct(xs);\n    for(auto [a,b,l,r]:lines)lct.insert_range(a,b,l,r);\n\
    \    for(auto [op,a,b,l,r]:qrs){\n        if(op){\n            ll res=lct.query(a);\n\
    \            if(res>=lct.INF)cout << \"INFINITY\\n\";\n            else cout <<\
    \ res << \"\\n\";\n        }else{\n            lct.insert_range(a,b,l,r);\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"template.hpp\"\n#include \"data-structure/convex/li-chao-tree.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<tuple<ll,ll,ll,ll>> lines(n);\n    vector<ll>\
    \ xs;\n    for(auto &[a,b,l,r]:lines){\n        cin >> l >> r >> a >> b;\n   \
    \     r--;\n        xs.emplace_back(l);\n        xs.emplace_back(r);\n    }\n\
    \    vector<tuple<int,ll,ll,ll,ll>> qrs(q);\n    for(auto &[op,a,b,l,r]:qrs){\n\
    \        cin >> op;\n        if(op){\n            cin >> a;\n            xs.emplace_back(a);\n\
    \        }else{\n            cin >> l >> r >> a >> b;\n            r--;\n    \
    \        xs.emplace_back(l);\n            xs.emplace_back(r);\n        }\n   \
    \ }\n    LiChaoTree<ll,true> lct(xs);\n    for(auto [a,b,l,r]:lines)lct.insert_range(a,b,l,r);\n\
    \    for(auto [op,a,b,l,r]:qrs){\n        if(op){\n            ll res=lct.query(a);\n\
    \            if(res>=lct.INF)cout << \"INFINITY\\n\";\n            else cout <<\
    \ res << \"\\n\";\n        }else{\n            lct.insert_range(a,b,l,r);\n  \
    \      }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/convex/li-chao-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/convex/li-chao-tree/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 17:59:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/convex/li-chao-tree/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/convex/li-chao-tree/segment_add_get_min.test.cpp
- /verify/verify/yosupo/data-structure/convex/li-chao-tree/segment_add_get_min.test.cpp.html
title: verify/yosupo/data-structure/convex/li-chao-tree/segment_add_get_min.test.cpp
---
