#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "template.hpp"
#include "misc/enumerate-xor.hpp"

mt19937_64 gen(12345);

void test_small(){
    for(int it=0;it<5000;it++){
        ll p=gen()%128,l=gen()%129,r=gen()%129;
        if(l>r)swap(l,r);
        vector<int> cnt(256);
        enumerate_xor(p,l,r,[&](ll a,ll b){
            assert(0<=a&&a<b&&b<=256);
            for(ll x=a;x<b;x++)cnt[x]++;
        });
        for(ll x=0;x<256;x++){
            assert(cnt[x]==(l<=(x^p)&&(x^p)<r));
        }
    }
}

void test_large(){
    for(int it=0;it<5000;it++){
        int k=1+gen()%62;
        ll mask=(1LL<<k)-1;
        ll p=gen()&mask,l=gen()&mask,r=gen()&mask;
        if(l>r)swap(l,r);
        vector<pair<ll,ll>> img;
        int calls=0;
        enumerate_xor(p,l,r,[&](ll a,ll b){
            ll len=b-a;
            assert(len>0&&(len&(len-1))==0&&a%len==0);
            ll lo=(a^p)&~(len-1);
            img.emplace_back(lo,lo+len);
            calls++;
        });
        assert(calls<=2*64);
        sort(img.begin(),img.end());
        ll cur=l;
        for(auto [lo,hi]:img){
            assert(lo==cur);
            cur=hi;
        }
        assert(cur==r);
    }
}

int main(){
    test_small();
    test_large();
    ll a,b;
    cin >> a >> b;
    cout << a+b << "\n";
}
