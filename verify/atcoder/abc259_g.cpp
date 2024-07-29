#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_g"
#include "template.hpp"
#include "flow/binary-optimization.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector a(n,vector<ll>(m));
    vector<ll> sumh(n),sumv(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            sumh[i]+=a[i][j];
            sumv[j]+=a[i][j];
        }
    }
    BinaryOptimization<ll,false> b(n+m);
    for(int i=0;i<n;i++)b.add1(i,sumh[i],0);
    for(int i=0;i<m;i++)b.add1(i+n,0,sumv[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]<0){
                b.add2(i,j+n,0,-LINF,0,0);
            }else{
                b.add2(i,j+n,0,-a[i][j],0,0);
            }
        }
    }
    cout << b.solve();
}