#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "template.hpp"
#include "data-structure/persistent-queue.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    PersistentQueue<int> q;
    for(int i=0;i<n;i++){
        int op,t;
        cin >> op >> t;
        if(op==0){
            int x;
            cin >> x;
            q.push(t,x);
        }else{
            cout << q.front(t) << "\n";
            q.pop(t);
        }
    }
}