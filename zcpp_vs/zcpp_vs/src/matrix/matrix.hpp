#pragma once
#include <vector>
#include <iostream>

template<typename T>
class Matrix
{
    std::vector<T> matrix;
    int rows;
    int cols;

    public:
        Matrix();
        Matrix(const int&, const int&);
        Matrix(const Matrix<T>&);
        Matrix<T>& operator=(const Matrix<T>&);

        int get_rows();
        int get_cols();

        template<typename T>
        friend Matrix<T> operator+(const Matrix<T>&, const Matrix<T>&);

        template<typename T>
        friend Matrix<T> operator-(const Matrix<T>&, const Matrix<T>&);

        template<typename T>
        friend Matrix<T> operator*(const Matrix<T>&, const Matrix<T>&);

        Matrix<T> operator+(const T&);
        Matrix<T> operator*(const T&);

        Matrix<T> transpose();
        T& operator()(const int&, const int&);
        const T& operator()(const int&, const int&) const;

        template<typename T>
        friend std::ostream& operator<<(std::ostream&, const Matrix<T>&);
};
