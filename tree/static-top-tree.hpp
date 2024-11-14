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
        root=compress(hld.root).second;
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
    P compress(int i){
        vector<P> a{add_vertex(i)};
        auto work=[&](){
            auto [sj,j]=a.back();
            a.pop_back();
            auto [si,i]=a.back();
            a.back()={max(si,sj)+1,add(-1,i,j,Compress)};
        };
        while(hld.hv[i]!=-1){
            a.emplace_back(add_vertex(i=hld.hv[i]));
            while(true){
                if(a.size()>=3&&(a.end()[-3].first==a.end()[-2].first||a.end()[-3].first<=a.back().first)){
                    P tmp=a.back();
                    a.pop_back();
                    work();
                    a.emplace_back(tmp);
                }else if(a.size()>=2&&a.end()[-2].first<=a.back().first){
                    work();
                }else break;
            }
        }
        while(a.size()>=2)work();
        return a[0];
    }
    P rake(int i){
        priority_queue<P,vector<P>,greater<P>> pq;
        for(int j:hld.g[i])if(j!=hld.par[i]&&j!=hld.hv[i])pq.emplace(add_edge(j));
        while(pq.size()>=2){
            auto [si,i]=pq.top();pq.pop();
            auto [sj,j]=pq.top();pq.pop();
            pq.emplace(max(si,sj)+1,add(-1,i,j,Rake));
        }
        return pq.empty()?make_pair(0,-1):pq.top();
    }
    P add_edge(int i){
        auto [sj,j]=compress(i);
        return {sj+1,add(-1,j,-1,AddEdge)};
    }
    P add_vertex(int i){
        auto [sj,j]=rake(i);
        return {sj+1,add(i,j,-1,j==-1?Vertex:AddVertex)};
    }
};

