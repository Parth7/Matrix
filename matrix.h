//
// Created by Parth Parakh on 07/01/21.
//

#ifndef _MATRIX_H
#define _MATRIX_H

#include<vector>

using namespace std;

template<typename T>
class  QSMatrix
{
private :
    vector<vector<T>> mat;
    unsigned rows;
    unsigned cols;
public:
    QSMatrix(unsigned rows_,unsigned cols_,const T& _initials);
    QSMatrix(const QSMatrix<T> & rhs);
    virtual ~QSMatrix() = default;
    QSMatrix<T> &operator=(const QSMatrix<T> &rhs);
    QSMatrix<T> &operator+=(const QSMatrix<T> &rhs);
    QSMatrix<T> operator +(const QSMatrix<T> &rhs);
    QSMatrix<T> &operator*=(const QSMatrix<T> &rhs);
    QSMatrix<T> operator *(const QSMatrix<T> &rhs);
    QSMatrix<T> operator -(const QSMatrix<T> &rhs);
    QSMatrix<T> &operator -=(const QSMatrix<T> &rhs);
    QSMatrix<T> transpose();

    QSMatrix<T> operator +(const T& rhs);
    QSMatrix<T> operator -(const T& rhs);
    QSMatrix<T> operator *(const T& rhs);
    QSMatrix<T> operator /(const T& rhs);

    vector<T> operator *(const vector<T> &v);
    vector<T> diag_vec();

    T& operator()(const unsigned& row, const unsigned& col);
    vector<T>& operator[]( unsigned& row);
    const T& operator()(const unsigned & row, const unsigned& col) const;

    T& operator[](const unsigned& a);
    const T& operator[](const unsigned &a) const;

    [[nodiscard]]
    unsigned get_rows() const;
    [[nodiscard]]
    unsigned get_cols() const;
};

#include"matrix.cpp"
#endif
