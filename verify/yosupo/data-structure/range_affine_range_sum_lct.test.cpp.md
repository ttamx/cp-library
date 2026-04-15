---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/link-cut-tree/lazy-link-cut-tree.hpp
    title: data-structure/link-cut-tree/lazy-link-cut-tree.hpp
  - icon: ':x:'
    path: data-structure/link-cut-tree/lazy-reversible-bbst.hpp
    title: data-structure/link-cut-tree/lazy-reversible-bbst.hpp
  - icon: ':x:'
    path: data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
    title: data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
  - icon: ':x:'
    path: data-structure/link-cut-tree/link-cut-tree-base.hpp
    title: data-structure/link-cut-tree/link-cut-tree-base.hpp
  - icon: ':x:'
    path: data-structure/link-cut-tree/splay-tree-base.hpp
    title: data-structure/link-cut-tree/splay-tree-base.hpp
  - icon: ':x:'
    path: group/monoid-action/add-count-affine.hpp
    title: group/monoid-action/add-count-affine.hpp
  - icon: ':x:'
    path: group/monoid/add-count.hpp
    title: group/monoid/add-count.hpp
  - icon: ':question:'
    path: group/monoid/affine.hpp
    title: group/monoid/affine.hpp
  - icon: ':question:'
    path: modular-arithmetic/modint.hpp
    title: modular-arithmetic/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #line 1 \"template.hpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line\
    \ 2 \"modular-arithmetic/modint.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n\
    \ * Description: modular arithmetic operations\n */\n\ntemplate<int mod,int root=0>\n\
    struct ModInt{\n    using mint = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must\
    \ be positive\");\n\n    int x;\n\n    constexpr ModInt():x(0){}\n    constexpr\
    \ ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n    explicit operator int()const{return\
    \ x;}\n    constexpr static int get_mod(){return mod;}\n    constexpr static mint\
    \ get_root(){return mint(root);}\n    \n    mint operator-()const{\n        mint\
    \ res;\n        res.x=x?mod-x:0;\n        return res;\n    }\n    mint operator+()const{return\
    \ *this;}\n\n    mint inv()const{\n        int a=x,b=mod,u=1,v=0,q=0;\n      \
    \  while(b>0){\n            q=a/b;\n            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n\
    \        }\n        return mint(u);\n    }\n    mint pow(ll n)const{\n       \
    \ mint res=1,a=*this;\n        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n        return\
    \ res;\n    }\n    mint &operator+=(const mint &o){\n        if((x+=o.x)>=mod)x-=mod;\n\
    \        return *this;\n    }\n    mint &operator-=(const mint &o){\n        if((x-=o.x)<0)x+=mod;\n\
    \        return *this;\n    }\n    mint &operator*=(const mint &o){\n        x=(ll(x)*o.x)%mod;\n\
    \        return *this;\n    }\n    mint &operator/=(const mint &o){\n        return\
    \ *this*=o.inv();\n    }\n\n    mint operator+(const mint &o)const{return mint(*this)+=o;}\n\
    \    mint operator-(const mint &o)const{return mint(*this)-=o;}\n    mint operator*(const\
    \ mint &o)const{return mint(*this)*=o;}\n    mint operator/(const mint &o)const{return\
    \ mint(*this)/=o;}\n\n    mint &operator++(){return *this+=mint(1);}\n    mint\
    \ &operator--(){return *this-=mint(1);}\n    mint operator++(int){mint res=*this;*this+=mint(1);return\
    \ res;}\n    mint operator--(int){mint res=*this;*this-=mint(1);return res;}\n\
    \    \n    bool operator==(const mint &o)const{return x==o.x;}\n    bool operator!=(const\
    \ mint &o)const{return x!=o.x;}\n    bool operator<(const mint &o)const{return\
    \ x<o.x;}\n    \n    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    };\nusing mint998 = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n\
    #line 2 \"data-structure/link-cut-tree/splay-tree-base.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-04-13\n * Description: Splay Tree. splay(u) will make\
    \ node u be the root of the tree in amortized O(log n) time.\n */\n\ntemplate<class\
    \ Node>\nstruct SplayTreeBase{\n    using Ptr = Node*;\n    bool is_root(Ptr t){\n\
    \        return !(t->p)||(t->p->l!=t&&t->p->r!=t);\n    } // The parent of the\
    \ root stores the path parant in link cut tree.\n    int size(Ptr t){\n      \
    \  return t?t->size:0;\n    }\n    virtual void push(Ptr t){};\n    virtual void\
    \ pull(Ptr t){};\n    int pos(Ptr t){\n        if(t->p){\n            if(t->p->l==t)return\
    \ -1;\n            if(t->p->r==t)return 1;\n        }\n        return 0;\n   \
    \ }\n    void rotate(Ptr t){\n        Ptr x=t->p,y=x->p;\n        if(pos(t)==-1){\n\
    \            if((x->l=t->r))t->r->p=x;\n            t->r=x,x->p=t;\n        }else{\n\
    \            if((x->r=t->l))t->l->p=x;\n            t->l=x,x->p=t;\n        }\n\
    \        pull(x),pull(t);\n        if((t->p=y)){\n            if(y->l==x)y->l=t;\n\
    \            if(y->r==x)y->r=t;\n        }\n    }\n    void splay(Ptr t){\n  \
    \      if(!t)return;\n        push(t);\n        while(!is_root(t)){\n        \
    \    Ptr x=t->p;\n            if(is_root(x)){\n                push(x),push(t);\n\
    \                rotate(t);\n            }else{\n                Ptr y=x->p;\n\
    \                push(y),push(x),push(t);\n                if(pos(x)==pos(t))rotate(x),rotate(t);\n\
    \                else rotate(t),rotate(t);\n            }\n        }\n    }\n\
    \    Ptr get_first(Ptr t){\n        while(t->l)push(t),t=t->l;\n        splay(t);\n\
    \        return t;\n    }\n    Ptr get_last(Ptr t){\n        while(t->r)push(t),t=t->r;\n\
    \        splay(t);\n        return t;\n    }\n    Ptr merge(Ptr l,Ptr r){\n  \
    \      splay(l),splay(r);\n        if(!l)return r;\n        if(!r)return l;\n\
    \        l=get_last(l);\n        l->r=r;\n        r->p=l;\n        pull(l);\n\
    \        return l;\n    }\n    pair<Ptr,Ptr> split(Ptr t,int k){\n        if(!t)return\
    \ {nullptr,nullptr};\n        if(k==0)return {nullptr,t};\n        if(k==size(t))return\
    \ {t,nullptr};\n        push(t);\n        if(k<=size(t->l)){\n            auto\
    \ x=split(t->l,k);\n            t->l=x.second;\n            t->p=nullptr;\n  \
    \          if(x.second)x.second->p=t;\n            pull(t);\n            return\
    \ {x.first,t};\n        }else{\n            auto x=split(t->r,k-size(t->l)-1);\n\
    \            t->r=x.first;\n            t->p=nullptr;\n            if(x.first)x.first->p=t;\n\
    \            pull(t);\n            return {t,x.second};\n        }\n    }\n  \
    \  void insert(Ptr &t,int k,Ptr v){\n        splay(t);\n        auto x=split(t,k);\n\
    \        t=merge(merge(x.first,v),x.second);\n    }\n    void erase(Ptr &t,int\
    \ k){\n        splay(t);\n        auto x=split(t,k);\n        auto y=split(x.second,1);\n\
    \        // delete y.first;\n        t=merge(x.first,y.second);\n    }\n    template<class\
    \ T>\n    Ptr build(const vector<T> &v){\n        if(v.empty())return nullptr;\n\
    \        function<Ptr(int,int)> build=[&](int l,int r){\n            if(l==r)return\
    \ new Node(v[l]);\n            int m=(l+r)/2;\n            return merge(build(l,m),build(m+1,r));\n\
    \        };\n        return build(0,v.size()-1);\n    }\n};\n\n#line 2 \"data-structure/link-cut-tree/lazy-reversible-bbst.hpp\"\
    \n\n/**\n * Author: Teetat Info.\n * Date: 2024-04-13\n * Description: Lazy Reversible\
    \ BBST Base.\n */\n\ntemplate<class Tree,class Node,class MonoidAction>\nstruct\
    \ LazyReversibleBBST:Tree{\n    using Tree::merge;\n    using Tree::split;\n \
    \   using typename Tree::Ptr;\n    using InfoMonoid = typename MonoidAction::InfoMonoid;\n\
    \    using TagMonoid = typename MonoidAction::TagMonoid;\n    using Info = typename\
    \ MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n\n    LazyReversibleBBST()=default;\n\
    \n    Info sum(Ptr t){\n        return t?t->sum:InfoMonoid::unit();\n    }\n \
    \   void pull(Ptr t){\n        if(!t)return;\n        push(t);\n        t->size=1;\n\
    \        t->sum=t->val;\n        t->revsum=t->val;\n        if(t->l){\n      \
    \      t->size+=t->l->size;\n            t->sum=InfoMonoid::op(t->l->sum,t->sum);\n\
    \            t->revsum=InfoMonoid::op(t->revsum,t->l->revsum);\n        }\n  \
    \      if(t->r){\n            t->size+=t->r->size;\n            t->sum=InfoMonoid::op(t->sum,t->r->sum);\n\
    \            t->revsum=InfoMonoid::op(t->r->revsum,t->revsum);\n        }\n  \
    \  }\n    void push(Ptr t){\n        if(!t)return;\n        if(t->rev){\n    \
    \        toggle(t->l);\n            toggle(t->r);\n            t->rev=false;\n\
    \        }\n        if(t->lz!=TagMonoid::unit()){\n            propagate(t->l,t->lz);\n\
    \            propagate(t->r,t->lz);\n            t->lz=TagMonoid::unit();\n  \
    \      }\n    }\n    void toggle(Ptr t){\n        if(!t)return;\n        swap(t->l,t->r);\n\
    \        swap(t->sum,t->revsum);\n        t->rev^=true;\n    }\n    void propagate(Ptr\
    \ t,const Tag &v){\n        if(!t)return;\n        t->val=MonoidAction::op(t->val,v);\n\
    \        t->sum=MonoidAction::op(t->sum,v);\n        t->revsum=MonoidAction::op(t->revsum,v);\n\
    \        t->lz=TagMonoid::op(t->lz,v);\n    }\n    void apply(Ptr &t,int l,int\
    \ r,const Tag &v){\n        if(l>r)return;\n        auto x=split(t,l);\n     \
    \   auto y=split(x.second,r-l+1);\n        propagate(y.first,v);\n        t=merge(x.first,merge(y.first,y.second));\n\
    \    }\n    Info query(Ptr &t,int l,int r){\n        if(l>r)return InfoMonoid::unit();\n\
    \        auto x=split(t,l);\n        auto y=split(x.second,r-l+1);\n        Info\
    \ res=sum(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n     \
    \   return res;\n    }\n    void reverse(Ptr &t,int l,int r){\n        if(l>r)return;\n\
    \        auto x=split(t,l);\n        auto y=split(x.second,r-l+1);\n        toggle(y.first);\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n};\n\n#line 4 \"data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-13\n * Description: Lazy Reversible\
    \ Splay Tree.\n */\n\ntemplate<class MonoidAction>\nstruct LazyReversibleSplayTreeNode{\n\
    \    using Ptr = LazyReversibleSplayTreeNode*;\n    using InfoMonoid = typename\
    \ MonoidAction::InfoMonoid;\n    using TagMonoid = typename MonoidAction::TagMonoid;\n\
    \    using Info = typename MonoidAction::Info;\n    using Tag = typename MonoidAction::Tag;\n\
    \    using value_type = Info;\n    Ptr l,r,p;\n    Info val,sum,revsum;\n    Tag\
    \ lz;\n    int size;\n    bool rev;\n    LazyReversibleSplayTreeNode(const Info\
    \ &_val=InfoMonoid::unit(),const Tag &_lz=TagMonoid::unit())\n        :l(),r(),p(),val(_val),sum(_val),revsum(_val),lz(_lz),size(1),rev(false){}\n\
    };\n\ntemplate<class MonoidAction>\nstruct LazyReversibleSplayTree\n    : LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<MonoidAction>>,\n\
    \      LazyReversibleSplayTreeNode<MonoidAction>,MonoidAction>{\n    using Node\
    \ = LazyReversibleSplayTreeNode<MonoidAction>;\n};\n\n#line 2 \"data-structure/link-cut-tree/link-cut-tree-base.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-05-19\n * Description: Link Cut Tree\
    \ Base.\n * Usage:\n *  evert(u): make u be the root of the tree.\n *  link(u,v):\
    \ attach u to v.\n *  cut(u,v): remove edge between u and v.\n *  get_root(u):\
    \ get the root of the tree containing u.\n *  lca(u,v): get the lowest common\
    \ ancestor of u and v.\n *  fold(u,v): get the value of the path from u to v.\n\
    \ */\n\ntemplate<class Splay>\nstruct LinkCutTreeBase:Splay{\n    using Node =\
    \ typename Splay::Node;\n    using Ptr = Node*;\n    using T = typename Node::value_type;\n\
    \    Ptr expose(Ptr t){\n        Ptr pc=nullptr; // preferred child\n        for(Ptr\
    \ cur=t;cur;cur=cur->p){\n            this->splay(cur);\n            cur->r=pc;\n\
    \            this->pull(cur);\n            pc=cur;\n        }\n        this->splay(t);\n\
    \        return pc;\n    }\n    void evert(Ptr t){ // make t be the root of the\
    \ tree\n        expose(t);\n        this->toggle(t);\n        this->push(t);\n\
    \    }\n    void link(Ptr u,Ptr v){ // attach u to v\n        evert(u);\n    \
    \    expose(v);\n        u->p=v;\n    }\n    void cut(Ptr u,Ptr v){ // cut edge\
    \ between u and v\n        evert(u);\n        expose(v);\n        assert(u->p==v);\n\
    \        v->l=u->p=nullptr;\n        this->pull(v);\n    }\n    Ptr get_root(Ptr\
    \ t){\n        expose(t);\n        while(t->l)this->push(t),t=t->l;\n        this->splay(t);\n\
    \        return t;\n    }\n    Ptr lca(Ptr u,Ptr v){\n        if(get_root(u)!=get_root(v))return\
    \ nullptr;\n        expose(u);\n        return expose(v);\n    }\n    void set_val(Ptr\
    \ t,const T &val){\n        this->evert(t);\n        t->val=val;\n        this->pull(t);\n\
    \    }\n    T get_val(Ptr t){\n        this->evert(t);\n        return t->val;\n\
    \    }\n    T fold(Ptr u,Ptr v){\n        evert(u);\n        expose(v);\n    \
    \    return v->sum;\n    }\n};\n\n#line 4 \"data-structure/link-cut-tree/lazy-link-cut-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-08-02\n * Description: Lazy Link\
    \ Cut Tree.\n * Usage: using Lct = LazyLinkCutTree<Action>;\n *  using Ptr = Lct::Ptr;\n\
    \ *  using Node = Lct::Node;\n *  vector<Ptr> ptr(n);\n *  for(int i=0;i<n;i++)ptr[i]=new\
    \ Node(val[i]);\n *  auto link=[&](int u,int v){\n *      Lct::link(ptr[u],ptr[v]);\n\
    \ *  };\n *  auto cut=[&](int u,int v){\n *      Lct::cut(ptr[u],ptr[v]);\n *\
    \  };\n *  auto update=[&](int u,int v,const Action::Tag &val){\n *     Lct::apply(ptr[u],ptr[v],val);\n\
    \ *  };\n *  auto query=[&](int u,int v){\n *     return Lct::fold(ptr[u],ptr[v]);\n\
    \ *  };\n */\n\ntemplate<class MonoidAction>\nstruct LazyLinkCutTree:LinkCutTreeBase<LazyReversibleSplayTree<MonoidAction>>{\n\
    \    using base = LinkCutTreeBase<LazyReversibleSplayTree<MonoidAction>>;\n  \
    \  using Ptr = typename base::Ptr;\n    using Tag = typename MonoidAction::Tag;\n\
    \n    void apply(Ptr u,Ptr v,const Tag &val){\n        this->evert(u);\n     \
    \   this->expose(v);\n        this->propagate(v,val);\n    }\n};\n\n#line 2 \"\
    group/monoid/affine.hpp\"\n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n\
    \ * Description: Affine Transfomation Monoid class.\n */\n\ntemplate<class T>\n\
    struct AffineMonoid{\n    using P = pair<T,T>;\n    using value_type = P;\n  \
    \  static constexpr P op(const P &x,const P &y){\n        return P(x.first*y.first,x.second*y.first+y.second);\n\
    \    }\n    static constexpr P unit(){return P(T(1),T(0));}\n    static constexpr\
    \ T eval(const P &f,const T &x){\n        return f.first*x+f.second;\n    }\n\
    };\n\n#line 2 \"group/monoid/add-count.hpp\"\n\n/**\n * Author: Teetat T.\n *\
    \ Date: 2024-04-14\n * Description: Add & Count Monoid class.\n */\n\ntemplate<class\
    \ T>\nstruct AddCountMonoid{\n    using P = pair<T,ll>;\n    using value_type\
    \ = P;\n    static constexpr P op(const P &x,const P &y){\n        return P(x.first+y.first,x.second+y.second);\n\
    \    }\n    static constexpr P inverse(const P &x){return P(-x.first,-x.second);}\n\
    \    static constexpr P unit(){return P(T(0),0LL);}\n    static constexpr P make(const\
    \ T &x){return P(x,1LL);}\n};\n\n#line 4 \"group/monoid-action/add-count-affine.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-04-14\n * Description: Affine to\
    \ Add & Count Action class.\n */\n\ntemplate<class T>\nstruct AddCountAffineAction{\n\
    \    using InfoMonoid = AddCountMonoid<T>;\n    using TagMonoid = AffineMonoid<T>;\n\
    \    using Info = typename InfoMonoid::value_type;\n    using Tag = typename TagMonoid::value_type;\n\
    \    static constexpr Info op(const Info &a,const Tag &b){\n        return Info(a.first*b.first+a.second*b.second,a.second);\n\
    \    }\n};\n\n#line 6 \"verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp\"\
    \n\nusing mint = mint998;\nusing Monoid = AddCountMonoid<mint>;\nusing Action\
    \ = AddCountAffineAction<mint>;\nusing T = Monoid::value_type;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin >> n >>\
    \ q;\n    using LCT = LazyLinkCutTree<Action>;\n    using Ptr = LCT::Ptr;\n  \
    \  using Node = LCT::Node;\n    LCT lct;\n    vector<Ptr> ptr(n);\n    for(int\
    \ i=0;i<n;i++){\n        mint x;\n        cin >> x;\n        ptr[i] = new Node(Monoid::make(x));\n\
    \    }\n    for(int i=1;i<n;i++){\n        lct.link(ptr[i-1],ptr[i]);\n    }\n\
    \    while(q--){\n        int op;\n        cin >> op;\n        if(op){\n     \
    \       int l,r;\n            cin >> l >> r;\n            cout << lct.fold(ptr[l],ptr[r-1]).first\
    \ << \"\\n\";\n        }else{\n            int l,r,b,c;\n            cin >> l\
    \ >> r >> b >> c;\n            lct.apply(ptr[l],ptr[r-1],T(b,c));\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"template.hpp\"\n#include \"modular-arithmetic/modint.hpp\"\n#include\
    \ \"data-structure/link-cut-tree/lazy-link-cut-tree.hpp\"\n#include \"group/monoid-action/add-count-affine.hpp\"\
    \n\nusing mint = mint998;\nusing Monoid = AddCountMonoid<mint>;\nusing Action\
    \ = AddCountAffineAction<mint>;\nusing T = Monoid::value_type;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n    cin >> n >>\
    \ q;\n    using LCT = LazyLinkCutTree<Action>;\n    using Ptr = LCT::Ptr;\n  \
    \  using Node = LCT::Node;\n    LCT lct;\n    vector<Ptr> ptr(n);\n    for(int\
    \ i=0;i<n;i++){\n        mint x;\n        cin >> x;\n        ptr[i] = new Node(Monoid::make(x));\n\
    \    }\n    for(int i=1;i<n;i++){\n        lct.link(ptr[i-1],ptr[i]);\n    }\n\
    \    while(q--){\n        int op;\n        cin >> op;\n        if(op){\n     \
    \       int l,r;\n            cin >> l >> r;\n            cout << lct.fold(ptr[l],ptr[r-1]).first\
    \ << \"\\n\";\n        }else{\n            int l,r,b,c;\n            cin >> l\
    \ >> r >> b >> c;\n            lct.apply(ptr[l],ptr[r-1],T(b,c));\n        }\n\
    \    }\n}"
  dependsOn:
  - template.hpp
  - modular-arithmetic/modint.hpp
  - data-structure/link-cut-tree/lazy-link-cut-tree.hpp
  - data-structure/link-cut-tree/lazy-reversible-splay-tree.hpp
  - data-structure/link-cut-tree/splay-tree-base.hpp
  - data-structure/link-cut-tree/lazy-reversible-bbst.hpp
  - data-structure/link-cut-tree/link-cut-tree-base.hpp
  - group/monoid-action/add-count-affine.hpp
  - group/monoid/affine.hpp
  - group/monoid/add-count.hpp
  isVerificationFile: true
  path: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
  requiredBy: []
  timestamp: '2026-04-15 18:40:12+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
- /verify/verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp.html
title: verify/yosupo/data-structure/range_affine_range_sum_lct.test.cpp
---
