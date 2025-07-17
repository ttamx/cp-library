---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-trie.hpp
    title: data-structure/binary-trie.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/yosupo/data-structure/set_xor_min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n#include<ext/pb_ds/tree_policy.hpp>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;\n\nusing ll = long long;\n\
    using db = long double;\nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing\
    \ vd = vector<db>;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing\
    \ pdd = pair<db,db>;\nconst int INF=INT_MAX/2;\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst ll LINF=LLONG_MAX/2;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    template<class T>\nusing ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"data-structure/binary-trie.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-11\n * Description: Binary Trie\n\
    \ */\n\ntemplate<int BIT,class T = uint32_t,class S = int>\nstruct BinaryTrie{\n\
    \    struct Node{\n        array<int,2> ch;\n        S cnt;\n        Node():ch{-1,-1},cnt(0){}\n\
    \    };\n    vector<Node> t;\n    BinaryTrie():t{Node()}{}\n    int new_node(){\n\
    \        t.emplace_back(Node());\n        return t.size()-1;\n    }\n    S size(){\n\
    \        return t[0].cnt;\n    }\n    bool empty(){\n        return size()==0;\n\
    \    }\n    S get_cnt(int i){\n        return i!=-1?t[i].cnt:S(0);\n    }\n  \
    \  void insert(T x,S k=1){\n        int u=0;\n        t[u].cnt+=k;\n        for(int\
    \ i=BIT-1;i>=0;i--){\n            int v=x>>i&1;\n            if(t[u].ch[v]==-1)t[u].ch[v]=new_node();\n\
    \            u=t[u].ch[v];\n            t[u].cnt+=k;\n        }\n    }\n    void\
    \ erase(T x,S k=1){\n        int u=0;\n        assert(t[u].cnt>=k);\n        t[u].cnt-=k;\n\
    \        for(int i=BIT-1;i>=0;i--){\n            int v=x>>i&1;\n            u=t[u].ch[v];\n\
    \            assert(u!=-1&&t[u].cnt>=k);\n            t[u].cnt-=k;\n        }\n\
    \    }\n    T kth(S k,T x=0){\n        assert(k<size());\n        int u=0;\n \
    \       T res=0;\n        for(int i=BIT-1;i>=0;i--){\n            int v=x>>i&1;\n\
    \            if(k<get_cnt(t[u].ch[v])){\n                u=t[u].ch[v];\n     \
    \       }else{\n                res|=T(1)<<i;\n                k-=get_cnt(t[u].ch[v]);\n\
    \                u=t[u].ch[v^1];\n            }\n        }\n        return res;\n\
    \    }\n    T min(T x){\n        return kth(0,x);\n    }\n    T max(T x){\n  \
    \      return kth(size()-1,x);\n    }\n};\n\n#line 4 \"verify/yosupo/data-structure/set_xor_min.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int q;\n \
    \   cin >> q;\n    set<int> s;\n    BinaryTrie<30> trie;\n    while(q--){\n  \
    \      int t,x;\n        cin >> t >> x;\n        if(t==0){\n            if(s.insert(x).second)trie.insert(x);\n\
    \        }else if(t==1){\n            auto it=s.find(x);\n            if(it!=s.end()){\n\
    \                s.erase(it);\n                trie.erase(x);\n            }\n\
    \        }else{\n            cout << trie.min(x) << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"template.hpp\"\n#include \"data-structure/binary-trie.hpp\"\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int q;\n    cin >> q;\n  \
    \  set<int> s;\n    BinaryTrie<30> trie;\n    while(q--){\n        int t,x;\n\
    \        cin >> t >> x;\n        if(t==0){\n            if(s.insert(x).second)trie.insert(x);\n\
    \        }else if(t==1){\n            auto it=s.find(x);\n            if(it!=s.end()){\n\
    \                s.erase(it);\n                trie.erase(x);\n            }\n\
    \        }else{\n            cout << trie.min(x) << \"\\n\";\n        }\n    }\n\
    }"
  dependsOn:
  - template.hpp
  - data-structure/binary-trie.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/set_xor_min.test.cpp
- /verify/verify/yosupo/data-structure/set_xor_min.test.cpp.html
title: verify/yosupo/data-structure/set_xor_min.test.cpp
---
