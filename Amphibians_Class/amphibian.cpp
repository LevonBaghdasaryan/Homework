#include "amphibian.hpp"

void Amphibian::displayInfo() const {
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Habitat: " << _habitat << std::endl; 
}

void Amphibian::additionalInfo() {
    // Default implementation does nothing
}