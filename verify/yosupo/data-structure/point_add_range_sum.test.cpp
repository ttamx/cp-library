#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "template.hpp"
#include "data-structure/fenwick-tree.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    Fenwick<ll> f(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        f.update(i,x);
    }
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