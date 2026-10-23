#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "template.hpp"
#include "graph/graph-base.hpp"
#include "tree/hld.hpp"
#include "data-structure/fenwick-tree.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x:a)cin >> x;
    Graph g(n);
    for(int i=1;i<n;i++){
        int p;
        cin >> p;
        g.add_edge(i,p);
    }
    HLD hld=g;
    auto b=a;
    for(int i=0;i<n;i++)a[hld.tin[i]]=b[i];
    Fenwick<ll> f(a);
    while(q--){
        int op;
        cin >> op;
        if(op==0){
            int p,x;
            cin >> p >> x;
            f.update(hld.tin[p],x);
        }else{
            int u;
            cin >> u;
            cout << f.query(hld.tin[u],hld.tout[u]) << "\n";
        }
    }
}