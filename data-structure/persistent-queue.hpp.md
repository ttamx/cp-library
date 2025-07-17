---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/persistent_queue.test.cpp
    title: verify/yosupo/data-structure/persistent_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent-queue.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-06-28\n * Description: Persistent Queue.\n */\n\ntemplate<class\
    \ T>\nstruct PersistentQueue{\n    int n,lg;\n    vector<T> dat;\n    vector<int>\
    \ back_id,len;\n    vector<vector<int>> par;\n    PersistentQueue():n(1),lg(1),dat(0),back_id(0),len(0),par(1,{0}){}\n\
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
    \    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-28\n * Description:\
    \ Persistent Queue.\n */\n\ntemplate<class T>\nstruct PersistentQueue{\n    int\
    \ n,lg;\n    vector<T> dat;\n    vector<int> back_id,len;\n    vector<vector<int>>\
    \ par;\n    PersistentQueue():n(1),lg(1),dat(0),back_id(0),len(0),par(1,{0}){}\n\
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
    \    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent-queue.hpp
  requiredBy: []
  timestamp: '2024-07-29 18:44:45+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/data-structure/persistent_queue.test.cpp
documentation_of: data-structure/persistent-queue.hpp
layout: document
redirect_from:
- /library/data-structure/persistent-queue.hpp
- /library/data-structure/persistent-queue.hpp.html
title: data-structure/persistent-queue.hpp
---
