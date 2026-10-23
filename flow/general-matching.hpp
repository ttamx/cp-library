#pragma once

/**
 * Author: Teetat T.
 * Date: 2025-09-03
 * Description: General matching using blossom algorithm.
 * Time: O(E V \alpha(V)).
 */

template<int N>
struct GeneralMatching{

int n,m;
vector<int> adj[N+1];
int fa[N+1],link[N+1],match[N+1],vis[N+1],dep[N+1];
queue<int> q;

int find(int u){
    while(fa[u]!=u)u=fa[u]=fa[fa[u]];
    return u;
}
int get_lca(int u,int v){
    u=find(u),v=find(v);
    while(u!=v){
        if(dep[u]<dep[v])swap(u,v);
        u=find(link[match[u]]);
    }
    return u;
}
void blossom(int u,int v,int lca){
    while(find(u)!=lca){
        link[u]=v;
        v=match[u];
        if(vis[v]==0){
            vis[v]=1;
            q.emplace(v);
        }
        fa[u]=fa[v]=lca;
        u=link[v];
    }
}
bool augment(int st){
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)vis[i]=-1;
    vis[st]=1;
    dep[st]=0;
    q=queue<int>();
    q.emplace(st);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(vis[v]==-1){
                vis[v]=0;
                link[v]=u;
                dep[v]=dep[u]+1;
                if(!match[v]){
                    for(int x=v,y=u,z;y;y=link[x=z]){
                        z=match[y];
                        match[x]=y;
                        match[y]=x;
                    }
                    return 1;
                }
                vis[match[v]]=1;
                dep[match[v]]=dep[u]+2;
                q.emplace(match[v]);
            }else if(vis[v]==1&&find(u)!=find(v)){
                int lca=get_lca(u,v);
                blossom(u,v,lca);
                blossom(v,u,lca);
            }
        }
    }
    return 0;
}
int solve(){
    int ans=0;
    for(int u=1;u<=n;u++)if(!match[u]){
        for(auto v:adj[u])if(!match[v]){
            match[u]=v;
            match[v]=u;
            ans++;
            break;
        }
    }
    for(int u=1;u<=n;u++)if(!match[u])ans+=augment(u);
    return ans;
}
void init(int _n){
    n=_n;
    for(int i=1;i<=n;i++)match[i]=0;
    for(int i=1;i<=n;i++)adj[i].clear();
}
void add_edge(int u,int v){
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

};