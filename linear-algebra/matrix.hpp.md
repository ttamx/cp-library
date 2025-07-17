---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linear-algebra/matrix.hpp\"\n\ntemplate<class T,int SIZE>\n\
    struct Matrix:array<array<T,SIZE>,SIZE>{\n    Matrix(T val=T(0)){\n        for(int\
    \ i=0;i<SIZE;i++){\n            for(int j=0;j<SIZE;j++){\n                this->at(i).at(j)=val;\n\
    \            }\n        }\n    }\n    static constexpr Matrix additive_identity(){\n\
    \        return Matrix();\n    }\n    static constexpr Matrix multiplicative_identity(){\n\
    \        Matrix res;\n        for(int i=0;i<SIZE;i++){\n            res[i][i]=1;\n\
    \        }\n        return res;\n    }\n    Matrix& operator+=(const Matrix &rhs){\n\
    \        for(int i=0;i<SIZE;i++){\n            for(int j=0;j<SIZE;j++){\n    \
    \            this->at(i).at(j)+=rhs[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n    Matrix& operator-=(const Matrix &rhs){\n        for(int\
    \ i=0;i<SIZE;i++){\n            for(int j=0;j<SIZE;j++){\n                this->at(i).at(j)-=rhs[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix& operator*=(const\
    \ Matrix &rhs){\n        Matrix res;\n        for(int i=0;i<SIZE;i++){\n     \
    \       for(int j=0;j<SIZE;j++){\n                for(int k=0;k<SIZE;k++){\n \
    \                   res[i][j]+=this->at(i).at(k)*rhs[k][j];\n                }\n\
    \            }\n        }\n        return *this=res;\n    }\n    Matrix& operator*=(const\
    \ T &val){\n        for(int i=0;i<SIZE;i++){\n            for(int j=0;j<SIZE;j++){\n\
    \                this->at(i).at(j)*=val;\n            }\n        }\n        return\
    \ *this;\n    }\n    constexpr Matrix operator-()const{return Matrix(*this)*=-1;}\n\
    \    friend constexpr Matrix operator+(const Matrix &lhs,const Matrix &rhs){return\
    \ Matrix(lhs)+=rhs;}\n    friend constexpr Matrix operator-(const Matrix &lhs,const\
    \ Matrix &rhs){return Matrix(lhs)-=rhs;}\n    friend constexpr Matrix operator*(const\
    \ Matrix &lhs,const Matrix &rhs){return Matrix(lhs)*=rhs;}\n    friend constexpr\
    \ Matrix operator*(const Matrix &lhs,const T &rhs){return Matrix(lhs)*=rhs;}\n\
    \    friend constexpr Matrix operator*(const ll &lhs,const Matrix &rhs){return\
    \ Matrix(rhs)*=lhs;}\n\n    constexpr Matrix pow(ll n){\n        Matrix base=*this;\n\
    \        Matrix res=multiplicative_identity();\n        while(n>0){\n        \
    \    if(n&1)res*=base;\n            base*=base;\n            n>>=1;\n        }\n\
    \        return res;\n    }\n};\n"
  code: "#pragma once\n\ntemplate<class T,int SIZE>\nstruct Matrix:array<array<T,SIZE>,SIZE>{\n\
    \    Matrix(T val=T(0)){\n        for(int i=0;i<SIZE;i++){\n            for(int\
    \ j=0;j<SIZE;j++){\n                this->at(i).at(j)=val;\n            }\n  \
    \      }\n    }\n    static constexpr Matrix additive_identity(){\n        return\
    \ Matrix();\n    }\n    static constexpr Matrix multiplicative_identity(){\n \
    \       Matrix res;\n        for(int i=0;i<SIZE;i++){\n            res[i][i]=1;\n\
    \        }\n        return res;\n    }\n    Matrix& operator+=(const Matrix &rhs){\n\
    \        for(int i=0;i<SIZE;i++){\n            for(int j=0;j<SIZE;j++){\n    \
    \            this->at(i).at(j)+=rhs[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n    Matrix& operator-=(const Matrix &rhs){\n        for(int\
    \ i=0;i<SIZE;i++){\n            for(int j=0;j<SIZE;j++){\n                this->at(i).at(j)-=rhs[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix& operator*=(const\
    \ Matrix &rhs){\n        Matrix res;\n        for(int i=0;i<SIZE;i++){\n     \
    \       for(int j=0;j<SIZE;j++){\n                for(int k=0;k<SIZE;k++){\n \
    \                   res[i][j]+=this->at(i).at(k)*rhs[k][j];\n                }\n\
    \            }\n        }\n        return *this=res;\n    }\n    Matrix& operator*=(const\
    \ T &val){\n        for(int i=0;i<SIZE;i++){\n            for(int j=0;j<SIZE;j++){\n\
    \                this->at(i).at(j)*=val;\n            }\n        }\n        return\
    \ *this;\n    }\n    constexpr Matrix operator-()const{return Matrix(*this)*=-1;}\n\
    \    friend constexpr Matrix operator+(const Matrix &lhs,const Matrix &rhs){return\
    \ Matrix(lhs)+=rhs;}\n    friend constexpr Matrix operator-(const Matrix &lhs,const\
    \ Matrix &rhs){return Matrix(lhs)-=rhs;}\n    friend constexpr Matrix operator*(const\
    \ Matrix &lhs,const Matrix &rhs){return Matrix(lhs)*=rhs;}\n    friend constexpr\
    \ Matrix operator*(const Matrix &lhs,const T &rhs){return Matrix(lhs)*=rhs;}\n\
    \    friend constexpr Matrix operator*(const ll &lhs,const Matrix &rhs){return\
    \ Matrix(rhs)*=lhs;}\n\n    constexpr Matrix pow(ll n){\n        Matrix base=*this;\n\
    \        Matrix res=multiplicative_identity();\n        while(n>0){\n        \
    \    if(n&1)res*=base;\n            base*=base;\n            n>>=1;\n        }\n\
    \        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: linear-algebra/matrix.hpp
  requiredBy: []
  timestamp: '2025-03-14 23:36:46+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linear-algebra/matrix.hpp
layout: document
redirect_from:
- /library/linear-algebra/matrix.hpp
- /library/linear-algebra/matrix.hpp.html
title: linear-algebra/matrix.hpp
---
