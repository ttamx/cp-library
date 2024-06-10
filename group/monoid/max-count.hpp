#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-04-14
 * Description: Max & Count Monoid class.
 */

template<class T>
struct MaxCountMonoid{
    using P = pair<T,int>;
    using value_type = P;
    static constexpr P op(const P &x,const P &y){
        if(x.first>y.first)return x;
        if(y.first>x.first)return y;
        return P(x.first,x.second+y.second);
    }
    static constexpr P unit(){return P(numeric_limits<T>::min(),0);}
    static constexpr P make(const T &x){return P(x,1);}
};

