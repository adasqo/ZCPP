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
        Matrix(){};
        Matrix(const T& rows, const T& cols): rows(rows), cols(cols)
        {
            this->matrix = std::vector<T>(rows*cols);
        };
        Matrix(const Matrix<T>& m): rows(m.rows), cols(m.cols)
        {
            this->matrix = std::vector<T>(m.rows*m.cols);
            for(int i=0; i<m.rows; ++i)
                for(int j=0; j<m.cols; ++j)
                    this->matrix[i*this->cols + j] = m(i, j);
        };
        Matrix<T>& operator=(const Matrix<T>& m)
        {    
            if (this != &m) {
                this->matrix = std::vector<T>(m.rows*m.cols);
                this->rows = m.rows;
                this->cols = m.cols;
                for(int i=0; i<m.rows; ++i)
                    for(int j=0; j<m.cols; ++j)
                        this->matrix[i*this->cols + j] = m(i, j);
            }
            return *this;
        }

        friend Matrix<T> operator+(const Matrix<T>& m1, const Matrix<T>& m2)
        {
            if(m1.rows != m2.rows || m1.cols != m2.cols)
                throw std::out_of_range("");
            Matrix<T> m = Matrix<T>(m1.rows, m1.cols);
            for(int i=0; i<m1.rows; ++i)
                for(int j=0; j<m1.cols; ++j)
                    m(i, j) = m1(i, j) + m2(i, j);
            return m;
        };
        friend Matrix<T> operator-(const Matrix<T>& m1, const Matrix<T>& m2)
        {
            if(m1.rows != m2.rows || m1.cols != m2.cols)
                throw std::out_of_range("");
            Matrix<T> m = Matrix<T>(m1.rows, m1.cols);
            for(int i=0; i<m1.rows; ++i)
                for(int j=0; j<m1.cols; ++j)
                    m(i, j) = m1(i, j) - m2(i, j);
            return m;
        };
        friend Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2)
        {
            if(m1.rows != m2.cols || m1.cols != m2.rows)
                throw std::out_of_range("");
            Matrix<T> m = Matrix<T>(m1.rows, m2.cols);
            for(int i=0; i<m1.rows; ++i)
                for(int j=0; j<m2.cols; ++j)
                    for(int k=0; k<m1.cols; ++k)
                        m(i, j) += m1(i, k) * m2(k, j);
            return m;
        };

        Matrix<T> operator+(const T& c)
        {
            Matrix<T> m = Matrix<T>(this->rows, this->cols);
            for(int i=0; i<this->rows; ++i)
                for(int j=0; j<this->cols; ++j)
                    m(i, j) = this->matrix[i*this->cols + j] + c;
            return m;
        };
        Matrix<T> operator*(const T& c)
        {
            Matrix<T> m = Matrix<T>(this->rows, this->cols);
            for(int i=0; i<this->rows; ++i)
                for(int j=0; j<this->cols; ++j)
                    m(i, j) = this->matrix[i*this->cols + j]*c;
            return m;
        };

        Matrix<T> transpose()
        {
            Matrix<T> m = Matrix<T>(this->rows, this->cols);
            for(int i=0; i<this->rows; ++i)
                for(int j=0; j<this->cols; ++j)
                    if(i == j)
                        m(i, j) = this->matrix[i*this->cols + j];
                    else
                        m(this->rows - i - 1, this->cols - j - 1) = this->matrix[i*this->cols + j];
            return m;
        };
        T& operator()(const T& row, const T& col)
        {
            if(row < 0 || row >= this->rows || col < 0 || col >= this->cols)
                throw std::out_of_range("Index out of bounds");
            return matrix[row*this->cols + col];
        };
        const T& operator()(const T& row, const T& col) const
        {
            if(row < 0 || row >= this->rows || col < 0 || col >= this->cols)
                throw std::out_of_range("Index out of bounds");
            return matrix[row*this->cols + col];
        }

        friend std::ostream& operator<<(std::ostream& out, Matrix<T>& m)
        {
            for(int i=0; i<m.rows; ++i)
            {
                for(int j=0; j<m.cols; ++j)
                    out << m(i, j) << " ";
                out << std::endl;
            }
            return out;
        };
};
