#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
#include "template.hpp"
#include "data-structure/link-cut-tree/reversible-splay-tree.hpp"
#include "group/monoid/add.hpp"

using Monoid = AddMonoid<ll>;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<ll> a(n);
    for(auto &x:a)cin >> x;
    using Tree = ReversibleSplayTree<Monoid>;
    using Ptr = Tree::Node*;
    Tree s;
    Ptr root=s.build(a);
    while(q--){
        int op;
        cin >> op;
        if(op){
            int l,r;
            cin >> l >> r;
            cout << s.query(root,l,r-1) << "\n";
        }else{
            int l,r;
            cin >> l >> r;
            s.reverse(root,l,r-1);
        }
    }
}