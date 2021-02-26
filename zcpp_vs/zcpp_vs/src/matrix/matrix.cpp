#pragma once
#include "matrix.hpp"

template<typename T>
Matrix<T>::Matrix() : rows(0), cols(0)
{
    matrix = std::vector<T>();
};
template<typename T>
Matrix<T>::Matrix(const int& rows, const int& cols) : rows(rows), cols(cols)
{
    this->matrix = std::vector<T>(rows * cols);
};
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m) : rows(m.rows), cols(m.cols)
{
    this->matrix = std::vector<T>(m.rows * m.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            this->matrix[i * this->cols + j] = m(i, j);
};
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m)
{
    if (this != &m) {
        this->matrix = std::vector<T>(m.rows * m.cols);
        this->rows = m.rows;
        this->cols = m.cols;
        for (int i = 0; i < m.rows; ++i)
            for (int j = 0; j < m.cols; ++j)
                this->matrix[i * this->cols + j] = m(i, j);
    }
    return *this;
}
template<typename T>
int Matrix<T>::get_rows()
{
    return rows;
}
template<typename T>
int Matrix<T>::get_cols()
{
    return cols;
}
template<typename T>
Matrix<T> operator+(const Matrix<T>& m1, const Matrix<T>& m2)
{
    if (m1.rows != m2.rows || m1.cols != m2.cols)
        throw std::out_of_range("");
    Matrix<T> m = Matrix<T>(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; ++i)
        for (int j = 0; j < m1.cols; ++j)
            m(i, j) = m1(i, j) + m2(i, j);
    return m;
};
template<typename T>
Matrix<T> operator-(const Matrix<T>& m1, const Matrix<T>& m2)
{
    if (m1.rows != m2.rows || m1.cols != m2.cols)
        throw std::out_of_range("");
    Matrix<T> m = Matrix<T>(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; ++i)
        for (int j = 0; j < m1.cols; ++j)
            m(i, j) = m1(i, j) - m2(i, j);
    return m;
};
template<typename T>
Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2)
{
    if (m1.rows != m2.cols || m1.cols != m2.rows)
        throw std::out_of_range("");
    Matrix<T> m = Matrix<T>(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; ++i)
        for (int j = 0; j < m2.cols; ++j)
            for (int k = 0; k < m1.cols; ++k)
                m(i, j) += m1(i, k) * m2(k, j);
    return m;
};
template<typename T>
Matrix<T> Matrix<T>::operator+(const T& c)
{
    Matrix<T> m = Matrix<T>(this->rows, this->cols);
    for (int i = 0; i < this->rows; ++i)
        for (int j = 0; j < this->cols; ++j)
            m(i, j) = this->matrix[i * this->cols + j] + c;
    return m;
};
template<typename T>
Matrix<T> Matrix<T>::operator*(const T& c)
{
    Matrix<T> m = Matrix<T>(this->rows, this->cols);
    for (int i = 0; i < this->rows; ++i)
        for (int j = 0; j < this->cols; ++j)
            m(i, j) = this->matrix[i * this->cols + j] * c;
    return m;
};
template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> m = Matrix<T>(this->cols, this->rows);
    for (int i = 0; i < this->rows; ++i)
        for (int j = 0; j < this->cols; ++j)
            if (i == j)
                m(j, i) = this->matrix[i * this->cols + j];
            else
                m(j, i) = this->matrix[i * this->cols + j];
    return m;
};
template<typename T>
T& Matrix<T>::operator()(const int& row, const int& col)
{
    if (row < 0 || row >= this->rows || col < 0 || col >= this->cols)
        throw std::out_of_range("Index out of bounds");
    return matrix[row * this->cols + col];
};
template<typename T>
const T& Matrix<T>::operator()(const int& row, const int& col) const
{
    if (row < 0 || row >= this->rows || col < 0 || col >= this->cols)
        throw std::out_of_range("Index out of bounds");
    return matrix[row * this->cols + col];
};
template<typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m)
{
    for (int i = 0; i < m.rows; ++i)
    {
        for (int j = 0; j < m.cols; ++j)
            out << m(i, j) << " ";
        out << std::endl;
    }
    return out;
};
