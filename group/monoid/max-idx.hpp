#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-07-21
 * Description: Max Index Monoid class.
 */

template<class T,class IDX=int,bool tie_is_left=true>
struct MaxIdxMonoid{
    using P = pair<T,IDX>;
    using value_type = P;
    static constexpr P op(const P &x,const P &y){
        if(x.first>y.first)return x;
        if(x.first<y.first)return y;
        return tie_is_left?x:y;
    }
    static constexpr P unit(){return P(numeric_limits<T>::min(),IDX(-1));}
};

