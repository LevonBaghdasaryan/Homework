#include <iostream>

class A {
    public:
        ~A() noexcept(false) {
            std::cout << "A Destructor" << std::endl;
            throw std::runtime_error("Exeption");
        }
};

int main() {
    
    try {
        A obj;
    }
    catch(const std::exception& b) {
        std::cout << b.what() << std::endl;
    }
    
    return 0;
}