---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/yosupo/graph/assignment.cpp
    title: verify/yosupo/graph/assignment.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/graph/general_weighted_matching.test.cpp
    title: verify/yosupo/graph/general_weighted_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
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
    \ 3 \"flow/general-weighted-matching.hpp\"\n\n/**\n * Description: General weighted\
    \ matching using blossom algorithm.\n * Time: O(|V|^3) \\text{(fast in practice)}\n\
    \ */\n\ntemplate<int N,class T>\nstruct GeneralWeightedMatching{\nstatic const\
    \ T INF=numeric_limits<T>::max();\nstruct Edge{\n  int u,v;\n  T w;\n  Edge(){}\n\
    \  Edge(int u,int v,T w):u(u),v(v),w(w){}\n};\nint n,n_x;\nEdge g[N*2][N*2];\n\
    T lab[N*2];\nint match[N*2],slack[N*2],st[N*2],pa[N*2];\nint flo_from[N*2][N+1],S[N*2],vis[N*2];\n\
    vector<int> flo[N*2];\nqueue<int> q;\nT e_delta(const Edge &e){return lab[e.u]+lab[e.v]-g[e.u][e.v].w*2;}\n\
    void update_slack(int u,int x){\n  if(!slack[x]||e_delta(g[u][x])<e_delta(g[slack[x]][x]))slack[x]=u;\n\
    }\nvoid set_slack(int x){\n  slack[x]=0;\n  for(int u=1;u<=n;u++)\n    if(g[u][x].w>0&&st[u]!=x&&S[st[u]]==0)update_slack(u,x);\n\
    }\nvoid q_push(int x){\n  if(x<=n)q.push(x);\n  else for(auto xs:flo[x])q_push(xs);\n\
    }\nvoid set_st(int x,int b){\n  st[x]=b;\n  if(x>n)for(auto xs:flo[x])set_st(xs,b);\n\
    }\nint get_pr(int b,int xr){\n  int pr=find(ALL(flo[b]),xr)-flo[b].begin();\n\
    \  if(pr&1){reverse(1+ALL(flo[b]));return SZ(flo[b])-pr;}\n  return pr;\n}\nvoid\
    \ set_match(int u,int v){\n  Edge e=g[u][v];match[u]=g[u][v].v;if(u<=n)return;\n\
    \  int xr=flo_from[u][e.u],pr=get_pr(u,xr);\n  for(int i=0;i<pr;i++)set_match(flo[u][i],flo[u][i^1]);\n\
    \  set_match(xr,v);rotate(flo[u].begin(),pr+ALL(flo[u]));\n}\nvoid augment(int\
    \ u,int v){\n  while(true){\n    int xnv=st[match[u]];set_match(u,v);\n    if(!xnv)return;\n\
    \    set_match(xnv,st[pa[xnv]]);u=st[pa[xnv]];v=xnv;\n  }\n}\nint get_lca(int\
    \ u,int v){\n  static int t=0;\n  for(++t;u||v;swap(u,v)){\n    if(u==0)continue;\n\
    \    if(vis[u]==t)return u;\n    vis[u]=t;u=st[match[u]];\n    if(u)u=st[pa[u]];\n\
    \  }\n  return 0;\n}\nvoid add_blossom(int u,int lca,int v){\n  int b=n+1;while(b<=n_x&&st[b])++b;\n\
    \  if(b>n_x)++n_x; //new blossom;\n  lab[b]=0;S[b]=0;match[b]=match[lca];flo[b]=vector<int>{lca};\n\
    \  for(int x=u,y;x!=lca;x=st[pa[y]])\n    flo[b].eb(x),flo[b].eb(y=st[match[x]]),q_push(y);\n\
    \  reverse(1+ALL(flo[b]));\n  for(int x=v,y;x!=lca;x=st[pa[y]])\n    flo[b].eb(x),flo[b].eb(y=st[match[x]]),q_push(y);\n\
    \  set_st(b,b);\n  for(int x=1;x<=n_x;x++)g[b][x].w=g[x][b].w=0;\n  for(int x=1;x<=n;x++)flo_from[b][x]=0;\n\
    \  for(auto xs:flo[b]){\n    for(int x=1;x<=n_x;x++)\n      if(g[b][x].w==0||e_delta(g[xs][x])<e_delta(g[b][x]))\n\
    \        g[b][x]=g[xs][x],g[x][b]=g[x][xs];\n    for(int x=1;x<=n;x++)if(flo_from[xs][x])flo_from[b][x]=xs;\n\
    \  }\n  set_slack(b);\n}\nvoid expand_blossom(int b){\n  for(auto xs:flo[b])set_st(xs,xs);\n\
    \  int xr=flo_from[b][g[b][pa[b]].u],pr=get_pr(b,xr);\n  for(int i=0;i<pr;i+=2){\n\
    \    int xs=flo[b][i],xns=flo[b][i+1];\n    pa[xs]=g[xns][xs].u;S[xs]=1;S[xns]=0;\n\
    \    slack[xs]=0,set_slack(xns);q_push(xns);\n  }\n  S[xr]=1,pa[xr]=pa[b];\n \
    \ for(int i=pr+1;i<SZ(flo[b]);i++)S[flo[b][i]]=-1,set_slack(flo[b][i]);\n  st[b]=0;\n\
    }\nbool on_found_edge(const Edge &e){\n  int u=st[e.u],v=st[e.v];\n  if(S[v]==-1){\n\
    \    pa[v]=e.u;S[v]=1;\n    int nu=st[match[v]];\n    slack[v]=slack[nu]=S[nu]=0;q_push(nu);\n\
    \  }else if(S[v]==0){\n    int lca=get_lca(u,v);\n    if(!lca)return augment(u,v),augment(v,u),true;\n\
    \    add_blossom(u,lca,v);\n  }\n  return false;\n}\nbool matching(){\n  for(int\
    \ i=1;i<=n_x;i++)S[i]=-1;\n  for(int i=1;i<=n_x;i++)slack[i]=-0;\n  q=queue<int>();\n\
    \  for(int x=1;x<=n_x;x++)if(st[x]==x&&!match[x])pa[x]=S[x]=0,q_push(x);\n  if(q.empty())return\
    \ false;\n  while(true){\n    while(!q.empty()){\n      int u=q.front();q.pop();if(S[st[u]]==1)continue;\n\
    \      for(int v=1;v<=n;v++)if(g[u][v].w>0&&st[u]!=st[v]){\n        if(e_delta(g[u][v])==0){if(on_found_edge(g[u][v]))return\
    \ true;}\n        else update_slack(u,st[v]);\n      }\n    }\n    T d=INF;\n\
    \    for(int b=n+1;b<=n_x;b++)if(st[b]==b&&S[b]==1)d=min(d,lab[b]/2);\n    for(int\
    \ x=1;x<=n_x;x++)if(st[x]==x&&slack[x]){\n      if(S[x]==-1)d=min(d,e_delta(g[slack[x]][x]));\n\
    \      else if(S[x]==0)d=min(d,e_delta(g[slack[x]][x])/2);\n    }\n    for(int\
    \ u=1;u<=n;u++){\n      if(S[st[u]]==0){if(lab[u]<=d)return 0;lab[u]-=d;}\n  \
    \    else if(S[st[u]]==1)lab[u]+=d;\n    }\n    for(int b=n+1;b<=n_x;b++)if(st[b]==b){\n\
    \      if(S[st[b]]==0)lab[b]+=d*2;\n      else if(S[st[b]]==1)lab[b]-=d*2;\n \
    \   }\n    q=queue<int>();\n    for(int x=1;x<=n_x;x++)\n      if(st[x]==x&&slack[x]&&st[slack[x]]!=x&&e_delta(g[slack[x]][x])==0)\n\
    \        if(on_found_edge(g[slack[x]][x]))return true;\n    for(int b=n+1;b<=n_x;b++)\n\
    \      if(st[b]==b&&S[b]==1&&lab[b]==0)expand_blossom(b);\n  }\n  return false;\n\
    }\npair<T,int> solve(){\n  for(int i=1;i<=n;i++)match[i]=0;\n  n_x=n;int n_matches=0;T\
    \ w_max=0,tot_weight=0;\n  for(int u=0;u<=n;u++)st[u]=u,flo[u].clear();\n  for(int\
    \ u=1;u<=n;u++)for(int v=1;v<=n;v++)\n    flo_from[u][v]=u==v?u:0,w_max=max(w_max,g[u][v].w);\n\
    \  for(int u=1;u<=n;u++)lab[u]=w_max;\n  while(matching())++n_matches;\n  for(int\
    \ u=1;u<=n;u++)if(match[u]&&match[u]<u)tot_weight+=g[u][match[u]].w;\n  return\
    \ make_pair(tot_weight,n_matches);\n}\nvoid add_edge(int u,int v,T w){\n  if(w<=g[u][v].w)return;\n\
    \  g[u][v].w=g[v][u].w=w;\n}\nvoid init(int _n){\n  n=_n;\n  for(int u=1;u<=n;u++)for(int\
    \ v=1;v<=n;v++)g[u][v]=Edge(u,v,T(0));\n}\n\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n\n/**\n * Description: General weighted\
    \ matching using blossom algorithm.\n * Time: O(|V|^3) \\text{(fast in practice)}\n\
    \ */\n\ntemplate<int N,class T>\nstruct GeneralWeightedMatching{\nstatic const\
    \ T INF=numeric_limits<T>::max();\nstruct Edge{\n  int u,v;\n  T w;\n  Edge(){}\n\
    \  Edge(int u,int v,T w):u(u),v(v),w(w){}\n};\nint n,n_x;\nEdge g[N*2][N*2];\n\
    T lab[N*2];\nint match[N*2],slack[N*2],st[N*2],pa[N*2];\nint flo_from[N*2][N+1],S[N*2],vis[N*2];\n\
    vector<int> flo[N*2];\nqueue<int> q;\nT e_delta(const Edge &e){return lab[e.u]+lab[e.v]-g[e.u][e.v].w*2;}\n\
    void update_slack(int u,int x){\n  if(!slack[x]||e_delta(g[u][x])<e_delta(g[slack[x]][x]))slack[x]=u;\n\
    }\nvoid set_slack(int x){\n  slack[x]=0;\n  for(int u=1;u<=n;u++)\n    if(g[u][x].w>0&&st[u]!=x&&S[st[u]]==0)update_slack(u,x);\n\
    }\nvoid q_push(int x){\n  if(x<=n)q.push(x);\n  else for(auto xs:flo[x])q_push(xs);\n\
    }\nvoid set_st(int x,int b){\n  st[x]=b;\n  if(x>n)for(auto xs:flo[x])set_st(xs,b);\n\
    }\nint get_pr(int b,int xr){\n  int pr=find(ALL(flo[b]),xr)-flo[b].begin();\n\
    \  if(pr&1){reverse(1+ALL(flo[b]));return SZ(flo[b])-pr;}\n  return pr;\n}\nvoid\
    \ set_match(int u,int v){\n  Edge e=g[u][v];match[u]=g[u][v].v;if(u<=n)return;\n\
    \  int xr=flo_from[u][e.u],pr=get_pr(u,xr);\n  for(int i=0;i<pr;i++)set_match(flo[u][i],flo[u][i^1]);\n\
    \  set_match(xr,v);rotate(flo[u].begin(),pr+ALL(flo[u]));\n}\nvoid augment(int\
    \ u,int v){\n  while(true){\n    int xnv=st[match[u]];set_match(u,v);\n    if(!xnv)return;\n\
    \    set_match(xnv,st[pa[xnv]]);u=st[pa[xnv]];v=xnv;\n  }\n}\nint get_lca(int\
    \ u,int v){\n  static int t=0;\n  for(++t;u||v;swap(u,v)){\n    if(u==0)continue;\n\
    \    if(vis[u]==t)return u;\n    vis[u]=t;u=st[match[u]];\n    if(u)u=st[pa[u]];\n\
    \  }\n  return 0;\n}\nvoid add_blossom(int u,int lca,int v){\n  int b=n+1;while(b<=n_x&&st[b])++b;\n\
    \  if(b>n_x)++n_x; //new blossom;\n  lab[b]=0;S[b]=0;match[b]=match[lca];flo[b]=vector<int>{lca};\n\
    \  for(int x=u,y;x!=lca;x=st[pa[y]])\n    flo[b].eb(x),flo[b].eb(y=st[match[x]]),q_push(y);\n\
    \  reverse(1+ALL(flo[b]));\n  for(int x=v,y;x!=lca;x=st[pa[y]])\n    flo[b].eb(x),flo[b].eb(y=st[match[x]]),q_push(y);\n\
    \  set_st(b,b);\n  for(int x=1;x<=n_x;x++)g[b][x].w=g[x][b].w=0;\n  for(int x=1;x<=n;x++)flo_from[b][x]=0;\n\
    \  for(auto xs:flo[b]){\n    for(int x=1;x<=n_x;x++)\n      if(g[b][x].w==0||e_delta(g[xs][x])<e_delta(g[b][x]))\n\
    \        g[b][x]=g[xs][x],g[x][b]=g[x][xs];\n    for(int x=1;x<=n;x++)if(flo_from[xs][x])flo_from[b][x]=xs;\n\
    \  }\n  set_slack(b);\n}\nvoid expand_blossom(int b){\n  for(auto xs:flo[b])set_st(xs,xs);\n\
    \  int xr=flo_from[b][g[b][pa[b]].u],pr=get_pr(b,xr);\n  for(int i=0;i<pr;i+=2){\n\
    \    int xs=flo[b][i],xns=flo[b][i+1];\n    pa[xs]=g[xns][xs].u;S[xs]=1;S[xns]=0;\n\
    \    slack[xs]=0,set_slack(xns);q_push(xns);\n  }\n  S[xr]=1,pa[xr]=pa[b];\n \
    \ for(int i=pr+1;i<SZ(flo[b]);i++)S[flo[b][i]]=-1,set_slack(flo[b][i]);\n  st[b]=0;\n\
    }\nbool on_found_edge(const Edge &e){\n  int u=st[e.u],v=st[e.v];\n  if(S[v]==-1){\n\
    \    pa[v]=e.u;S[v]=1;\n    int nu=st[match[v]];\n    slack[v]=slack[nu]=S[nu]=0;q_push(nu);\n\
    \  }else if(S[v]==0){\n    int lca=get_lca(u,v);\n    if(!lca)return augment(u,v),augment(v,u),true;\n\
    \    add_blossom(u,lca,v);\n  }\n  return false;\n}\nbool matching(){\n  for(int\
    \ i=1;i<=n_x;i++)S[i]=-1;\n  for(int i=1;i<=n_x;i++)slack[i]=-0;\n  q=queue<int>();\n\
    \  for(int x=1;x<=n_x;x++)if(st[x]==x&&!match[x])pa[x]=S[x]=0,q_push(x);\n  if(q.empty())return\
    \ false;\n  while(true){\n    while(!q.empty()){\n      int u=q.front();q.pop();if(S[st[u]]==1)continue;\n\
    \      for(int v=1;v<=n;v++)if(g[u][v].w>0&&st[u]!=st[v]){\n        if(e_delta(g[u][v])==0){if(on_found_edge(g[u][v]))return\
    \ true;}\n        else update_slack(u,st[v]);\n      }\n    }\n    T d=INF;\n\
    \    for(int b=n+1;b<=n_x;b++)if(st[b]==b&&S[b]==1)d=min(d,lab[b]/2);\n    for(int\
    \ x=1;x<=n_x;x++)if(st[x]==x&&slack[x]){\n      if(S[x]==-1)d=min(d,e_delta(g[slack[x]][x]));\n\
    \      else if(S[x]==0)d=min(d,e_delta(g[slack[x]][x])/2);\n    }\n    for(int\
    \ u=1;u<=n;u++){\n      if(S[st[u]]==0){if(lab[u]<=d)return 0;lab[u]-=d;}\n  \
    \    else if(S[st[u]]==1)lab[u]+=d;\n    }\n    for(int b=n+1;b<=n_x;b++)if(st[b]==b){\n\
    \      if(S[st[b]]==0)lab[b]+=d*2;\n      else if(S[st[b]]==1)lab[b]-=d*2;\n \
    \   }\n    q=queue<int>();\n    for(int x=1;x<=n_x;x++)\n      if(st[x]==x&&slack[x]&&st[slack[x]]!=x&&e_delta(g[slack[x]][x])==0)\n\
    \        if(on_found_edge(g[slack[x]][x]))return true;\n    for(int b=n+1;b<=n_x;b++)\n\
    \      if(st[b]==b&&S[b]==1&&lab[b]==0)expand_blossom(b);\n  }\n  return false;\n\
    }\npair<T,int> solve(){\n  for(int i=1;i<=n;i++)match[i]=0;\n  n_x=n;int n_matches=0;T\
    \ w_max=0,tot_weight=0;\n  for(int u=0;u<=n;u++)st[u]=u,flo[u].clear();\n  for(int\
    \ u=1;u<=n;u++)for(int v=1;v<=n;v++)\n    flo_from[u][v]=u==v?u:0,w_max=max(w_max,g[u][v].w);\n\
    \  for(int u=1;u<=n;u++)lab[u]=w_max;\n  while(matching())++n_matches;\n  for(int\
    \ u=1;u<=n;u++)if(match[u]&&match[u]<u)tot_weight+=g[u][match[u]].w;\n  return\
    \ make_pair(tot_weight,n_matches);\n}\nvoid add_edge(int u,int v,T w){\n  if(w<=g[u][v].w)return;\n\
    \  g[u][v].w=g[v][u].w=w;\n}\nvoid init(int _n){\n  n=_n;\n  for(int u=1;u<=n;u++)for(int\
    \ v=1;v<=n;v++)g[u][v]=Edge(u,v,T(0));\n}\n\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: flow/general-weighted-matching.hpp
  requiredBy:
  - verify/yosupo/graph/assignment.cpp
  timestamp: '2026-07-22 11:58:01+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/graph/general_weighted_matching.test.cpp
documentation_of: flow/general-weighted-matching.hpp
layout: document
redirect_from:
- /library/flow/general-weighted-matching.hpp
- /library/flow/general-weighted-matching.hpp.html
title: flow/general-weighted-matching.hpp
---
