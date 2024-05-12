#include "zoo.hpp"

Zoo& Zoo::getInstance(const std::string &name) {
    static Zoo instance(name);
    return instance;
}

void Zoo::addAnimals(Animals* a) {
    if(_numAnimals < _size) {
        animals[_numAnimals++] = a;
    }
    else {
        std::cout << "Zoo is full: " << std::endl;
    }
}

void Zoo::displayAnimals() const {
    
    std::cout << "Zoo name is: " << _name << "\n"<< std::endl;
    std::cout << "Animals: " << std::endl;

    for(size_t i = 0; i < _size; ++i) {
        std::cout << "Animal Name - " << animals[i]->getSpecies() << std::endl;
        std::cout << "Age - " << animals[i]->getAge() << std::endl;
        std::cout << std::endl;
    }
}