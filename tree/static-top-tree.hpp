#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-11-14
 * Description: Static Top Tree.
 */

template<class HLD>
struct StaticTopTree{
    using P = pair<int,int>;
    enum Type{Compress,Rake,AddEdge,AddVertex,Vertex};
    int n,root;
    HLD &hld;
    vector<int> lch,rch,par;
    vector<Type> type;
    StaticTopTree(HLD &_hld):hld(_hld){build();}
    void build(){
        n=hld.n;
        lch=rch=par=vector<int>(n,-1);
        type.assign(n,Compress);
        root=compress(hld.root).first;
    }
    int add(int i,int l,int r,Type t){
        if(i==-1){
            i=n++;
            lch.emplace_back(l);
            rch.emplace_back(r);
            par.emplace_back(-1);
            type.emplace_back(t);
        }else{
            lch[i]=l,rch[i]=r,type[i]=t;
        }
        if(l!=-1)par[l]=i;
        if(r!=-1)par[r]=i;
        return i;
    }
    P merge(const vector<P> &a,Type t){
        if(a.size()==1)return a[0];
        vector<P> b,c;
        int tot=0;
        for(auto [i,s]:a)tot+=s;
        for(auto [i,s]:a){
            (tot>s?b:c).emplace_back(i,s);
            tot-=2*s;
        }
        auto [i,si]=merge(b,t);
        auto [j,sj]=merge(c,t);
        return {add(-1,i,j,t),si+sj};
    }
    P compress(int i){
        vector<P> a{add_vertex(i)};
        while(hld.hv[i]!=-1)a.emplace_back(add_vertex(i=hld.hv[i]));
        return merge(a,Compress);
    }
    P rake(int i){
        vector<P> a;
        for(int j:hld.g[i])if(j!=hld.par[i]&&j!=hld.hv[i])a.emplace_back(add_edge(j));
        return a.empty()?P(-1,0):merge(a,Rake);
    }
    P add_edge(int i){
        auto [j,sj]=compress(i);
        return {add(-1,j,-1,AddEdge),sj};
    }
    P add_vertex(int i){
        auto [j,sj]=rake(i);
        return {add(i,j,-1,j==-1?Vertex:AddVertex),sj+1};
    }
};

