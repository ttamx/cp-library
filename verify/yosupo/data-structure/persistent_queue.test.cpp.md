---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent-queue.hpp
    title: data-structure/persistent-queue.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"verify/yosupo/data-structure/persistent_queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n#define\
    \ RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
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
    \ 2 \"data-structure/persistent-queue.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-06-28\n * Description: Persistent Queue.\n */\n\ntemplate<class T>\nstruct\
    \ PersistentQueue{\n    int n,lg;\n    vector<T> dat;\n    vector<int> back_id,len;\n\
    \    vector<vector<int>> par;\n    PersistentQueue():n(1),lg(1),dat(0),back_id(0),len(0),par(1,{0}){}\n\
    \    void calc_par(){\n        if(n<(1<<lg))return;\n        for(int i=0;i<n;i++)par[i].emplace_back(par[par[i][lg-1]][lg-1]);\n\
    \        lg++;\n    }\n    int push(int t,const T &val){\n        dat.emplace_back(val);\n\
    \        back_id.emplace_back(n);\n        len.emplace_back((t==-1?0:len[t])+1);\n\
    \        par.emplace_back(vector<int>(lg,0));\n        par[n][0]=t==-1?0:back_id[t];\n\
    \        for(int i=1;i<lg;i++)par[n][i]=par[par[n][i-1]][i-1];\n        n++;\n\
    \        calc_par();\n        return back_id.size()-1;\n    }\n    int pop(int\
    \ t){\n        back_id.emplace_back(back_id[t]);\n        len.emplace_back(len[t]-1);\n\
    \        return back_id.size()-1;\n    }\n    T front(int t){\n        int d=size(t)-1;\n\
    \        int x=back_id[t];\n        for(int j=lg-1;j>=0;j--)if(d>>j&1)x=par[x][j];\n\
    \        return dat[x-1];\n    }\n    int size(int t){\n        return len[t];\n\
    \    }\n};\n\n#line 4 \"verify/yosupo/data-structure/persistent_queue.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n \
    \   cin >> n;\n    PersistentQueue<int> q;\n    for(int i=0;i<n;i++){\n      \
    \  int op,t;\n        cin >> op >> t;\n        if(op==0){\n            int x;\n\
    \            cin >> x;\n            q.push(t,x);\n        }else{\n           \
    \ cout << q.front(t) << \"\\n\";\n            q.pop(t);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#include\
    \ \"template.hpp\"\n#include \"data-structure/persistent-queue.hpp\"\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    cin >> n;\n  \
    \  PersistentQueue<int> q;\n    for(int i=0;i<n;i++){\n        int op,t;\n   \
    \     cin >> op >> t;\n        if(op==0){\n            int x;\n            cin\
    \ >> x;\n            q.push(t,x);\n        }else{\n            cout << q.front(t)\
    \ << \"\\n\";\n            q.pop(t);\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/persistent-queue.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/persistent_queue.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 22:12:04+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/persistent_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/persistent_queue.test.cpp
- /verify/verify/yosupo/data-structure/persistent_queue.test.cpp.html
title: verify/yosupo/data-structure/persistent_queue.test.cpp
---
