#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "template.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"
#include "data-structure/link-cut-tree/lazy-link-cut-tree.hpp"
#include "group/monoid-action/add-count-affine.hpp"

using mint = mint998;
using Monoid = AddCountMonoid<mint>;
using Action = AddCountAffineAction<mint>;
using T = Monoid::value_type;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    using LCT = LazyLinkCutTree<Action>;
    using Ptr = LCT::Ptr;
    using Node = LCT::Node;
    LCT lct;
    vector<Ptr> ptr(n);
    for(int i=0;i<n;i++){
        mint x;
        cin >> x;
        ptr[i] = new Node(Monoid::make(x));
    }
    for(int i=1;i<n;i++){
        lct.link(ptr[i-1],ptr[i]);
    }
    while(q--){
        int op;
        cin >> op;
        if(op){
            int l,r;
            cin >> l >> r;
            cout << lct.fold(ptr[l],ptr[r-1]).first << "\n";
        }else{
            int l,r,b,c;
            cin >> l >> r >> b >> c;
            lct.apply(ptr[l],ptr[r-1],T(b,c));
        }
    }
}