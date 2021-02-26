#pragma once
#include <vector>
#include <ostream>

template<typename T>
class Matrix
{
    std::vector<T> matrix;
    T rows;
    T cols;

    public:
        Matrix();
        Matrix(const T&, const T&);
        Matrix(const Matrix<T>&);
        Matrix<T>& operator=(const Matrix<T>&);

        friend Matrix<T> operator+(const Matrix<T>&, const Matrix<T>&);
        friend Matrix<T> operator-(const Matrix<T>&, const Matrix<T>&);
        friend Matrix<T> operator*(const Matrix<T>&, const Matrix<T>&);

        Matrix<T> operator+(const T&);
        Matrix<T> operator*(const T&);

        Matrix<T> transpose();
        T& operator()(const T&, const T&);
        const T& operator()(const T&, const T&) const;

        friend std::ostream& operator<<(std::ostream&, Matrix<T>&);
};
