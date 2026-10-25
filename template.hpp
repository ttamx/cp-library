#pragma once
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using db = long double;
using i128 = __int128_t;
using u32 = uint32_t;
using u64 = uint64_t;
template<class T>
using PQ = priority_queue<T,vector<T>,greater<T>>;

const int INF=INT_MAX/2;
const ll LINF=LLONG_MAX/4;
const db DINF=numeric_limits<db>::infinity();
const db EPS=1e-9;
const db PI=acos(db(-1));

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SZ(a) (int)(a.size())
#define SORT(a) sort(ALL(a))
#define RSORT(a) sort(RALL(a))
#define REV(a) reverse(ALL(a))
#define UNI(a) a.erase(unique(ALL(a)),a.end())
#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())
#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())
#define FIND(a,x) (int)(find(ALL(a),x)-a.begin())
#define COUNT(a,x) (int)count(ALL(a),x)
#define MIN(a) *min_element(ALL(a))
#define MAX(a) *max_element(ALL(a))

template<class T,class U>
bool chmin(T &a,U b){return b<a?a=b,1:0;}
template<class T,class U>
bool chmax(T &a,U b){return a<b?a=b,1:0;}

template<class T>
T floor(T a,T b){return a/b-((a^b)<0&&a%b);}
template<class T>
T ceil(T a,T b){return a/b+((a^b)>=0&&a%b);}

int popcnt(ll x){return __builtin_popcountll(x);}
int topbit(ll x){return x==0?-1:63-__builtin_clzll(x);}
int lowbit(ll x){return x==0?-1:__builtin_ctzll(x);}

template<class T,class U>
T SUM(const U &a){return accumulate(ALL(a),T{});}
template<class T>
vector<int> argsort(const vector<T> &a){
    vector<int> p(SZ(a));
    iota(ALL(p),0);
    stable_sort(ALL(p),[&](int i,int j){return a[i]<a[j];});
    return p;
}