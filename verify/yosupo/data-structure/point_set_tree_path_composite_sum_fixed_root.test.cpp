#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"
#include "template.hpp"
#include "graph/graph-base.hpp"
#include "tree/hld.hpp"
#include "tree/static-top-tree-dp.hpp"
#include "modular-arithmetic/montgomery-modint.hpp"

using mint = mint998;

int n;
vector<int> id;
vector<mint> a,b,c;

struct TreeDP{
    struct Path{
        mint a,b,cnt,ans;
        static Path unit(){
            return {1,0,0,0};
        }
    };
    struct Point{
        mint cnt,ans;
        static Point unit(){
            return {0,0};
        }
    };
    static Path compress(const Path &l,const Path &r){
        Path res;
        res.a=l.a*r.a;
        res.b=l.a*r.b+l.b;
        res.cnt=l.cnt+r.cnt;
        res.ans=l.ans+l.a*r.ans+l.b*r.cnt;
        return res;
    }
    static Point rake(const Point &l,const Point &r){
        return {l.cnt+r.cnt,l.ans+r.ans};
    }
    static Point add_edge(const Path &p){
        return {p.cnt,p.ans};
    }
    static Path add_vertex(const Point &p,int u){
        Path res{b[u],c[u],p.cnt+(u<n),p.ans+a[u]};
        res.ans=res.a*res.ans+res.b*res.cnt;
        return res;
    }
    static Path vertex(int u){
        Path res{b[u],c[u],u<n,a[u]};
        res.ans=res.a*res.ans+res.b*res.cnt;
        return res;
    }
};

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> n >> q;
    a.resize(2*n);
    b.resize(2*n-1,mint(1));
    c.resize(2*n-1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    Graph<void,false> g(2*n-1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v >> b[i+n] >> c[i+n];
        g.add_edge(u,i+n);
        g.add_edge(v,i+n);
    }
    HLD hld(g);
    StaticTopTreeDP<decltype(hld),TreeDP> dp(hld);
    while(q--){
        int op;
        cin >> op;
        if(op==0){
            int u;
            mint x;
            cin >> u >> x;
            a[u]=x;
            dp.update(u);
        }else{
            int e;
            mint x,y;
            cin >> e >> x >> y;
            e+=n;
            b[e]=x,c[e]=y;
            dp.update(e);
        }
        cout << dp.query_all().ans << "\n";
    }
}