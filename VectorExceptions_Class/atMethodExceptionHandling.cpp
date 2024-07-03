#include <iostream>
#include <vector>

template <typename T>
class Vector {
    public:
        Vector(const std::vector<T>& v) : _vector(v) {}
        
        void print() const {
            for(const auto& i : _vector) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
        
        std::size_t getSize() const {
            return _vector.size();
        }
        
        T& atMecthod(const int& index) {
            if(index < 0 || index > _vector.size()) {
                throw std::out_of_range("Error: Index out of bounds.");
            }
            return _vector.at(index);
        }
        
        const T& atMecthod(const int& index) const {
            if(index < 0 || index > _vector.size()) {
                throw std::out_of_range("Error: Index out of bounds.");
            }
            return _vector.at(index);
        }
        
    private:
        std::vector<T> _vector;
};

int main() {
    
    Vector<int> vector({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    int n = 0;
    std::cout << "Enter the number: ";
    std::cin >> n;
    
    try {
        std::cout << "Vector: ";
        vector.print();
        int value = vector.atMecthod(n);
        std::cout << "Value at index " << n << ": " << value << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
        std::cout << "The size of the vector is 0 - " << vector.getSize() << std::endl;
    }
    
    return 0;
}