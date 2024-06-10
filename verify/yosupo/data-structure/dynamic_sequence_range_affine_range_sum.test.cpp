#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "template.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"
#include "data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp"
#include "group/monoid-action/add-count-affine.hpp"

using Action = AddCountAffineAction<mint>;
using Info = Action::Info;
using Tag = Action::Tag;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<Info> a(n);
    for(auto &[x,y]:a)cin >> x,y=1;
    using Tree = LazyReversibleSplayTree<Action>;
    using Node = Tree::Node;
    using Ptr = Node*;
    Tree s;
    Ptr root=s.build(a);
    while(q--){
        int op;
        cin >> op;
        if(op==0){
            int i;
            mint x;
            cin >> i >> x;
            s.insert(root,i,new Node(Info(x,1)));
        }else if(op==1){
            int i;
            cin >> i;
            s.erase(root,i);
        }else if(op==2){
            int l,r;
            cin >> l >> r;
            s.reverse(root,l,r-1);
        }else if(op==3){
            int l,r;
            mint b,c;
            cin >> l >> r >> b >> c;
            s.apply(root,l,r-1,Tag(b,c));
        }else{
            int l,r;
            cin >> l >> r;
            cout << s.query(root,l,r-1).first << "\n";
        }
    }
}