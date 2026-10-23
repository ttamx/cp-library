---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  - icon: ':question:'
    path: group/monoid/min.hpp
    title: group/monoid/min.hpp
  - icon: ':x:'
    path: string/suffix-array.hpp
    title: string/suffix-array.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/yosupo/string/suffix-array/suffixarray.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#line 2 \"\
    template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing ll =\
    \ long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
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
    \ 2 \"data-structure/sparse-table.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-06-12\n * Description: Sparse Table class.\n */\n\ntemplate<class Monoid>\n\
    struct SparseTable{\n    using T = typename Monoid::value_type;\n    int n;\n\
    \    vector<vector<T>> t;\n    SparseTable(){}\n    SparseTable(const vector<T>\
    \ &a){init(a);}\n    void init(const vector<T> &a){\n        n=(int)a.size();\n\
    \        int lg=31-__builtin_clz(n);\n        t.assign(lg+1,vector<T>(n,Monoid::unit()));\n\
    \        t[0]=a;\n        for(int i=0;i<lg;i++){\n            for(int j=0;j+(2<<i)<=n;j++){\n\
    \                t[i+1][j]=Monoid::op(t[i][j],t[i][j+(1<<i)]);\n            }\n\
    \        }\n    }\n    T query(int l,int r){\n        int lg=31-__builtin_clz(r-l+1);\n\
    \        return Monoid::op(t[lg][l],t[lg][r-(1<<lg)+1]);\n    }\n};\n\n#line 2\
    \ \"group/monoid/min.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n\
    \ * Description: Min Monoid class.\n */\n\ntemplate<class T>\nstruct MinMonoid{\n\
    \    using value_type = T;\n    static constexpr T op(const T &x,const T &y){return\
    \ min(x,y);}\n    static constexpr T unit(){return numeric_limits<T>::max();}\n\
    };\n\n#line 4 \"string/suffix-array.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-06-14\n * Description: Suffix Array.\n */\n\ntemplate<class STR>\nstruct\
    \ SuffixArray{\n    int n;\n    vector<int> sa,isa,lcp;\n    SparseTable<MinMonoid<int>>\
    \ st;\n    SuffixArray(){}\n    SuffixArray(const STR &s){init(s);}\n    void\
    \ init(const STR &s){\n        n=(int)s.size();\n        sa=isa=lcp=vector<int>(n+1);\n\
    \        sa[0]=n;\n        iota(sa.begin()+1,sa.end(),0);\n        sort(sa.begin()+1,sa.end(),[&](int\
    \ i,int j){return s[i]<s[j];});\n        for(int i=1;i<=n;i++){\n            int\
    \ x=sa[i-1],y=sa[i];\n            isa[y]=i>1&&s[x]==s[y]?isa[x]:i;\n        }\n\
    \        for(int len=1;len<=n;len<<=1){\n            vector<int> ps(sa),pi(isa),pos(n+1);\n\
    \            iota(pos.begin(),pos.end(),0);\n            for(auto i:ps)if((i-=len)>=0)sa[pos[isa[i]]++]=i;\n\
    \            for(int i=1;i<=n;i++){\n                int x=sa[i-1],y=sa[i];\n\
    \                isa[y]=pi[x]==pi[y]&&pi[x+len]==pi[y+len]?isa[x]:i;\n       \
    \     }\n        }\n        for(int i=0,k=0;i<n;i++){\n            for(int j=sa[isa[i]-1];j+k<n&&s[j+k]==s[i+k];k++);\n\
    \            lcp[isa[i]]=k;\n            if(k)k--;\n        }\n        st.init(lcp);\n\
    \    }\n    int get_lcp(int i,int j){\n        if(i==j)return n-i;\n        auto\
    \ [l,r]=minmax(isa[i],isa[j]);\n        return st.query(l+1,r);\n    }\n};\n\n\
    #line 4 \"verify/yosupo/string/suffix-array/suffixarray.test.cpp\"\n\nint main(){\n\
    \    string s;\n    cin >> s;\n    SuffixArray sa(s);\n    for(int i=1;i<=s.size();++i)cout\
    \ << sa.sa[i] << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#include\
    \ \"template.hpp\"\n#include \"string/suffix-array.hpp\"\n\nint main(){\n    string\
    \ s;\n    cin >> s;\n    SuffixArray sa(s);\n    for(int i=1;i<=s.size();++i)cout\
    \ << sa.sa[i] << \" \";\n}"
  dependsOn:
  - template.hpp
  - string/suffix-array.hpp
  - data-structure/sparse-table.hpp
  - group/monoid/min.hpp
  isVerificationFile: true
  path: verify/yosupo/string/suffix-array/suffixarray.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/string/suffix-array/suffixarray.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/string/suffix-array/suffixarray.test.cpp
- /verify/verify/yosupo/string/suffix-array/suffixarray.test.cpp.html
title: verify/yosupo/string/suffix-array/suffixarray.test.cpp
---
