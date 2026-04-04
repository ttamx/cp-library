#pragma once

/**
 * Author: Teetat T.
 * Description: Lagrange interpolation. Given f(0)...f(n) return a polynomial with degree n.
 * Time: $O(N)$
 */

template<class mint>
mint lagrange_interpolate(vector<mint> &f,mint c){
    int n=f.size();
    if(c.val()<n)return f[c.val()];
    vector<mint> l(n+1),r(n+1);
    l[0]=r[n]=1;
    for(int i=0;i<n;i++)l[i+1]=l[i]*(c-i);
    for(int i=n-1;i>=0;i--)r[i]=r[i+1]*(c-i);
    mint ans=0;
    for(int i=0;i<n;i++){
        mint cur=f[i]*comb.ifac(i)*comb.ifac(n-i-1);
        if((n-i-1)&1)cur*=-1;
        ans+=cur*l[i]*r[i+1];
    }
    return ans;
}
