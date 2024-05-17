#include "animals.hpp"

Animals::Animals(Animals&& other) noexcept {
    std::cout << "Move constructor" << std::endl;
    _name = std::move(other._name);
    _age = other._age;

   other. _name = "";
   other._age = 0;  
}

Animals& Animals::operator=(Animals&& other) noexcept {
    std::cout << "Move assignment operator: " << std::endl;
    if(this != &other) {
        _name = std::move(other._name);
        _age = other._age;

        other. _name = "";
        other._age = 0; 
    }
    return *this;
}