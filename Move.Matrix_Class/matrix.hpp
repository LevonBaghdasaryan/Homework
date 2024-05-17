#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <random>

class Matrix {
    public:
        Matrix(const int &rows, const int &cols);
        ~Matrix();

        Matrix(const Matrix&) = delete;
        Matrix& operator=(const Matrix&) = delete;

        Matrix(Matrix&& other) noexcept;
        Matrix& operator=(Matrix&& other) noexcept;

        void inputMatrix();
        void printMatrix() const;
    private:
        int _rows;
        int _cols;
        int **_matrix;
};

#endif // __MATRIX_HPP__