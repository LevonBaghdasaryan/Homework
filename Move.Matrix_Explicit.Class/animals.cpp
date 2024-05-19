#include "animals.hpp"

Animals::Animals(Animals&& other) noexcept {
    _name = std::move(other._name);
    _age = other._age;
    _weight = other._weight;

   other. _name = "";
   other._age = 0;
   other._weight = 0;  
}

Animals& Animals::operator=(Animals&& other) noexcept {
    if(this != &other) {
        _name = std::move(other._name);
        _age = other._age;
        _weight = other._weight;

        other. _name = "";
        other._age = 0;
        other._weight = 0; 
    }
    return *this;
}

bool Animals::operator<(const Animals& other) const {
    if(_age == other._age) {
        return _weight < other._weight;
    }
    return _age < other._age;
}

bool Animals::operator>(const Animals& other) const {
     if(_age == other._age) {
        return _weight > other._weight;
    }
    return _age > other._age;
}

bool Animals::operator==(const Animals& other) const {
    return  (_name == other._name && _age == other._age && _weight == other._weight);
}