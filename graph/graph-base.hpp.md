---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
    title: verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
    title: verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
    title: verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
    title: verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/graph/scc.test.cpp
    title: verify/yosupo/graph/scc.test.cpp
  - icon: ':x:'
    path: verify/yosupo/tree/jump_on_tree.test.cpp
    title: verify/yosupo/tree/jump_on_tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo/tree/lca.test.cpp
    title: verify/yosupo/tree/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph-base.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-06-15\n * Description: Graph Base\n */\n\ntemplate<class T>\nstruct\
    \ Edge{\n    int from,to,id;\n    T cost;\n    Edge(int _from,int _to,T _cost,int\
    \ _id):from(_from),to(_to),cost(_cost),id(_id){}\n    operator int()const{return\
    \ to;}\n};\n\ntemplate<class T=void,bool directed=false>\nstruct Graph{\n    static\
    \ constexpr bool is_directed=directed;\n    static constexpr bool is_weighted=!is_same<T,void>::value;\n\
    \    using cost_type = std::conditional_t<is_weighted,T,int>;\n    using edge_type\
    \ = Edge<cost_type>;\n    int n,m;\n    vector<edge_type> edges;\n    vector<vector<edge_type>>\
    \ g;\n    vector<int> _deg,_indeg,_outdeg;\n    Graph():n(0),m(0){}\n    Graph(int\
    \ _n):n(_n),m(0),g(_n){}\n    vector<edge_type> &operator[](int u){return g[u];}\n\
    \    void add_edge(int from,int to,cost_type cost=1,int id=-1){\n        assert(0<=from&&from<n&&0<=to&&to<n);\n\
    \        if(id==-1)id=m;\n        edges.emplace_back(edge_type(from,to,cost,id));\n\
    \        g[from].emplace_back(edge_type(from,to,cost,id));\n        if(!is_directed)g[to].emplace_back(edge_type(to,from,cost,id));\n\
    \        m++;\n    }\n    void calc_deg(){\n        _deg.assign(n,0);\n      \
    \  for(auto &e:edges)_deg[e.from]++,_deg[e.to]++;\n    }\n    void calc_inout_deg(){\n\
    \        _indeg.assign(n,0);\n        _outdeg.assign(n,0);\n        for(auto &e:edges)_outdeg[e.from]++,_indeg[e.to]++;\n\
    \    }\n    const vector<int> &deg_array(){\n        if(_deg.empty())calc_deg();\n\
    \        return _deg;\n    }\n    const vector<int> &indeg_array(){\n        if(_indeg.empty())calc_inout_deg();\n\
    \        return _indeg;\n    }\n    const vector<int> &outdeg_array(){\n     \
    \   if(_outdeg.empty())calc_inout_deg();\n        return _outdeg;\n    }\n   \
    \ int deg(int u){return deg_array()[u];}\n    int indeg(int u){return indeg_array()[u];}\n\
    \    int outdeg(int u){return outdeg_array()[u];}\n    Graph reverse(){\n    \
    \    assert(is_directed);\n        Graph res(n);\n        for(auto &e:edges)res.add_edge(e.to,e.from,e.cost,e.id);\n\
    \        return res;\n    }\n};\n\ntemplate<class T=void,bool directed=false>\n\
    Graph<T,directed> read_graph(int n,int m,int offset=1){\n    using G = Graph<T,directed>;\n\
    \    G g(n);\n    for(int i=0;i<m;i++){\n        int u,v;\n        cin >> u >>\
    \ v;\n        u-=offset,v-=offset;\n        if(g.is_weighted){\n            typename\
    \ G::cost_type w;\n            cin >> w;\n            g.add_edge(u,v,w);\n   \
    \     }else{\n            g.add_edge(u,v);\n        }\n    }\n    return g;\n\
    }\ntemplate<class T=void,bool directed=false>\nGraph<T,directed> read_tree(int\
    \ n,int offset=1){\n    return read_graph<T,directed>(n,n-1,offset);\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-15\n * Description:\
    \ Graph Base\n */\n\ntemplate<class T>\nstruct Edge{\n    int from,to,id;\n  \
    \  T cost;\n    Edge(int _from,int _to,T _cost,int _id):from(_from),to(_to),cost(_cost),id(_id){}\n\
    \    operator int()const{return to;}\n};\n\ntemplate<class T=void,bool directed=false>\n\
    struct Graph{\n    static constexpr bool is_directed=directed;\n    static constexpr\
    \ bool is_weighted=!is_same<T,void>::value;\n    using cost_type = std::conditional_t<is_weighted,T,int>;\n\
    \    using edge_type = Edge<cost_type>;\n    int n,m;\n    vector<edge_type> edges;\n\
    \    vector<vector<edge_type>> g;\n    vector<int> _deg,_indeg,_outdeg;\n    Graph():n(0),m(0){}\n\
    \    Graph(int _n):n(_n),m(0),g(_n){}\n    vector<edge_type> &operator[](int u){return\
    \ g[u];}\n    void add_edge(int from,int to,cost_type cost=1,int id=-1){\n   \
    \     assert(0<=from&&from<n&&0<=to&&to<n);\n        if(id==-1)id=m;\n       \
    \ edges.emplace_back(edge_type(from,to,cost,id));\n        g[from].emplace_back(edge_type(from,to,cost,id));\n\
    \        if(!is_directed)g[to].emplace_back(edge_type(to,from,cost,id));\n   \
    \     m++;\n    }\n    void calc_deg(){\n        _deg.assign(n,0);\n        for(auto\
    \ &e:edges)_deg[e.from]++,_deg[e.to]++;\n    }\n    void calc_inout_deg(){\n \
    \       _indeg.assign(n,0);\n        _outdeg.assign(n,0);\n        for(auto &e:edges)_outdeg[e.from]++,_indeg[e.to]++;\n\
    \    }\n    const vector<int> &deg_array(){\n        if(_deg.empty())calc_deg();\n\
    \        return _deg;\n    }\n    const vector<int> &indeg_array(){\n        if(_indeg.empty())calc_inout_deg();\n\
    \        return _indeg;\n    }\n    const vector<int> &outdeg_array(){\n     \
    \   if(_outdeg.empty())calc_inout_deg();\n        return _outdeg;\n    }\n   \
    \ int deg(int u){return deg_array()[u];}\n    int indeg(int u){return indeg_array()[u];}\n\
    \    int outdeg(int u){return outdeg_array()[u];}\n    Graph reverse(){\n    \
    \    assert(is_directed);\n        Graph res(n);\n        for(auto &e:edges)res.add_edge(e.to,e.from,e.cost,e.id);\n\
    \        return res;\n    }\n};\n\ntemplate<class T=void,bool directed=false>\n\
    Graph<T,directed> read_graph(int n,int m,int offset=1){\n    using G = Graph<T,directed>;\n\
    \    G g(n);\n    for(int i=0;i<m;i++){\n        int u,v;\n        cin >> u >>\
    \ v;\n        u-=offset,v-=offset;\n        if(g.is_weighted){\n            typename\
    \ G::cost_type w;\n            cin >> w;\n            g.add_edge(u,v,w);\n   \
    \     }else{\n            g.add_edge(u,v);\n        }\n    }\n    return g;\n\
    }\ntemplate<class T=void,bool directed=false>\nGraph<T,directed> read_tree(int\
    \ n,int offset=1){\n    return read_graph<T,directed>(n,n-1,offset);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph-base.hpp
  requiredBy: []
  timestamp: '2024-06-22 18:46:46+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/graph/scc.test.cpp
  - verify/yosupo/tree/lca.test.cpp
  - verify/yosupo/tree/jump_on_tree.test.cpp
  - verify/yosupo/data-structure/vertex_set_path_composite.test.cpp
  - verify/yosupo/data-structure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - verify/yosupo/data-structure/point_set_tree_path_composite_sum.test.cpp
  - verify/yosupo/data-structure/vertex_add_subtree_sum.test.cpp
  - verify/yosupo/data-structure/vertex_add_path_sum.test.cpp
documentation_of: graph/graph-base.hpp
layout: document
redirect_from:
- /library/graph/graph-base.hpp
- /library/graph/graph-base.hpp.html
title: graph/graph-base.hpp
---
