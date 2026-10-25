---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/general-matching.hpp
    title: flow/general-matching.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#line 1 \"verify/yosupo/flow/general-matching/general_matching.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
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
    }\n#line 2 \"flow/general-matching.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2025-09-03\n * Description: General matching using blossom algorithm.\n * Time:\
    \ O(E V \\alpha(V)).\n */\n\ntemplate<int N>\nstruct GeneralMatching{\n\nint n,m;\n\
    vector<int> adj[N+1];\nint fa[N+1],link[N+1],match[N+1],vis[N+1],dep[N+1];\nqueue<int>\
    \ q;\n\nint find(int u){\n    while(fa[u]!=u)u=fa[u]=fa[fa[u]];\n    return u;\n\
    }\nint get_lca(int u,int v){\n    u=find(u),v=find(v);\n    while(u!=v){\n   \
    \     if(dep[u]<dep[v])swap(u,v);\n        u=find(link[match[u]]);\n    }\n  \
    \  return u;\n}\nvoid blossom(int u,int v,int lca){\n    while(find(u)!=lca){\n\
    \        link[u]=v;\n        v=match[u];\n        if(vis[v]==0){\n           \
    \ vis[v]=1;\n            q.emplace(v);\n        }\n        fa[u]=fa[v]=lca;\n\
    \        u=link[v];\n    }\n}\nbool augment(int st){\n    for(int i=1;i<=n;i++)fa[i]=i;\n\
    \    for(int i=1;i<=n;i++)vis[i]=-1;\n    vis[st]=1;\n    dep[st]=0;\n    q=queue<int>();\n\
    \    q.emplace(st);\n    while(!q.empty()){\n        int u=q.front();\n      \
    \  q.pop();\n        for(auto v:adj[u]){\n            if(vis[v]==-1){\n      \
    \          vis[v]=0;\n                link[v]=u;\n                dep[v]=dep[u]+1;\n\
    \                if(!match[v]){\n                    for(int x=v,y=u,z;y;y=link[x=z]){\n\
    \                        z=match[y];\n                        match[x]=y;\n  \
    \                      match[y]=x;\n                    }\n                  \
    \  return 1;\n                }\n                vis[match[v]]=1;\n          \
    \      dep[match[v]]=dep[u]+2;\n                q.emplace(match[v]);\n       \
    \     }else if(vis[v]==1&&find(u)!=find(v)){\n                int lca=get_lca(u,v);\n\
    \                blossom(u,v,lca);\n                blossom(v,u,lca);\n      \
    \      }\n        }\n    }\n    return 0;\n}\nint solve(){\n    int ans=0;\n \
    \   for(int u=1;u<=n;u++)if(!match[u]){\n        for(auto v:adj[u])if(!match[v]){\n\
    \            match[u]=v;\n            match[v]=u;\n            ans++;\n      \
    \      break;\n        }\n    }\n    for(int u=1;u<=n;u++)if(!match[u])ans+=augment(u);\n\
    \    return ans;\n}\nvoid init(int _n){\n    n=_n;\n    for(int i=1;i<=n;i++)match[i]=0;\n\
    \    for(int i=1;i<=n;i++)adj[i].clear();\n}\nvoid add_edge(int u,int v){\n  \
    \  adj[u].emplace_back(v);\n    adj[v].emplace_back(u);\n}\n\n};\n#line 4 \"verify/yosupo/flow/general-matching/general_matching.test.cpp\"\
    \n\nGeneralMatching<500> gm;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,m;\n    cin >> n >> m;\n    gm.init(n);\n    for(int i=0;i<m;i++){\n\
    \        int u,v,w;\n        cin >> u >> v;\n        u++,v++;\n        gm.add_edge(u,v);\n\
    \    }\n    cout << gm.solve() << \"\\n\";\n    for(int i=1;i<=n;i++){\n     \
    \   if(gm.match[i]>i){\n            cout << i-1 << \" \" << gm.match[i]-1 << \"\
    \\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#include\
    \ \"template.hpp\"\n#include \"flow/general-matching.hpp\"\n\nGeneralMatching<500>\
    \ gm;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n\
    \    cin >> n >> m;\n    gm.init(n);\n    for(int i=0;i<m;i++){\n        int u,v,w;\n\
    \        cin >> u >> v;\n        u++,v++;\n        gm.add_edge(u,v);\n    }\n\
    \    cout << gm.solve() << \"\\n\";\n    for(int i=1;i<=n;i++){\n        if(gm.match[i]>i){\n\
    \            cout << i-1 << \" \" << gm.match[i]-1 << \"\\n\";\n        }\n  \
    \  }\n}"
  dependsOn:
  - template.hpp
  - flow/general-matching.hpp
  isVerificationFile: true
  path: verify/yosupo/flow/general-matching/general_matching.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 14:43:57+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/flow/general-matching/general_matching.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/flow/general-matching/general_matching.test.cpp
- /verify/verify/yosupo/flow/general-matching/general_matching.test.cpp.html
title: verify/yosupo/flow/general-matching/general_matching.test.cpp
---
