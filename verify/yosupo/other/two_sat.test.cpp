#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "template.hpp"
#include "graph/twosat.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    int n,m;
    cin >> s >> s >> n >> m;
    TwoSAT sat(n);
    for(int i=0;i<m;i++){
        int a,b,x;
        cin >> a >> b >> x;
        sat.add_clause(abs(a)-1,a<0,abs(b)-1,b<0);
    }
    auto [ok,ans]=sat.solve();
    if(ok){
        cout << "s SATISFIABLE\n";
        cout << "v ";
        for(int i=0;i<n;i++)cout << (ans[i]?i+1:-(i+1)) << " ";
        cout << "0\n";

    }else{
        cout << "s UNSATISFIABLE\n";
    }
}