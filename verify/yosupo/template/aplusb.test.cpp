#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "template.hpp"

void test_macros(){
    vector<int> a{3,1,4,1,5};
    assert(SZ(a)==5);
    assert(FIND(a,4)==2&&FIND(a,9)==SZ(a));
    assert(COUNT(a,1)==2&&COUNT(a,7)==0);
    assert(MIN(a)==1&&MAX(a)==5);
    SORT(a);
    assert(a==vector<int>({1,1,3,4,5}));
    UNI(a);
    assert(a==vector<int>({1,3,4,5}));
    assert(LB(a,3)==1&&UB(a,3)==2&&LB(a,6)==4);
    RSORT(a);
    assert(a==vector<int>({5,4,3,1}));
    REV(a);
    assert(a==vector<int>({1,3,4,5}));
}

void test_chmin_chmax(){
    ll x=5;
    assert(chmin(x,3)&&x==3);
    assert(!chmin(x,4)&&x==3);
    assert(chmax(x,7)&&x==7);
    assert(!chmax(x,7)&&x==7);
}

void test_floor_ceil(){
    for(ll a=-50;a<=50;a++){
        for(ll b=-7;b<=7;b++){
            if(b==0)continue;
            assert(floor(a,b)==(ll)std::floor((db)a/b));
            assert(ceil(a,b)==(ll)std::ceil((db)a/b));
        }
    }
}

void test_bits(){
    assert(popcnt(0)==0&&popcnt(13)==3&&popcnt((1LL<<62)|1)==2);
    assert(topbit(0)==-1&&topbit(1)==0&&topbit(13)==3&&topbit(1LL<<62)==62);
    assert(lowbit(0)==-1&&lowbit(1)==0&&lowbit(12)==2&&lowbit(1LL<<62)==62);
}

void test_sum_argsort(){
    vector<int> a(3,2000000000);
    assert(SUM<ll>(a)==6000000000LL);
    vector<int> b{30,10,20,10};
    assert(argsort(b)==vector<int>({1,3,2,0}));
}

void test_vec(){
    auto a=VEC<pair<int,int>>[2][3][4]();
    static_assert(is_same_v<decltype(a),vector<vector<vector<pair<int,int>>>>>);
    assert(SZ(a)==2&&SZ(a[0])==3&&SZ(a[0][0])==4&&a[1][2][3]==pair(0,0));
    auto b=VEC<ll>[2][3](LINF);
    assert(b[1][2]==LINF);
}

int main(){
    test_macros();
    test_chmin_chmax();
    test_floor_ceil();
    test_bits();
    test_sum_argsort();
    test_vec();
    ll a,b;
    cin >> a >> b;
    cout << a+b << "\n";
}
