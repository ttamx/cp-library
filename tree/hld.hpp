#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-06-15
 * Description: Heavy-Light Decomposition.
 */

template<class G>
struct HLD{
    int n;
    G &g;
    int root,timer;
    vector<int> par,sz,dep,hv,head,tin,tout,ord;
    HLD(G &_g,int _root=0)
        : n(_g.n),g(_g),root(_root),timer(-1),par(n,root),sz(n,1),
          dep(n),hv(n,-1),head(n),tin(n),tout(n),ord(n){
        par[0]=-1;
        dfs_sz(root);
        dfs_hld(root);
    }
    void dfs_sz(int u){
        for(int v:g[u])if(v!=par[u]){
            par[v]=u;
            dep[v]=dep[u]+1;
            dfs_sz(v);
            sz[u]+=sz[v];
            if(hv[u]==-1||sz[v]>sz[hv[u]])hv[u]=v;
        }
    }
    void dfs_hld(int u){
        tin[u]=++timer;
        ord[timer]=u;
        if(hv[u]!=-1){
            head[hv[u]]=head[u];
            dfs_hld(hv[u]);
        }
        for(int v:g[u])if(v!=par[u]&&v!=hv[u]){
            head[v]=v;
            dfs_hld(v);
        }
        tout[u]=timer;
    }
    vector<pair<int,int>> get_path(int u,int v,bool vertex,bool commutative=true){
        vector<pair<int,int>> up,down;
        while(head[u]!=head[v]){
            if(dep[head[u]]>dep[head[v]]){
                up.emplace_back(tin[head[u]],tin[u]);
                u=par[head[u]];
            }else{
                down.emplace_back(tin[head[v]],tin[v]);
                v=par[head[v]];
            }
        }
        if(dep[u]>dep[v])up.emplace_back(tin[v]+1,tin[u]),u=v;
        else if(u!=v)down.emplace_back(tin[u]+1,tin[v]),v=u;
        if(vertex)up.emplace_back(tin[u],tin[u]);
        reverse(down.begin(),down.end());
        if(!commutative)for(auto &[x,y]:up)swap(x,y);
        up.insert(up.end(),down.begin(),down.end());
        return up;
    }
    int lca(int u,int v){
        while(head[u]!=head[v]){
            if(dep[head[u]]>dep[head[v]])swap(u,v);
            v=par[head[v]];
        }
        return dep[u]<dep[v]?u:v;
    }
    int dist(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
    int jump(int u,int v,int k){
        int w=lca(u,v);
        int d=dep[u]+dep[v]-2*dep[w];
        if(k>d)return -1;
        if(k>dep[u]-dep[w]){
            k=d-k;
            swap(u,v);
        }
        while(k>=dep[u]-dep[head[u]]+1){
            k-=dep[u]-dep[head[u]]+1;
            u=par[head[u]];
        }
        return ord[tin[u]-k];
    }
    bool is_ancestor(int u,int v){
        return tin[u]<=tin[v]&&tout[v]<=tout[u];
    }
};

