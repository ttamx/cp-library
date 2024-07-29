#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "template.hpp"
#include "data-structure/dsu.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    DSU dsu(n);
    while(q--){
        int t,u,v;
        cin >> t >> u >> v;
        if(t==0)dsu.merge(u,v);
        else cout << dsu.same(u,v) << "\n";
    }
}