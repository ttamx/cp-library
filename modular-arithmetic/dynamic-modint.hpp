#pragma once

/**
 * Author: Teetat T.
 * Date: 2026-04-15
 * Description: modular arithmetic operations
 */

struct Barrett{
    u32 _m;
    u64 im;

    explicit Barrett(u32 m):_m(m),im((u64)(-1)/m+1){}

    u32 umod()const{return _m;}
    u32 mul(u32 a,u32 b)const{
        u64 z=a;
        z*=b;
        u64 x=(u64)(((unsigned __int128)(z)*im)>>64);
        u64 y=x*_m;
        return (u32)(z-y+(z<y?_m:0));
    }
};

template<int id>
struct DynamicModInt{
    using mint = DynamicModInt;

    u32 x;
    static Barrett bt;

    constexpr DynamicModInt():x(0){}
    constexpr DynamicModInt(ll x):x((x%=get_mod())<0?x+get_mod():x){}
    constexpr explicit operator int()const{return (int)x;}
    constexpr static u32 umod(){return bt.umod();}
    constexpr static int get_mod(){return (int)bt.umod();}
    static void set_mod(u32 m){
        assert(m>=1);
        bt=Barrett(m);
    }
    
    constexpr mint operator-()const{
        mint res;
        res.val=x?umod()-x:0;
        return res;
    }
    constexpr mint operator+()const{return *this;}

    constexpr mint inv()const{
        int a=x,b=get_mod(),u=1,v=0,q=0;
        while(b>0){
            q=a/b;
            swap(a-=q*b,b);
            swap(u-=q*v,v);
        }
        return mint(u);
    }
    constexpr mint pow(ll n)const{
        mint res=1,a=*this;
        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;
        return res;
    }
    constexpr mint &operator+=(const mint &o){
        if((x+=o.x)>=umod())x-=umod();
        return *this;
    }
    constexpr mint &operator-=(const mint &o){
        if((x-=o.x)>=umod())x+=umod();
        return *this;
    }
    constexpr mint &operator*=(const mint &o){
        x=bt.mul(x,o.x);
        return *this;
    }
    constexpr mint &operator/=(const mint &o){
        return *this*=o.inv();
    }

    constexpr mint operator+(const mint &o)const{return mint(*this)+=o;}
    constexpr mint operator-(const mint &o)const{return mint(*this)-=o;}
    constexpr mint operator*(const mint &o)const{return mint(*this)*=o;}
    constexpr mint operator/(const mint &o)const{return mint(*this)/=o;}

    constexpr mint &operator++(){return *this+=mint(1);}
    constexpr mint &operator--(){return *this-=mint(1);}
    constexpr mint operator++(int){mint res=*this;*this+=mint(1);return res;}
    constexpr mint operator--(int){mint res=*this;*this-=mint(1);return res;}
    
    constexpr bool operator==(const mint &o)const{return x==o.x;}
    constexpr bool operator!=(const mint &o)const{return x!=o.x;}
    constexpr bool operator<(const mint &o)const{return x<o.x;}
    
    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return is;}
    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}
};
template<int id>
Barrett DynamicModInt<id>::bt=Barrett(998244353);
using dmint = DynamicModInt<0>;