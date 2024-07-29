#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-03-17
 * Description: modular arithmetic operations
 */

template<int64_t M,int64_t root=0>
struct ModInt64{
    using mint = ModInt64;
    using i64 = int64_t;
    i64 x;
    constexpr ModInt64():x(0){}
    constexpr ModInt64(i64 x):x(norm(x%get_mod())){}
    static i64 Mod;
    static constexpr i64 get_mod(){return M>0?M:Mod;}
    static constexpr void set_mod(i64 Mod_){Mod=Mod_;}
    static constexpr mint get_root(){return mint(root);}
    constexpr i64 norm(i64 x)const{if(x<0)x+=get_mod();if(x>=get_mod())x-=get_mod();return x;}
    explicit constexpr operator i64()const{return x;}
    constexpr mint operator-()const{return mint()-mint(*this);};
    constexpr mint operator+()const{return mint(*this);};
    constexpr mint inv()const{
        i64 a=x,b=get_mod(),u=1,v=0,q=0;
        while(b>0){
            q=a/b;
            a-=q*b;
            u-=q*v;
            swap(a,b);
            swap(u,v);
        }
        return mint(u);
    }
    constexpr i64 mul(i64 a,i64 b)const{
        i64 mod=get_mod();
        i64 res=(a*b-i64(1.l*a*b/mod)*mod)%mod;
        if(res<0)res+=mod;
        return res;
    }
    constexpr mint &operator+=(const mint &rhs){x=norm(x+rhs.x);return *this;}
    constexpr mint &operator-=(const mint &rhs){x=norm(x-rhs.x);return *this;}
    constexpr mint &operator*=(const mint &rhs){x=mul(x,rhs.x);return *this;}
    constexpr mint &operator/=(const mint &rhs){x=mul(x,rhs.inv().x);return *this;}
    constexpr mint &operator++(){return *this+=1;}
    constexpr mint &operator--(){return *this-=1;}
    constexpr mint operator++(int){mint res=*this;*this+=1;return res;}
    constexpr mint operator--(int){mint res=*this;*this-=1;return res;}
    friend constexpr mint operator+(mint lhs,const mint &rhs){return lhs+=rhs;}
    friend constexpr mint operator-(mint lhs,const mint &rhs){return lhs-=rhs;}
    friend constexpr mint operator*(mint lhs,const mint &rhs){return lhs*=rhs;}
    friend constexpr mint operator/(mint lhs,const mint &rhs){return lhs/=rhs;}
    friend istream &operator>>(istream &is,mint &o){i64 x{};is>>x;o=mint(x);return is;}
    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}
    friend constexpr bool operator==(const mint &lhs,const mint &rhs){return lhs.x==rhs.x;}
    friend constexpr bool operator!=(const mint &lhs,const mint &rhs){return lhs.x!=rhs.x;}
    friend constexpr bool operator<(const mint &lhs,const mint &rhs){return lhs.x<rhs.x;} // for std::map
};
using mint64 = ModInt64<0>;
template<>
int64_t mint64::Mod=int64_t(1e18)+9;

