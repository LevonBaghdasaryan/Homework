#ifndef __MATRIXCLASS_HPP__
#define __MATRIXCLASS_HPP__

#include <iostream>
#include <stdexcept>

template <typename T>
class Matrix {
    public:
        Matrix(const int &rows, const int &cols);
        Matrix(const Matrix<T> &other);
        Matrix<T>& operator=(const Matrix<T> &other);
        ~Matrix();

        void inputMatrix();
        void printMatrix(std::ostream &out) const;

        void setValue(int row, int col, T value);
        T getValue(int row, int col) const;
        int getRows() const;
        int getCols() const;

        Matrix<T> operator*(const Matrix<T> &other) const;

    private:
        int _rows;
        int _cols;
        T **_matrix;

        void allocateMemory();
        void deallocateMemory();
        void copyFrom(const Matrix<T> &other);
};

#endif // __MATRIXCLASS_HPP__
