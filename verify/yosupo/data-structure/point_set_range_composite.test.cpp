#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "template.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"
#include "data-structure/segment-tree/segment-tree.hpp"
#include "group/monoid/affine.hpp"

using mint = mint998;
using Monoid = AffineMonoid<mint>;
using T = Monoid::value_type;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<T> a(n);
    for(auto &[x,y]:a)cin >> x >> y;
    SegmentTree<Monoid> s(a);
    while(q--){
        int op;
        cin >> op;
        if(op){
            int l,r,x;
            cin >> l >> r >> x;
            cout << Monoid::eval(s.query(l,r-1),x) << "\n";
        }else{
            int p,a,b;
            cin >> p >> a >> b;
            s.modify(p,T(a,b));
        }
    }
}