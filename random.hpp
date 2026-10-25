#pragma once
#include "template.hpp"

struct SplitMix64{
    using result_type = u64;
    u64 x;
    SplitMix64(u64 seed=chrono::steady_clock::now().time_since_epoch().count()):x(seed){}
    static constexpr u64 min(){return 0;}
    static constexpr u64 max(){return numeric_limits<u64>::max();}
    u64 operator()(){
        u64 z=(x+=0x9e3779b97f4a7c15);
        z=(z^(z>>30))*0xbf58476d1ce4e5b9;
        z=(z^(z>>27))*0x94d049bb133111eb;
        return z^(z>>31);
    }
};

SplitMix64 rng;

u64 rnd(u64 n){
    return rng()%n;
}
ll rnd(ll l,ll r){
    assert(l<=r);
    return l+rng()%(r-l+1);
}
db rnd_real(db l,db r){
    return l+(r-l)*(rng()>>11)*0x1p-53;
}