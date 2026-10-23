#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "template.hpp"
#include "data-structure/convex/li-chao-tree.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<tuple<ll,ll,ll,ll>> lines(n);
    vector<ll> xs;
    for(auto &[a,b,l,r]:lines){
        cin >> l >> r >> a >> b;
        r--;
        xs.emplace_back(l);
        xs.emplace_back(r);
    }
    vector<tuple<int,ll,ll,ll,ll>> qrs(q);
    for(auto &[op,a,b,l,r]:qrs){
        cin >> op;
        if(op){
            cin >> a;
            xs.emplace_back(a);
        }else{
            cin >> l >> r >> a >> b;
            r--;
            xs.emplace_back(l);
            xs.emplace_back(r);
        }
    }
    LiChaoTree<ll> lct(xs);
    for(auto [a,b,l,r]:lines)lct.insert_range(a,b,l,r);
    for(auto [op,a,b,l,r]:qrs){
        if(op){
            ll res=lct.query(a);
            if(res>=lct.INF)cout << "INFINITY\n";
            else cout << res << "\n";
        }else{
            lct.insert_range(a,b,l,r);
        }
    }
}