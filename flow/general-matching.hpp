#pragma once

/**
 * Author: Teetat T.
 * Date: 2025-09-03
 * Description: General matching using blossom algorithm.
 * Time: O(E \sqrt{V} log_{\max(2,1+E/V)}).
 */

struct GeneralMatching{
    int n;
    vector<vector<int>> adj;
    vector<int> match,vis,link,fa,dep;
    queue<int> q;
    GeneralMatching(int n):n(n),adj(n),match(n,-1),vis(n),link(n),fa(n),dep(n){}
    void add_edge(int u,int v){
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int fp(int u){
        while(fa[u]!=u)u=fa[u]=fa[fa[u]];
        return u;
    }
    int lca(int u,int v){
        u=fp(u),v=fp(v);
        while(u!=v){
            if(dep[u]<dep[v])swap(u,v);
            u=fp(link[match[u]]);
        }
        return u;
    }
    void blossom(int u,int v,int p){
        while(fp(u)!=p){
            link[u]=v;
            v=match[u];
            if(vis[v]==0){
                vis[v]=1;
                q.emplace(v);
            }
            fa[u]=fa[v]=p;
            u=link[v];
        }
    }
    int augment(int u){
        while(!q.empty())q.pop();
        iota(fa.begin(),fa.end(),0);
        fill(vis.begin(),vis.end(),-1);
        q.emplace(u);
        vis[u]=1;
        dep[u]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(vis[v]==-1){
                    vis[v]=0;
                    link[v]=u;
                    dep[v]=dep[u]+1;
                    if(match[v]==-1){
                        for(int x=v,y=u,z;y!=-1;x=z,y=x==-1?-1:link[x]){
                            z=match[y];
                            match[x]=y;
                            match[y]=x;
                        }
                        return 1;
                    }
                    vis[match[v]]=1;
                    dep[match[v]]=dep[u]+2;
                    q.emplace(match[v]);
                }else if(vis[v]==1&&fp(u)!=fp(v)){
                    int p=lca(u,v);
                    blossom(u,v,p);
                    blossom(v,u,p);
                }
            }
        }
        return 0;
    }
    int max_matching(){
        int res=0;
        for(int u=0;u<n;u++){
            if(match[u]!=-1)continue;
            for(auto v:adj[u]){
                if(match[v]==-1){
                    match[u]=v;
                    match[v]=u;
                    res++;
                    break;
                }
            }
        }
        for(int u=0;u<n;u++){
            if(match[u]==-1){
                res+=augment(u);
            }
        }
        return res;
    }
};