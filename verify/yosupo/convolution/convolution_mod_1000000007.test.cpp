#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "template.hpp"
#include "polynomial/fft.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),b(m);
    for(auto &x:a)cin >> x;
    for(auto &x:b)cin >> x;
    auto c=FFT<ll,MOD2>()(a,b);
    for(auto x:c)cout << x << " ";
    cout << "\n";
}