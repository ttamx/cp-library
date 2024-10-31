---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/string/number_of_substrings.test.cpp
    title: verify/yosupo/string/number_of_substrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix-automaton.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-06-14\n * Description: Suffix Automaton.\n */\n\ntemplate<class\
    \ STR>\nstruct SuffixAutomaton{\n    using T = typename STR::value_type;\n   \
    \ struct Node{\n        map<T,int> nxt;\n        int link,len;\n        Node(int\
    \ link,int len):link(link),len(len){}\n    };\n    vector<Node> nodes;\n    int\
    \ last;\n    SuffixAutomaton():nodes{Node(-1,0)},last(0){}\n    SuffixAutomaton(const\
    \ STR &s):SuffixAutomaton(){\n        for(auto c:s)extend(c);\n    }\n    int\
    \ new_node(int link,int len){\n        nodes.emplace_back(Node(link,len));\n \
    \       return (int)nodes.size()-1;\n    }\n    void extend(T c){\n        int\
    \ cur=new_node(0,nodes[last].len+1);\n        int p=last;\n        while(p!=-1&&!nodes[p].nxt.count(c)){\n\
    \            nodes[p].nxt[c]=cur;\n            p=nodes[p].link;\n        }\n \
    \       if(p!=-1){\n            int q=nodes[p].nxt[c];\n            if(nodes[p].len+1==nodes[q].len){\n\
    \                nodes[cur].link=q;\n            }else{\n                int r=new_node(nodes[q].link,nodes[p].len+1);\n\
    \                nodes[r].nxt=nodes[q].nxt;\n                while(p!=-1&&nodes[p].nxt[c]==q){\n\
    \                    nodes[p].nxt[c]=r;\n                    p=nodes[p].link;\n\
    \                }\n                nodes[q].link=nodes[cur].link=r;\n       \
    \     }\n        }\n        last=cur;\n    }\n    ll distinct_substrings(){\n\
    \        ll res=0;\n        for(int i=1;i<(int)nodes.size();i++)res+=nodes[i].len-nodes[nodes[i].link].len;\n\
    \        return res;\n    }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description:\
    \ Suffix Automaton.\n */\n\ntemplate<class STR>\nstruct SuffixAutomaton{\n   \
    \ using T = typename STR::value_type;\n    struct Node{\n        map<T,int> nxt;\n\
    \        int link,len;\n        Node(int link,int len):link(link),len(len){}\n\
    \    };\n    vector<Node> nodes;\n    int last;\n    SuffixAutomaton():nodes{Node(-1,0)},last(0){}\n\
    \    SuffixAutomaton(const STR &s):SuffixAutomaton(){\n        for(auto c:s)extend(c);\n\
    \    }\n    int new_node(int link,int len){\n        nodes.emplace_back(Node(link,len));\n\
    \        return (int)nodes.size()-1;\n    }\n    void extend(T c){\n        int\
    \ cur=new_node(0,nodes[last].len+1);\n        int p=last;\n        while(p!=-1&&!nodes[p].nxt.count(c)){\n\
    \            nodes[p].nxt[c]=cur;\n            p=nodes[p].link;\n        }\n \
    \       if(p!=-1){\n            int q=nodes[p].nxt[c];\n            if(nodes[p].len+1==nodes[q].len){\n\
    \                nodes[cur].link=q;\n            }else{\n                int r=new_node(nodes[q].link,nodes[p].len+1);\n\
    \                nodes[r].nxt=nodes[q].nxt;\n                while(p!=-1&&nodes[p].nxt[c]==q){\n\
    \                    nodes[p].nxt[c]=r;\n                    p=nodes[p].link;\n\
    \                }\n                nodes[q].link=nodes[cur].link=r;\n       \
    \     }\n        }\n        last=cur;\n    }\n    ll distinct_substrings(){\n\
    \        ll res=0;\n        for(int i=1;i<(int)nodes.size();i++)res+=nodes[i].len-nodes[nodes[i].link].len;\n\
    \        return res;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix-automaton.hpp
  requiredBy: []
  timestamp: '2024-06-15 00:08:38+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/string/number_of_substrings.test.cpp
documentation_of: string/suffix-automaton.hpp
layout: document
redirect_from:
- /library/string/suffix-automaton.hpp
- /library/string/suffix-automaton.hpp.html
title: string/suffix-automaton.hpp
---
