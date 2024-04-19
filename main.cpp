#include <iostream>
#include <cstdlib>

class Matrix {
public:
    Matrix(const int &rows, const int &cols) : _rows(rows), _cols(cols) {}

    void dynamicMatrix() {
        _matrix = (int**)malloc(sizeof(int*) * _rows);
        for (size_t i = 0; i < _rows; ++i) {
            _matrix[i] = (int*)malloc(sizeof(int) * _cols);
        }
    }

    void inputMatrix() {
        for (size_t i = 0; i < _rows; ++i) {
            for (size_t j = 0; j < _cols; ++j) {
                _matrix[i][j] = rand() % 100;
            }
        }
    }

    void printMatrix() const {
        for (size_t i = 0; i < _rows; ++i) {
            for (size_t j = 0; j < _cols; ++j) {
                std::cout << _matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void matrixInversion() {
        int *arr = (int*)malloc(sizeof(int) * _rows * _cols);
        int x = 0;
        for (size_t i = 0; i < _rows; ++i) {
            for (size_t j = 0; j < _cols + 1; ++j) {
                arr[x] = _matrix[_rows - j - 1][i];
                x++;
            }
        }

        _invertedMatrix = (int**)malloc(sizeof(int*) * _cols);
        for (size_t i = 0; i < _cols; ++i) {
            _invertedMatrix[i] = (int*)malloc(sizeof(int) * _rows);
        }

        x = 0;
        for (size_t i = 0; i < _cols; ++i) {
            for (size_t j = 0; j < _rows; ++j) {
                _invertedMatrix[i][j] = arr[x];
                x++;
            }
        }
        printInvertedMatrix();
        for (size_t i = 0; i < _cols; ++i) {
            free(_invertedMatrix[i]);
        }
        free(_invertedMatrix);
        free(arr);
    }

    void printInvertedMatrix() const {
        for (size_t i = 0; i < _cols; ++i) {
            for (size_t j = 0; j < _rows; ++j) {
                std::cout << _invertedMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void deallocateMatrix() {
        for (size_t i = 0; i < _rows; ++i) {
            free(_matrix[i]);
        }
        free(_matrix);
    }

private:
    int **_matrix = nullptr;
    int **_invertedMatrix = nullptr;
    unsigned int _rows;
    unsigned int _cols;
};

int main() {

    unsigned int rows = 0;
    unsigned int cols = 0;

    std::cout << "Enter the matrix rows: ";
    std::cin >> rows;

    std::cout << "Enter the matrix cols: ";
    std::cin >> cols;

    Matrix matrix(rows, cols);

    matrix.dynamicMatrix();
    matrix.inputMatrix();

    std::cout << "Original Matrix:" << std::endl;
    matrix.printMatrix();

    // The inverted matrix
    std::cout << "Inverted Matrix:" << std::endl;
    matrix.matrixInversion();

    // Deallocate Matrix
    matrix.deallocateMatrix();

    return 0;
}