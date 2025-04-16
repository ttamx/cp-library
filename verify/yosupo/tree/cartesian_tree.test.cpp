#define PROBLEM https://judge.yosupo.jp/problem/cartesian_tree
#include "template.hpp"
#include "data-structure/cartesian-tree.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a)cin >> x;
    CartesianTree<int,true> ct(a);
    auto ans=ct.par;
    ans[ct.root]=ct.root;
    for(auto x:ans)cout << x << " ";
}