#include "template.hpp"
#include "flow/dinic.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int x,y;
    cin >> x >> y;
    Dinic<ll> mf(n*m*2+1,(x*m+y)*2,n*m*2);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u=i*m+j;
            mf.add_edge(u*2,u*2+1,a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            int u=i*m+j-1,v=i*m+j;
            mf.add_edge(u*2+1,v*2,LINF);
            mf.add_edge(v*2+1,u*2,LINF);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u=(i-1)*m+j,v=i*m+j;
            mf.add_edge(u*2+1,v*2,LINF);
            mf.add_edge(v*2+1,u*2,LINF);
        }
    }
    for(int i=0;i<n;i++){
        mf.add_edge(i*m*2+1,mf.t,LINF);
        mf.add_edge((i*m+m-1)*2+1,mf.t,LINF);
    }
    for(int i=1;i<m-1;i++){
        mf.add_edge(i*2+1,mf.t,LINF);
        mf.add_edge(((n-1)*m+i)*2+1,mf.t,LINF);
    }
    cout << mf.flow();
}