#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "template.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"
#include "polynomial/formal-power-series.hpp"


using mint = mint998;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    ll m;
    cin >> n >> m;
    FPS a(n);
    for(auto &x:a)cin >> x;
    a=a.pow(m);
    for(auto x:a)cout << x << " ";
    cout << "\n";
}