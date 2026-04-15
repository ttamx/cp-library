#pragma once
#include "template.hpp"

/**
 * Author: Teetat T.
 * Date: 2026-04-16
 * Description: Fast Set
 */

struct FastSet{
    using u64 = uint64_t;

    int n,len;
    vector<u64> t;

    FastSet(){}
    FastSet(int n){build(n);}

    int size(){return n;}
    void build(int _n){
        assert(_n>=0);
        n=_n;
        len=1;
        while((len<<6)<n)len<<=6;
        len/=63;
        t.resize(len+(n+63)/64);
    }

    bool count(int i)const{
        assert(0<=i&&i<n);
        return t[len+(i>>6)]>>(i&63)&1;
    }
    void insert(int x){
        assert(0<=x&&x<n);
        int i=len+(x>>6),j=x&63;
        while(true){
            if(t[i]>>j&1ULL)return;
            t[i]|=1ULL<<j;
            if(!i)return;
            j=(--i)&63;
            i>>=6;
        }
    }
    void erase(int x){
        assert(0<=x&&x<n);
        int i=len+(x>>6),j=x&63;
        while(true){
            t[i]&=~(1ULL<<j);
            if(!i||t[i])return;
            j=(--i)&63;
            i>>=6;
        }
    }
    int next(int x){
        if(x>=n)return n;
        if(x<0)x=0;
        if(count(x))return x;
        int i=len+(x>>6),j=x&63;
        while(true){
            if(t[i]&((~1ULL)<<j)){
                j=__builtin_ctzll(t[i]&((~1ULL)<<j));
                if(i>=len)return (i-len)*64+j;
                break;
            }
            if(!i)return n;
            j=(--i)&63;
            i>>=6;
        }
        i=i*64+j+1;
        while(i<len)i=i*64+__builtin_ctzll(t[i])+1;
        return (i-len)*64+__builtin_ctzll(t[i]);
    }
    int prev(int x){
        if(x<0)return -1;
        if(x>=n)x=n-1;
        if(count(x))return x;
        int i=len+(x>>6),j=x&63;
        while(true){
            if(t[i]&((1ULL<<j)-1ULL)){
                j=63-__builtin_clzll(t[i]&((1ULL<<j)-1ULL));
                if(i>=len)return (i-len)*64+j;
                break;
            }
            if(!i)return -1;
            j=(--i)&63;
            i>>=6;
        }
        i=i*64+j+1;
        while(i<len)i=i*64+64-__builtin_clzll(t[i]);
        return (i-len)*64+63-__builtin_clzll(t[i]);
    }
};