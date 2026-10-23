#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "template.hpp"
#include "data-structure/fenwick-tree.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x:a)cin >> x;
    Fenwick<ll> f(a);
    while(q--){
        int op;
        cin >> op;
        if(op){
            int l,r;
            cin >> l >> r;
            cout << f.query(l,r-1) << "\n";
        }else{
            int p,x;
            cin >> p >> x;
            f.update(p,x);
        }
    }
}