---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp
    title: verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/max-plus-convolution.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-09-01\n * Description: Max Plus Convolution. Find $C[k]\
    \ = max_{i+j=k}\\{A[i] + B[j]\\}$.\n * Time: $O(N)$.\n */\n\n// SMAWCK algorithm\
    \ for finding row-wise maxima.\n// f(i,j,k) checks if M[i][j] <= M[i][k].\n//\
    \ f(i,j,k) checks if M[i][k] is at least as good as M[i][j].\n// higher is better.\n\
    template<class F>\nvector<int> smawck(const F &f,const vector<int> &rows,const\
    \ vector<int> &cols){\n    int n=(int)rows.size(),m=(int)cols.size();\n    if(max(n,m)<=2){\n\
    \        vector<int> ans(n,-1);\n        for(int i=0;i<n;i++){\n            for(int\
    \ j:cols){\n                if(ans[i]==-1||f(rows[i],ans[i],j)){\n           \
    \         ans[i]=j;\n                }\n            }\n        }\n        return\
    \ ans;\n    }\n    if(n<m){\n        // reduce\n        vector<int> st;\n    \
    \    for(int j:cols){\n            while(true){\n                if(st.empty()){\n\
    \                    st.emplace_back(j);\n                    break;\n       \
    \         }else if(f(rows[(int)st.size()-1],st.back(),j)){\n                 \
    \   st.pop_back();\n                }else if(st.size()<n){\n                 \
    \   st.emplace_back(j);\n                    break;\n                }else{\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     return smawck(f,rows,st);\n    }   \n    vector<int> ans(n,-1);\n    vector<int>\
    \ new_rows;\n    for(int i=1;i<n;i+=2){\n        new_rows.emplace_back(rows[i]);\n\
    \    }\n    auto res=smawck(f,new_rows,cols);\n    for(int i=0;i<new_rows.size();i++){\n\
    \        ans[2*i+1]=res[i];\n    }\n    for(int i=0,l=0,r=0;i<n;i+=2){\n     \
    \   if(i+1==n)r=m;\n        while(r<m&&cols[r]<=ans[i+1])r++;\n        ans[i]=cols[l++];\n\
    \        for(;l<r;l++){\n            if(f(rows[i],ans[i],cols[l])){\n        \
    \        ans[i]=cols[l];\n            }\n        }\n        l--;\n    }\n    return\
    \ ans;\n}\n\ntemplate<class F>\nvector<int> smawck(const F &f,int n,int m){\n\
    \    vector<int> rows(n),cols(m);\n    iota(rows.begin(),rows.end(),0);\n    iota(cols.begin(),cols.end(),0);\n\
    \    return smawck(f,rows,cols);\n}\n\n// Max Plus Convolution.\n// b must be\
    \ convex, i.e. b[i]-b[i-1]>=b[i+1]-b[i].\ntemplate<class T>\nvector<T> max_plus_convolution_arbitary_convex(vector<T>\
    \ a,const vector<T> &b){\n    if(a.empty()||b.empty())return {};\n    if((int)b.size()==1){\n\
    \        for(auto &x:a)x+=b[0];\n        return a;\n    }\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    auto f=[&](int i,int j){\n        return a[j]+b[i-j];\n    };\n    auto cmp=[&](int\
    \ i,int j,int k){\n        if(i<k)return false;\n        if(i-j>=m)return true;\n\
    \        return f(i,j)<=f(i,k);\n    };\n    auto best=smawck(cmp,n+m-1,n);\n\
    \    vector<T> ans(n+m-1);\n    for(int i=0;i<n+m-1;i++){\n        ans[i]=f(i,best[i]);\n\
    \    }\n    return ans;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-09-01\n * Description:\
    \ Max Plus Convolution. Find $C[k] = max_{i+j=k}\\{A[i] + B[j]\\}$.\n * Time:\
    \ $O(N)$.\n */\n\n// SMAWCK algorithm for finding row-wise maxima.\n// f(i,j,k)\
    \ checks if M[i][j] <= M[i][k].\n// f(i,j,k) checks if M[i][k] is at least as\
    \ good as M[i][j].\n// higher is better.\ntemplate<class F>\nvector<int> smawck(const\
    \ F &f,const vector<int> &rows,const vector<int> &cols){\n    int n=(int)rows.size(),m=(int)cols.size();\n\
    \    if(max(n,m)<=2){\n        vector<int> ans(n,-1);\n        for(int i=0;i<n;i++){\n\
    \            for(int j:cols){\n                if(ans[i]==-1||f(rows[i],ans[i],j)){\n\
    \                    ans[i]=j;\n                }\n            }\n        }\n\
    \        return ans;\n    }\n    if(n<m){\n        // reduce\n        vector<int>\
    \ st;\n        for(int j:cols){\n            while(true){\n                if(st.empty()){\n\
    \                    st.emplace_back(j);\n                    break;\n       \
    \         }else if(f(rows[(int)st.size()-1],st.back(),j)){\n                 \
    \   st.pop_back();\n                }else if(st.size()<n){\n                 \
    \   st.emplace_back(j);\n                    break;\n                }else{\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     return smawck(f,rows,st);\n    }   \n    vector<int> ans(n,-1);\n    vector<int>\
    \ new_rows;\n    for(int i=1;i<n;i+=2){\n        new_rows.emplace_back(rows[i]);\n\
    \    }\n    auto res=smawck(f,new_rows,cols);\n    for(int i=0;i<new_rows.size();i++){\n\
    \        ans[2*i+1]=res[i];\n    }\n    for(int i=0,l=0,r=0;i<n;i+=2){\n     \
    \   if(i+1==n)r=m;\n        while(r<m&&cols[r]<=ans[i+1])r++;\n        ans[i]=cols[l++];\n\
    \        for(;l<r;l++){\n            if(f(rows[i],ans[i],cols[l])){\n        \
    \        ans[i]=cols[l];\n            }\n        }\n        l--;\n    }\n    return\
    \ ans;\n}\n\ntemplate<class F>\nvector<int> smawck(const F &f,int n,int m){\n\
    \    vector<int> rows(n),cols(m);\n    iota(rows.begin(),rows.end(),0);\n    iota(cols.begin(),cols.end(),0);\n\
    \    return smawck(f,rows,cols);\n}\n\n// Max Plus Convolution.\n// b must be\
    \ convex, i.e. b[i]-b[i-1]>=b[i+1]-b[i].\ntemplate<class T>\nvector<T> max_plus_convolution_arbitary_convex(vector<T>\
    \ a,const vector<T> &b){\n    if(a.empty()||b.empty())return {};\n    if((int)b.size()==1){\n\
    \        for(auto &x:a)x+=b[0];\n        return a;\n    }\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    auto f=[&](int i,int j){\n        return a[j]+b[i-j];\n    };\n    auto cmp=[&](int\
    \ i,int j,int k){\n        if(i<k)return false;\n        if(i-j>=m)return true;\n\
    \        return f(i,j)<=f(i,k);\n    };\n    auto best=smawck(cmp,n+m-1,n);\n\
    \    vector<T> ans(n+m-1);\n    for(int i=0;i<n+m-1;i++){\n        ans[i]=f(i,best[i]);\n\
    \    }\n    return ans;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/max-plus-convolution.hpp
  requiredBy: []
  timestamp: '2024-09-02 00:35:52+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: convolution/max-plus-convolution.hpp
layout: document
redirect_from:
- /library/convolution/max-plus-convolution.hpp
- /library/convolution/max-plus-convolution.hpp.html
title: convolution/max-plus-convolution.hpp
---
