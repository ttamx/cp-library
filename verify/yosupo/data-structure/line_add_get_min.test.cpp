#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "template.hpp"
#include "data-structure/convex/li-chao-tree.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<pair<ll,ll>> lines(n);
    for(auto &[a,b]:lines)cin >> a >> b;
    vector<tuple<int,ll,ll>> qrs(q);
    vector<ll> xs;
    for(auto &[op,a,b]:qrs){
        cin >> op;
        if(op){
            cin >> a;
            xs.emplace_back(a);
        }else{
            cin >> a >> b;
        }
    }
    if(xs.empty()){
        exit(0);
    }
    LiChaoTree<ll> lct(xs);
    for(auto [a,b]:lines)lct.insert(a,b);
    for(auto [op,a,b]:qrs){
        if(op){
            cout << lct.query(a) << "\n";
        }else{
            lct.insert(a,b);
        }
    }
}
