#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include "template.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"
#include "convolution/gcd-convolution.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<mint> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cin >> b[i];
    auto c=gcd_convolution(a,b);
    for(int i=1;i<=n;i++)cout << c[i] << " \n"[i==n];
}