//
// Created by Parth Parakh on 07/01/21.
//

#ifndef __MATRIX_CPP
#define __MATRIX_CPP
#include "matrix.h"

template<typename T>
QSMatrix<T>::QSMatrix(unsigned int rows_, unsigned int cols_, const T &_initials) : rows(rows_), cols(cols_)
{
    mat.resize(rows_);
    for(int i = 0;i<mat.size();i++)
    {
        mat[i].resize(cols_,_initials);
    }
}

template<typename T>
QSMatrix<T>::QSMatrix(const QSMatrix<T> &rhs) : rows(rhs.rows),cols (rhs.cols)
{
    (*this).mat = rhs.mat;
    (*this).rows = rhs.get_rows();
    (*this).cols = rhs.get_cols();
}

template<typename T>
QSMatrix<T> & QSMatrix<T>::operator=(const QSMatrix<T> &rhs)
{
    if(*this==rhs) return *this;
    rows = rhs.get_rows();
    cols = rhs.get_cols();
    (*this).mat.resize(rows);
    for(int i=0;i<mat.size();i++)
    {
        (*this).mat[i].resize(cols);
    }

    for(auto i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            (*this).mat[i][j] = rhs[i][j];
        }
    }
    return *this;
}

template<typename T>
QSMatrix<T> QSMatrix<T>::operator*(const QSMatrix<T> &rhs)
{
    if(rhs.rows!=(*this).rows && rhs.cols!=(*this).cols) return NULL;
    QSMatrix RES(rows,cols,0);
    for (unsigned i=0; i<rows; i++)
    {
        for (unsigned j=0; j<cols; j++)
        {
            for (unsigned k=0; k<rows; k++)
            {
                RES[i][j] += this->mat[i][k] * rhs[k][j];
            }
        }
    }
    return RES;
}

template<typename T>
QSMatrix<T> & QSMatrix<T>::operator*=(const QSMatrix<T> &rhs)
{
    QSMatrix m = (*this).mat*rhs.mat;
    return (*this)=m;
}

template<typename T>
QSMatrix<T> & QSMatrix<T>::operator+=(const QSMatrix<T> &rhs)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            (*this).mat[i][j] += rhs[i][j];
        }
    }
}

template<typename T>
QSMatrix<T> QSMatrix<T> ::operator+(const QSMatrix<T> &rhs)
{
    QSMatrix RES(rows,cols,0);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            RES[i][j] =  (*this).mat[i][j] + rhs.mat[i][j];
        }
    }
}

template<typename T>
QSMatrix<T> QSMatrix<T>::operator-(const QSMatrix<T>& rhs)
{
    QSMatrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            result[i][j] = this->mat[i][j] - rhs(i,j);
        }
    }
    return result;
}

template<typename T>
QSMatrix<T>& QSMatrix<T>::operator-=(const QSMatrix<T>& rhs)
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            this->mat[i][j] -= rhs[i][j];
        }
    }
    return *this;
}

template<typename T>
QSMatrix<T> QSMatrix<T> ::transpose()
{
    QSMatrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            result[i][j] = this->mat[j][i];
        }
    }
    return result;
}

template<typename T>
QSMatrix<T> QSMatrix<T>::operator+(const T& rhs)
{
    QSMatrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            result[i][j] = this->mat[i][j] + rhs;
        }
    }
    return result;
}


template<typename T>
QSMatrix<T> QSMatrix<T>::operator-(const T& rhs)
{
    QSMatrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            result[i][j] = this->mat[i][j] - rhs;
        }
    }
    return result;
}

template<typename T>
QSMatrix<T> QSMatrix<T>::operator*(const T& rhs)
{
    QSMatrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            result[i][j] = this->mat[i][j] * rhs;
        }
    }
    return result;
}

template<typename T>
QSMatrix<T> QSMatrix<T>::operator/(const T& rhs)
{
    QSMatrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            result[i][j] = this->mat[i][j] / rhs;
        }
    }
    return result;
}


template<typename T>
std::vector<T> QSMatrix<T>::operator*(const std::vector<T>& rhs)
{
    std::vector<T> result(rhs.size(), 0.0);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            result[i] = this->mat[i][j] * rhs[j];
        }
    }

    return result;
}

template<typename T>
std::vector<T> QSMatrix<T>::diag_vec()
{
    std::vector<T> result(rows, 0.0);
    for (int i=0; i<rows; i++)
    {
        result[i] = this->mat[i][i];
    }
    return result;
}

template<typename T>
T& QSMatrix<T>::operator()(const unsigned& row, const unsigned& col)
{
    return this->mat[row][col];
}

template<typename T>
const T& QSMatrix<T>::operator()(const unsigned& row, const unsigned& col) const
{
    return this->mat[row][col];
}

template<typename T>
const T& QSMatrix<T>::operator[](const unsigned& row) const
{
    return this->mat[row];
}

template<typename T>
vector<T>& QSMatrix<T>::operator[]( unsigned& row)
{
    return this->mat[row];
}

template<typename T>
T& QSMatrix<T>::operator[](const unsigned& row)
{
    return this->mat[row];
}

template<typename T>
unsigned QSMatrix<T>::get_rows() const
{
    return this->rows;
}

template<typename T>
unsigned QSMatrix<T>::get_cols() const
{
    return this->cols;
}



#endif

