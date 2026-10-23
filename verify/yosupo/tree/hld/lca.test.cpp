#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "template.hpp"
#include "graph/graph-base.hpp"
#include "tree/hld.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    Graph g(n);
    for(int i=1;i<n;i++){
        int p;
        cin >> p;
        g.add_edge(i,p);
    }
    HLD hld(g);
    while(q--){
        int u,v;
        cin >> u >> v;
        cout << hld.lca(u,v) << '\n';
    }
}