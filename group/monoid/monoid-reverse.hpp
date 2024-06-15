#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-06-16
 * Description: Monoid Reverse class.
 */

template<class Monoid>
struct MonoidReverse{
    using value_type = typename Monoid::value_type;
    static constexpr value_type op(const value_type &x,const value_type &y){return Monoid::op(y,x);}
    static constexpr value_type unit(){return Monoid::unit();}
};

