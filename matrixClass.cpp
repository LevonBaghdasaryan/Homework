#include <iostream>
#include <cstdlib>

class Matrix {
    public:
        // Constructor
        Matrix(const unsigned int &rows, const unsigned int &cols) : _rows(rows), _cols(cols) {

            _matrix = new int* [_rows];

            for(size_t i = 0; i < _rows; ++i) {
                _matrix[i] = new int[_cols];
            }
        }

        // Destructor
        ~Matrix() {

            // Deallocate memory
            for(size_t i = 0; i < _rows; ++i) {
                delete[] _matrix[i];
            }
            delete[] _matrix;
        }

        void inputMatrix() {
            for(size_t i = 0; i < _rows; ++i) {
                for(size_t j = 0; j < _cols; ++j) {
                    _matrix[i][j] = rand() % 100;
                }
            }
        }

        void printMatrix() const {
            for(size_t i = 0; i < _rows; ++i) {
                for(size_t j = 0; j < _cols; ++j) {
                    std::cout << _matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        // Copy Constructor
        Matrix(const Matrix& other) : _rows(other._rows), _cols(other._cols) {

            _matrix = new int* [_rows];

            for(size_t i = 0; i < _rows; ++i) {
                _matrix[i] = new int[_cols];

                for(size_t j = 0; j < _cols; ++j) {
                    _matrix[i][j] = other._matrix[i][j];
                }
            }
        }

        // Assignment operators

        Matrix& operator=(const Matrix& other) {
            if(this != &other) {

                for(size_t i = 0; i < _rows; ++i) {
                    delete[] _matrix[i];
                }
                delete[] _matrix;


                _rows = other._rows;
                _cols = other._cols;


                _matrix = new int* [_rows];

                for(size_t i = 0; i < _rows; ++i) {
                    _matrix[i] = new int[_cols];

                    for(size_t j = 0; j < _cols; ++j) {
                        _matrix[i][j] = other._matrix[i][j];
                    }
                }
            }
            return *this;
        }


    private:
        unsigned int _rows;
        unsigned int _cols;
        int **_matrix;
};

int main() {

    Matrix matrix(3,4);

    matrix.inputMatrix();
    std::cout << "Matrix: " << std::endl;
    matrix.printMatrix();

    Matrix matrix2(matrix);

    std::cout << "Matrix 2:" << std::endl;
    matrix2.printMatrix();

    return 0;
}