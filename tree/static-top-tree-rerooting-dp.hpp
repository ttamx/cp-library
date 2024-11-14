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
struct StaticTopTreeRerootingDP{
    using Path = typename TreeDP::Path;
    using Point = typename TreeDP::Point;
    StaticTopTree<HLD> stt;
    vector<Path> path,rpath;
    vector<Point> point;
    StaticTopTreeRerootingDP(HLD &hld):stt(hld){
        int n=stt.n;
        path.resize(n);
        point.resize(n);
        rpath.resize(n);
        dfs(stt.root);
    }
    void update(int u){
        if(stt.type[u]==stt.Vertex){
            path[u]=rpath[u]=TreeDP::vertex(u);
        }else if(stt.type[u]==stt.Compress){
            path[u]=TreeDP::compress(path[stt.lch[u]],path[stt.rch[u]]);
            rpath[u]=TreeDP::compress(rpath[stt.rch[u]],rpath[stt.lch[u]]);
        }else if(stt.type[u]==stt.Rake){
            point[u]=TreeDP::rake(point[stt.lch[u]],point[stt.rch[u]]);
        }else if(stt.type[u]==stt.AddEdge){
            point[u]=TreeDP::add_edge(path[stt.lch[u]]);
        }else{
            path[u]=rpath[u]=TreeDP::add_vertex(point[stt.lch[u]],u);
        }
    }
    void dfs(int u){
        if(u==-1)return;
        dfs(stt.lch[u]);
        dfs(stt.rch[u]);
        update(u);
    }
    void recalc(int u){
        while(u!=-1){
            update(u);
            u=stt.par[u];
        }
    }
    Path query_all(){
        return path[stt.root];
    }
    Path query_subtree(int u){
        Path res=path[u];
        while(true){
            int p=stt.par[u];
            if(p==-1||stt.type[p]!=stt.Compress)break;
            if(stt.lch[p]==u){
                res=TreeDP::compress(path[stt.rch[p]],res);
            }
        }
        return res;
    }
    Path query_reroot(int u){
        auto rec=[&](auto &&rec,int u)->Point{
            int p=stt.par[u];
            Path below=Path::unit(),above=Path::unit();
            while(p!=-1&&stt.type[p]==stt.Compress){
                int l=stt.lch[p],r=stt.rch[p];
                if(l==u){
                    below=TreeDP::compress(below,path[r]);
                }else{
                    above=TreeDP::compress(above,rpath[l]);
                }
                u=p;
                p=stt.par[u];
            }
            if(p!=-1){
                u=p;
                p=stt.par[u];
                Point sum=Point::unit();
                while(stt.type[p]==stt.Rake){
                    int l=stt.lch[p],r=stt.rch[p];
                    sum=TreeDP::rake(sum,u==r?point[l]:point[r]);
                    u=p;
                    p=stt.par[u];
                }
                sum=TreeDP::rake(sum,rec(rec,p));
                above=TreeDP::compress(above,TreeDP::add_vertex(sum,p));
            }
            return TreeDP::rake(TreeDP::add_edge(below),TreeDP::add_edge(above));
        };
        Point res=rec(rec,u);
        if(stt.type[u]==stt.AddVertex){
            res=TreeDP::rake(res,point[stt.lch[u]]);
        }
        return TreeDP::add_vertex(res,u);
    }
};

