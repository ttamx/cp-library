---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-base.hpp
    title: graph/graph-base.hpp
  - icon: ':question:'
    path: modular-arithmetic/modint.hpp
    title: modular-arithmetic/modint.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tree/hld.hpp
    title: tree/hld.hpp
  - icon: ':heavy_check_mark:'
    path: tree/static-top-tree-rerooting-dp.hpp
    title: tree/static-top-tree-rerooting-dp.hpp
  - icon: ':heavy_check_mark:'
    path: tree/static-top-tree.hpp
    title: tree/static-top-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum
  bundledCode: "#line 1 \"verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum\"\
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
    \      return tin[u]<=tin[v]&&tout[v]<=tout[u];\n    }\n};\n\n#line 2 \"tree/static-top-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-11-14\n * Description: Static Top\
    \ Tree.\n */\n\ntemplate<class HLD>\nstruct StaticTopTree{\n    using P = pair<int,int>;\n\
    \    enum Type{Compress,Rake,AddEdge,AddVertex,Vertex};\n    int n,root;\n   \
    \ HLD &hld;\n    vector<int> lch,rch,par;\n    vector<Type> type;\n    StaticTopTree(HLD\
    \ &_hld):hld(_hld){build();}\n    void build(){\n        n=hld.n;\n        lch=rch=par=vector<int>(n,-1);\n\
    \        type.assign(n,Compress);\n        root=compress(hld.root).second;\n \
    \   }\n    int add(int i,int l,int r,Type t){\n        if(i==-1){\n          \
    \  i=n++;\n            lch.emplace_back(l);\n            rch.emplace_back(r);\n\
    \            par.emplace_back(-1);\n            type.emplace_back(t);\n      \
    \  }else{\n            lch[i]=l,rch[i]=r,type[i]=t;\n        }\n        if(l!=-1)par[l]=i;\n\
    \        if(r!=-1)par[r]=i;\n        return i;\n    }\n    P compress(int i){\n\
    \        vector<P> a{add_vertex(i)};\n        auto work=[&](){\n            auto\
    \ [sj,j]=a.back();\n            a.pop_back();\n            auto [si,i]=a.back();\n\
    \            a.back()={max(si,sj)+1,add(-1,i,j,Compress)};\n        };\n     \
    \   while(hld.hv[i]!=-1){\n            a.emplace_back(add_vertex(i=hld.hv[i]));\n\
    \            while(true){\n                if(a.size()>=3&&(a.end()[-3].first==a.end()[-2].first||a.end()[-3].first<=a.back().first)){\n\
    \                    P tmp=a.back();\n                    a.pop_back();\n    \
    \                work();\n                    a.emplace_back(tmp);\n         \
    \       }else if(a.size()>=2&&a.end()[-2].first<=a.back().first){\n          \
    \          work();\n                }else break;\n            }\n        }\n \
    \       while(a.size()>=2)work();\n        return a[0];\n    }\n    P rake(int\
    \ i){\n        priority_queue<P,vector<P>,greater<P>> pq;\n        for(int j:hld.g[i])if(j!=hld.par[i]&&j!=hld.hv[i])pq.emplace(add_edge(j));\n\
    \        while(pq.size()>=2){\n            auto [si,i]=pq.top();pq.pop();\n  \
    \          auto [sj,j]=pq.top();pq.pop();\n            pq.emplace(max(si,sj)+1,add(-1,i,j,Rake));\n\
    \        }\n        return pq.empty()?make_pair(0,-1):pq.top();\n    }\n    P\
    \ add_edge(int i){\n        auto [sj,j]=compress(i);\n        return {sj+1,add(-1,j,-1,AddEdge)};\n\
    \    }\n    P add_vertex(int i){\n        auto [sj,j]=rake(i);\n        return\
    \ {sj+1,add(i,j,-1,j==-1?Vertex:AddVertex)};\n    }\n};\n\n#line 3 \"tree/static-top-tree-rerooting-dp.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-11-14\n * Description: Static Top\
    \ Tree DP.\n */\n\n/*\nstruct TreeDP{\n    struct Path{\n        static Path unit();\n\
    \    };\n    struct Point{\n        static Point unit();\n    };\n    static Path\
    \ compress(Path l,Path r);\n    static Point rake(Point l,Point r);\n    static\
    \ Point add_edge(Path p);\n    static Path add_vertex(Point p,int u);\n    static\
    \ Path vertex(int u);\n};\n*/\n\ntemplate<class HLD,class TreeDP>\nstruct StaticTopTreeRerootingDP{\n\
    \    using Path = typename TreeDP::Path;\n    using Point = typename TreeDP::Point;\n\
    \    StaticTopTree<HLD> stt;\n    vector<Path> path,rpath;\n    vector<Point>\
    \ point;\n    StaticTopTreeRerootingDP(HLD &hld):stt(hld){\n        int n=stt.n;\n\
    \        path.resize(n);\n        point.resize(n);\n        rpath.resize(n);\n\
    \        dfs(stt.root);\n    }\n    void _update(int u){\n        if(stt.type[u]==stt.Vertex){\n\
    \            path[u]=rpath[u]=TreeDP::vertex(u);\n        }else if(stt.type[u]==stt.Compress){\n\
    \            path[u]=TreeDP::compress(path[stt.lch[u]],path[stt.rch[u]]);\n  \
    \          rpath[u]=TreeDP::compress(rpath[stt.rch[u]],rpath[stt.lch[u]]);\n \
    \       }else if(stt.type[u]==stt.Rake){\n            point[u]=TreeDP::rake(point[stt.lch[u]],point[stt.rch[u]]);\n\
    \        }else if(stt.type[u]==stt.AddEdge){\n            point[u]=TreeDP::add_edge(path[stt.lch[u]]);\n\
    \        }else{\n            path[u]=rpath[u]=TreeDP::add_vertex(point[stt.lch[u]],u);\n\
    \        }\n    }\n    void dfs(int u){\n        if(u==-1)return;\n        dfs(stt.lch[u]);\n\
    \        dfs(stt.rch[u]);\n        _update(u);\n    }\n    void update(int u){\n\
    \        for(;u!=-1;u=stt.par[u])_update(u);\n    }\n    Path query_all(){\n \
    \       return path[stt.root];\n    }\n    Path query_subtree(int u){\n      \
    \  Path res=path[u];\n        while(true){\n            int p=stt.par[u];\n  \
    \          if(p==-1||stt.type[p]!=stt.Compress)break;\n            if(stt.lch[p]==u)res=TreeDP::compress(res,path[stt.rch[p]]);\n\
    \        }\n        return res;\n    }\n    Path query_reroot(int u){\n      \
    \  auto rec=[&](auto &&rec,int u)->Point{\n            int p=stt.par[u];\n   \
    \         Path below=Path::unit(),above=Path::unit();\n            while(p!=-1&&stt.type[p]==stt.Compress){\n\
    \                int l=stt.lch[p],r=stt.rch[p];\n                if(l==u)below=TreeDP::compress(below,path[r]);\n\
    \                else above=TreeDP::compress(above,rpath[l]);\n              \
    \  u=p;\n                p=stt.par[u];\n            }\n            if(p!=-1){\n\
    \                u=p;\n                p=stt.par[u];\n                Point sum=Point::unit();\n\
    \                while(stt.type[p]==stt.Rake){\n                    int l=stt.lch[p],r=stt.rch[p];\n\
    \                    sum=TreeDP::rake(sum,u==r?point[l]:point[r]);\n         \
    \           u=p;\n                    p=stt.par[u];\n                }\n     \
    \           sum=TreeDP::rake(sum,rec(rec,p));\n                above=TreeDP::compress(above,TreeDP::add_vertex(sum,p));\n\
    \            }\n            return TreeDP::rake(TreeDP::add_edge(below),TreeDP::add_edge(above));\n\
    \        };\n        Point res=rec(rec,u);\n        if(stt.type[u]==stt.AddVertex){\n\
    \            res=TreeDP::rake(res,point[stt.lch[u]]);\n        }\n        return\
    \ TreeDP::add_vertex(res,u);\n    }\n};\n\n#line 2 \"modular-arithmetic/modint.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n * Description: modular arithmetic\
    \ operations\n */\n\ntemplate<int mod,int root=0>\nstruct ModInt{\n    using mint\
    \ = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must be positive\");\n\n    int\
    \ x;\n\n    constexpr ModInt():x(0){}\n    constexpr ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n\
    \    constexpr explicit operator int()const{return x;}\n    constexpr static int\
    \ get_mod(){return mod;}\n    constexpr static mint get_root(){return mint(root);}\n\
    \    \n    constexpr mint operator-()const{\n        mint res;\n        res.x=x?mod-x:0;\n\
    \        return res;\n    }\n    constexpr mint operator+()const{return *this;}\n\
    \n    constexpr mint inv()const{\n        int a=x,b=mod,u=1,v=0,q=0;\n       \
    \ while(b>0){\n            q=a/b;\n            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n\
    \        }\n        return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n\
    \        mint res=1,a=*this;\n        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n   \
    \     return res;\n    }\n    constexpr mint &operator+=(const mint &o){\n   \
    \     if((x+=o.x)>=mod)x-=mod;\n        return *this;\n    }\n    constexpr mint\
    \ &operator-=(const mint &o){\n        if((x-=o.x)<0)x+=mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator*=(const mint &o){\n        x=(ll(x)*o.x)%mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator/=(const mint &o){\n\
    \        return *this*=o.inv();\n    }\n\n    constexpr mint operator+(const mint\
    \ &o)const{return mint(*this)+=o;}\n    constexpr mint operator-(const mint &o)const{return\
    \ mint(*this)-=o;}\n    constexpr mint operator*(const mint &o)const{return mint(*this)*=o;}\n\
    \    constexpr mint operator/(const mint &o)const{return mint(*this)/=o;}\n\n\
    \    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){mint\
    \ res=*this;*this+=mint(1);return res;}\n    constexpr mint operator--(int){mint\
    \ res=*this;*this-=mint(1);return res;}\n    \n    constexpr bool operator==(const\
    \ mint &o)const{return x==o.x;}\n    constexpr bool operator!=(const mint &o)const{return\
    \ x!=o.x;}\n    constexpr bool operator<(const mint &o)const{return x<o.x;}\n\
    \    \n    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    };\nusing mint998 = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n\
    #line 7 \"verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp\"\
    \n\nusing mint = mint998;\n\nint n;\nvector<int> id;\nvector<mint> a,b,c;\n\n\
    struct TreeDP{\n    struct Path{\n        mint a,b,cnt,ans;\n        static Path\
    \ unit(){\n            return {1,0,0,0};\n        }\n    };\n    struct Point{\n\
    \        mint cnt,ans;\n        static Point unit(){\n            return {0,0};\n\
    \        }\n    };\n    static Path compress(const Path &l,const Path &r){\n \
    \       Path res;\n        res.a=l.a*r.a;\n        res.b=l.a*r.b+l.b;\n      \
    \  res.cnt=l.cnt+r.cnt;\n        res.ans=l.ans+l.a*r.ans+l.b*r.cnt;\n        return\
    \ res;\n    }\n    static Point rake(const Point &l,const Point &r){\n       \
    \ return {l.cnt+r.cnt,l.ans+r.ans};\n    }\n    static Point add_edge(const Path\
    \ &p){\n        return {p.cnt,p.ans};\n    }\n    static Path add_vertex(const\
    \ Point &p,int u){\n        Path res{b[u],c[u],p.cnt+(u<n),p.ans+a[u]};\n    \
    \    res.ans=res.a*res.ans+res.b*res.cnt;\n        return res;\n    }\n    static\
    \ Path vertex(int u){\n        Path res{b[u],c[u],u<n,a[u]};\n        res.ans=res.a*res.ans+res.b*res.cnt;\n\
    \        return res;\n    }\n};\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int q;\n    cin >> n >> q;\n    a.resize(2*n);\n    b.resize(2*n-1,mint(1));\n\
    \    c.resize(2*n-1);\n    for(int i=0;i<n;i++){\n        cin >> a[i];\n    }\n\
    \    Graph<void,false> g(2*n-1);\n    for(int i=0;i<n-1;i++){\n        int u,v;\n\
    \        cin >> u >> v >> b[i+n] >> c[i+n];\n        g.add_edge(u,i+n);\n    \
    \    g.add_edge(v,i+n);\n    }\n    HLD hld(g);\n    StaticTopTreeRerootingDP<decltype(hld),TreeDP>\
    \ dp(hld);\n    while(q--){\n        int op;\n        cin >> op;\n        if(op==0){\n\
    \            int u;\n            mint x;\n            cin >> u >> x;\n       \
    \     a[u]=x;\n            dp.update(u);\n        }else{\n            int e;\n\
    \            mint x,y;\n            cin >> e >> x >> y;\n            e+=n;\n \
    \           b[e]=x,c[e]=y;\n            dp.update(e);\n        }\n        int\
    \ r;\n        cin >> r;\n        cout << dp.query_reroot(r).ans << \"\\n\";\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum\"\
    \n#include \"template.hpp\"\n#include \"graph/graph-base.hpp\"\n#include \"tree/hld.hpp\"\
    \n#include \"tree/static-top-tree-rerooting-dp.hpp\"\n#include \"modular-arithmetic/modint.hpp\"\
    \n\nusing mint = mint998;\n\nint n;\nvector<int> id;\nvector<mint> a,b,c;\n\n\
    struct TreeDP{\n    struct Path{\n        mint a,b,cnt,ans;\n        static Path\
    \ unit(){\n            return {1,0,0,0};\n        }\n    };\n    struct Point{\n\
    \        mint cnt,ans;\n        static Point unit(){\n            return {0,0};\n\
    \        }\n    };\n    static Path compress(const Path &l,const Path &r){\n \
    \       Path res;\n        res.a=l.a*r.a;\n        res.b=l.a*r.b+l.b;\n      \
    \  res.cnt=l.cnt+r.cnt;\n        res.ans=l.ans+l.a*r.ans+l.b*r.cnt;\n        return\
    \ res;\n    }\n    static Point rake(const Point &l,const Point &r){\n       \
    \ return {l.cnt+r.cnt,l.ans+r.ans};\n    }\n    static Point add_edge(const Path\
    \ &p){\n        return {p.cnt,p.ans};\n    }\n    static Path add_vertex(const\
    \ Point &p,int u){\n        Path res{b[u],c[u],p.cnt+(u<n),p.ans+a[u]};\n    \
    \    res.ans=res.a*res.ans+res.b*res.cnt;\n        return res;\n    }\n    static\
    \ Path vertex(int u){\n        Path res{b[u],c[u],u<n,a[u]};\n        res.ans=res.a*res.ans+res.b*res.cnt;\n\
    \        return res;\n    }\n};\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int q;\n    cin >> n >> q;\n    a.resize(2*n);\n    b.resize(2*n-1,mint(1));\n\
    \    c.resize(2*n-1);\n    for(int i=0;i<n;i++){\n        cin >> a[i];\n    }\n\
    \    Graph<void,false> g(2*n-1);\n    for(int i=0;i<n-1;i++){\n        int u,v;\n\
    \        cin >> u >> v >> b[i+n] >> c[i+n];\n        g.add_edge(u,i+n);\n    \
    \    g.add_edge(v,i+n);\n    }\n    HLD hld(g);\n    StaticTopTreeRerootingDP<decltype(hld),TreeDP>\
    \ dp(hld);\n    while(q--){\n        int op;\n        cin >> op;\n        if(op==0){\n\
    \            int u;\n            mint x;\n            cin >> u >> x;\n       \
    \     a[u]=x;\n            dp.update(u);\n        }else{\n            int e;\n\
    \            mint x,y;\n            cin >> e >> x >> y;\n            e+=n;\n \
    \           b[e]=x,c[e]=y;\n            dp.update(e);\n        }\n        int\
    \ r;\n        cin >> r;\n        cout << dp.query_reroot(r).ans << \"\\n\";\n\
    \    }\n}"
  dependsOn:
  - template.hpp
  - graph/graph-base.hpp
  - tree/hld.hpp
  - tree/static-top-tree-rerooting-dp.hpp
  - tree/static-top-tree.hpp
  - modular-arithmetic/modint.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 21:45:25+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
- /verify/verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp.html
title: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
---
