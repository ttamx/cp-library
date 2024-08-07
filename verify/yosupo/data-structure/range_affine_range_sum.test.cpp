#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "template.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"
#include "data-structure/segment-tree/lazy-segment-tree.hpp"
#include "group/monoid-action/add-count-affine.hpp"

using mint = mint998;
using Monoid = AddCountMonoid<mint>;
using Action = AddCountAffineAction<mint>;
using T = Monoid::value_type;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<mint> a(n);
    for(auto &x:a)cin >> x;
    LazySegmentTree<Action> s(n,[&](int i){return Monoid::make(a[i]);});
    while(q--){
        int op;
        cin >> op;
        if(op){
            int l,r;
            cin >> l >> r;
            cout << s.query(l,r-1).first << "\n";
        }else{
            int l,r,b,c;
            cin >> l >> r >> b >> c;
            s.update(l,r-1,T(b,c));
        }
    }
}