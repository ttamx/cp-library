#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "template.hpp"
#include "data-structure/binary-trie.hpp"

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    set<int> s;
    BinaryTrie<30> trie;
    while(q--){
        int t,x;
        cin >> t >> x;
        if(t==0){
            if(s.insert(x).second)trie.insert(x);
        }else if(t==1){
            auto it=s.find(x);
            if(it!=s.end()){
                s.erase(it);
                trie.erase(x);
            }
        }else{
            cout << trie.min(x) << "\n";
        }
    }
}