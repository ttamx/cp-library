#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-06-12
 * Description: Dynamic Li-Chao Tree.
 */

template<class T,bool IS_MIN>
struct DynamicLiChaoTree{
    static constexpr T INF=numeric_limits<T>::max();
    struct Line{
        T m,c;
        Line(T _m,T _c):m(_m),c(_c){}
        inline T eval(T x)const{return m*x+c;}
    };
    struct Node{
        Line v;
        int l,r;
        Node(Line _v=Line(0,INF)):v(_v),l(-1),r(-1){}
    };
    ll lb,ub;
    vector<Node> t;
    DynamicLiChaoTree(ll _lb,ll _ub):lb(_lb),ub(_ub),t{Node()}{assert(lb<=ub);}
    int new_node(Line v=Line(0,INF)){
        t.emplace_back(v);
        return t.size()-1;
    }
    void insert(T l,T r,int u,Line v){
        T m=l+(r-l)/2;
        if(v.eval(m)<t[u].v.eval(m))swap(t[u].v,v);
        if(v.eval(l)<t[u].v.eval(l)){
            if(t[u].l==-1){int c=new_node(v);t[u].l=c;}
            else insert(l,m,t[u].l,v);
        }
        if(v.eval(r)<t[u].v.eval(r)){
            if(t[u].r==-1){int c=new_node(v);t[u].r=c;}
            else insert(m+1,r,t[u].r,v);
        }
    }
    inline void insert(T m,T c){
        if constexpr(!IS_MIN)m=-m,c=-c;
        insert(lb,ub,0,Line(m,c));
    }
    void insert_range(T l,T r,int u,T x,T y,Line v){
        if(y<l||r<x)return;
        if(x<=l&&r<=y)return insert(l,r,u,v);
        T m=l+(r-l)/2;
        if(x<=m){
            if(t[u].l==-1){int c=new_node();t[u].l=c;}
            insert_range(l,m,t[u].l,x,y,v);
        }
        if(m<y){
            if(t[u].r==-1){int c=new_node();t[u].r=c;}
            insert_range(m+1,r,t[u].r,x,y,v);
        }
    }
    inline void insert_range(T m,T c,T x,T y){
        if constexpr(!IS_MIN)m=-m,c=-c;
        insert_range(lb,ub,0,x,y,Line(m,c));
    }
    T query(T l,T r,int u,T x){
        if(u==-1)return INF;
        T m=l+(r-l)/2;
        if(x<=m)return min(t[u].v.eval(x),query(l,m,t[u].l,x));
        return min(t[u].v.eval(x),query(m+1,r,t[u].r,x));
    }
    inline T query(T x){
        T res=query(lb,ub,0,x);
        return IS_MIN?res:-res;
    }
};
