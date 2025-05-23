#pragma once
#include "group/monoid/add.hpp"
#include "group/monoid/max-idx.hpp"

/**
 * Author: Teetat T.
 * Date: 2024-04-14
 * Description: Add to Max Action class.
 */

template<class T,class IDX=int,bool tie_is_left=true>
struct MaxAddIdxAction{
    using InfoMonoid = MaxIdxMonoid<T,IDX,tie_is_left>;
    using TagMonoid = AddMonoid<T>;
    using Info = typename InfoMonoid::value_type;
    using Tag = typename TagMonoid::value_type;
    static constexpr Info op(const Info &a,const Tag &b){
        return (a==InfoMonoid::unit()?a:Info(a.first+b,a.second));
    }
};

