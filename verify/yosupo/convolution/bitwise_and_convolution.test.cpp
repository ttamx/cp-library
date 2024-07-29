#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "template.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"
#include "convolution/and-convolution.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    n=1<<n;
    vector<mint> a(n),b(n);
    for(auto &x:a)cin >> x;
    for(auto &x:b)cin >> x;
    auto c=and_convolution(a,b);
    for(auto x:c)cout << x << " ";
}