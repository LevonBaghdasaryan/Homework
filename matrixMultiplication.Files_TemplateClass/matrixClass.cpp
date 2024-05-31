#include "matrixClass.hpp"
#include <cstdlib> // for rand()

template <typename T>
Matrix<T>::Matrix(const int &rows, const int &cols) : _rows(rows), _cols(cols), _matrix(nullptr) {
    allocateMemory();
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &other) : _rows(other._rows), _cols(other._cols), _matrix(nullptr) {
    allocateMemory();
    copyFrom(other);
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &other) {
    std::cout << "operator=()" << std::endl;
    if (this != &other) {
        deallocateMemory();
        _rows = other._rows;
        _cols = other._cols;
        allocateMemory();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Matrix<T>::~Matrix() {
    deallocateMemory();
}

template <typename T>
void Matrix<T>::allocateMemory() {
    _matrix = new T*[_rows];
    for (std::size_t i = 0; i < _rows; ++i) {
        _matrix[i] = new T[_cols]();
    }
}

template <typename T>
void Matrix<T>::deallocateMemory() {
    for (std::size_t i = 0; i < _rows; ++i) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
}

template <typename T>
void Matrix<T>::copyFrom(const Matrix<T> &other) {
    for (std::size_t i = 0; i < _rows; ++i) {
        for (std::size_t j = 0; j < _cols; ++j) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::inputMatrix() {
    for (std::size_t i = 0; i < _rows; ++i) {
        for (std::size_t j = 0; j < _cols; ++j) {
            _matrix[i][j] = rand() % 100;
        }
    }
}

template <typename T>
void Matrix<T>::printMatrix(std::ostream &out) const {
    for (std::size_t i = 0; i < _rows; ++i) {
        for (std::size_t j = 0; j < _cols; ++j) {
            out << _matrix[i][j] << " ";
        }
        out << std::endl;
    }
}

template <typename T>
void Matrix<T>::setValue(int row, int col, T value) {
    _matrix[row][col] = value;
}

template <typename T>
T Matrix<T>::getValue(int row, int col) const {
    return _matrix[row][col];
}

template <typename T>
int Matrix<T>::getRows() const {
    return _rows;
}

template <typename T>
int Matrix<T>::getCols() const {
    return _cols;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
    std::cout << "operator*()" << std::endl;
    if (_cols != other._rows) {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication");
    }

    Matrix<T> result(_rows, other._cols);
    for (std::size_t i = 0; i < _rows; ++i) {
        for (std::size_t j = 0; j < other._cols; ++j) {
            for (std::size_t k = 0; k < _cols; ++k) {
                result._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
            }
        }
    }
    return result;
}

template class Matrix<int>;
template class Matrix<double>;