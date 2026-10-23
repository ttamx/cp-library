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
  bundledCode: "#line 1 \"verify/yosupo/convolution/max-plus-convolution/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
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
    \ 2 \"convolution/max-plus-convolution.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-09-01\n * Description: Max Plus Convolution. Find $C[k] = max_{i+j=k}\\\
    {A[i] + B[j]\\}$.\n * Time: $O(N)$.\n */\n\n// SMAWCK algorithm for finding row-wise\
    \ maxima.\n// f(i,j,k) checks if M[i][j] <= M[i][k].\n// f(i,j,k) checks if M[i][k]\
    \ is at least as good as M[i][j].\n// higher is better.\ntemplate<class F>\nvector<int>\
    \ smawck(const F &f,const vector<int> &rows,const vector<int> &cols){\n    int\
    \ n=(int)rows.size(),m=(int)cols.size();\n    if(max(n,m)<=2){\n        vector<int>\
    \ ans(n,-1);\n        for(int i=0;i<n;i++){\n            for(int j:cols){\n  \
    \              if(ans[i]==-1||f(rows[i],ans[i],j)){\n                    ans[i]=j;\n\
    \                }\n            }\n        }\n        return ans;\n    }\n   \
    \ if(n<m){\n        // reduce\n        vector<int> st;\n        for(int j:cols){\n\
    \            while(true){\n                if(st.empty()){\n                 \
    \   st.emplace_back(j);\n                    break;\n                }else if(f(rows[(int)st.size()-1],st.back(),j)){\n\
    \                    st.pop_back();\n                }else if(st.size()<n){\n\
    \                    st.emplace_back(j);\n                    break;\n       \
    \         }else{\n                    break;\n                }\n            }\n\
    \        }\n        return smawck(f,rows,st);\n    }   \n    vector<int> ans(n,-1);\n\
    \    vector<int> new_rows;\n    for(int i=1;i<n;i+=2){\n        new_rows.emplace_back(rows[i]);\n\
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
    \    }\n    return ans;\n}\n\n#line 4 \"verify/yosupo/convolution/max-plus-convolution/min_plus_convolution_convex_arbitrary.test.cpp\"\
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
  path: verify/yosupo/convolution/max-plus-convolution/min_plus_convolution_convex_arbitrary.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/convolution/max-plus-convolution/min_plus_convolution_convex_arbitrary.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/convolution/max-plus-convolution/min_plus_convolution_convex_arbitrary.test.cpp
- /verify/verify/yosupo/convolution/max-plus-convolution/min_plus_convolution_convex_arbitrary.test.cpp.html
title: verify/yosupo/convolution/max-plus-convolution/min_plus_convolution_convex_arbitrary.test.cpp
---
