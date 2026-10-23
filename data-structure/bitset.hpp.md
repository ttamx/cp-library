---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/linear-algebra/matrix_product_mod_2.test.cpp
    title: verify/yosupo/linear-algebra/matrix_product_mod_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/bitset.hpp\"\n\nstruct BitSet{\n    using\
    \ u64 = uint64_t;\n    vector<u64> dat;\n    int n;\n    \n    static u64 maskbit(int\
    \ p){return 1ULL<<p;}\n\n    struct Proxy{\n        u64 &dat;\n        int idx;\n\
    \        Proxy(vector<u64> &d,int i):dat(d[i>>6]),idx(i&63){}\n        operator\
    \ bool()const{return (dat>>idx)&1;}\n        bool operator~()const{return ((dat>>idx)&1)^1;}\n\
    \        Proxy &flip(){dat^=maskbit(idx);return *this;}\n        Proxy &operator=(bool\
    \ x){\n            if(x)dat|=maskbit(idx);\n            else dat&=~maskbit(idx);\n\
    \            return *this;\n        }\n        Proxy &operator=(const Proxy &o){return\
    \ *this=bool(o);}\n        Proxy &operator|=(bool x){if(x)dat|=maskbit(idx);return\
    \ *this;}\n        Proxy &operator&=(bool x){if(!x)dat&=~maskbit(idx);return *this;}\n\
    \        Proxy &operator^=(bool x){if(x)dat^=maskbit(idx);return *this;}\n   \
    \ };\n\n    explicit BitSet(int _n=0,bool x=false):dat((_n+63)>>6,u64(x?-1:0)),n(_n){trim();}\n\
    \n    int size()const{return n;}\n    void trim(){if(n&63)dat.back()&=maskbit(n&63)-1;}\n\
    \    void resize(int m,bool x=false){\n        assert(m>=0);\n        if(x&&n<m&&(n&63))dat[n>>6]|=u64(-1)<<(n&63);\n\
    \        dat.resize((m+63)>>6,u64(x?-1:0));\n        n=m;\n        trim();\n \
    \   }\n    void push_back(bool x){\n        if((n&63)==0)dat.push_back(0);\n \
    \       if(x)dat[n>>6]|=maskbit(n&63);\n        n++;\n    }\n    void pop_back(){\n\
    \        assert(n>0);\n        n--;\n        if((n&63)==0)dat.pop_back();\n  \
    \      else dat.back()&=maskbit(n&63)-1;\n    }\n\n    Proxy operator[](int i){\n\
    \        assert(0<=i&&i<n);\n        return Proxy(dat,i);\n    }\n    bool operator[](int\
    \ i)const{\n        assert(0<=i&&i<n);\n        return (dat[i>>6]>>(i&63))&1;\n\
    \    }\n\n    void set(){fill(ALL(dat),u64(-1));trim();}\n    void reset(){fill(ALL(dat),0);}\n\
    \    void flip(){for(auto &x:dat)x=~x;trim();}\n    void set(int i){(*this)[i]=1;}\n\
    \    void reset(int i){(*this)[i]=0;}\n    void flip(int i){(*this)[i].flip();}\n\
    \n    int count()const{\n        int res=0;\n        for(auto x:dat)res+=__builtin_popcountll(x);\n\
    \        return res;\n    }\n    bool any()const{\n        for(auto x:dat)if(x)return\
    \ true;\n        return false;\n    }\n    bool none()const{return !any();}\n\
    \    bool all()const{return count()==n;}\n\n    BitSet &operator&=(const BitSet\
    \ &o){\n        assert(n==o.n);\n        for(int i=0;i<SZ(dat);i++)dat[i]&=o.dat[i];\n\
    \        return *this;\n    }\n    BitSet &operator|=(const BitSet &o){\n    \
    \    assert(n==o.n);\n        for(int i=0;i<SZ(dat);i++)dat[i]|=o.dat[i];\n  \
    \      return *this;\n    }\n    BitSet &operator^=(const BitSet &o){\n      \
    \  assert(n==o.n);\n        for(int i=0;i<SZ(dat);i++)dat[i]^=o.dat[i];\n    \
    \    return *this;\n    }\n    BitSet &operator<<=(int k){\n        assert(k>=0);\n\
    \        if(k>=n)return reset(),*this;\n        int q=k>>6,r=k&63,m=SZ(dat);\n\
    \        if(!r){\n            for(int i=m-1;i>=q;i--)dat[i]=dat[i-q];\n      \
    \  }else{\n            for(int i=m-1;i>q;i--)dat[i]=(dat[i-q]<<r)|(dat[i-q-1]>>(64-r));\n\
    \            dat[q]=dat[0]<<r;\n        }\n        fill(dat.begin(),dat.begin()+q,0);\n\
    \        trim();\n        return *this;\n    }\n    BitSet &operator>>=(int k){\n\
    \        assert(k>=0);\n        if(k>=n)return reset(),*this;\n        int q=k>>6,r=k&63,m=SZ(dat);\n\
    \        if(!r){\n            for(int i=0;i+q<m;i++)dat[i]=dat[i+q];\n       \
    \ }else{\n            for(int i=0;i+q+1<m;i++)dat[i]=(dat[i+q]>>r)|(dat[i+q+1]<<(64-r));\n\
    \            dat[m-q-1]=dat[m-1]>>r;\n        }\n        fill(dat.end()-q,dat.end(),0);\n\
    \        return *this;\n    }\n    BitSet operator&(const BitSet &o)const{return\
    \ BitSet(*this)&=o;}\n    BitSet operator|(const BitSet &o)const{return BitSet(*this)|=o;}\n\
    \    BitSet operator^(const BitSet &o)const{return BitSet(*this)^=o;}\n    BitSet\
    \ operator<<(int k)const{return BitSet(*this)<<=k;}\n    BitSet operator>>(int\
    \ k)const{return BitSet(*this)>>=k;}\n    bool operator==(const BitSet &o){return\
    \ n==o.n&&dat==o.dat;}\n    bool operator!=(const BitSet &o){return !(*this==o);}\n\
    \    BitSet operator~()const{\n        BitSet o(*this);\n        o.flip();\n \
    \       return o;\n    }\n\n    int find_next(int i)const{ // first set bit >=\
    \ i, n if none\n        if(i<0)i=0;\n        if(i>=n)return n;\n        int q=i>>6;\n\
    \        u64 x=dat[q]&(u64(-1)<<(i&63));\n        while(!x){\n            if(++q==SZ(dat))return\
    \ n;\n            x=dat[q];\n        }\n        return q<<6|__builtin_ctzll(x);\n\
    \    }\n    int find_prev(int i)const{ // last set bit <= i, -1 if none\n    \
    \    if(i>=n)i=n-1;\n        if(i<0)return -1;\n        int q=i>>6;\n        u64\
    \ x=dat[q]&(u64(-1)>>(63-(i&63)));\n        while(!x){\n            if(--q<0)return\
    \ -1;\n            x=dat[q];\n        }\n        return q<<6|(63-__builtin_clzll(x));\n\
    \    }\n    int find_first()const{return find_next(0);}\n    int find_last()const{return\
    \ find_prev(n-1);}\n\n    void set_range(int l,int r){\n        assert(0<=l&&l<=r&&r<=n);\n\
    \        if(l==r)return;\n        int ql=l>>6,qr=r>>6;\n        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;\n\
    \        if(ql==qr)return void(dat[ql]|=ml&mr);\n        if(l&63)dat[ql++]|=ml;\n\
    \        if(r&63)dat[qr]|=mr;\n        for(int i=ql;i<qr;i++)dat[i]=u64(-1);\n\
    \    }\n    void reset_range(int l,int r){\n        assert(0<=l&&l<=r&&r<=n);\n\
    \        if(l==r)return;\n        int ql=l>>6,qr=r>>6;\n        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;\n\
    \        if(ql==qr)return void(dat[ql]&=~(ml&mr));\n        if(l&63)dat[ql++]&=~ml;\n\
    \        if(r&63)dat[qr]&=~mr;\n        for(int i=ql;i<qr;i++)dat[i]=u64(0);\n\
    \    }\n    void flip_range(int l,int r){\n        assert(0<=l&&l<=r&&r<=n);\n\
    \        if(l==r)return;\n        int ql=l>>6,qr=r>>6;\n        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;\n\
    \        if(ql==qr)return void(dat[ql]^=ml&mr);\n        if(l&63)dat[ql++]^=ml;\n\
    \        if(r&63)dat[qr]^=mr;\n        for(int i=ql;i<qr;i++)dat[i]=~dat[i];\n\
    \    }\n    int count_range(int l,int r)const{\n        assert(0<=l&&l<=r&&r<=n);\n\
    \        if(l==r)return 0;\n        int ql=l>>6,qr=r>>6;\n        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;\n\
    \        if(ql==qr)return __builtin_popcountll(dat[ql]&ml&mr);\n        int res=0;\n\
    \        if(l&63)res+=__builtin_popcountll(dat[ql++]&ml);\n        if(r&63)res+=__builtin_popcountll(dat[qr]&mr);\n\
    \        for(int i=ql;i<qr;i++)res+=__builtin_popcountll(dat[i]);\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n\nstruct BitSet{\n    using u64 = uint64_t;\n    vector<u64>\
    \ dat;\n    int n;\n    \n    static u64 maskbit(int p){return 1ULL<<p;}\n\n \
    \   struct Proxy{\n        u64 &dat;\n        int idx;\n        Proxy(vector<u64>\
    \ &d,int i):dat(d[i>>6]),idx(i&63){}\n        operator bool()const{return (dat>>idx)&1;}\n\
    \        bool operator~()const{return ((dat>>idx)&1)^1;}\n        Proxy &flip(){dat^=maskbit(idx);return\
    \ *this;}\n        Proxy &operator=(bool x){\n            if(x)dat|=maskbit(idx);\n\
    \            else dat&=~maskbit(idx);\n            return *this;\n        }\n\
    \        Proxy &operator=(const Proxy &o){return *this=bool(o);}\n        Proxy\
    \ &operator|=(bool x){if(x)dat|=maskbit(idx);return *this;}\n        Proxy &operator&=(bool\
    \ x){if(!x)dat&=~maskbit(idx);return *this;}\n        Proxy &operator^=(bool x){if(x)dat^=maskbit(idx);return\
    \ *this;}\n    };\n\n    explicit BitSet(int _n=0,bool x=false):dat((_n+63)>>6,u64(x?-1:0)),n(_n){trim();}\n\
    \n    int size()const{return n;}\n    void trim(){if(n&63)dat.back()&=maskbit(n&63)-1;}\n\
    \    void resize(int m,bool x=false){\n        assert(m>=0);\n        if(x&&n<m&&(n&63))dat[n>>6]|=u64(-1)<<(n&63);\n\
    \        dat.resize((m+63)>>6,u64(x?-1:0));\n        n=m;\n        trim();\n \
    \   }\n    void push_back(bool x){\n        if((n&63)==0)dat.push_back(0);\n \
    \       if(x)dat[n>>6]|=maskbit(n&63);\n        n++;\n    }\n    void pop_back(){\n\
    \        assert(n>0);\n        n--;\n        if((n&63)==0)dat.pop_back();\n  \
    \      else dat.back()&=maskbit(n&63)-1;\n    }\n\n    Proxy operator[](int i){\n\
    \        assert(0<=i&&i<n);\n        return Proxy(dat,i);\n    }\n    bool operator[](int\
    \ i)const{\n        assert(0<=i&&i<n);\n        return (dat[i>>6]>>(i&63))&1;\n\
    \    }\n\n    void set(){fill(ALL(dat),u64(-1));trim();}\n    void reset(){fill(ALL(dat),0);}\n\
    \    void flip(){for(auto &x:dat)x=~x;trim();}\n    void set(int i){(*this)[i]=1;}\n\
    \    void reset(int i){(*this)[i]=0;}\n    void flip(int i){(*this)[i].flip();}\n\
    \n    int count()const{\n        int res=0;\n        for(auto x:dat)res+=__builtin_popcountll(x);\n\
    \        return res;\n    }\n    bool any()const{\n        for(auto x:dat)if(x)return\
    \ true;\n        return false;\n    }\n    bool none()const{return !any();}\n\
    \    bool all()const{return count()==n;}\n\n    BitSet &operator&=(const BitSet\
    \ &o){\n        assert(n==o.n);\n        for(int i=0;i<SZ(dat);i++)dat[i]&=o.dat[i];\n\
    \        return *this;\n    }\n    BitSet &operator|=(const BitSet &o){\n    \
    \    assert(n==o.n);\n        for(int i=0;i<SZ(dat);i++)dat[i]|=o.dat[i];\n  \
    \      return *this;\n    }\n    BitSet &operator^=(const BitSet &o){\n      \
    \  assert(n==o.n);\n        for(int i=0;i<SZ(dat);i++)dat[i]^=o.dat[i];\n    \
    \    return *this;\n    }\n    BitSet &operator<<=(int k){\n        assert(k>=0);\n\
    \        if(k>=n)return reset(),*this;\n        int q=k>>6,r=k&63,m=SZ(dat);\n\
    \        if(!r){\n            for(int i=m-1;i>=q;i--)dat[i]=dat[i-q];\n      \
    \  }else{\n            for(int i=m-1;i>q;i--)dat[i]=(dat[i-q]<<r)|(dat[i-q-1]>>(64-r));\n\
    \            dat[q]=dat[0]<<r;\n        }\n        fill(dat.begin(),dat.begin()+q,0);\n\
    \        trim();\n        return *this;\n    }\n    BitSet &operator>>=(int k){\n\
    \        assert(k>=0);\n        if(k>=n)return reset(),*this;\n        int q=k>>6,r=k&63,m=SZ(dat);\n\
    \        if(!r){\n            for(int i=0;i+q<m;i++)dat[i]=dat[i+q];\n       \
    \ }else{\n            for(int i=0;i+q+1<m;i++)dat[i]=(dat[i+q]>>r)|(dat[i+q+1]<<(64-r));\n\
    \            dat[m-q-1]=dat[m-1]>>r;\n        }\n        fill(dat.end()-q,dat.end(),0);\n\
    \        return *this;\n    }\n    BitSet operator&(const BitSet &o)const{return\
    \ BitSet(*this)&=o;}\n    BitSet operator|(const BitSet &o)const{return BitSet(*this)|=o;}\n\
    \    BitSet operator^(const BitSet &o)const{return BitSet(*this)^=o;}\n    BitSet\
    \ operator<<(int k)const{return BitSet(*this)<<=k;}\n    BitSet operator>>(int\
    \ k)const{return BitSet(*this)>>=k;}\n    bool operator==(const BitSet &o){return\
    \ n==o.n&&dat==o.dat;}\n    bool operator!=(const BitSet &o){return !(*this==o);}\n\
    \    BitSet operator~()const{\n        BitSet o(*this);\n        o.flip();\n \
    \       return o;\n    }\n\n    int find_next(int i)const{ // first set bit >=\
    \ i, n if none\n        if(i<0)i=0;\n        if(i>=n)return n;\n        int q=i>>6;\n\
    \        u64 x=dat[q]&(u64(-1)<<(i&63));\n        while(!x){\n            if(++q==SZ(dat))return\
    \ n;\n            x=dat[q];\n        }\n        return q<<6|__builtin_ctzll(x);\n\
    \    }\n    int find_prev(int i)const{ // last set bit <= i, -1 if none\n    \
    \    if(i>=n)i=n-1;\n        if(i<0)return -1;\n        int q=i>>6;\n        u64\
    \ x=dat[q]&(u64(-1)>>(63-(i&63)));\n        while(!x){\n            if(--q<0)return\
    \ -1;\n            x=dat[q];\n        }\n        return q<<6|(63-__builtin_clzll(x));\n\
    \    }\n    int find_first()const{return find_next(0);}\n    int find_last()const{return\
    \ find_prev(n-1);}\n\n    void set_range(int l,int r){\n        assert(0<=l&&l<=r&&r<=n);\n\
    \        if(l==r)return;\n        int ql=l>>6,qr=r>>6;\n        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;\n\
    \        if(ql==qr)return void(dat[ql]|=ml&mr);\n        if(l&63)dat[ql++]|=ml;\n\
    \        if(r&63)dat[qr]|=mr;\n        for(int i=ql;i<qr;i++)dat[i]=u64(-1);\n\
    \    }\n    void reset_range(int l,int r){\n        assert(0<=l&&l<=r&&r<=n);\n\
    \        if(l==r)return;\n        int ql=l>>6,qr=r>>6;\n        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;\n\
    \        if(ql==qr)return void(dat[ql]&=~(ml&mr));\n        if(l&63)dat[ql++]&=~ml;\n\
    \        if(r&63)dat[qr]&=~mr;\n        for(int i=ql;i<qr;i++)dat[i]=u64(0);\n\
    \    }\n    void flip_range(int l,int r){\n        assert(0<=l&&l<=r&&r<=n);\n\
    \        if(l==r)return;\n        int ql=l>>6,qr=r>>6;\n        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;\n\
    \        if(ql==qr)return void(dat[ql]^=ml&mr);\n        if(l&63)dat[ql++]^=ml;\n\
    \        if(r&63)dat[qr]^=mr;\n        for(int i=ql;i<qr;i++)dat[i]=~dat[i];\n\
    \    }\n    int count_range(int l,int r)const{\n        assert(0<=l&&l<=r&&r<=n);\n\
    \        if(l==r)return 0;\n        int ql=l>>6,qr=r>>6;\n        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;\n\
    \        if(ql==qr)return __builtin_popcountll(dat[ql]&ml&mr);\n        int res=0;\n\
    \        if(l&63)res+=__builtin_popcountll(dat[ql++]&ml);\n        if(r&63)res+=__builtin_popcountll(dat[qr]&mr);\n\
    \        for(int i=ql;i<qr;i++)res+=__builtin_popcountll(dat[i]);\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bitset.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:48:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/linear-algebra/matrix_product_mod_2.test.cpp
documentation_of: data-structure/bitset.hpp
layout: document
redirect_from:
- /library/data-structure/bitset.hpp
- /library/data-structure/bitset.hpp.html
title: data-structure/bitset.hpp
---
