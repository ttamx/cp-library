---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: group/monoid/min.hpp
    title: group/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix-array.hpp
    title: string/suffix-array.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"verify/yosupo/string/number_of_substrings2.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n#line\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"data-structure/sparse-table.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-12\n * Description: Sparse Table\
    \ class.\n */\n\ntemplate<class Monoid>\nstruct SparseTable{\n    using T = typename\
    \ Monoid::value_type;\n    int n;\n    vector<vector<T>> t;\n    SparseTable(){}\n\
    \    SparseTable(const vector<T> &a){init(a);}\n    void init(const vector<T>\
    \ &a){\n        n=(int)a.size();\n        int lg=31-__builtin_clz(n);\n      \
    \  t.assign(lg+1,vector<T>(n,Monoid::unit()));\n        t[0]=a;\n        for(int\
    \ i=0;i<lg;i++){\n            for(int j=0;j+(2<<i)<=n;j++){\n                t[i+1][j]=Monoid::op(t[i][j],t[i][j+(1<<i)]);\n\
    \            }\n        }\n    }\n    T query(int l,int r){\n        int lg=31-__builtin_clz(r-l+1);\n\
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
    #line 4 \"verify/yosupo/string/number_of_substrings2.test.cpp\"\n\nint main(){\n\
    \    string s;\n    cin >> s;\n    SuffixArray sa(s);\n    int n=(int)s.size();\n\
    \    cout << 1LL*n*(n+1)/2-accumulate(sa.lcp.begin(),sa.lcp.end(),0LL);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    #include \"template.hpp\"\n#include \"string/suffix-array.hpp\"\n\nint main(){\n\
    \    string s;\n    cin >> s;\n    SuffixArray sa(s);\n    int n=(int)s.size();\n\
    \    cout << 1LL*n*(n+1)/2-accumulate(sa.lcp.begin(),sa.lcp.end(),0LL);\n}"
  dependsOn:
  - template.hpp
  - string/suffix-array.hpp
  - data-structure/sparse-table.hpp
  - group/monoid/min.hpp
  isVerificationFile: true
  path: verify/yosupo/string/number_of_substrings2.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/string/number_of_substrings2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/string/number_of_substrings2.test.cpp
- /verify/verify/yosupo/string/number_of_substrings2.test.cpp.html
title: verify/yosupo/string/number_of_substrings2.test.cpp
---
