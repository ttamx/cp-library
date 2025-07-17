---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/manacher.hpp
    title: string/manacher.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/yosupo/string/enumerate_palindromes.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n#line\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"string/manacher.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description: Manacher's\
    \ Algorithm. pal[i] := the length of the longest palindrome centered at i/2.\n\
    \ */\n\ntemplate<class STR>\nvector<int> manacher(const STR &s){\n    int n=(int)s.size();\n\
    \    if(n==0)return {};\n    vector<int> pal(2*n-1);\n    for(int p=0,l=-1,r=-1;p<2*n-1;p++){\n\
    \        int i=(p+1)>>1,j=p>>1;\n        int k=(i>=r?0:min(r-i,pal[2*(l+r)-p]));\n\
    \        while(j+k+1<n&&i-k-1>=0&&s[j+k+1]==s[i-k-1])k++;\n        pal[p]=k;\n\
    \        if(j+k>r)l=i-k,r=j+k;\n    }\n    for(int i=0;i<2*n-1;i++)pal[i]=pal[i]<<1|(i&1^1);\n\
    \    return pal;\n}\n\n#line 4 \"verify/yosupo/string/enumerate_palindromes.test.cpp\"\
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
  path: verify/yosupo/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/string/enumerate_palindromes.test.cpp
- /verify/verify/yosupo/string/enumerate_palindromes.test.cpp.html
title: verify/yosupo/string/enumerate_palindromes.test.cpp
---
