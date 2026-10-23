---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp
    title: verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/convex/line-container.hpp\"\n\ntemplate<class\
    \ T>\nstruct LineContainerLine{\n    mutable T m,c,p;\n    LineContainerLine(T\
    \ _m,T _c,T _p=0):m(_m),c(_c),p(_p){}\n    bool operator<(const LineContainerLine\
    \ &o)const{return m<o.m;}\n    bool operator<(T x)const{return p<x;}\n    inline\
    \ T eval(T x)const{return m*x+c;}\n};\n\ntemplate<class T,bool IS_MIN>\nstruct\
    \ LineContainer:multiset<LineContainerLine<T>,less<>>{\n    using Line = LineContainerLine<T>;\n\
    \    using base = multiset<Line,less<>>;\n    using iterator = typename base::iterator;\n\
    \    static constexpr T INF=numeric_limits<T>::max();\n    static T div(T a,T\
    \ b){\n        if constexpr(is_integral_v<T>)return a/b-((a^b)<0&&a%b);\n    \
    \    else return a/b;\n    }\n    bool isect(iterator x,iterator y){\n       \
    \ if(y==this->end())return x->p=INF,false;\n        if(x->m==y->m)x->p=x->c>y->c?INF:-INF;\n\
    \        else x->p=div(y->c-x->c,x->m-y->m);\n        return x->p>=y->p;\n   \
    \ }\n    void insert(T m,T c){\n        if constexpr(IS_MIN)m=-m,c=-c;\n     \
    \   auto z=base::insert(Line(m,c)),y=z++,x=y;\n        while(isect(y,z))z=this->erase(z);\n\
    \        if(x!=this->begin()&&isect(--x,y))isect(x,y=this->erase(y));\n      \
    \  while((y=x)!=this->begin()&&(--x)->p>=y->p)isect(x,this->erase(y));\n    }\n\
    \    T query(T x){\n        if(this->empty())return IS_MIN?INF:-INF;\n       \
    \ T res=this->lower_bound(x)->eval(x);\n        return IS_MIN?-res:res;\n    }\n\
    };\n"
  code: "#pragma once\n\ntemplate<class T>\nstruct LineContainerLine{\n    mutable\
    \ T m,c,p;\n    LineContainerLine(T _m,T _c,T _p=0):m(_m),c(_c),p(_p){}\n    bool\
    \ operator<(const LineContainerLine &o)const{return m<o.m;}\n    bool operator<(T\
    \ x)const{return p<x;}\n    inline T eval(T x)const{return m*x+c;}\n};\n\ntemplate<class\
    \ T,bool IS_MIN>\nstruct LineContainer:multiset<LineContainerLine<T>,less<>>{\n\
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
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/convex/line-container.hpp
  requiredBy: []
  timestamp: '2026-10-24 00:09:54+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/convex/line-container/line_add_get_min.test.cpp
documentation_of: data-structure/convex/line-container.hpp
layout: document
redirect_from:
- /library/data-structure/convex/line-container.hpp
- /library/data-structure/convex/line-container.hpp.html
title: data-structure/convex/line-container.hpp
---
