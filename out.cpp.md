---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"out.cpp\"\n#line 1 \"verify/yosupo/data-structure/segment_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
    \ 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing vi = vector<int>;\nusing vl\
    \ = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing pll\
    \ = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst int\
    \ MOD=998244353;\nconst int MOD2=1000000007;\nconst ll LINF=0x1fffffffffffffff;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    #line 2 \"data-structure/convex/li-chao-tree.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-06-12\n * Description: Li-Chao Tree (minimize).\n */\n\ntemplate<class\
    \ T>\nstruct LiChaoTree{\n    struct Line{\n        T m,c;\n        Line(T _m,T\
    \ _c):m(_m),c(_c){}\n        inline T eval(T x)const{return m*x+c;}\n    };\n\
    \    vector<T> xs;\n    vector<Line> t;\n    const T INF=numeric_limits<T>::max()/2;\n\
    \    LiChaoTree(){}\n    LiChaoTree(const vector<T> &x):xs(x){init(x);}\n    LiChaoTree(int\
    \ n):xs(n){\n        vector<T> x(n);\n        iota(x.begin(),x.end(),0);\n   \
    \     init(x);\n    }\n    void init(const vector<T> &x){\n        xs=x;\n   \
    \     sort(xs.begin(),xs.end());\n        xs.erase(unique(xs.begin(),xs.end()),xs.end());\n\
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
    verify/yosupo/data-structure/segment_add_get_min.test.cpp\"\n\nint main(){\n \
    \   cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin >> n >> q;\n\
    \    vector<tuple<ll,ll,ll,ll>> lines(n);\n    vector<ll> xs;\n    for(auto &[a,b,l,r]:lines){\n\
    \        cin >> l >> r >> a >> b;\n        r--;\n        xs.emplace_back(l);\n\
    \        xs.emplace_back(r);\n    }\n    vector<tuple<int,ll,ll,ll,ll>> qrs(q);\n\
    \    for(auto &[op,a,b,l,r]:qrs){\n        cin >> op;\n        if(op){\n     \
    \       cin >> a;\n            xs.emplace_back(a);\n        }else{\n         \
    \   cin >> l >> r >> a >> b;\n            r--;\n            xs.emplace_back(l);\n\
    \            xs.emplace_back(r);\n        }\n    }\n    LiChaoTree<ll> lct(xs);\n\
    \    for(auto [a,b,l,r]:lines)lct.insert_range(a,b,l,r);\n    for(auto [op,a,b,l,r]:qrs){\n\
    \        if(op){\n            ll res=lct.query(a);\n            if(res>=LINF)cout\
    \ << \"INFINITY\\n\";\n            else cout << res << \"\\n\";\n        }else{\n\
    \            lct.insert_range(a,b,l,r);\n        }\n    }\n}\n"
  code: "#line 1 \"verify/yosupo/data-structure/segment_add_get_min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line 1 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ db = long double;\nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing vd\
    \ = vector<db>;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing pdd\
    \ = pair<db,db>;\nconst int INF=0x3fffffff;\nconst int MOD=998244353;\nconst int\
    \ MOD2=1000000007;\nconst ll LINF=0x1fffffffffffffff;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n#line 2 \"data-structure/convex/li-chao-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-12\n * Description: Li-Chao Tree\
    \ (minimize).\n */\n\ntemplate<class T>\nstruct LiChaoTree{\n    struct Line{\n\
    \        T m,c;\n        Line(T _m,T _c):m(_m),c(_c){}\n        inline T eval(T\
    \ x)const{return m*x+c;}\n    };\n    vector<T> xs;\n    vector<Line> t;\n   \
    \ const T INF=numeric_limits<T>::max()/2;\n    LiChaoTree(){}\n    LiChaoTree(const\
    \ vector<T> &x):xs(x){init(x);}\n    LiChaoTree(int n):xs(n){\n        vector<T>\
    \ x(n);\n        iota(x.begin(),x.end(),0);\n        init(x);\n    }\n    void\
    \ init(const vector<T> &x){\n        xs=x;\n        sort(xs.begin(),xs.end());\n\
    \        xs.erase(unique(xs.begin(),xs.end()),xs.end());\n        t.assign(4<<(31-__builtin_clz(xs.size())),Line(0,INF));\n\
    \    }\n    void insert(int l,int r,int i,Line v){\n        int m=(l+r)/2;\n \
    \       if(v.eval(xs[m])<t[i].eval(xs[m]))swap(t[i],v);\n        if(v.eval(xs[l])<t[i].eval(xs[l]))insert(l,m,i*2,v);\n\
    \        if(v.eval(xs[r])<t[i].eval(xs[r]))insert(m+1,r,i*2+1,v);\n    }\n   \
    \ inline void insert(T m,T c){\n        insert(0,(int)xs.size()-1,1,Line(m,c));\n\
    \    }\n    void insert_range(int l,int r,int i,T x,T y,Line v){\n        if(y<xs[l]||xs[r]<x)return;\n\
    \        if(x<=xs[l]&&xs[r]<=y)return insert(l,r,i,v);\n        int m=(l+r)/2;\n\
    \        insert_range(l,m,i*2,x,y,v);\n        insert_range(m+1,r,i*2+1,x,y,v);\n\
    \    }\n    inline void insert_range(T m,T c,T x,T y){\n        insert_range(0,(int)xs.size()-1,1,x,y,Line(m,c));\n\
    \    }\n    T query(int l,int r,int i,T x){\n        if(l==r)return t[i].eval(x);\n\
    \        int m=(l+r)/2;\n        if(x<=xs[m])return min(t[i].eval(x),query(l,m,i*2,x));\n\
    \        return min(t[i].eval(x),query(m+1,r,i*2+1,x));\n    }\n    inline T query(T\
    \ x){\n        return query(0,(int)xs.size()-1,1,x);\n    }\n};\n\n#line 4 \"\
    verify/yosupo/data-structure/segment_add_get_min.test.cpp\"\n\nint main(){\n \
    \   cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin >> n >> q;\n\
    \    vector<tuple<ll,ll,ll,ll>> lines(n);\n    vector<ll> xs;\n    for(auto &[a,b,l,r]:lines){\n\
    \        cin >> l >> r >> a >> b;\n        r--;\n        xs.emplace_back(l);\n\
    \        xs.emplace_back(r);\n    }\n    vector<tuple<int,ll,ll,ll,ll>> qrs(q);\n\
    \    for(auto &[op,a,b,l,r]:qrs){\n        cin >> op;\n        if(op){\n     \
    \       cin >> a;\n            xs.emplace_back(a);\n        }else{\n         \
    \   cin >> l >> r >> a >> b;\n            r--;\n            xs.emplace_back(l);\n\
    \            xs.emplace_back(r);\n        }\n    }\n    LiChaoTree<ll> lct(xs);\n\
    \    for(auto [a,b,l,r]:lines)lct.insert_range(a,b,l,r);\n    for(auto [op,a,b,l,r]:qrs){\n\
    \        if(op){\n            ll res=lct.query(a);\n            if(res>=LINF)cout\
    \ << \"INFINITY\\n\";\n            else cout << res << \"\\n\";\n        }else{\n\
    \            lct.insert_range(a,b,l,r);\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: out.cpp
  requiredBy: []
  timestamp: '2024-06-12 17:31:48+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: out.cpp
layout: document
redirect_from:
- /library/out.cpp
- /library/out.cpp.html
title: out.cpp
---
