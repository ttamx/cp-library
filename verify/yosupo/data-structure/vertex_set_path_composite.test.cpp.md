---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/segment-tree.hpp
    title: data-structure/segment-tree/segment-tree.hpp
  - icon: ':question:'
    path: graph/graph-base.hpp
    title: graph/graph-base.hpp
  - icon: ':question:'
    path: group/monoid/affine.hpp
    title: group/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/monoid-reverse.hpp
    title: group/monoid/monoid-reverse.hpp
  - icon: ':question:'
    path: modular-arithmetic/modint.hpp
    title: modular-arithmetic/modint.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tree/hld.hpp
    title: tree/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"verify/yosupo/data-structure/vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 2 \"graph/graph-base.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-15\n\
    \ * Description: Graph Base\n */\n\ntemplate<class T>\nstruct Edge{\n    int from,to,id;\n\
    \    T cost;\n    Edge(int _from,int _to,T _cost,int _id):from(_from),to(_to),cost(_cost),id(_id){}\n\
    \    operator int()const{return to;}\n};\n\ntemplate<class T=void,bool directed=false>\n\
    struct Graph{\n    static constexpr bool is_directed=directed;\n    static constexpr\
    \ bool is_weighted=!is_same<T,void>::value;\n    using cost_type = std::conditional_t<is_weighted,T,int>;\n\
    \    using edge_type = Edge<cost_type>;\n    int n,m;\n    vector<edge_type> edges;\n\
    \    vector<vector<edge_type>> g;\n    vector<int> _deg,_indeg,_outdeg;\n    Graph():n(0),m(0){}\n\
    \    Graph(int _n):n(_n),m(0),g(_n){}\n    vector<edge_type> &operator[](int u){return\
    \ g[u];}\n    void add_edge(int from,int to,cost_type cost=1,int id=-1){\n   \
    \     assert(0<=from&&from<n&&0<=to&&to<n);\n        if(id==-1)id=m;\n       \
    \ edges.emplace_back(edge_type(from,to,cost,id));\n        g[from].emplace_back(edge_type(from,to,cost,id));\n\
    \        if(!is_directed)g[to].emplace_back(edge_type(to,from,cost,id));\n   \
    \     m++;\n    }\n    void calc_deg(){\n        _deg.assign(n,0);\n        for(auto\
    \ &e:edges)_deg[e.from]++,_deg[e.to]++;\n    }\n    void calc_inout_deg(){\n \
    \       _indeg.assign(n,0);\n        _outdeg.assign(n,0);\n        for(auto &e:edges)_outdeg[e.from]++,_indeg[e.to]++;\n\
    \    }\n    const vector<int> &deg_array(){\n        if(_deg.empty())calc_deg();\n\
    \        return _deg;\n    }\n    const vector<int> &indeg_array(){\n        if(_indeg.empty())calc_inout_deg();\n\
    \        return _indeg;\n    }\n    const vector<int> &outdeg_array(){\n     \
    \   if(_outdeg.empty())calc_inout_deg();\n        return _outdeg;\n    }\n   \
    \ int deg(int u){return deg_array()[u];}\n    int indeg(int u){return indeg_array()[u];}\n\
    \    int outdeg(int u){return outdeg_array()[u];}\n    Graph reverse(){\n    \
    \    assert(is_directed);\n        Graph res(n);\n        for(auto &e:edges)res.add_edge(e.to,e.from,e.cost,e.id);\n\
    \        return res;\n    }\n};\n\ntemplate<class T=void,bool directed=false>\n\
    Graph<T,directed> read_graph(int n,int m,int offset=1){\n    using G = Graph<T,directed>;\n\
    \    G g(n);\n    for(int i=0;i<m;i++){\n        int u,v;\n        cin >> u >>\
    \ v;\n        u-=offset,v-=offset;\n        if(g.is_weighted){\n            typename\
    \ G::cost_type w;\n            cin >> w;\n            g.add_edge(u,v,w);\n   \
    \     }else{\n            g.add_edge(u,v);\n        }\n    }\n    return g;\n\
    }\ntemplate<class T=void,bool directed=false>\nGraph<T,directed> read_tree(int\
    \ n,int offset=1){\n    return read_graph<T,directed>(n,n-1,offset);\n}\n\n#line\
    \ 2 \"tree/hld.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-15\n * Description:\
    \ Heavy-Light Decomposition.\n */\n\ntemplate<class G>\nstruct HLD{\n    int n;\n\
    \    G &g;\n    int root,timer;\n    vector<int> par,sz,dep,hv,head,tin,tout,ord;\n\
    \    HLD(G &_g,int _root=0)\n        : n(_g.n),g(_g),root(_root),timer(-1),par(n,root),sz(n,1),\n\
    \          dep(n),hv(n,-1),head(n),tin(n),tout(n),ord(n){\n        par[0]=-1;\n\
    \        dfs_sz(root);\n        dfs_hld(root);\n    }\n    void dfs_sz(int u){\n\
    \        for(int v:g[u])if(v!=par[u]){\n            par[v]=u;\n            dep[v]=dep[u]+1;\n\
    \            dfs_sz(v);\n            sz[u]+=sz[v];\n            if(hv[u]==-1||sz[v]>sz[hv[u]])hv[u]=v;\n\
    \        }\n    }\n    void dfs_hld(int u){\n        tin[u]=++timer;\n       \
    \ ord[timer]=u;\n        if(hv[u]!=-1){\n            head[hv[u]]=head[u];\n  \
    \          dfs_hld(hv[u]);\n        }\n        for(int v:g[u])if(v!=par[u]&&v!=hv[u]){\n\
    \            head[v]=v;\n            dfs_hld(v);\n        }\n        tout[u]=timer;\n\
    \    }\n    vector<pair<int,int>> get_path(int u,int v,bool vertex,bool commutative=true){\n\
    \        vector<pair<int,int>> up,down;\n        while(head[u]!=head[v]){\n  \
    \          if(dep[head[u]]>dep[head[v]]){\n                up.emplace_back(tin[head[u]],tin[u]);\n\
    \                u=par[head[u]];\n            }else{\n                down.emplace_back(tin[head[v]],tin[v]);\n\
    \                v=par[head[v]];\n            }\n        }\n        if(dep[u]>dep[v])up.emplace_back(tin[v]+1,tin[u]),u=v;\n\
    \        else if(u!=v)down.emplace_back(tin[u]+1,tin[v]),v=u;\n        if(vertex)up.emplace_back(tin[u],tin[u]);\n\
    \        reverse(down.begin(),down.end());\n        if(!commutative)for(auto &[x,y]:up)swap(x,y);\n\
    \        up.insert(up.end(),down.begin(),down.end());\n        return up;\n  \
    \  }\n    int lca(int u,int v){\n        while(head[u]!=head[v]){\n          \
    \  if(dep[head[u]]>dep[head[v]])swap(u,v);\n            v=par[head[v]];\n    \
    \    }\n        return dep[u]<dep[v]?u:v;\n    }\n    int dist(int u,int v){\n\
    \        return dep[u]+dep[v]-2*dep[lca(u,v)];\n    }\n    int jump(int u,int\
    \ v,int k){\n        int w=lca(u,v);\n        int d=dep[u]+dep[v]-2*dep[w];\n\
    \        if(k>d)return -1;\n        if(k>dep[u]-dep[w]){\n            k=d-k;\n\
    \            swap(u,v);\n        }\n        while(k>=dep[u]-dep[head[u]]+1){\n\
    \            k-=dep[u]-dep[head[u]]+1;\n            u=par[head[u]];\n        }\n\
    \        return ord[tin[u]-k];\n    }\n    bool is_ancestor(int u,int v){\n  \
    \      return tin[u]<=tin[v]&&tout[v]<=tout[u];\n    }\n};\n\n#line 2 \"group/monoid/affine.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Affine Transfomation\
    \ Monoid class.\n */\n\ntemplate<class T>\nstruct AffineMonoid{\n    using P =\
    \ pair<T,T>;\n    using value_type = P;\n    static constexpr P op(const P &x,const\
    \ P &y){\n        return P(x.first*y.first,x.second*y.first+y.second);\n    }\n\
    \    static constexpr P unit(){return P(T(1),T(0));}\n    static constexpr T eval(const\
    \ P &f,const T &x){\n        return f.first*x+f.second;\n    }\n};\n\n#line 2\
    \ \"group/monoid/monoid-reverse.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-16\n\
    \ * Description: Monoid Reverse class.\n */\n\ntemplate<class Monoid>\nstruct\
    \ MonoidReverse{\n    using value_type = typename Monoid::value_type;\n    static\
    \ constexpr value_type op(const value_type &x,const value_type &y){return Monoid::op(y,x);}\n\
    \    static constexpr value_type unit(){return Monoid::unit();}\n};\n\n#line 2\
    \ \"modular-arithmetic/modint.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n\
    \ * Description: modular arithmetic operations\n */\n\ntemplate<int mod,int root=0>\n\
    struct ModInt{\n    using mint = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must\
    \ be positive\");\n\n    int x;\n\n    constexpr ModInt():x(0){}\n    constexpr\
    \ ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n    constexpr explicit operator int()const{return\
    \ x;}\n    constexpr static int get_mod(){return mod;}\n    constexpr static mint\
    \ get_root(){return mint(root);}\n    \n    constexpr mint operator-()const{\n\
    \        mint res;\n        res.x=x?mod-x:0;\n        return res;\n    }\n   \
    \ constexpr mint operator+()const{return *this;}\n\n    constexpr mint inv()const{\n\
    \        int a=x,b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n\
    \            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n        }\n       \
    \ return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n        mint res=1,a=*this;\n\
    \        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n        return res;\n    }\n    constexpr\
    \ mint &operator+=(const mint &o){\n        if((x+=o.x)>=mod)x-=mod;\n       \
    \ return *this;\n    }\n    constexpr mint &operator-=(const mint &o){\n     \
    \   if((x-=o.x)<0)x+=mod;\n        return *this;\n    }\n    constexpr mint &operator*=(const\
    \ mint &o){\n        x=(ll(x)*o.x)%mod;\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &o){\n        return *this*=o.inv();\n    }\n\n\
    \    constexpr mint operator+(const mint &o)const{return mint(*this)+=o;}\n  \
    \  constexpr mint operator-(const mint &o)const{return mint(*this)-=o;}\n    constexpr\
    \ mint operator*(const mint &o)const{return mint(*this)*=o;}\n    constexpr mint\
    \ operator/(const mint &o)const{return mint(*this)/=o;}\n\n    constexpr mint\
    \ &operator++(){return *this+=mint(1);}\n    constexpr mint &operator--(){return\
    \ *this-=mint(1);}\n    constexpr mint operator++(int){mint res=*this;*this+=mint(1);return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=mint(1);return\
    \ res;}\n    \n    constexpr bool operator==(const mint &o)const{return x==o.x;}\n\
    \    constexpr bool operator!=(const mint &o)const{return x!=o.x;}\n    constexpr\
    \ bool operator<(const mint &o)const{return x<o.x;}\n    \n    friend istream\
    \ &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return is;}\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n};\nusing mint998\
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 2 \"data-structure/segment-tree/segment-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Segment Tree\n\
    \ */\n\ntemplate<class Monoid>\nstruct SegmentTree{\n    using T = typename Monoid::value_type;\n\
    \    int n;\n    vector<T> t;\n    SegmentTree(){}\n    SegmentTree(int n,function<T(int)>\
    \ create){init(n,create);}\n    SegmentTree(int n,T v=Monoid::unit()){init(n,[&](int){return\
    \ v;});}\n    template<class U>\n    SegmentTree(const vector<U> &a){init((int)a.size(),[&](int\
    \ i){return T(a[i]);});}\n    void init(int _n,function<T(int)> create){\n   \
    \     n=_n;\n        t.assign(4<<(31-__builtin_clz(n)),Monoid::unit());\n    \
    \    function<void(int,int,int)> build=[&](int l,int r,int i){\n            if(l==r)return\
    \ void(t[i]=create(l));\n            int m=(l+r)/2;\n            build(l,m,i*2);\n\
    \            build(m+1,r,i*2+1);\n            pull(i);\n        };\n        build(0,n-1,1);\n\
    \    }\n    void pull(int i){\n        t[i]=Monoid::op(t[i*2],t[i*2+1]);\n   \
    \ }\n    void modify(int l,int r,int i,int x,const T &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[i]=v);\n        int m=(l+r)/2;\n        modify(l,m,i*2,x,v);\n\
    \        modify(m+1,r,i*2+1,x,v);\n        pull(i);\n    }\n    void modify(int\
    \ x,const T &v){\n        modify(0,n-1,1,x,v);\n    }\n    template<class U>\n\
    \    void update(int l,int r,int i,int x,const U &v){\n        if(x<l||r<x)return;\n\
    \        if(l==r)return void(t[i]=Monoid::op(t[i],v));\n        int m=(l+r)/2;\n\
    \        update(l,m,i*2,x,v);\n        update(m+1,r,i*2+1,x,v);\n        pull(i);\n\
    \    }\n    template<class U>\n    void update(int x,const U &v){\n        update(0,n-1,1,x,v);\n\
    \    }\n    T query(int l,int r,int i,int x,int y){\n        if(y<l||r<x)return\
    \ Monoid::unit();\n        if(x<=l&&r<=y)return t[i];\n        int m=(l+r)/2;\n\
    \        return Monoid::op(query(l,m,i*2,x,y),query(m+1,r,i*2+1,x,y));\n    }\n\
    \    T query(int x,int y){\n        return query(0,n-1,1,x,y);\n    }\n    template<class\
    \ F>\n    int findfirst(int l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ n;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        int res=findfirst(l,m,i*2,x,y,f);\n\
    \        if(res==n)res=findfirst(m+1,r,i*2+1,x,y,f);\n        return res;\n  \
    \  }\n    template<class F>\n    int findfirst(int x,int y,const F &f){\n    \
    \    return findfirst(0,n-1,1,x,y,f);\n    }\n    template<class F>\n    int findlast(int\
    \ l,int r,int i,int x,int y,const F &f){\n        if(y<l||r<x||!f(t[i]))return\
    \ -1;\n        if(l==r)return l;\n        int m=(l+r)/2;\n        int res=findlast(m+1,r,i*2+1,x,y,f);\n\
    \        if(res==-1)res=findlast(l,m,i*2,x,y,f);\n        return res;\n    }\n\
    \    template<class F>\n    int findlast(int x,int y,const F &f){\n        return\
    \ findlast(0,n-1,1,x,y,f);\n    }\n};\n\n#line 9 \"verify/yosupo/data-structure/vertex_set_path_composite.test.cpp\"\
    \n\nusing mint = mint998;\nusing Mon = AffineMonoid<mint>;\nusing Rev = MonoidReverse<Mon>;\n\
    using T = Mon::value_type;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    vector<T> a(n);\n    for(auto &[x,y]:a)cin\
    \ >> x >> y;\n    auto g=read_tree(n,0);\n    HLD hld(g);\n    auto b=a;\n   \
    \ for(int i=0;i<n;i++)a[hld.tin[i]]=b[i];\n    SegmentTree<Mon> s(a);\n    SegmentTree<Rev>\
    \ sr(a);\n    while(q--){\n        int op;\n        cin >> op;\n        if(op==0){\n\
    \            int p;\n            mint x,y;\n            cin >> p >> x >> y;\n\
    \            s.modify(hld.tin[p],T(x,y));\n            sr.modify(hld.tin[p],T(x,y));\n\
    \        }else{\n            int u,v;\n            cin >> u >> v;\n          \
    \  mint x;\n            cin >> x;\n            for(auto [u,v]:hld.get_path(u,v,true,false)){\n\
    \                if(u<=v){\n                    x=Mon::eval(s.query(u,v),x);\n\
    \                }else{\n                    x=Mon::eval(sr.query(v,u),x);\n \
    \               }\n            }\n            cout << x << \"\\n\";\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"template.hpp\"\n#include \"graph/graph-base.hpp\"\n#include \"tree/hld.hpp\"\
    \n#include \"group/monoid/affine.hpp\"\n#include \"group/monoid/monoid-reverse.hpp\"\
    \n#include \"modular-arithmetic/modint.hpp\"\n#include \"data-structure/segment-tree/segment-tree.hpp\"\
    \n\nusing mint = mint998;\nusing Mon = AffineMonoid<mint>;\nusing Rev = MonoidReverse<Mon>;\n\
    using T = Mon::value_type;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    vector<T> a(n);\n    for(auto &[x,y]:a)cin\
    \ >> x >> y;\n    auto g=read_tree(n,0);\n    HLD hld(g);\n    auto b=a;\n   \
    \ for(int i=0;i<n;i++)a[hld.tin[i]]=b[i];\n    SegmentTree<Mon> s(a);\n    SegmentTree<Rev>\
    \ sr(a);\n    while(q--){\n        int op;\n        cin >> op;\n        if(op==0){\n\
    \            int p;\n            mint x,y;\n            cin >> p >> x >> y;\n\
    \            s.modify(hld.tin[p],T(x,y));\n            sr.modify(hld.tin[p],T(x,y));\n\
    \        }else{\n            int u,v;\n            cin >> u >> v;\n          \
    \  mint x;\n            cin >> x;\n            for(auto [u,v]:hld.get_path(u,v,true,false)){\n\
    \                if(u<=v){\n                    x=Mon::eval(s.query(u,v),x);\n\
    \                }else{\n                    x=Mon::eval(sr.query(v,u),x);\n \
    \               }\n            }\n            cout << x << \"\\n\";\n        }\n\
    \    }\n}"
  dependsOn:
  - template.hpp
  - graph/graph-base.hpp
  - tree/hld.hpp
  - group/monoid/affine.hpp
  - group/monoid/monoid-reverse.hpp
  - modular-arithmetic/modint.hpp
  - data-structure/segment-tree/segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 21:45:25+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
- /verify/verify/yosupo/data-structure/vertex_set_path_composite.test.cpp.html
title: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
---
