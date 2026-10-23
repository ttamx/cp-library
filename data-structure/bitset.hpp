#pragma once

struct BitSet{
    using u64 = uint64_t;
    vector<u64> dat;
    int n;
    
    static u64 maskbit(int p){return 1ULL<<p;}

    struct Proxy{
        u64 &dat;
        int idx;
        Proxy(vector<u64> &d,int i):dat(d[i>>6]),idx(i&63){}
        operator bool()const{return (dat>>idx)&1;}
        bool operator~()const{return ((dat>>idx)&1)^1;}
        Proxy &flip(){dat^=maskbit(idx);return *this;}
        Proxy &operator=(bool x){
            if(x)dat|=maskbit(idx);
            else dat&=~maskbit(idx);
            return *this;
        }
        Proxy &operator=(const Proxy &o){return *this=bool(o);}
        Proxy &operator|=(bool x){if(x)dat|=maskbit(idx);return *this;}
        Proxy &operator&=(bool x){if(!x)dat&=~maskbit(idx);return *this;}
        Proxy &operator^=(bool x){if(x)dat^=maskbit(idx);return *this;}
    };

    explicit BitSet(int _n=0,bool x=false):dat((_n+63)>>6,u64(x?-1:0)),n(_n){trim();}

    int size()const{return n;}
    void trim(){if(n&63)dat.back()&=maskbit(n&63)-1;}
    void resize(int m,bool x=false){
        assert(m>=0);
        if(x&&n<m&&(n&63))dat[n>>6]|=u64(-1)<<(n&63);
        dat.resize((m+63)>>6,u64(x?-1:0));
        n=m;
        trim();
    }
    void push_back(bool x){
        if((n&63)==0)dat.push_back(0);
        if(x)dat[n>>6]|=maskbit(n&63);
        n++;
    }
    void pop_back(){
        assert(n>0);
        n--;
        if((n&63)==0)dat.pop_back();
        else dat.back()&=maskbit(n&63)-1;
    }

    Proxy operator[](int i){
        assert(0<=i&&i<n);
        return Proxy(dat,i);
    }
    bool operator[](int i)const{
        assert(0<=i&&i<n);
        return (dat[i>>6]>>(i&63))&1;
    }

    void set(){fill(ALL(dat),u64(-1));trim();}
    void reset(){fill(ALL(dat),0);}
    void flip(){for(auto &x:dat)x=~x;trim();}
    void set(int i){(*this)[i]=1;}
    void reset(int i){(*this)[i]=0;}
    void flip(int i){(*this)[i].flip();}

    int count()const{
        int res=0;
        for(auto x:dat)res+=__builtin_popcountll(x);
        return res;
    }
    bool any()const{
        for(auto x:dat)if(x)return true;
        return false;
    }
    bool none()const{return !any();}
    bool all()const{return count()==n;}

    BitSet &operator&=(const BitSet &o){
        assert(n==o.n);
        for(int i=0;i<SZ(dat);i++)dat[i]&=o.dat[i];
        return *this;
    }
    BitSet &operator|=(const BitSet &o){
        assert(n==o.n);
        for(int i=0;i<SZ(dat);i++)dat[i]|=o.dat[i];
        return *this;
    }
    BitSet &operator^=(const BitSet &o){
        assert(n==o.n);
        for(int i=0;i<SZ(dat);i++)dat[i]^=o.dat[i];
        return *this;
    }
    BitSet &operator<<=(int k){
        assert(k>=0);
        if(k>=n)return reset(),*this;
        int q=k>>6,r=k&63,m=SZ(dat);
        if(!r){
            for(int i=m-1;i>=q;i--)dat[i]=dat[i-q];
        }else{
            for(int i=m-1;i>q;i--)dat[i]=(dat[i-q]<<r)|(dat[i-q-1]>>(64-r));
            dat[q]=dat[0]<<r;
        }
        fill(dat.begin(),dat.begin()+q,0);
        trim();
        return *this;
    }
    BitSet &operator>>=(int k){
        assert(k>=0);
        if(k>=n)return reset(),*this;
        int q=k>>6,r=k&63,m=SZ(dat);
        if(!r){
            for(int i=0;i+q<m;i++)dat[i]=dat[i+q];
        }else{
            for(int i=0;i+q+1<m;i++)dat[i]=(dat[i+q]>>r)|(dat[i+q+1]<<(64-r));
            dat[m-q-1]=dat[m-1]>>r;
        }
        fill(dat.end()-q,dat.end(),0);
        return *this;
    }
    BitSet operator&(const BitSet &o)const{return BitSet(*this)&=o;}
    BitSet operator|(const BitSet &o)const{return BitSet(*this)|=o;}
    BitSet operator^(const BitSet &o)const{return BitSet(*this)^=o;}
    BitSet operator<<(int k)const{return BitSet(*this)<<=k;}
    BitSet operator>>(int k)const{return BitSet(*this)>>=k;}
    bool operator==(const BitSet &o){return n==o.n&&dat==o.dat;}
    bool operator!=(const BitSet &o){return !(*this==o);}
    BitSet operator~()const{
        BitSet o(*this);
        o.flip();
        return o;
    }

    int find_next(int i)const{ // first set bit >= i, n if none
        if(i<0)i=0;
        if(i>=n)return n;
        int q=i>>6;
        u64 x=dat[q]&(u64(-1)<<(i&63));
        while(!x){
            if(++q==SZ(dat))return n;
            x=dat[q];
        }
        return q<<6|__builtin_ctzll(x);
    }
    int find_prev(int i)const{ // last set bit <= i, -1 if none
        if(i>=n)i=n-1;
        if(i<0)return -1;
        int q=i>>6;
        u64 x=dat[q]&(u64(-1)>>(63-(i&63)));
        while(!x){
            if(--q<0)return -1;
            x=dat[q];
        }
        return q<<6|(63-__builtin_clzll(x));
    }
    int find_first()const{return find_next(0);}
    int find_last()const{return find_prev(n-1);}

    void set_range(int l,int r){
        assert(0<=l&&l<=r&&r<=n);
        if(l==r)return;
        int ql=l>>6,qr=r>>6;
        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;
        if(ql==qr)return void(dat[ql]|=ml&mr);
        if(l&63)dat[ql++]|=ml;
        if(r&63)dat[qr]|=mr;
        for(int i=ql;i<qr;i++)dat[i]=u64(-1);
    }
    void reset_range(int l,int r){
        assert(0<=l&&l<=r&&r<=n);
        if(l==r)return;
        int ql=l>>6,qr=r>>6;
        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;
        if(ql==qr)return void(dat[ql]&=~(ml&mr));
        if(l&63)dat[ql++]&=~ml;
        if(r&63)dat[qr]&=~mr;
        for(int i=ql;i<qr;i++)dat[i]=u64(0);
    }
    void flip_range(int l,int r){
        assert(0<=l&&l<=r&&r<=n);
        if(l==r)return;
        int ql=l>>6,qr=r>>6;
        u64 ml=u64(-1)<<(l&63),mr=maskbit(r&63)-1;
        if(ql==qr)return void(dat[ql]^=ml&mr);
        if(l&63)dat[ql++]^=ml;
        if(r&63)dat[qr]^=mr;
        for(int i=ql;i<qr;i++)dat[i]=~dat[i];
    }
    int count_range(int l,int r)const{
        assert(0<=l&&l<=r&&r<=n);
        int res=0;
        while(l<r&&(l&63))res+=(*this)[l++];
        while(l<r&&(r&63))res+=(*this)[--r];
        for(int i=l>>6;i<(r>>6);i++)res+=__builtin_popcountll(dat[i]);
        return res;
    }
};