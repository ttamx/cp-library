#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "template.hpp"
#include "data-structure/fast-set.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    string t;
    cin >> t;
    FastSet fs(n);
    for(int i=0;i<n;i++)if(t[i]=='1')fs.insert(i);
    while(q--){
        int op,k;
        cin >> op >> k;
        if(op==0){
            fs.insert(k);
        }else if(op==1){
            fs.erase(k);
        }else if(op==2){
            cout << fs.count(k) << "\n";
        }else if(op==3){
            int x=fs.next(k);
            if(x==n)x=-1;
            cout << x << "\n";
        }else{
            cout << fs.prev(k) << "\n";
        }
    }
}