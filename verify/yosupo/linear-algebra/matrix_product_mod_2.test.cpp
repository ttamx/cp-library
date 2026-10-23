#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"
#include "template.hpp"
#include "data-structure/bitset.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    vector<BitSet> a(n,BitSet(m)),b(m,BitSet(k));
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++)if(s[j]=='1')a[i].set(j);
    }
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        for(int j=0;j<k;j++)if(s[j]=='1')b[i].set(j);
    }
    for(int i=0;i<n;i++){
        BitSet c(k);
        for(int j=a[i].find_first();j<m;j=a[i].find_next(j+1))c^=b[j];
        string s(k,'0');
        for(int j=0;j<k;j++)if(c[j])s[j]='1';
        cout << s << "\n";
    }
}
