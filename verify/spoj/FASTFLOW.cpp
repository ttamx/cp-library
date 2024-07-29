#include "template.hpp"
#include "flow/dinic.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    Dinic<ll,false> mf(n,0,n-1);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        u--,v--;
        mf.add_edge(u,v,c);
    }
    cout << mf.flow();
}