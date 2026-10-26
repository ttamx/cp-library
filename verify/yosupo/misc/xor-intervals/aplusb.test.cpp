#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "template.hpp"
#include "misc/xor-intervals.hpp"

mt19937_64 gen(12345);

void check_shape(const vector<pair<u64,u64>> &res){
    for(int i=0;i<SZ(res);i++){
        assert(res[i].first<res[i].second);
        if(i>0)assert(res[i-1].second<res[i].first);
    }
}

vector<char> brute(u64 l1,u64 r1,u64 l2,u64 r2){
    vector<char> ok(128);
    for(u64 x=l1;x<r1;x++)for(u64 y=l2;y<r2;y++)ok[x^y]=1;
    return ok;
}

void test_small(){
    for(int it=0;it<5000;it++){
        u64 l1=gen()%65,r1=gen()%65,l2=gen()%65,r2=gen()%65;
        if(it%4&&l1>r1)swap(l1,r1);
        if(it%4&&l2>r2)swap(l2,r2);
        auto res=xor_intervals(l1,r1,l2,r2);
        check_shape(res);
        vector<char> got(128);
        for(auto [a,b]:res){
            assert(b<=128);
            for(u64 z=a;z<b;z++)got[z]=1;
        }
        assert(got==brute(l1,r1,l2,r2));
    }
}

// With values below 2^20 and offsets k1, k2 that are multiples of 2^20,
// (x+k1)^(y+k2) = (x^y)+(k1^k2), so every interval shifts by k1^k2.
void test_large(){
    for(int it=0;it<5000;it++){
        u64 l1=gen()%(1<<20),r1=gen()%(1<<20)+1;
        u64 l2=gen()%(1<<20),r2=gen()%(1<<20)+1;
        if(l1>r1)swap(l1,r1);
        if(l2>r2)swap(l2,r2);
        u64 k1=(gen()%(1ULL<<43))<<20,k2=(gen()%(1ULL<<43))<<20;
        auto small=xor_intervals(l1,r1,l2,r2);
        auto big=xor_intervals(l1+k1,r1+k1,l2+k2,r2+k2);
        check_shape(big);
        u64 k=k1^k2;
        assert(SZ(small)==SZ(big));
        for(int i=0;i<SZ(small);i++){
            assert(big[i].first==small[i].first+k);
            assert(big[i].second==small[i].second+k);
        }
    }
}

int main(){
    test_small();
    test_large();
    ll a,b;
    cin >> a >> b;
    cout << a+b << "\n";
}
