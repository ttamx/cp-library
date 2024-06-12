#line 1 "verify/yosupo/data-structure/segment_add_get_min.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#line 1 "template.hpp"
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using db = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<db,db>;
const int INF=0x3fffffff;
const int MOD=998244353;
const int MOD2=1000000007;
const ll LINF=0x1fffffffffffffff;
const db DINF=numeric_limits<db>::infinity();
const db EPS=1e-9;
const db PI=acos(db(-1));
#line 2 "data-structure/convex/li-chao-tree.hpp"

/**
 * Author: Teetat T.
 * Date: 2024-06-12
 * Description: Li-Chao Tree (minimize).
 */

template<class T>
struct LiChaoTree{
    struct Line{
        T m,c;
        Line(T _m,T _c):m(_m),c(_c){}
        inline T eval(T x)const{return m*x+c;}
    };
    vector<T> xs;
    vector<Line> t;
    const T INF=numeric_limits<T>::max()/2;
    LiChaoTree(){}
    LiChaoTree(const vector<T> &x):xs(x){init(x);}
    LiChaoTree(int n):xs(n){
        vector<T> x(n);
        iota(x.begin(),x.end(),0);
        init(x);
    }
    void init(const vector<T> &x){
        xs=x;
        sort(xs.begin(),xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
        t.assign(4<<(31-__builtin_clz(xs.size())),Line(0,INF));
    }
    void insert(int l,int r,int i,Line v){
        int m=(l+r)/2;
        if(v.eval(xs[m])<t[i].eval(xs[m]))swap(t[i],v);
        if(v.eval(xs[l])<t[i].eval(xs[l]))insert(l,m,i*2,v);
        if(v.eval(xs[r])<t[i].eval(xs[r]))insert(m+1,r,i*2+1,v);
    }
    inline void insert(T m,T c){
        insert(0,(int)xs.size()-1,1,Line(m,c));
    }
    void insert_range(int l,int r,int i,T x,T y,Line v){
        if(y<xs[l]||xs[r]<x)return;
        if(x<=xs[l]&&xs[r]<=y)return insert(l,r,i,v);
        int m=(l+r)/2;
        insert_range(l,m,i*2,x,y,v);
        insert_range(m+1,r,i*2+1,x,y,v);
    }
    inline void insert_range(T m,T c,T x,T y){
        insert_range(0,(int)xs.size()-1,1,x,y,Line(m,c));
    }
    T query(int l,int r,int i,T x){
        if(l==r)return t[i].eval(x);
        int m=(l+r)/2;
        if(x<=xs[m])return min(t[i].eval(x),query(l,m,i*2,x));
        return min(t[i].eval(x),query(m+1,r,i*2+1,x));
    }
    inline T query(T x){
        return query(0,(int)xs.size()-1,1,x);
    }
};

#line 4 "verify/yosupo/data-structure/segment_add_get_min.test.cpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<tuple<ll,ll,ll,ll>> lines(n);
    vector<ll> xs;
    for(auto &[a,b,l,r]:lines){
        cin >> l >> r >> a >> b;
        r--;
        xs.emplace_back(l);
        xs.emplace_back(r);
    }
    vector<tuple<int,ll,ll,ll,ll>> qrs(q);
    for(auto &[op,a,b,l,r]:qrs){
        cin >> op;
        if(op){
            cin >> a;
            xs.emplace_back(a);
        }else{
            cin >> l >> r >> a >> b;
            r--;
            xs.emplace_back(l);
            xs.emplace_back(r);
        }
    }
    LiChaoTree<ll> lct(xs);
    for(auto [a,b,l,r]:lines)lct.insert_range(a,b,l,r);
    for(auto [op,a,b,l,r]:qrs){
        if(op){
            ll res=lct.query(a);
            if(res>=LINF)cout << "INFINITY\n";
            else cout << res << "\n";
        }else{
            lct.insert_range(a,b,l,r);
        }
    }
}
