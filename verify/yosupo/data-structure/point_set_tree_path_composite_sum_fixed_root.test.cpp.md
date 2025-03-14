---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-base.hpp
    title: graph/graph-base.hpp
  - icon: ':question:'
    path: modular-arithmetic/montgomery-modint.hpp
    title: modular-arithmetic/montgomery-modint.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: tree/hld.hpp
    title: tree/hld.hpp
  - icon: ':heavy_check_mark:'
    path: tree/static-top-tree-dp.hpp
    title: tree/static-top-tree-dp.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
  bundledCode: "#line 1 \"verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n\nusing namespace std;\nusing namespace __gnu_pbds;\n\
    \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\nusing\
    \ vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst\
    \ int MOD=998244353;\nconst int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    template<class T>\nusing ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"graph/graph-base.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-15\n * Description: Graph Base\n\
    \ */\n\ntemplate<class T>\nstruct Edge{\n    int from,to,id;\n    T cost;\n  \
    \  Edge(int _from,int _to,T _cost,int _id):from(_from),to(_to),cost(_cost),id(_id){}\n\
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
    \ {sj+1,add(i,j,-1,j==-1?Vertex:AddVertex)};\n    }\n};\n\n#line 3 \"tree/static-top-tree-dp.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-11-14\n * Description: Static Top\
    \ Tree DP.\n */\n\n/*\nstruct TreeDP{\n    struct Path{\n        static Path unit();\n\
    \    };\n    struct Point{\n        static Point unit();\n    };\n    static Path\
    \ compress(Path l,Path r);\n    static Point rake(Point l,Point r);\n    static\
    \ Point add_edge(Path p);\n    static Path add_vertex(Point p,int u);\n    static\
    \ Path vertex(int u);\n};\n*/\n\ntemplate<class HLD,class TreeDP>\nstruct StaticTopTreeDP{\n\
    \    using Path = typename TreeDP::Path;\n    using Point = typename TreeDP::Point;\n\
    \    StaticTopTree<HLD> stt;\n    vector<Path> path;\n    vector<Point> point;\n\
    \    StaticTopTreeDP(HLD &hld):stt(hld){\n        int n=stt.n;\n        path.resize(n);\n\
    \        point.resize(n);\n        dfs(stt.root);\n    }\n    void _update(int\
    \ u){\n        if(stt.type[u]==stt.Vertex){\n            path[u]=TreeDP::vertex(u);\n\
    \        }else if(stt.type[u]==stt.Compress){\n            path[u]=TreeDP::compress(path[stt.lch[u]],path[stt.rch[u]]);\n\
    \        }else if(stt.type[u]==stt.Rake){\n            point[u]=TreeDP::rake(point[stt.lch[u]],point[stt.rch[u]]);\n\
    \        }else if(stt.type[u]==stt.AddEdge){\n            point[u]=TreeDP::add_edge(path[stt.lch[u]]);\n\
    \        }else{\n            path[u]=TreeDP::add_vertex(point[stt.lch[u]],u);\n\
    \        }\n    }\n    void dfs(int u){\n        if(u==-1)return;\n        dfs(stt.lch[u]);\n\
    \        dfs(stt.rch[u]);\n        _update(u);\n    }\n    void update(int u){\n\
    \        for(;u!=-1;u=stt.par[u])_update(u);\n    }\n    Path query_all(){\n \
    \       return path[stt.root];\n    }\n    Path query_subtree(int u){\n      \
    \  Path res=path[u];\n        while(true){\n            int p=stt.par[u];\n  \
    \          if(p==-1||stt.type[p]!=stt.Compress)break;\n            if(stt.lch[p]==u)res=TreeDP::compress(res,path[stt.rch[p]]);\n\
    \        }\n        return res;\n    }\n};\n\n#line 2 \"modular-arithmetic/montgomery-modint.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description: modular arithmetic\
    \ operators using Montgomery space\n */\n\ntemplate<uint32_t mod,uint32_t root=0>\n\
    struct MontgomeryModInt{\n    using mint = MontgomeryModInt;\n    using i32 =\
    \ int32_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static\
    \ constexpr u32 get_r(){\n        u32 res=1;\n        for(i32 i=0;i<5;i++)res*=2-mod*res;\n\
    \        return res;\n    }\n\n    static const u32 r=get_r();\n    static const\
    \ u32 n2=-u64(mod)%mod;\n    static_assert(mod<(1<<30));\n    static_assert((mod&1)==1);\n\
    \    static_assert(r*mod==1);\n\n    u32 x;\n\n    constexpr MontgomeryModInt():x(0){}\n\
    \    constexpr MontgomeryModInt(const int64_t &v):x(reduce(u64(v%mod+mod)*n2)){}\n\
    \n    static constexpr u32 get_mod(){return mod;}\n    static constexpr mint get_root(){return\
    \ mint(root);}\n    explicit constexpr operator int64_t()const{return val();}\n\
    \n    static constexpr u32 reduce(const u64 &v){\n        return (v+u64(u32(v)*u32(-r))*mod)>>32;\n\
    \    }\n\n    constexpr u32 val()const{\n        u32 res=reduce(x);\n        return\
    \ res>=mod?res-mod:res;\n    }\n\n    constexpr mint inv()const{\n        int\
    \ a=val(),b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n      \
    \      a-=q*b;\n            u-=q*v;\n            swap(a,b);\n            swap(u,v);\n\
    \        }\n        return mint(u);\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &rhs){\n        if(i32(x+=rhs.x-2*mod)<0)x+=2*mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator-=(const mint &rhs){\n        if(i32(x-=rhs.x)<0)x+=2*mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator*=(const mint &rhs){\n\
    \        x=reduce(u64(x)*rhs.x);\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &rhs){\n        return *this*=rhs.inv();\n    }\n\
    \n    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){\n\
    \        mint res=*this;\n        return *this+=mint(1),res;\n    }\n    constexpr\
    \ mint operator--(int){\n        mint res=*this;\n        return *this-=mint(1),res;\n\
    \    }\n\n    constexpr mint operator-()const{return mint()-mint(*this);};\n \
    \   constexpr mint operator+()const{return mint(*this);};\n\n    friend constexpr\
    \ mint operator+(const mint &lhs,const mint &rhs){return mint(lhs)+=rhs;}\n  \
    \  friend constexpr mint operator-(const mint &lhs,const mint &rhs){return mint(lhs)-=rhs;}\n\
    \    friend constexpr mint operator*(const mint &lhs,const mint &rhs){return mint(lhs)*=rhs;}\n\
    \    friend constexpr mint operator/(const mint &lhs,const mint &rhs){return mint(lhs)/=rhs;}\n\
    \    friend constexpr bool operator==(const mint &lhs,const mint &rhs){\n    \
    \    return (lhs.x>=mod?lhs.x-mod:lhs.x)==(rhs.x>=mod?rhs.x-mod:rhs.x);\n    }\n\
    \    friend constexpr bool operator!=(const mint &lhs,const mint &rhs){\n    \
    \    return (lhs.x>=mod?lhs.x-mod:lhs.x)!=(rhs.x>=mod?rhs.x-mod:rhs.x);\n    }\n\
    \    friend constexpr bool operator<(const mint &lhs,const mint &rhs){\n     \
    \   return (lhs.x>=mod?lhs.x-mod:lhs.x)<(rhs.x>=mod?rhs.x-mod:rhs.x); // for std::map\n\
    \    }\n\n    friend istream &operator>>(istream &is,mint &o){\n        int64_t\
    \ v;\n        is >> v;\n        o=mint(v);\n        return is;\n    }\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){\n        return os << o.val();\n\
    \    }\n};\nusing mint998 = MontgomeryModInt<998244353,3>;\nusing mint107 = MontgomeryModInt<1000000007>;\n\
    \n#line 7 \"verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\
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
    \    g.add_edge(v,i+n);\n    }\n    HLD hld(g);\n    StaticTopTreeDP<decltype(hld),TreeDP>\
    \ dp(hld);\n    while(q--){\n        int op;\n        cin >> op;\n        if(op==0){\n\
    \            int u;\n            mint x;\n            cin >> u >> x;\n       \
    \     a[u]=x;\n            dp.update(u);\n        }else{\n            int e;\n\
    \            mint x,y;\n            cin >> e >> x >> y;\n            e+=n;\n \
    \           b[e]=x,c[e]=y;\n            dp.update(e);\n        }\n        cout\
    \ << dp.query_all().ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n#include \"template.hpp\"\n#include \"graph/graph-base.hpp\"\n#include \"tree/hld.hpp\"\
    \n#include \"tree/static-top-tree-dp.hpp\"\n#include \"modular-arithmetic/montgomery-modint.hpp\"\
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
    \    g.add_edge(v,i+n);\n    }\n    HLD hld(g);\n    StaticTopTreeDP<decltype(hld),TreeDP>\
    \ dp(hld);\n    while(q--){\n        int op;\n        cin >> op;\n        if(op==0){\n\
    \            int u;\n            mint x;\n            cin >> u >> x;\n       \
    \     a[u]=x;\n            dp.update(u);\n        }else{\n            int e;\n\
    \            mint x,y;\n            cin >> e >> x >> y;\n            e+=n;\n \
    \           b[e]=x,c[e]=y;\n            dp.update(e);\n        }\n        cout\
    \ << dp.query_all().ans << \"\\n\";\n    }\n}"
  dependsOn:
  - template.hpp
  - graph/graph-base.hpp
  - tree/hld.hpp
  - tree/static-top-tree-dp.hpp
  - tree/static-top-tree.hpp
  - modular-arithmetic/montgomery-modint.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
