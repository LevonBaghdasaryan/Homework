#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>

class Matrix {
    public:
        Matrix(const int &rows, const int &cols);
        ~Matrix();

        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& other);

        void inputMatrix();
        void printMatrix() const;

        Matrix& operator++();
        Matrix operator++(int);
    private:
        int _rows;
        int _cols;
        int **_matrix;
};

#endif // __MATRIX_HPP__