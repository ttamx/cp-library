---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/max-plus-convolution.hpp
    title: convolution/max-plus-convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "#line 1 \"verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"convolution/max-plus-convolution.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-09-01\n * Description: Max Plus Convolution.\
    \ Find $C[k] = max_{i+j=k}\\{A[i] + B[j]\\}$.\n * Time: $O(N)$.\n */\n\n// SMAWCK\
    \ algorithm for finding row-wise maxima.\n// f(i,j,k) checks if M[i][j] <= M[i][k].\n\
    // f(i,j,k) checks if M[i][k] is at least as good as M[i][j].\n// higher is better.\n\
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
    \    }\n    return ans;\n}\n\n#line 4 \"verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n\
    \    cin >> n >> m;\n    vector<int> a(n),b(m);\n    for(auto &x:a){\n       \
    \ cin >> x;\n        x*=-1;\n    }\n    for(auto &x:b){\n        cin >> x;\n \
    \       x*=-1;\n    }\n    auto c=max_plus_convolution_arbitary_convex(b,a);\n\
    \    for(auto x:c){\n        cout << -x << \" \";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#include \"template.hpp\"\n#include \"convolution/max-plus-convolution.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n\
    \    cin >> n >> m;\n    vector<int> a(n),b(m);\n    for(auto &x:a){\n       \
    \ cin >> x;\n        x*=-1;\n    }\n    for(auto &x:b){\n        cin >> x;\n \
    \       x*=-1;\n    }\n    auto c=max_plus_convolution_arbitary_convex(b,a);\n\
    \    for(auto x:c){\n        cout << -x << \" \";\n    }\n}"
  dependsOn:
  - template.hpp
  - convolution/max-plus-convolution.hpp
  isVerificationFile: true
  path: verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp
- /verify/verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp.html
title: verify/yosupo/convolution/min_plus_convolution_convex_arbitrary.test.cpp
---
