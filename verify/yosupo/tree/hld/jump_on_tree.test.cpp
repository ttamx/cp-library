#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "template.hpp"
#include "graph/graph-base.hpp"
#include "tree/hld.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    Graph g=read_tree(n,0);
    HLD hld(g);
    while(q--){
        int u,v,k;
        cin >> u >> v >> k;
        cout << hld.jump(u,v,k) << '\n';
    }
}