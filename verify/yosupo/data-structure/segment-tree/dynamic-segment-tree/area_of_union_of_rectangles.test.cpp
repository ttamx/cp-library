#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include "template.hpp"
#include "data-structure/segment-tree/dynamic-segment-tree.hpp"
#include "group/monoid-action/min-count-add.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    map<int,vector<tuple<int,int,int>>> qr;
    for(int i=0;i<n;++i){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        ry--;
        qr[lx].emplace_back(ly,ry,1);
        qr[rx].emplace_back(ly,ry,-1);
    }
    const int X=1e9;
    DynamicSegmentTree<MinCountAddAction<int>> s(0,X-1,[](int l,int r){
        return make_pair(0,r-l+1);
    });
    ll ans=0,pre=0;
    for(auto &[x,v]:qr){
        auto [val,cnt]=s.query(0,X);
        if(val>0)cnt=0;
        ans+=(X-cnt)*(x-pre);
        for(auto &[l,r,d]:v)s.update(l,r,d);
        pre=x;
    }
    cout << ans;
}