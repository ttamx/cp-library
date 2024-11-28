#pragma once
#include "tree/static-top-tree.hpp"

/**
 * Author: Teetat T.
 * Date: 2024-11-14
 * Description: Static Top Tree DP.
 */

/*
struct TreeDP{
    struct Path{
        static Path unit();
    };
    struct Point{
        static Point unit();
    };
    static Path compress(Path l,Path r);
    static Point rake(Point l,Point r);
    static Point add_edge(Path p);
    static Path add_vertex(Point p,int u);
    static Path vertex(int u);
};
*/

template<class HLD,class TreeDP>
struct StaticTopTreeDP{
    using Path = typename TreeDP::Path;
    using Point = typename TreeDP::Point;
    StaticTopTree<HLD> stt;
    vector<Path> path;
    vector<Point> point;
    StaticTopTreeDP(HLD &hld):stt(hld){
        int n=stt.n;
        path.resize(n);
        point.resize(n);
        dfs(stt.root);
    }
    void _update(int u){
        if(stt.type[u]==stt.Vertex){
            path[u]=TreeDP::vertex(u);
        }else if(stt.type[u]==stt.Compress){
            path[u]=TreeDP::compress(path[stt.lch[u]],path[stt.rch[u]]);
        }else if(stt.type[u]==stt.Rake){
            point[u]=TreeDP::rake(point[stt.lch[u]],point[stt.rch[u]]);
        }else if(stt.type[u]==stt.AddEdge){
            point[u]=TreeDP::add_edge(path[stt.lch[u]]);
        }else{
            path[u]=TreeDP::add_vertex(point[stt.lch[u]],u);
        }
    }
    void dfs(int u){
        if(u==-1)return;
        dfs(stt.lch[u]);
        dfs(stt.rch[u]);
        _update(u);
    }
    void update(int u){
        for(;u!=-1;u=stt.par[u])_update(u);
    }
    Path query_all(){
        return path[stt.root];
    }
    Path query_subtree(int u){
        Path res=path[u];
        while(true){
            int p=stt.par[u];
            if(p==-1||stt.type[p]!=stt.Compress)break;
            if(stt.lch[p]==u)res=TreeDP::compress(res,path[stt.rch[p]]);
        }
        return res;
    }
};

