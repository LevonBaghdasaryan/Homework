#include <iostream>
#include <memory>

template <typename T>
class Matrix {
    public:
        Matrix(const std::size_t& rows, const std::size_t cols) : _rows(rows), _cols(cols) {
            _data = std::make_unique<std::unique_ptr<T[]>[]>(_rows);
            for(std::size_t i = 0; i < _rows; ++i) {
                _data[i] = std::make_unique<T[]>(_cols);
            }
        }

        Matrix(const Matrix&) = delete;
        Matrix& operator=(const Matrix&) = delete;

        Matrix(Matrix&&) = default;
        Matrix& operator=(Matrix&&) = default; 

        void setValue(const std::size_t& rows, const std::size_t cols, const T& value) {
            if (rows >= _rows || cols >= _cols) {
                throw std::out_of_range("Index out of range");
            }
            _data[rows][cols] = value;
        }

        T getValue(const std::size_t& rows, const std::size_t cols) const {
            if (rows >= _rows || cols >= _cols) {
                throw std::out_of_range("Index out of range");
            }
            return _data[rows][cols];
        }

        std::size_t getRows() const {
            return _rows;
        }

        std::size_t getCols() const {
            return _cols;
        }

        void display() const {
            for(std::size_t i = 0; i < _rows; ++i) {
                for(std::size_t j = 0; j < _cols; ++j) {
                    std::cout << _data[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
    private:
        std::size_t _rows;
        std::size_t _cols;
        std::unique_ptr<std::unique_ptr<T[]>[]> _data;
};

int main() {

    std::size_t rows = 3;
    std::size_t cols = 3;

    Matrix<int> data(rows, cols);

    for(std::size_t i = 0; i < rows; ++i) {
        for(std::size_t j = 0; j < cols; ++j) {
            data.setValue(i, j, i * 5 + j);
        }
    }
    
    std::cout << "Matrix: " << std::endl;
    data.display();

    return 0;
}