---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: flow/binary-optimization.hpp
    title: flow/binary-optimization.hpp
  - icon: ':warning:'
    path: flow/dinic.hpp
    title: flow/dinic.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc259/tasks/abc259_g
  bundledCode: "#line 1 \"verify/atcoder/abc259_g.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_g\"\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"flow/dinic.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-07-15\n * Description: Dinic's Algorithm\
    \ for finding the maximum flow.\n * Time: O(V E \\log U) where U is the maximum\
    \ flow.\n */\n\ntemplate<class T,bool directed=true,bool scaling=true>\nstruct\
    \ Dinic{\n    static constexpr T INF=numeric_limits<T>::max()/2;\n    struct Edge{\n\
    \        int to;\n        T flow,cap;\n        Edge(int _to,T _cap):to(_to),flow(0),cap(_cap){}\n\
    \        T remain(){return cap-flow;}\n    };\n    int n,s,t;\n    T U;\n    vector<Edge>\
    \ e;\n    vector<vector<int>> g;\n    vector<int> ptr,lv;\n    bool calculated;\n\
    \    T max_flow;\n    Dinic(){}\n    Dinic(int n,int s,int t){init(n,s,t);}\n\
    \    void init(int _n,int _s,int _t){\n        n=_n,s=_s,t=_t;\n        U=0;\n\
    \        e.clear();\n        g.assign(n,{});\n        calculated=false;\n    }\n\
    \    void add_edge(int from,int to,T cap){\n        assert(0<=from&&from<n&&0<=to&&to<n);\n\
    \        g[from].emplace_back(e.size());\n        e.emplace_back(to,cap);\n  \
    \      g[to].emplace_back(e.size());\n        e.emplace_back(from,directed?0:cap);\n\
    \        U=max(U,cap);\n    }\n    bool bfs(T scale){\n        lv.assign(n,-1);\n\
    \        vector<int> q{s};\n        lv[s]=0;\n        for(int i=0;i<(int)q.size();i++){\n\
    \            int u=q[i];\n            for(int j:g[u]){\n                int v=e[j].to;\n\
    \                if(lv[v]==-1&&e[j].remain()>=scale){\n                    q.emplace_back(v);\n\
    \                    lv[v]=lv[u]+1;\n                }\n            }\n      \
    \  }\n        return lv[t]!=-1;\n    }\n    T dfs(int u,int t,T f){\n        if(u==t||f==0)return\
    \ f;\n        for(int &i=ptr[u];i<(int)g[u].size();i++){\n            int j=g[u][i];\n\
    \            int v=e[j].to;\n            if(lv[v]==lv[u]+1){\n               \
    \ T res=dfs(v,t,min(f,e[j].remain()));\n                if(res>0){\n         \
    \           e[j].flow+=res;\n                    e[j^1].flow-=res;\n         \
    \           return res;\n                }\n            }\n        }\n       \
    \ return 0;\n    }\n    T flow(){\n        if(calculated)return max_flow;\n  \
    \      calculated=true;\n        max_flow=0;\n        for(T scale=scaling?1LL<<(63-__builtin_clzll(U)):1LL;scale>0;scale>>=1){\n\
    \            while(bfs(scale)){\n                ptr.assign(n,0);\n          \
    \      while(true){\n                    T f=dfs(s,t,INF);\n                 \
    \   if(f==0)break;\n                    max_flow+=f;\n                }\n    \
    \        }\n        }\n        return max_flow;\n    }\n    pair<T,vector<int>>\
    \ cut(){\n        flow();\n        vector<int> res(n);\n        for(int i=0;i<n;i++)res[i]=(lv[i]==-1);\n\
    \        return {max_flow,res};\n    }\n};\n\n#line 3 \"flow/binary-optimization.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-07-16\n * Description: Binary Optimization.\n\
    \ *  minimize $\\kappa + \\sum_i \\theta_i(x_i) + \\sum_{i<j} \\phi_{ij}(x_i,x_j)\
    \ + \\sum_{i<j<k} \\psi_{ijk}(x_i,x_j,x_k)$\n *  where $x_i \\in \\{0,1\\}$ and\
    \ $\\phi_{ij},\\psi_{ijk}$ are submodular functions.\n *  a set function $f$ is\
    \ submodular if $f(S) + f(T) \\geq f(S \\cap T) + f(S \\cup T)$ for all $S,T$.\n\
    \ *  $\\phi_{ij}(0,1) + \\phi_{ij}(1,0) \\geq \\phi_{ij}(1,1) + \\phi_{ij}(0,0)$.\n\
    \ */\n\ntemplate<class T,bool minimize=true>\nstruct BinaryOptimization{\n   \
    \ static constexpr T INF=numeric_limits<T>::max()/2;\n    int n,s,t,node_id;\n\
    \    T base;\n    map<pair<int,int>,T> edges;\n    BinaryOptimization(int _n):n(_n),s(n),t(n+1),node_id(n+2),base(0){}\n\
    \    void add_edge(int u,int v,T w){\n        assert(w>=0);\n        if(u==v||w==0)return;\n\
    \        auto &e=edges[{u,v}];\n        e=min(e+w,INF);\n    }\n    void add0(T\
    \ w){\n        base+=w;\n    }\n    void _add1(int i,T a,T b){\n        if(a<=b){\n\
    \            add0(a);\n            add_edge(s,i,b-a);\n        }else{\n      \
    \      add0(b);\n            add_edge(i,t,a-b);\n        }\n    }\n    void add1(int\
    \ i,T x0,T x1){\n        assert(0<=i&&i<n);\n        if(!minimize)x0=-x0,x1=-x1;\n\
    \        _add1(i,x0,x1);\n    }\n    void _add2(int i,int j,T a,T b,T c,T d){\n\
    \        assert(b+c>=a+d);\n        add0(a);\n        _add1(i,0,c-a);\n      \
    \  _add1(j,0,d-c);\n        add_edge(i,j,b+c-a-d);\n    }\n    void add2(int i,int\
    \ j,T x00,T x01,T x10,T x11){\n        assert(i!=j&&0<=i&&i<n&&0<=j&&j<n);\n \
    \       if(!minimize)x00=-x00,x01=-x01,x10=-x10,x11=-x11;\n        _add2(i,j,x00,x01,x10,x11);\n\
    \    }\n    void _add3(int i,int j,int k,T a,T b,T c,T d,T e,T f,T g,T h){\n \
    \       T p=a+d+f+g-b-c-e-h;\n        if(p>=0){\n            add0(a);\n      \
    \      _add1(i,0,f-b);\n            _add1(j,0,g-e);\n            _add1(k,0,d-c);\n\
    \            _add2(i,j,0,c+e-a-g,0,0);\n            _add2(i,k,0,0,b+e-a-f,0);\n\
    \            _add2(j,k,0,b+c-a-d,0,0);\n            int u=node_id++;\n       \
    \     add0(-p);\n            add_edge(i,u,p);\n            add_edge(j,u,p);\n\
    \            add_edge(k,u,p);\n            add_edge(u,t,p);\n        }else{\n\
    \            add0(h);\n            _add1(i,c-g,0);\n            _add1(j,b-d,0);\n\
    \            _add1(k,e-f,0);\n            _add2(i,j,0,0,d+f-b-h,0);\n        \
    \    _add2(i,k,0,d+g-c-h,0,0);\n            _add2(j,k,0,0,f+g-e-h,0);\n      \
    \      int u=node_id++;\n            add0(p);\n            add_edge(s,u,-p);\n\
    \            add_edge(u,i,-p);\n            add_edge(u,j,-p);\n            add_edge(u,k,-p);\n\
    \        }\n    }\n    void add3(int i,int j,int k,T x000,T x001,T x010,T x011,T\
    \ x100,T x101,T x110,T x111){\n        assert(i!=j&&j!=k&&k!=i&&0<=i&&i<n&&0<=j&&j<n&&0<=k&&k<n);\n\
    \        if(!minimize){\n            x000=-x000,x001=-x001,x010=-x010,x011=-x011;\n\
    \            x100=-x100,x101=-x101,x110=-x110,x111=-x111;\n        }\n       \
    \ _add3(i,j,k,x000,x001,x010,x011,x100,x101,x110,x111);\n    }\n    T solve(){\n\
    \        Dinic<T> dinic(node_id,s,t);\n        for(auto &[p,w]:edges){\n     \
    \       auto [u,v]=p;\n            dinic.add_edge(u,v,w);\n        }\n       \
    \ T ans=dinic.flow()+base;\n        return minimize?ans:-ans;\n    }\n};\n\n#line\
    \ 4 \"verify/atcoder/abc259_g.cpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,m;\n    cin >> n >> m;\n    vector a(n,vector<ll>(m));\n    vector<ll>\
    \ sumh(n),sumv(m);\n    for(int i=0;i<n;i++){\n        for(int j=0;j<m;j++){\n\
    \            cin >> a[i][j];\n            sumh[i]+=a[i][j];\n            sumv[j]+=a[i][j];\n\
    \        }\n    }\n    BinaryOptimization<ll,false> b(n+m);\n    for(int i=0;i<n;i++)b.add1(i,sumh[i],0);\n\
    \    for(int i=0;i<m;i++)b.add1(i+n,0,sumv[i]);\n    for(int i=0;i<n;i++){\n \
    \       for(int j=0;j<m;j++){\n            if(a[i][j]<0){\n                b.add2(i,j+n,0,-LINF,0,0);\n\
    \            }else{\n                b.add2(i,j+n,0,-a[i][j],0,0);\n         \
    \   }\n        }\n    }\n    cout << b.solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_g\"\n#include\
    \ \"template.hpp\"\n#include \"flow/binary-optimization.hpp\"\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n    cin >> n >>\
    \ m;\n    vector a(n,vector<ll>(m));\n    vector<ll> sumh(n),sumv(m);\n    for(int\
    \ i=0;i<n;i++){\n        for(int j=0;j<m;j++){\n            cin >> a[i][j];\n\
    \            sumh[i]+=a[i][j];\n            sumv[j]+=a[i][j];\n        }\n   \
    \ }\n    BinaryOptimization<ll,false> b(n+m);\n    for(int i=0;i<n;i++)b.add1(i,sumh[i],0);\n\
    \    for(int i=0;i<m;i++)b.add1(i+n,0,sumv[i]);\n    for(int i=0;i<n;i++){\n \
    \       for(int j=0;j<m;j++){\n            if(a[i][j]<0){\n                b.add2(i,j+n,0,-LINF,0,0);\n\
    \            }else{\n                b.add2(i,j+n,0,-a[i][j],0,0);\n         \
    \   }\n        }\n    }\n    cout << b.solve();\n}"
  dependsOn:
  - template.hpp
  - flow/binary-optimization.hpp
  - flow/dinic.hpp
  isVerificationFile: false
  path: verify/atcoder/abc259_g.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/atcoder/abc259_g.cpp
layout: document
redirect_from:
- /library/verify/atcoder/abc259_g.cpp
- /library/verify/atcoder/abc259_g.cpp.html
title: verify/atcoder/abc259_g.cpp
---
