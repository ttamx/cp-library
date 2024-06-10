#pragma once
#include "group/monoid/add.hpp"
#include "group/monoid/min-count.hpp"

/**
 * Author: Teetat T.
 * Date: 2024-04-14
 * Description: Add to Min & Count Action class.
 */

template<class T>
struct MinCountAddAction{
    using InfoMonoid = MinCountMonoid<T>;
    using TagMonoid = AddMonoid<T>;
    using Info = typename InfoMonoid::value_type;
    using Tag = typename TagMonoid::value_type;
    static constexpr Info op(const Info &a,const Tag &b){
        if(a.first==InfoMonoid::unit().first)return a;
        return Info(a.first+b,a.second);
    }
};

