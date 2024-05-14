#include "matrix.hpp"

Matrix::Matrix(const int &rows, const int &cols) : _rows(rows), _cols(cols), _matrix(nullptr) {
    _matrix = new int *[_rows];

    for(size_t i = 0; i < _rows; ++i) {
        _matrix[i] = new int [_cols];
    }
}

Matrix::~Matrix() {
    for (size_t i = 0; i < _rows; ++i) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
}

void Matrix::inputMatrix() {

    for(size_t i = 0; i < _rows; ++i) {
        for(size_t j = 0; j < _cols; ++j) {
            _matrix[i][j] = rand() % 100;
        }
    }
}

void Matrix::printMatrix() const {

    for(size_t i = 0; i < _rows; ++i) {
        for(size_t j = 0; j < _cols; ++j) {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix& Matrix::operator++() {

    for(size_t i = 0; i < _rows; ++i) {
        for(size_t j = 0; j < _cols; ++j) {
            _matrix[i][j] += 3;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp(*this);

    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            _matrix[i][j] += 3;
        }
    }
    return temp;
}

Matrix::Matrix(const Matrix& other) {
    for (size_t i = 0; i < _rows; ++i) {
        for (size_t j = 0; j < _cols; ++j) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (size_t i = 0; i < _rows; ++i) {
            for (size_t j = 0; j < _cols; ++j) {
                _matrix[i][j] = other._matrix[i][j];
            }
        }
    }
    return *this;
}