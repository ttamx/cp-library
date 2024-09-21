#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include "template.hpp"
#include "number-theory/floor-sum.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll n,m,a,b;
        cin >> n >> m >> a >> b;
        cout << floor_sum(a,b,m,n-1) << "\n";
    }
}