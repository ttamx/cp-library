#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"
#include "template.hpp"
#include "convolution/max-plus-convolution.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(auto &x:a){
        cin >> x;
        x*=-1;
    }
    for(auto &x:b){
        cin >> x;
        x*=-1;
    }
    auto c=max_plus_convolution_arbitary_convex(b,a);
    for(auto x:c){
        cout << -x << " ";
    }
}