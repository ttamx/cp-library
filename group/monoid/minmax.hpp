#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-04-14
 * Description: Min Max Monoid class.
 */

template<class T>
struct MinMaxMonoid{
    using P = pair<T,T>;
    using value_type = P;
    static constexpr P op(const P &x,const P &y){return P(min(x.first,y.first),max(x.second,y.second));}
    static constexpr P unit(){return P(numeric_limits<T>::max(),numeric_limits<T>::min());}
};

