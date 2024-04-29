#include <iostream>
#include "animalsClass.hpp"

int main() {

    const int numAnimals = 5;

    Animals *animals[numAnimals] = { new Lion(), new Tiger(), new Bear(), new Wolf(), new Elephant() };

    animals[0]->_name = "Lion";
    animals[1]->_name = "Tiger";
    animals[2]->_name = "Bear";
    animals[3]->_name = "Wolf";
    animals[4]->_name = "Elephant";

    std::cout << "Animals: \n" << std::endl;

    for (size_t i = 0; i < numAnimals; ++i) {
        animals[i]->voice();
        std::cout << std::endl;
    }

    for (size_t i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}