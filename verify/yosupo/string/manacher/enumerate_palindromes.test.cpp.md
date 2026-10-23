---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/manacher.hpp
    title: string/manacher.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/yosupo/string/manacher/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\
    #line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
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
    \ 2 \"string/manacher.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n\
    \ * Description: Manacher's Algorithm. pal[i] := the length of the longest palindrome\
    \ centered at i/2.\n */\n\ntemplate<class STR>\nvector<int> manacher(const STR\
    \ &s){\n    int n=(int)s.size();\n    if(n==0)return {};\n    vector<int> pal(2*n-1);\n\
    \    for(int p=0,l=-1,r=-1;p<2*n-1;p++){\n        int i=(p+1)>>1,j=p>>1;\n   \
    \     int k=(i>=r?0:min(r-i,pal[2*(l+r)-p]));\n        while(j+k+1<n&&i-k-1>=0&&s[j+k+1]==s[i-k-1])k++;\n\
    \        pal[p]=k;\n        if(j+k>r)l=i-k,r=j+k;\n    }\n    for(int i=0;i<2*n-1;i++)pal[i]=pal[i]<<1|(i&1^1);\n\
    \    return pal;\n}\n\n#line 4 \"verify/yosupo/string/manacher/enumerate_palindromes.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin >> s;\n    for(auto x:manacher(s))cout\
    \ << x << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"template.hpp\"\n#include \"string/manacher.hpp\"\n\nint main(){\n\
    \    string s;\n    cin >> s;\n    for(auto x:manacher(s))cout << x << \" \";\n\
    }"
  dependsOn:
  - template.hpp
  - string/manacher.hpp
  isVerificationFile: true
  path: verify/yosupo/string/manacher/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 00:10:28+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/string/manacher/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/string/manacher/enumerate_palindromes.test.cpp
- /verify/verify/yosupo/string/manacher/enumerate_palindromes.test.cpp.html
title: verify/yosupo/string/manacher/enumerate_palindromes.test.cpp
---
