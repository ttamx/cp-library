#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
#include "template.hpp"
#include "data-structure/bbst/treap.hpp"
#include "group/monoid/add.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<ll> a(n);
    for(auto &x:a)cin >> x;
    Treap<AddMonoid<ll>> s(n);
    int root=s.build(a);
    while(q--){
        int op,l,r;
        cin >> op >> l >> r;
        if(op)cout << s.query(root,l,r-1) << "\n";
        else s.reverse(root,l,r-1);
    }
}
