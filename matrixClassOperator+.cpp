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

        // Assignment operator +

        Matrix operator+(const Matrix& other) {
            if(_rows != other._rows || _cols != other._cols) {
                std::cout << " Matrix sizes do not match: " << std::endl;
                return *this;
            }

            Matrix result(_rows, _cols);

            for(size_t i = 0; i < _rows; ++i) {
                for(size_t j = 0; j < _cols; ++j) {
                    result._matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
                }
            }
            return result;
        }


    private:
        unsigned int _rows;
        unsigned int _cols;
        int **_matrix;
};

int main() {

    Matrix matrix1(3,4);

    matrix1.inputMatrix();
    std::cout << "Matrix 1: " << std::endl;
    matrix1.printMatrix();

    Matrix matrix2(matrix1);

    std::cout << "Matrix 2:" << std::endl;
    matrix2.printMatrix();

    Matrix matrix3 = matrix1 + matrix2;
    std::cout << "Sum of Matrix:" << std::endl;
    matrix3.printMatrix();

    return 0;
}