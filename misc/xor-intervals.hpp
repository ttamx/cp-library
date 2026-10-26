#pragma once

/**
 * Author: Teetat T.
 * Date: 2026-10-26
 * Source: https://qoj.ac/contest/4538/problem/22840
 * Description: Returns $\{x \oplus y \mid l_1 \le x < r_1,\ l_2 \le y < r_2\}$
 * as a sorted list of disjoint, merged half-open intervals $[a, b)$. The output
 * has $O(\log V)$ intervals, at most $8$ per bit. Requires $r_1, r_2 \le 2^{63}$.
 * Time: O(\log V)
 */

auto xor_intervals(u64 l1,u64 r1,u64 l2,u64 r2){
    using VP = vector<pair<u64,u64>>;
    VP res;
    if(l1>=r1||l2>=r2)return res;
    auto in=[](u64 x,u64 s,u64 l,u64 r){return l<=x&&x+s<=r;};
    auto ov=[](u64 x,u64 s,u64 l,u64 r){return x<r&&l<x+s;};
    auto rec=[&](auto &self,u64 s,u64 z,const VP &a)->void {
        if(a.empty())return;
        for(auto [x,y]:a)if(in(x,s,l1,r1)||in(y,s,l2,r2)){
            if(!res.empty()&&res.back().second==z)
                res.back().second=z+s;
            else res.emplace_back(z,z+s);
            return;
        }
        s>>=1;
        VP b[2];
        for(auto [x,y]:a)for(u64 u:{x,x|s})if(ov(u,s,l1,r1))
            for(u64 v:{y,y|s})if(ov(v,s,l2,r2))
                b[((u^v)&s)!=0].emplace_back(u,v);
        self(self,s,z,b[0]);
        self(self,s,z|s,b[1]);
    };
    rec(rec,1ULL<<63,0,{{0,0}});
    return res;
}
