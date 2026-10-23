---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/graph-base.hpp
    title: graph/graph-base.hpp
  - icon: ':x:'
    path: graph/strongly-connected-component.hpp
    title: graph/strongly-connected-component.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/yosupo/graph/strongly-connected-component/scc.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ db = long double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64\
    \ = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SZ(a) (int)(a.size())\n#define SORT(a)\
    \ sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
    #define UNI(a) a.erase(unique(ALL(a)),a.end())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define FIND(a,x) (int)(find(ALL(a),x)-a.begin())\n\
    #define COUNT(a,x) (int)count(ALL(a),x)\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\ntemplate<class T,class U>\nbool chmin(T\
    \ &a,U b){return b<a?a=b,1:0;}\ntemplate<class T,class U>\nbool chmax(T &a,U b){return\
    \ a<b?a=b,1:0;}\n\ntemplate<class T>\nT floor(T a,T b){return a/b-((a^b)<0&&a%b);}\n\
    template<class T>\nT ceil(T a,T b){return a/b+((a^b)>=0&&a%b);}\n\nint popcnt(ll\
    \ x){return __builtin_popcountll(x);}\nint topbit(ll x){return x==0?-1:63-__builtin_clzll(x);}\n\
    int lowbit(ll x){return x==0?-1:__builtin_ctzll(x);}\n\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\ntemplate<class T>\nvector<int>\
    \ argsort(const vector<T> &a){\n    vector<int> p(SZ(a));\n    iota(ALL(p),0);\n\
    \    stable_sort(ALL(p),[&](int i,int j){return a[i]<a[j];});\n    return p;\n\
    }\n\ntemplate<class T,size_t D=0>\nstruct VecBuilder{\n    array<size_t,D> d;\n\
    \    VecBuilder<T,D+1> operator[](size_t n)const{\n        VecBuilder<T,D+1> res{};\n\
    \        for(size_t i=0;i<D;i++)res.d[i]=d[i];\n        res.d[D]=n;\n        return\
    \ res;\n    }\n    template<size_t I=0>\n    auto build(const T &x)const{\n  \
    \      if constexpr(I+1==D)return vector<T>(d[I],x);\n        else return vector<decltype(build<I+1>(x))>(d[I],build<I+1>(x));\n\
    \    }\n    auto operator()(const T &x=T())const{\n        static_assert(D>0);\n\
    \        return build(x);\n    }\n};\ntemplate<class T>\ninline constexpr VecBuilder<T>\
    \ VEC{};\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ 2 \"graph/strongly-connected-component.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-06-28\n * Description: Strongly Connected Component.\n */\n\ntemplate<class\
    \ G>\npair<int,vector<int>> strongly_connected_component(G &g){\n    static_assert(G::is_directed);\n\
    \    int n=g.n;\n    vector<int> disc(n,-1),low(n),scc(n,-1);\n    stack<int>\
    \ st;\n    vector<bool> in_st(n);\n    int t=0,scc_cnt=0;\n    function<void(int,int)>\
    \ dfs=[&](int u,int p){\n        disc[u]=low[u]=t++;\n        st.emplace(u);\n\
    \        in_st[u]=true;\n        for(int v:g[u]){\n            if(disc[v]==-1){\n\
    \                dfs(v,u);\n                low[u]=min(low[u],low[v]);\n     \
    \       }else if(in_st[v]){\n                low[u]=min(low[u],disc[v]);\n   \
    \         }\n        }\n        if(disc[u]==low[u]){\n            while(true){\n\
    \                int v=st.top();\n                st.pop();\n                in_st[v]=false;\n\
    \                scc[v]=scc_cnt;\n                if(v==u)break;\n           \
    \ }\n            scc_cnt++;\n        }\n    };\n    for(int i=0;i<n;i++)if(disc[i]==-1)dfs(i,-1);\n\
    \    return {scc_cnt,scc};\n}\n\n#line 5 \"verify/yosupo/graph/strongly-connected-component/scc.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n\
    \    cin >> n >> m;\n    Graph g=read_graph<void,true>(n,m,0);\n    auto [k,scc]=strongly_connected_component(g);\n\
    \    vector<vector<int>> ans(k);\n    for(int i=0;i<n;i++)ans[scc[i]].emplace_back(i);\n\
    \    reverse(ans.begin(),ans.end());\n    cout << k << \"\\n\";\n    for(auto\
    \ &v:ans){\n        cout << v.size();\n        for(auto x:v)cout << \" \" << x;\n\
    \        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"template.hpp\"\
    \n#include \"graph/graph-base.hpp\"\n#include \"graph/strongly-connected-component.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n\
    \    cin >> n >> m;\n    Graph g=read_graph<void,true>(n,m,0);\n    auto [k,scc]=strongly_connected_component(g);\n\
    \    vector<vector<int>> ans(k);\n    for(int i=0;i<n;i++)ans[scc[i]].emplace_back(i);\n\
    \    reverse(ans.begin(),ans.end());\n    cout << k << \"\\n\";\n    for(auto\
    \ &v:ans){\n        cout << v.size();\n        for(auto x:v)cout << \" \" << x;\n\
    \        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - template.hpp
  - graph/graph-base.hpp
  - graph/strongly-connected-component.hpp
  isVerificationFile: true
  path: verify/yosupo/graph/strongly-connected-component/scc.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/graph/strongly-connected-component/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/graph/strongly-connected-component/scc.test.cpp
- /verify/verify/yosupo/graph/strongly-connected-component/scc.test.cpp.html
title: verify/yosupo/graph/strongly-connected-component/scc.test.cpp
---
