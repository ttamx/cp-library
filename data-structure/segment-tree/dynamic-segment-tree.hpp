#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-01-15
 * Description: Dynamic Segment Tree
 */

template<class MonoidAction>
struct DynamicSegmentTree{
    using InfoMonoid = typename MonoidAction::InfoMonoid;
    using TagMonoid = typename MonoidAction::TagMonoid;
    using Info = typename MonoidAction::Info;
    using Tag = typename MonoidAction::Tag;
    struct Node{
        Info val;
        Tag lz;
        int l,r;
        Node(Info v):val(v),lz(TagMonoid::unit()),l(-1),r(-1){}
    };
    ll lb,ub;
    vector<Node> t;
    function<Info(ll,ll)> create;
    DynamicSegmentTree(){init(0,0);}
    DynamicSegmentTree(ll n){init(0,n-1);}
    DynamicSegmentTree(ll lb,ll ub){init(lb,ub);}
    DynamicSegmentTree(ll lb,ll ub,function<Info(ll,ll)> create){init(lb,ub,create);}
    void init(ll _lb,ll _ub,function<Info(ll,ll)> _create=[](ll l,ll r){return InfoMonoid::unit();}){
        lb=_lb,ub=_ub;
        create=_create;
        t.clear();
        new_node(create(lb,ub));
    }
    int new_node(const Info &v){
        t.emplace_back(v);
        return t.size()-1;
    }
    void pull(int u){
        t[u].val=InfoMonoid::op(t[t[u].l].val,t[t[u].r].val);
    }
    void apply(int u,const Tag &v){
        t[u].val=MonoidAction::op(t[u].val,v);
        t[u].lz=TagMonoid::op(t[u].lz,v);
    }
    void push(int u,ll l,ll m,ll r){
        if(t[u].l==-1){int c=new_node(create(l,m));t[u].l=c;}
        if(t[u].r==-1){int c=new_node(create(m+1,r));t[u].r=c;}
        apply(t[u].l,t[u].lz);
        apply(t[u].r,t[u].lz);
        t[u].lz=TagMonoid::unit();
    }
    void modify(ll l,ll r,int u,ll x,const Info &v){
        if(x<l||r<x)return;
        if(l==r)return void(t[u].val=v);
        ll m=l+(r-l)/2;
        push(u,l,m,r);
        modify(l,m,t[u].l,x,v);
        modify(m+1,r,t[u].r,x,v);
        pull(u);
    }
    void modify(ll x,const Info &v){
        modify(lb,ub,0,x,v);
    }
    void update(ll l,ll r,int u,ll x,ll y,const Tag &v){
        if(y<l||r<x)return;
        if(x<=l&&r<=y)return apply(u,v);
        ll m=l+(r-l)/2;
        push(u,l,m,r);
        update(l,m,t[u].l,x,y,v);
        update(m+1,r,t[u].r,x,y,v);
        pull(u);
    }
    void update(ll x,ll y,const Tag &v){
        update(lb,ub,0,x,y,v);
    }
    Info query(ll l,ll r,int u,ll x,ll y){
        if(y<l||r<x)return InfoMonoid::unit();
        if(x<=l&&r<=y)return t[u].val;
        ll m=l+(r-l)/2;
        push(u,l,m,r);
        return InfoMonoid::op(query(l,m,t[u].l,x,y),query(m+1,r,t[u].r,x,y));
    }
    Info query(ll x,ll y){
        return query(lb,ub,0,x,y);
    }
    template<class F>
    ll findfirst(ll l,ll r,int u,ll x,ll y,const F &f){
        if(y<l||r<x||!f(t[u].val))return ub+1;
        if(l==r)return l;
        ll m=l+(r-l)/2;
        push(u,l,m,r);
        ll res=findfirst(l,m,t[u].l,x,y,f);
        if(res==ub+1)res=findfirst(m+1,r,t[u].r,x,y,f);
        return res;
    }
    template<class F>
    ll findfirst(ll x,ll y,const F &f){
        return findfirst(lb,ub,0,x,y,f);
    }
    template<class F>
    ll findlast(ll l,ll r,int u,ll x,ll y,const F &f){
        if(y<l||r<x||!f(t[u].val))return lb-1;
        if(l==r)return l;
        ll m=l+(r-l)/2;
        push(u,l,m,r);
        ll res=findlast(m+1,r,t[u].r,x,y,f);
        if(res==lb-1)res=findlast(l,m,t[u].l,x,y,f);
        return res;
    }
    template<class F>
    ll findlast(ll x,ll y,const F &f){
        return findlast(lb,ub,0,x,y,f);
    }
};
