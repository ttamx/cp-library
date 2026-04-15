---
data:
  _extendedDependsOn:
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
    links: []
  bundledCode: "#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
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
    \        return {max_flow,res};\n    }\n};\n\n#line 3 \"verify/kattis/thekingofthenorth.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n\
    \    cin >> n >> m;\n    vector a(n,vector<int>(m));\n    for(int i=0;i<n;i++){\n\
    \        for(int j=0;j<m;j++){\n            cin >> a[i][j];\n        }\n    }\n\
    \    int x,y;\n    cin >> x >> y;\n    Dinic<ll> mf(n*m*2+1,(x*m+y)*2,n*m*2);\n\
    \    for(int i=0;i<n;i++){\n        for(int j=0;j<m;j++){\n            int u=i*m+j;\n\
    \            mf.add_edge(u*2,u*2+1,a[i][j]);\n        }\n    }\n    for(int i=0;i<n;i++){\n\
    \        for(int j=1;j<m;j++){\n            int u=i*m+j-1,v=i*m+j;\n         \
    \   mf.add_edge(u*2+1,v*2,LINF);\n            mf.add_edge(v*2+1,u*2,LINF);\n \
    \       }\n    }\n    for(int i=1;i<n;i++){\n        for(int j=0;j<m;j++){\n \
    \           int u=(i-1)*m+j,v=i*m+j;\n            mf.add_edge(u*2+1,v*2,LINF);\n\
    \            mf.add_edge(v*2+1,u*2,LINF);\n        }\n    }\n    for(int i=0;i<n;i++){\n\
    \        mf.add_edge(i*m*2+1,mf.t,LINF);\n        mf.add_edge((i*m+m-1)*2+1,mf.t,LINF);\n\
    \    }\n    for(int i=1;i<m-1;i++){\n        mf.add_edge(i*2+1,mf.t,LINF);\n \
    \       mf.add_edge(((n-1)*m+i)*2+1,mf.t,LINF);\n    }\n    cout << mf.flow();\n\
    }\n"
  code: "#include \"template.hpp\"\n#include \"flow/dinic.hpp\"\n\nint main(){\n \
    \   cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n    cin >> n >> m;\n\
    \    vector a(n,vector<int>(m));\n    for(int i=0;i<n;i++){\n        for(int j=0;j<m;j++){\n\
    \            cin >> a[i][j];\n        }\n    }\n    int x,y;\n    cin >> x >>\
    \ y;\n    Dinic<ll> mf(n*m*2+1,(x*m+y)*2,n*m*2);\n    for(int i=0;i<n;i++){\n\
    \        for(int j=0;j<m;j++){\n            int u=i*m+j;\n            mf.add_edge(u*2,u*2+1,a[i][j]);\n\
    \        }\n    }\n    for(int i=0;i<n;i++){\n        for(int j=1;j<m;j++){\n\
    \            int u=i*m+j-1,v=i*m+j;\n            mf.add_edge(u*2+1,v*2,LINF);\n\
    \            mf.add_edge(v*2+1,u*2,LINF);\n        }\n    }\n    for(int i=1;i<n;i++){\n\
    \        for(int j=0;j<m;j++){\n            int u=(i-1)*m+j,v=i*m+j;\n       \
    \     mf.add_edge(u*2+1,v*2,LINF);\n            mf.add_edge(v*2+1,u*2,LINF);\n\
    \        }\n    }\n    for(int i=0;i<n;i++){\n        mf.add_edge(i*m*2+1,mf.t,LINF);\n\
    \        mf.add_edge((i*m+m-1)*2+1,mf.t,LINF);\n    }\n    for(int i=1;i<m-1;i++){\n\
    \        mf.add_edge(i*2+1,mf.t,LINF);\n        mf.add_edge(((n-1)*m+i)*2+1,mf.t,LINF);\n\
    \    }\n    cout << mf.flow();\n}"
  dependsOn:
  - template.hpp
  - flow/dinic.hpp
  isVerificationFile: false
  path: verify/kattis/thekingofthenorth.cpp
  requiredBy: []
  timestamp: '2026-04-15 17:32:38+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/kattis/thekingofthenorth.cpp
layout: document
redirect_from:
- /library/verify/kattis/thekingofthenorth.cpp
- /library/verify/kattis/thekingofthenorth.cpp.html
title: verify/kattis/thekingofthenorth.cpp
---
