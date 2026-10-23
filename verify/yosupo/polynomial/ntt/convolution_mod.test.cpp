#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "template.hpp"
#include "modular-arithmetic/modint.hpp"
#include "polynomial/ntt.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<mint> a(n),b(m);
    for(auto &x:a)cin >> x;
    for(auto &x:b)cin >> x;
    auto c=NTT<mint>()(a,b);
    for(auto x:c)cout << x << " ";
    cout << "\n";
}