#define PROBLEM "https://atcoder.jp/contests/abc193/tasks/abc193_f"
#include "template.hpp"
#include "flow/binary-optimization.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> a(n);
    for(auto &x:a)cin >> x;
    BinaryOptimization<ll,false> b(n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%2){
                if(a[i][j]=='W')b.add1(i*n+j,0,-INF);
                if(a[i][j]=='B')b.add1(i*n+j,-INF,0);
            }else{
                if(a[i][j]=='W')b.add1(i*n+j,-INF,0);
                if(a[i][j]=='B')b.add1(i*n+j,0,-INF);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>0){
                b.add2((i-1)*n+j,i*n+j,1,0,0,1);
            }
            if(j>0){
                b.add2(i*n+j-1,i*n+j,1,0,0,1);
            }
        }
    }
    cout << b.solve();
}