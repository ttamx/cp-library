#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "template.hpp"
#include "data-structure/convex/line-container.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    LineContainer<ll,true> cht;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        cht.insert(a,b);
    }
    while(q--){
        int op;
        cin >> op;
        if(op){
            ll x;
            cin >> x;
            cout << cht.query(x) << "\n";
        }else{
            ll a,b;
            cin >> a >> b;
            cht.insert(a,b);
        }
    }
}
