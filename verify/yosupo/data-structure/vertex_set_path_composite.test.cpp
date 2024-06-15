#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "template.hpp"
#include "graph/graph-base.hpp"
#include "tree/hld.hpp"
#include "group/monoid/affine.hpp"
#include "group/monoid/monoid-reverse.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"
#include "data-structure/segment-tree/segment-tree.hpp"

using mint = mint998;
using Mon = AffineMonoid<mint>;
using Rev = MonoidReverse<Mon>;
using T=Mon::value_type;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<T> a(n);
    for(auto &[x,y]:a)cin >> x >> y;
    auto g=read_tree(n,0);
    HLD hld(g);
    auto b=a;
    for(int i=0;i<n;i++)a[hld.tin[i]]=b[i];
    SegmentTree<Mon> s(a);
    SegmentTree<Rev> sr(a);
    while(q--){
        int op;
        cin >> op;
        if(op==0){
            int p;
            mint x,y;
            cin >> p >> x >> y;
            s.modify(hld.tin[p],T(x,y));
            sr.modify(hld.tin[p],T(x,y));
        }else{
            int u,v;
            cin >> u >> v;
            mint x;
            cin >> x;
            for(auto [u,v]:hld.get_path(u,v,true,false)){
                if(u<=v){
                    x=Mon::eval(s.query(u,v),x);
                }else{
                    x=Mon::eval(sr.query(v,u),x);
                }
            }
            cout << x << "\n";
        }
    }
}