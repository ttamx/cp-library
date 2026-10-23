#pragma once

template<class Monoid>
struct SplayTree{
    using T = typename Monoid::value_type;
    struct Node{
        int l,r,p,sz;
        bool rev;
        T val,sum,revsum;
    };
    vector<Node> t;

    SplayTree(int reserve=0){
        t.reserve(reserve+1);
        t.push_back(Node{0,0,0,0,false,Monoid::unit(),Monoid::unit(),Monoid::unit()});
    }
    int make(const T &v){
        t.push_back(Node{0,0,0,1,false,v,v,v});
        return SZ(t)-1;
    }
    int sz(int x){return t[x].sz;}
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
    void rotate(int x){
        int p=t[x].p,g=t[p].p;
        if(t[p].l==x){
            t[p].l=t[x].r;
            if(t[x].r)t[t[x].r].p=p;
            t[x].r=p;
        }else{
            t[p].r=t[x].l;
            if(t[x].l)t[t[x].l].p=p;
            t[x].l=p;
        }
        t[p].p=x;
        t[x].p=g;
        if(g)(t[g].l==p?t[g].l:t[g].r)=x;
        pull(p);
    }
    void splay(int x){
        while(int p=t[x].p){
            int g=t[p].p;
            if(g)rotate((t[g].l==p)==(t[p].l==x)?p:x);
            rotate(x);
        }
        pull(x);
    }
    int kth(int x,int k){
        assert(0<=k&&k<sz(x));
        while(true){
            push(x);
            int ls=t[t[x].l].sz;
            if(k<ls)x=t[x].l;
            else if(k==ls)break;
            else k-=ls+1,x=t[x].r;
        }
        splay(x);
        return x;
    }
    int build(const vector<T> &a){
        auto rec=[&](auto &&self,int l,int r)->int{
            if(l>r)return 0;
            int m=(l+r)/2,x=make(a[m]);
            int lc=self(self,l,m-1),rc=self(self,m+1,r);
            t[x].l=lc,t[x].r=rc;
            if(lc)t[lc].p=x;
            if(rc)t[rc].p=x;
            pull(x);
            return x;
        };
        return rec(rec,0,SZ(a)-1);
    }
    int merge(int a,int b){
        if(!a||!b)return a|b;
        a=kth(a,sz(a)-1);
        t[a].r=b;
        t[b].p=a;
        pull(a);
        return a;
    }
    pair<int,int> split(int x,int k){
        if(k<=0)return {0,x};
        if(k>=sz(x))return {x,0};
        x=kth(x,k-1);
        int y=t[x].r;
        t[x].r=0;
        t[y].p=0;
        pull(x);
        return {x,y};
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
        x=kth(x,k);
        return t[x].val;
    }
    void set(int &x,int k,const T &v){
        x=kth(x,k);
        t[x].val=v;
        pull(x);
    }
    void insert(int &x,int k,const T &v){
        auto [a,b]=split(x,k);
        x=merge(merge(a,make(v)),b);
    }
    void erase(int &x,int k){
        auto [a,b]=split(x,k);
        auto [c,d]=split(b,1);
        x=merge(a,d);
    }
};
