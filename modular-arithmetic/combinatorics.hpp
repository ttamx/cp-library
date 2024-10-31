#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-10-31
 * Description: Combinatorics.
 */

template<class mint>
struct Combinatorics{
    int n,mod;
    vector<mint> _inv,_fac,_ifac;
    Combinatorics():n(1),mod(mint::get_mod()),_inv({1,1}),_fac({1,1}),_ifac({1,1}){}
    void init(int m){
        if(n>=m)return;
        _inv.resize(m+1);
        _fac.resize(m+1);
        _ifac.resize(m+1);
        for(int i=n+1;i<=m;i++){
            _inv[i]=_inv[mod%i]*(mod-mod/i);
            _fac[i]=_fac[i-1]*i;
            _ifac[i]=_ifac[i-1]*_inv[i];
        }
        n=m;
    }
    mint inv(int x){
        init(x);
        return _inv[x];
    }
    mint fac(int x){
        init(x);
        return _fac[x];
    }
    mint ifac(int x){
        init(x);
        return _ifac[x];
    }
    mint C(int n,int r){
        if(n<r||n<0||r<0)return mint(0);
        init(n);
        return _fac[n]*_ifac[r]*_ifac[n-r];
    }
    mint P(int n,int r){
        if(n<r||n<0||r<0)return mint(0);
        init(n);
        return _fac[n]*_ifac[n-r];
    }
    mint H(int n,int r){
        if(n==0&&r==0)return mint(1);
        return C(n+r-1,n);
    }
};