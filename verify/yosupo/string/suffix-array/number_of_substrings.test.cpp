#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "template.hpp"
#include "string/suffix-array.hpp"

int main(){
    string s;
    cin >> s;
    SuffixArray sa(s);
    int n=(int)s.size();
    cout << 1LL*n*(n+1)/2-accumulate(sa.lcp.begin(),sa.lcp.end(),0LL);
}