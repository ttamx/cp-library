#pragma once

/**
 * Author: Teetat T.
 * Date: 2026-04-15
 * Description: modular arithmetic operations
 */

template<int mod,int root=0>
struct ModInt{
    using mint = ModInt;
    
	static_assert(mod>0,"mod must be positive");

    int x;

    constexpr ModInt():x(0){}
    constexpr ModInt(ll x):x((x%=mod)<0?x+mod:x){}
    constexpr explicit operator int()const{return x;}
    constexpr static int get_mod(){return mod;}
    constexpr static mint get_root(){return mint(root);}
    
    constexpr mint operator-()const{
        mint res;
        res.x=x?mod-x:0;
        return res;
    }
    constexpr mint operator+()const{return *this;}

    constexpr mint inv()const{
        int a=x,b=mod,u=1,v=0,q=0;
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
        if((x+=o.x)>=mod)x-=mod;
        return *this;
    }
    constexpr mint &operator-=(const mint &o){
        if((x-=o.x)<0)x+=mod;
        return *this;
    }
    constexpr mint &operator*=(const mint &o){
        x=(ll(x)*o.x)%mod;
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
using mint998 = ModInt<998244353,3>;
using mint107 = ModInt<1000000007>;