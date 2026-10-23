#pragma once

template<class T>
struct LineContainerLine{
    mutable T m,c,p;
    LineContainerLine(T _m,T _c,T _p=0):m(_m),c(_c),p(_p){}
    bool operator<(const LineContainerLine &o)const{return m<o.m;}
    bool operator<(T x)const{return p<x;}
    inline T eval(T x)const{return m*x+c;}
};

template<class T,bool IS_MIN>
struct LineContainer:multiset<LineContainerLine<T>,less<>>{
    using Line = LineContainerLine<T>;
    using base = multiset<Line,less<>>;
    using iterator = typename base::iterator;
    static constexpr T INF=numeric_limits<T>::max();
    static T div(T a,T b){
        if constexpr(is_integral_v<T>)return a/b-((a^b)<0&&a%b);
        else return a/b;
    }
    bool isect(iterator x,iterator y){
        if(y==this->end())return x->p=INF,false;
        if(x->m==y->m)x->p=x->c>y->c?INF:-INF;
        else x->p=div(y->c-x->c,x->m-y->m);
        return x->p>=y->p;
    }
    void insert(T m,T c){
        if constexpr(IS_MIN)m=-m,c=-c;
        auto z=base::insert(Line(m,c)),y=z++,x=y;
        while(isect(y,z))z=this->erase(z);
        if(x!=this->begin()&&isect(--x,y))isect(x,y=this->erase(y));
        while((y=x)!=this->begin()&&(--x)->p>=y->p)isect(x,this->erase(y));
    }
    T query(T x){
        if(this->empty())return IS_MIN?INF:-INF;
        T res=this->lower_bound(x)->eval(x);
        return IS_MIN?-res:res;
    }
};
