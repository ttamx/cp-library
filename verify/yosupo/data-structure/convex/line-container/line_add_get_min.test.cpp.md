---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/convex/line-container.hpp
    title: data-structure/convex/line-container.hpp
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
  bundledCode: "#line 1 \"verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
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
    }\n\ntemplate<class T,size_t D=0>\nstruct VecBuilder{\n    array<size_t,D> d;\n\
    \    VecBuilder<T,D+1> operator[](size_t n)const{\n        VecBuilder<T,D+1> res{};\n\
    \        for(size_t i=0;i<D;i++)res.d[i]=d[i];\n        res.d[D]=n;\n        return\
    \ res;\n    }\n    template<size_t I=0>\n    auto build(const T &x)const{\n  \
    \      if constexpr(I+1==D)return vector<T>(d[I],x);\n        else return vector<decltype(build<I+1>(x))>(d[I],build<I+1>(x));\n\
    \    }\n    auto operator()(const T &x=T())const{\n        static_assert(D>0);\n\
    \        return build(x);\n    }\n};\ntemplate<class T>\ninline constexpr VecBuilder<T>\
    \ VEC{};\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 2 \"data-structure/convex/line-container.hpp\"\n\ntemplate<class T>\nstruct\
    \ LineContainerLine{\n    mutable T m,c,p;\n    LineContainerLine(T _m,T _c,T\
    \ _p=0):m(_m),c(_c),p(_p){}\n    bool operator<(const LineContainerLine &o)const{return\
    \ m<o.m;}\n    bool operator<(T x)const{return p<x;}\n    inline T eval(T x)const{return\
    \ m*x+c;}\n};\n\ntemplate<class T,bool IS_MIN>\nstruct LineContainer:multiset<LineContainerLine<T>,less<>>{\n\
    \    using Line = LineContainerLine<T>;\n    using base = multiset<Line,less<>>;\n\
    \    using iterator = typename base::iterator;\n    static constexpr T INF=numeric_limits<T>::max();\n\
    \    static T div(T a,T b){\n        if constexpr(is_integral_v<T>)return a/b-((a^b)<0&&a%b);\n\
    \        else return a/b;\n    }\n    bool isect(iterator x,iterator y){\n   \
    \     if(y==this->end())return x->p=INF,false;\n        if(x->m==y->m)x->p=x->c>y->c?INF:-INF;\n\
    \        else x->p=div(y->c-x->c,x->m-y->m);\n        return x->p>=y->p;\n   \
    \ }\n    void insert(T m,T c){\n        if constexpr(IS_MIN)m=-m,c=-c;\n     \
    \   auto z=base::insert(Line(m,c)),y=z++,x=y;\n        while(isect(y,z))z=this->erase(z);\n\
    \        if(x!=this->begin()&&isect(--x,y))isect(x,y=this->erase(y));\n      \
    \  while((y=x)!=this->begin()&&(--x)->p>=y->p)isect(x,this->erase(y));\n    }\n\
    \    T query(T x){\n        if(this->empty())return IS_MIN?INF:-INF;\n       \
    \ T res=this->lower_bound(x)->eval(x);\n        return IS_MIN?-res:res;\n    }\n\
    };\n#line 4 \"verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    LineContainer<ll,true> cht;\n    for(int i=0;i<n;i++){\n\
    \        ll a,b;\n        cin >> a >> b;\n        cht.insert(a,b);\n    }\n  \
    \  while(q--){\n        int op;\n        cin >> op;\n        if(op){\n       \
    \     ll x;\n            cin >> x;\n            cout << cht.query(x) << \"\\n\"\
    ;\n        }else{\n            ll a,b;\n            cin >> a >> b;\n         \
    \   cht.insert(a,b);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"template.hpp\"\n#include \"data-structure/convex/line-container.hpp\"\n\n\
    int main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n   \
    \ cin >> n >> q;\n    LineContainer<ll,true> cht;\n    for(int i=0;i<n;i++){\n\
    \        ll a,b;\n        cin >> a >> b;\n        cht.insert(a,b);\n    }\n  \
    \  while(q--){\n        int op;\n        cin >> op;\n        if(op){\n       \
    \     ll x;\n            cin >> x;\n            cout << cht.query(x) << \"\\n\"\
    ;\n        }else{\n            ll a,b;\n            cin >> a >> b;\n         \
    \   cht.insert(a,b);\n        }\n    }\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/convex/line-container.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp
- /verify/verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp.html
title: verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp
---
