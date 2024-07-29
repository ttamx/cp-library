#define PROBLEM "https://atcoder.jp/contests/abc347/tasks/abc347_g"
#include "template.hpp"
#include "flow/k-ary-optimization.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector a(n,vector<int>(n));
    for(auto &v:a)for(auto &x:v)cin >> x,x--;
    K_aryOptimization<ll,true> s(n*n,5);
    auto enc=[&](int i,int j){return i*n+j;};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=-1){
                vector<ll> c(5,INF);
                c[a[i][j]]=0;
                s.add1(enc(i,j),c);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int u=enc(i,j);
            auto work=[&](int x,int y){
                if(x<0||x>=n||y<0||y>=n)return;
                int v=enc(x,y);
                vector c(5,vector<ll>(5));
                for(int x1=0;x1<5;x1++){
                    for(int x2=0;x2<5;x2++){
                        c[x1][x2]=(x1-x2)*(x1-x2);
                    }
                }
                s.add2(u,v,c);
            };
            work(i,j+1);
            work(i+1,j);
        }
    }
    auto ans=s.solve().second;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[enc(i,j)]+1 << " \n"[j==n-1];
        }
    }
}