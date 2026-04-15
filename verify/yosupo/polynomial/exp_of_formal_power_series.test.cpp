#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "template.hpp"
#include "modular-arithmetic/modint.hpp"
#include "polynomial/formal-power-series.hpp"


using mint = mint998;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    FPS a(n);
    for(auto &x:a)cin >> x;
    a=a.exp();
    for(auto x:a)cout << x << " ";
    cout << "\n";
}