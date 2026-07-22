#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include "template.hpp"
#include "flow/general-weighted-matching.hpp"

GeneralWeightedMatching<1000,i128> gwm;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    gwm.init(2*n);
    i128 X=1e12;
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            ll w;
            cin >> w;
            gwm.add_edge(u,n+v,X-i128(w));
        }
    }
    i128 ans=gwm.solve().first;
    cout << (ll)(X*n-ans) << "\n";
    for(int i=1;i<=n;i++){
        cout << gwm.match[i]-n-1 << " \n"[i==n];
    }
}
