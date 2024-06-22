#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-06-15
 * Description: Graph Base
 */

template<class T>
struct Edge{
    int from,to,id;
    T cost;
    Edge(int _from,int _to,T _cost,int _id):from(_from),to(_to),cost(_cost),id(_id){}
    operator int()const{return to;}
};

template<class T=void,bool directed=false>
struct Graph{
    static constexpr bool is_directed=directed;
    static constexpr bool is_weighted=!is_same<T,void>::value;
    using cost_type = std::conditional_t<is_weighted,T,int>;
    using edge_type = Edge<cost_type>;
    int n,m;
    vector<edge_type> edges;
    vector<vector<edge_type>> g;
    vector<int> _deg,_indeg,_outdeg;
    Graph():n(0),m(0){}
    Graph(int _n):n(_n),m(0),g(_n){}
    vector<edge_type> &operator[](int u){return g[u];}
    void add_edge(int from,int to,cost_type cost=1,int id=-1){
        assert(0<=from&&from<n&&0<=to&&to<n);
        if(id==-1)id=m;
        edges.emplace_back(edge_type(from,to,cost,id));
        g[from].emplace_back(edge_type(from,to,cost,id));
        if(!is_directed)g[to].emplace_back(edge_type(to,from,cost,id));
        m++;
    }
    void calc_deg(){
        _deg.assign(n,0);
        for(auto &e:edges)_deg[e.from]++,_deg[e.to]++;
    }
    void calc_inout_deg(){
        _indeg.assign(n,0);
        _outdeg.assign(n,0);
        for(auto &e:edges)_outdeg[e.from]++,_indeg[e.to]++;
    }
    const vector<int> &deg_array(){
        if(_deg.empty())calc_deg();
        return _deg;
    }
    const vector<int> &indeg_array(){
        if(_indeg.empty())calc_inout_deg();
        return _indeg;
    }
    const vector<int> &outdeg_array(){
        if(_outdeg.empty())calc_inout_deg();
        return _outdeg;
    }
    int deg(int u){return deg_array()[u];}
    int indeg(int u){return indeg_array()[u];}
    int outdeg(int u){return outdeg_array()[u];}
    Graph reverse(){
        assert(is_directed);
        Graph res(n);
        for(auto &e:edges)res.add_edge(e.to,e.from,e.cost,e.id);
        return res;
    }
};

template<class T=void,bool directed=false>
Graph<T,directed> read_graph(int n,int m,int offset=1){
    using G = Graph<T,directed>;
    G g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u-=offset,v-=offset;
        if(g.is_weighted){
            typename G::cost_type w;
            cin >> w;
            g.add_edge(u,v,w);
        }else{
            g.add_edge(u,v);
        }
    }
    return g;
}
template<class T=void,bool directed=false>
Graph<T,directed> read_tree(int n,int offset=1){
    return read_graph<T,directed>(n,n-1,offset);
}

