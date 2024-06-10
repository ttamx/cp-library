#pragma once
#include "group/monoid/add.hpp"
#include "group/monoid/add-count.hpp"

/**
 * Author: Teetat T.
 * Date: 2024-04-14
 * Description: Add to Add & Count Monoid class.
 */

template<class T>
struct AddCountAddAction{
    using InfoMonoid = AddCountMonoid<T>;
    using TagMonoid = AddMonoid<T>;
    using Info = typename InfoMonoid::value_type;
    using Tag = typename TagMonoid::value_type;
    static constexpr Info op(const Info &a,const Tag &b){
        return Info(a.first+a.second*b,a.second);
    }
};

