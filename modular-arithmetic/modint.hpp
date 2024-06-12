#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-03-17
 * Description: modular arithmetic operations
 */

template<int M,int root=0>
struct ModInt{
    using mint = ModInt;
    int x;
    constexpr ModInt():x(0){}
    constexpr ModInt(ll x):x(norm(x%get_mod())){}
    static int Mod;
    static constexpr int get_mod(){return M>0?M:Mod;}
    static constexpr void set_mod(int Mod_){Mod=Mod_;}
    static constexpr mint get_root(){return mint(root);}
    constexpr int norm(int x)const{if(x<0)x+=get_mod();if(x>=get_mod())x-=get_mod();return x;}
    explicit constexpr operator int()const{return x;}
    constexpr mint operator-()const{return mint()-mint(*this);};
    constexpr mint operator+()const{return mint(*this);};
    constexpr mint inv()const{
        int a=x,b=get_mod(),u=1,v=0,q=0;
        while(b>0){
            q=a/b;
            a-=q*b;
            u-=q*v;
            swap(a,b);
            swap(u,v);
        }
        return mint(u);
    }
    constexpr int mul(int a,int b)const{return 1LL*a*b%get_mod();}
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
    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return is;}
    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}
    friend constexpr bool operator==(const mint &lhs,const mint &rhs){return lhs.x==rhs.x;}
    friend constexpr bool operator!=(const mint &lhs,const mint &rhs){return lhs.x!=rhs.x;}
    friend constexpr bool operator<(const mint &lhs,const mint &rhs){return lhs.x<rhs.x;} // for std::map
};
using mint32 = ModInt<0>;
template<>
int mint32::Mod=int(1e9)+7;

