#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "template.hpp"
#include "data-structure/sparse-table.hpp"
#include "group/monoid/min.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x:a)cin >> x;
    SparseTable<MinMonoid<int>> s(a);
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << s.query(l,r-1) << "\n";
    }
}