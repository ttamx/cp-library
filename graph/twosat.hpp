#pragma once
#include "template.hpp"

/**
 * Author: Teetat T.
 * Date: 2025-02-20
 * Description: Cartesian Tree.
 */

struct TwoSAT{
    int n;
    vector<vector<int>> adj,rev;
    TwoSAT(int _n):n(_n),adj(n*2),rev(n*2){}
    void add_edge(int u,int v){
        adj[u].emplace_back(v);
        rev[v].emplace_back(u);
    }
    void add_clause(int u,bool nu,int v,bool nv){
        u=(u<<1)|nu,v=(v<<1)|nv;
        add_edge(u^1,v);
        add_edge(v^1,u);
    }
    pair<bool,vector<bool>> solve(){
        vector<bool> vis(n*2),ans(n);
        vector<int> ord,scc(n*2);
        int scc_id=0;
        function<void(int)> dfs=[&](int u){
            if(vis[u])return;
            vis[u]=true;
            for(auto v:adj[u])dfs(v);
            ord.emplace_back(u);
        };
        function<void(int)> dfs2=[&](int u){
            if(scc[u])return;
            scc[u]=scc_id;
            for(auto v:rev[u])dfs2(v);
        };
        for(int i=0;i<2*n;i++)dfs(i);
        reverse(ord.begin(),ord.end());
        for(int i:ord)if(!scc[i]){
            scc_id++;
            dfs2(i);
        }
        for(int i=0;i<n;i++){
            if(scc[i<<1]==scc[(i<<1)|1])return {false,ans};
            ans[i]=scc[i<<1]>scc[(i<<1)|1];
        }
        return {true,ans};
    }
};