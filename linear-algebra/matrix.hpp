#pragma once

template<class T,int SIZE>
struct Matrix:array<array<T,SIZE>,SIZE>{
    Matrix(T val=T(0)){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                this->at(i).at(j)=val;
            }
        }
    }
    static constexpr Matrix additive_identity(){
        return Matrix();
    }
    static constexpr Matrix multiplicative_identity(){
        Matrix res;
        for(int i=0;i<SIZE;i++){
            res[i][i]=1;
        }
        return res;
    }
    Matrix& operator+=(const Matrix &rhs){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                this->at(i).at(j)+=rhs[i][j];
            }
        }
        return *this;
    }
    Matrix& operator-=(const Matrix &rhs){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                this->at(i).at(j)-=rhs[i][j];
            }
        }
        return *this;
    }
    Matrix& operator*=(const Matrix &rhs){
        Matrix res;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                for(int k=0;k<SIZE;k++){
                    res[i][j]+=this->at(i).at(k)*rhs[k][j];
                }
            }
        }
        return *this=res;
    }
    Matrix& operator*=(const T &val){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                this->at(i).at(j)*=val;
            }
        }
        return *this;
    }
    constexpr Matrix operator-()const{return Matrix(*this)*=-1;}
    friend constexpr Matrix operator+(const Matrix &lhs,const Matrix &rhs){return Matrix(lhs)+=rhs;}
    friend constexpr Matrix operator-(const Matrix &lhs,const Matrix &rhs){return Matrix(lhs)-=rhs;}
    friend constexpr Matrix operator*(const Matrix &lhs,const Matrix &rhs){return Matrix(lhs)*=rhs;}
    friend constexpr Matrix operator*(const Matrix &lhs,const T &rhs){return Matrix(lhs)*=rhs;}
    friend constexpr Matrix operator*(const ll &lhs,const Matrix &rhs){return Matrix(rhs)*=lhs;}

    constexpr Matrix pow(ll n){
        Matrix base=*this;
        Matrix res=multiplicative_identity();
        while(n>0){
            if(n&1)res*=base;
            base*=base;
            n>>=1;
        }
        return res;
    }
};