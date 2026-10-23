#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"
#include "template.hpp"
#include "flow/general-matching.hpp"

GeneralMatching<500> gm;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    gm.init(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v;
        u++,v++;
        gm.add_edge(u,v);
    }
    cout << gm.solve() << "\n";
    for(int i=1;i<=n;i++){
        if(gm.match[i]>i){
            cout << i-1 << " " << gm.match[i]-1 << "\n";
        }
    }
}