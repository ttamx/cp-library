#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-11-27
 * Description: enumerate all range of x such that l <= x xor p < r.
 */

template<class F>
void enumerate_xor(ll p,ll l,ll r,const F &query){
    for(ll b=1;l<r;b<<=1){
        if(l&b)query(l^p,(l^p)+b),l+=b;
        if(r&b)r-=b,query(r^p,(r^p)+b);
        if(p&b)p^=b;
    }
}