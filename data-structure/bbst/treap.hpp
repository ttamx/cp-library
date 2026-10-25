#pragma once
#include "random.hpp"

template<class Monoid>
struct Treap{
    using T = typename Monoid::value_type;
    struct Node{
        int l,r,sz,prio;
        bool rev;
        T val,sum,revsum;
    };
    vector<Node> t;

    Treap(int n=0){
        t.reserve(n+1);
        t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});
    }
    int new_node(const T &v){
        t.push_back(Node{0,0,1,rng(),false,v,v,v});
        return SZ(t)-1;
    }
    int size(int x){return t[x].sz;}
    T sum(int x){return t[x].sum;}

    void pull(int x){
        Node &v=t[x];
        v.sz=t[v.l].sz+1+t[v.r].sz;
        v.sum=Monoid::op(Monoid::op(t[v.l].sum,v.val),t[v.r].sum);
        v.revsum=Monoid::op(Monoid::op(t[v.r].revsum,v.val),t[v.l].revsum);
    }
    void toggle(int x){
        if(!x)return;
        swap(t[x].l,t[x].r);
        swap(t[x].sum,t[x].revsum);
        t[x].rev^=1;
    }
    void push(int x){
        if(t[x].rev){
            toggle(t[x].l);
            toggle(t[x].r);
            t[x].rev=false;
        }
    }
    int build(const vector<T> &a){
        vector<int> st;
        for(auto &v:a){
            int x=new_node(v),last=0;
            while(!st.empty()&&t[st.back()].prio<t[x].prio){
                last=st.back();
                pull(last);
                st.pop_back();
            }
            t[x].l=last;
            if(!st.empty())t[st.back()].r=x;
            st.push_back(x);
        }
        for(int i=SZ(st)-1;i>=0;i--)pull(st[i]);
        return st.empty()?0:st[0];
    }
    int merge(int a,int b){
        if(!a||!b)return a|b;
        if(t[a].prio>t[b].prio){
            push(a);
            t[a].r=merge(t[a].r,b);
            pull(a);
            return a;
        }else{
            push(b);
            t[b].l=merge(a,t[b].l);
            pull(b);
            return b;
        }
    }
    pair<int,int> split(int x,int k){
        if(!x)return {0,0};
        push(x);
        int ls=t[t[x].l].sz;
        if(k<=ls){
            auto [a,b]=split(t[x].l,k);
            t[x].l=b;
            pull(x);
            return {a,x};
        }else{
            auto [a,b]=split(t[x].r,k-ls-1);
            t[x].r=a;
            pull(x);
            return {x,b};
        }
    }
    T query(int &x,int l,int r){
        if(l>r)return Monoid::unit();
        auto [a,b]=split(x,l);
        auto [c,d]=split(b,r-l+1);
        T res=sum(c);
        x=merge(a,merge(c,d));
        return res;
    }
    void reverse(int &x,int l,int r){
        if(l>=r)return;
        auto [a,b]=split(x,l);
        auto [c,d]=split(b,r-l+1);
        toggle(c);
        x=merge(a,merge(c,d));
    }
    T get(int &x,int k){
        auto [a,b]=split(x,k);
        auto [c,d]=split(b,1);
        T res=t[c].val;
        x=merge(a,merge(c,d));
        return res;
    }
    void set(int &x,int k,const T &v){
        auto [a,b]=split(x,k);
        auto [c,d]=split(b,1);
        t[c].val=v;
        pull(c);
        x=merge(a,merge(c,d));
    }
    void insert(int &x,int k,const T &v){
        auto [a,b]=split(x,k);
        x=merge(merge(a,new_node(v)),b);
    }
    void erase(int &x,int k){
        auto [a,b]=split(x,k);
        auto [c,d]=split(b,1);
        x=merge(a,d);
    }
};
