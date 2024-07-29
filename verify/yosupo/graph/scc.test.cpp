#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "template.hpp"
#include "graph/graph-base.hpp"
#include "graph/strongly-connected-component.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    Graph g=read_graph<void,true>(n,m,0);
    auto [k,scc]=strongly_connected_component(g);
    vector<vector<int>> ans(k);
    for(int i=0;i<n;i++)ans[scc[i]].emplace_back(i);
    reverse(ans.begin(),ans.end());
    cout << k << "\n";
    for(auto &v:ans){
        cout << v.size();
        for(auto x:v)cout << " " << x;
        cout << "\n";
    }
}