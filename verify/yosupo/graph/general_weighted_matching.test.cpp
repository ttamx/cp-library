#define PROBLEM "https://judge.yosupo.jp/problem/general_weighted_matching"
#include "template.hpp"
#include "flow/general-weighted-matching.hpp"

GeneralWeightedMatching<500,ll> gwm;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    gwm.init(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u++,v++;
        gwm.add_edge(u,v,w);
    }
    auto [w,x]=gwm.solve();
    cout << x << " " << w << "\n";
    for(int i=1;i<=n;i++){
        if(gwm.match[i]>i){
            cout << i-1 << " " << gwm.match[i]-1 << "\n";
        }
    }
}