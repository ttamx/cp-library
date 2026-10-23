---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: flow/dinic.hpp
    title: flow/dinic.hpp
  - icon: ':warning:'
    path: flow/k-ary-optimization.hpp
    title: flow/k-ary-optimization.hpp
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
    - https://atcoder.jp/contests/abc347/tasks/abc347_g
  bundledCode: "#line 1 \"verify/atcoder/abc347_g.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc347/tasks/abc347_g\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing\
    \ u32 = uint32_t;\nusing u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
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
    \ 2 \"flow/dinic.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-15\n * Description:\
    \ Dinic's Algorithm for finding the maximum flow.\n * Time: O(V E \\log U) where\
    \ U is the maximum flow.\n */\n\ntemplate<class T,bool directed=true,bool scaling=true>\n\
    struct Dinic{\n    static constexpr T INF=numeric_limits<T>::max()/2;\n    struct\
    \ Edge{\n        int to;\n        T flow,cap;\n        Edge(int _to,T _cap):to(_to),flow(0),cap(_cap){}\n\
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
    \        return {max_flow,res};\n    }\n};\n\n#line 3 \"flow/k-ary-optimization.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-07-16\n * Description: k-ary Optimization.\n\
    \ * minimize $\\kappa + \\sum_i \\theta_i(x_i) + \\sum_{i<j} \\phi_{ij}(x_i,x_j)$\n\
    \ * where $x_i \\in \\{0,1,\\ldots,k-1\\}$ and $\\phi_{i,j}$ is monge.\n * A function\
    \ $f$ is monge if $f(a,c)+f(b,d) \\leq f(a,d)+f(b,c)$ for all $a < b$ and $c <\
    \ d$.\n * $\\phi_{ij}(x-1,y)+\\phi_{ij}(x,y+1) \\leq \\phi_{ij}(x-1,y+1)+\\phi_{ij}(x,y)$.\n\
    \ * $\\phi_{ij}(x,y)+\\phi_{ij}(x-1,y+1)-\\phi_{ij}(x-1,y)-\\phi_{ij}(x,y+1) \\\
    geq 0$.\n */\n\ntemplate<class T,bool minimize=true>\nstruct K_aryOptimization{\n\
    \    static constexpr T INF=numeric_limits<T>::max()/2;\n    int n,s,t,node_id;\n\
    \    T base;\n    vector<int> ks;\n    vector<vector<int>> id;\n    map<pair<int,int>,T>\
    \ edges;\n    K_aryOptimization(int n,int k){init(vector<int>(n,k));}\n    K_aryOptimization(const\
    \ vector<int> &_ks){init(_ks);}\n    void init(const vector<int> &_ks){\n    \
    \    ks=_ks;\n        n=ks.size();\n        s=0,t=1,node_id=2;\n        base=0;\n\
    \        id.clear();\n        edges.clear();\n        for(auto &k:ks){\n     \
    \       assert(k>=1);\n            vector<int> a(k+1);\n            a[0]=s,a[k]=t;\n\
    \            for(int i=1;i<k;i++)a[i]=node_id++;\n            id.emplace_back(a);\n\
    \            for(int i=2;i<k;i++)add_edge(a[i],a[i-1],INF);\n        }\n    }\n\
    \    void add_edge(int u,int v,T w){\n        assert(w>=0);\n        if(u==v||w==0)return;\n\
    \        auto &e=edges[{u,v}];\n        e=min(e+w,INF);\n    }\n    void add0(T\
    \ w){\n        base+=w;\n    }\n    void _add1(int i,vector<T> cost){\n      \
    \  add0(cost[0]);\n        for(int j=1;j<ks[i];j++){\n            T x=cost[j]-cost[j-1];\n\
    \            if(x>0)add_edge(id[i][j],t,x);\n            if(x<0)add0(x),add_edge(s,id[i][j],-x);\n\
    \        }\n    }\n    void add1(int i,vector<T> cost){\n        assert(0<=i&&i<n&&(int)cost.size()==ks[i]);\n\
    \        if(!minimize)for(auto &x:cost)x=-x;\n        _add1(i,cost);\n    }\n\
    \    void _add2(int i,int j,vector<vector<T>> cost){\n        int h=ks[i],w=ks[j];\n\
    \        _add1(j,cost[0]);\n        for(int x=h-1;x>=0;x--)for(int y=0;y<w;y++)cost[x][y]-=cost[0][y];\n\
    \        vector<T> a(h);\n        for(int x=0;x<h;x++)a[x]=cost[x][w-1];\n   \
    \     _add1(i,a);\n        for(int x=0;x<h;x++)for(int y=0;y<w;y++)cost[x][y]-=a[x];\n\
    \        for(int x=1;x<h;x++){\n            for(int y=0;y<w-1;y++){\n        \
    \        T w=cost[x][y]+cost[x-1][y+1]-cost[x-1][y]-cost[x][y+1];\n          \
    \      assert(w>=0); // monge\n                add_edge(id[i][x],id[j][y+1],w);\n\
    \            }\n        }\n    }\n    void add2(int i,int j,vector<vector<T>>\
    \ cost){\n        assert(0<=i&&i<n&&0<=j&&j<n&&i!=j);\n        assert((int)cost.size()==ks[i]);\n\
    \        for(auto &v:cost)assert((int)v.size()==ks[j]);\n        if(!minimize)for(auto\
    \ &v:cost)for(auto &x:v)x=-x;\n        _add2(i,j,cost);\n    }\n    pair<T,vector<int>>\
    \ solve(){\n        Dinic<T> dinic(node_id,s,t);\n        for(auto &[p,w]:edges){\n\
    \            auto [u,v]=p;\n            dinic.add_edge(u,v,w);\n        }\n  \
    \      auto [val,cut]=dinic.cut();\n        val+=base;\n        if(!minimize)val=-val;\n\
    \        vector<int> ans(n);\n        for(int i=0;i<n;i++){\n            ans[i]=ks[i]-1;\n\
    \            for(int j=1;j<ks[i];j++)ans[i]-=cut[id[i][j]];\n        }\n     \
    \   return {val,ans};\n    }\n};\n\n#line 4 \"verify/atcoder/abc347_g.cpp\"\n\n\
    int main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    cin\
    \ >> n;\n    vector a(n,vector<int>(n));\n    for(auto &v:a)for(auto &x:v)cin\
    \ >> x,x--;\n    K_aryOptimization<ll,true> s(n*n,5);\n    auto enc=[&](int i,int\
    \ j){return i*n+j;};\n    for(int i=0;i<n;i++){\n        for(int j=0;j<n;j++){\n\
    \            if(a[i][j]!=-1){\n                vector<ll> c(5,INF);\n        \
    \        c[a[i][j]]=0;\n                s.add1(enc(i,j),c);\n            }\n \
    \       }\n    }\n    for(int i=0;i<n;i++){\n        for(int j=0;j<n;j++){\n \
    \           int u=enc(i,j);\n            auto work=[&](int x,int y){\n       \
    \         if(x<0||x>=n||y<0||y>=n)return;\n                int v=enc(x,y);\n \
    \               vector c(5,vector<ll>(5));\n                for(int x1=0;x1<5;x1++){\n\
    \                    for(int x2=0;x2<5;x2++){\n                        c[x1][x2]=(x1-x2)*(x1-x2);\n\
    \                    }\n                }\n                s.add2(u,v,c);\n  \
    \          };\n            work(i,j+1);\n            work(i+1,j);\n        }\n\
    \    }\n    auto ans=s.solve().second;\n    for(int i=0;i<n;i++){\n        for(int\
    \ j=0;j<n;j++){\n            cout << ans[enc(i,j)]+1 << \" \\n\"[j==n-1];\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc347/tasks/abc347_g\"\n#include\
    \ \"template.hpp\"\n#include \"flow/k-ary-optimization.hpp\"\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    cin >> n;\n  \
    \  vector a(n,vector<int>(n));\n    for(auto &v:a)for(auto &x:v)cin >> x,x--;\n\
    \    K_aryOptimization<ll,true> s(n*n,5);\n    auto enc=[&](int i,int j){return\
    \ i*n+j;};\n    for(int i=0;i<n;i++){\n        for(int j=0;j<n;j++){\n       \
    \     if(a[i][j]!=-1){\n                vector<ll> c(5,INF);\n               \
    \ c[a[i][j]]=0;\n                s.add1(enc(i,j),c);\n            }\n        }\n\
    \    }\n    for(int i=0;i<n;i++){\n        for(int j=0;j<n;j++){\n           \
    \ int u=enc(i,j);\n            auto work=[&](int x,int y){\n                if(x<0||x>=n||y<0||y>=n)return;\n\
    \                int v=enc(x,y);\n                vector c(5,vector<ll>(5));\n\
    \                for(int x1=0;x1<5;x1++){\n                    for(int x2=0;x2<5;x2++){\n\
    \                        c[x1][x2]=(x1-x2)*(x1-x2);\n                    }\n \
    \               }\n                s.add2(u,v,c);\n            };\n          \
    \  work(i,j+1);\n            work(i+1,j);\n        }\n    }\n    auto ans=s.solve().second;\n\
    \    for(int i=0;i<n;i++){\n        for(int j=0;j<n;j++){\n            cout <<\
    \ ans[enc(i,j)]+1 << \" \\n\"[j==n-1];\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - flow/k-ary-optimization.hpp
  - flow/dinic.hpp
  isVerificationFile: false
  path: verify/atcoder/abc347_g.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:09:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/atcoder/abc347_g.cpp
layout: document
redirect_from:
- /library/verify/atcoder/abc347_g.cpp
- /library/verify/atcoder/abc347_g.cpp.html
title: verify/atcoder/abc347_g.cpp
---
