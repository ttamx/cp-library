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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"data-structure/persistent-queue.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n * Description: Persistent\
    \ Queue.\n */\n\ntemplate<class T>\nstruct PersistentQueue{\n    int n,lg;\n \
    \   vector<T> dat;\n    vector<int> back_id,len;\n    vector<vector<int>> par;\n\
    \    PersistentQueue():n(1),lg(1),dat(0),back_id(0),len(0),par(1,{0}){}\n    void\
    \ calc_par(){\n        if(n<(1<<lg))return;\n        for(int i=0;i<n;i++)par[i].emplace_back(par[par[i][lg-1]][lg-1]);\n\
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
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/persistent_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/persistent_queue.test.cpp
- /verify/verify/yosupo/data-structure/persistent_queue.test.cpp.html
title: verify/yosupo/data-structure/persistent_queue.test.cpp
---
