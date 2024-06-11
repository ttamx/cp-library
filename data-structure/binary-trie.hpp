#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-06-11
 * Description: Binary Trie
 */

template<int BIT,class T = uint32_t,class S = int>
struct BinaryTrie{
    struct Node{
        array<Node*,2> ch;
        S cnt;
        Node():ch{nullptr,nullptr},cnt(0){}
    };
    Node* root;
    BinaryTrie():root(new Node()){}
    S size(){
        return root->cnt;
    }
    S get_cnt(Node* t){
        return t?t->cnt:0;
    }
    void insert(T x,S k=1){
        Node* t=root;
        t->cnt+=k;
        for(int i=BIT-1;i>=0;i--){
            int u=x>>i&1;
            if(!t->ch[u])t->ch[u]=new Node();
            t=t->ch[u];
            t->cnt+=k;
        }
    }
    void erase(T x,S k=1){
        Node* t=root;
        t->cnt-=k;
        for(int i=BIT-1;i>=0;i--){
            int u=x>>i&1;
            t=t->ch[u];
            t->cnt-=k;
        }
    }
    T kth(S k,T x=0){
        Node* t=root;
        T res=0;
        for(int i=BIT-1;i>=0;i--){
            int u=x>>i&1;
            if(k<get_cnt(t->ch[u])){
                t=t->ch[u];
            }else{
                res|=T(1)<<i;
                k-=get_cnt(t->ch[u]);
                t=t->ch[u^1];
            }
        }
        return res;
    }
    T min(T x){
        return kth(0,x);
    }
    T max(T x){
        return kth(size()-1,x);
    }
};