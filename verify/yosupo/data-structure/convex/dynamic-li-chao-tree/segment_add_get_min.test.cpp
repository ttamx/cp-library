#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "template.hpp"
#include "data-structure/convex/dynamic-li-chao-tree.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    const int X=1e9;
    DynamicLiChaoTree<ll> lct(-X,X);
    while(n--){
        ll l,r,a,b;
        cin >> l >> r >> a >> b;
        lct.insert_range(a,b,l,r-1);
    }
    while(q--){
        int op;
        cin >> op;
        if(op){
            ll x;
            cin >> x;
            ll res=lct.query(x);
            if(res>=lct.INF)cout << "INFINITY\n";
            else cout << res << "\n";
        }else{
            ll l,r,a,b;
            cin >> l >> r >> a >> b;
            lct.insert_range(a,b,l,r-1);
        }
    }
}