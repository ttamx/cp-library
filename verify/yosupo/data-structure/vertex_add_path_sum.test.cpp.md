---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: data-structure/fenwick-tree.hpp
  - icon: ':question:'
    path: graph/graph-base.hpp
    title: graph/graph-base.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"verify/yosupo/data-structure/vertex_add_path_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
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
    \      return tin[u]<=tin[v]&&tout[v]<=tout[u];\n    }\n};\n\n#line 2 \"data-structure/fenwick-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description: Fenwick /\
    \ Binary Indexed Tree\n */\n\ntemplate<class T>\nstruct Fenwick{\n    int n,logn;\n\
    \    vector<T> t;\n    Fenwick(){}\n    Fenwick(int _n){init(vector<T>(_n,T{}));}\n\
    \    template<class U>\n    Fenwick(const vector<U> &a){init(a);}\n    template<class\
    \ U>\n    void init(const vector<U> &a){\n        n=(int)a.size();\n        logn=31-__builtin_clz(n);\n\
    \        t.assign(n+1,T{});\n        for(int i=1;i<=n;i++){\n            t[i]=t[i]+a[i-1];\n\
    \            int j=i+(i&-i);\n            if(j<=n)t[j]=t[j]+t[i];\n        }\n\
    \    }\n    void update(int x,const T &v){\n        for(int i=x+1;i<=n;i+=i&-i)t[i]=t[i]+v;\n\
    \    }\n    void update(int l,int r,const T &v){\n        update(l,v),update(r+1,-v);\n\
    \    }\n    T query(int x){\n        T res{};\n        for(int i=x+1;i>0;i-=i&-i)res=res+t[i];\n\
    \        return res;\n    }\n    T query(int l,int r){\n        return query(r)-query(l-1);\n\
    \    }\n    int find(const T &k){\n        int x=0;\n        T cur{};\n      \
    \  for(int i=1<<logn;i>0;i>>=1)\n            if(x+i<=n&&cur+t[x+i]<=k)x+=i,cur=cur+t[x];\n\
    \        return x;\n    }\n};\n\n#line 6 \"verify/yosupo/data-structure/vertex_add_path_sum.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<int> a(n);\n    for(auto &x:a)cin >> x;\n    Graph\
    \ g=read_tree(n,0);\n    HLD hld=g;\n    auto b=a;\n    for(int i=0;i<n;i++)a[hld.tin[i]]=b[i];\n\
    \    Fenwick<ll> f(a);\n    while(q--){\n        int op;\n        cin >> op;\n\
    \        if(op==0){\n            int p,x;\n            cin >> p >> x;\n      \
    \      f.update(hld.tin[p],x);\n        }else{\n            int u,v;\n       \
    \     cin >> u >> v;\n            ll ans=0;\n            for(auto [u,v]:hld.get_path(u,v,true))ans+=f.query(u,v);\n\
    \            cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include \"template.hpp\"\n#include \"graph/graph-base.hpp\"\n#include \"tree/hld.hpp\"\
    \n#include \"data-structure/fenwick-tree.hpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for(auto &x:a)cin\
    \ >> x;\n    Graph g=read_tree(n,0);\n    HLD hld=g;\n    auto b=a;\n    for(int\
    \ i=0;i<n;i++)a[hld.tin[i]]=b[i];\n    Fenwick<ll> f(a);\n    while(q--){\n  \
    \      int op;\n        cin >> op;\n        if(op==0){\n            int p,x;\n\
    \            cin >> p >> x;\n            f.update(hld.tin[p],x);\n        }else{\n\
    \            int u,v;\n            cin >> u >> v;\n            ll ans=0;\n   \
    \         for(auto [u,v]:hld.get_path(u,v,true))ans+=f.query(u,v);\n         \
    \   cout << ans << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - graph/graph-base.hpp
  - tree/hld.hpp
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
- /verify/verify/yosupo/data-structure/vertex_add_path_sum.test.cpp.html
title: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
---
