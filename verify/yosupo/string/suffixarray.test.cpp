#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "template.hpp"
#include "string/suffix-array.hpp"

int main(){
    string s;
    cin >> s;
    SuffixArray sa(s);
    for(int i=1;i<=s.size();++i)cout << sa.sa[i] << " ";
}