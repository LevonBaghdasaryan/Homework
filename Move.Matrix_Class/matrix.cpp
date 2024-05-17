#include "matrix.hpp"

Matrix::Matrix(const int &rows, const int &cols) : _rows(rows), _cols(cols), _matrix(nullptr) {
    std::cout << "Matrix constructor: " << std::endl;
    _matrix = new int *[_rows];

    for(size_t i = 0; i < _rows; ++i) {
        _matrix[i] = new int [_cols];
    }
}

Matrix::~Matrix() {
     std::cout << "Matrix destructor: " << std::endl;
    for (int i = 0; i < _rows; ++i) {
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

Matrix::Matrix(Matrix&& other) noexcept {
    std::cout << "Move constructor: " << std::endl;
    _rows = other._rows;
    _cols = other._cols;
    _matrix = other._matrix;

    other._rows = 0;
    other._cols = 0;
    other._matrix = nullptr;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    std::cout << "Move assignment operator: " << std::endl;
    if (this != &other) {
        for (int i = 0; i < _rows; ++i) {
            delete[] _matrix[i];
        }
        delete[] _matrix;

        _rows = other._rows;
        _cols = other._cols;
        _matrix = other._matrix;

        other._rows = 0;
        other._cols = 0;
        other._matrix = nullptr;
    }
    return *this;
}