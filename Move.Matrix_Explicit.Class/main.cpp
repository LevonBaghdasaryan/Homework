#include "animals.hpp"
#include "lion.hpp"
#include "tiger.hpp"
#include "panda.hpp"
#include "bear.hpp"
#include "horse.hpp"

void findAndDisplayTopBigAnimals(Animals* animals[], const int size) {
    Animals* max1 = animals[0];
    Animals* max2 = nullptr;
    Animals* max3 = nullptr;

    for(size_t i = 0; i < size; ++i) {
        if(*animals[i] > *max1) {
            max3 = max2;
            max2 = max1;
            max1 = animals[i];
        }
        else if (!max2 || *animals[i] > *max2) {
            max3 = max2;
            max2 = animals[i];
        }
        else if (!max3 || *animals[i] > *max3) {
            max3 = animals[i];
        }
    }

    std::cout << "Top 3 animals: " << std::endl;

    max1->displayInformation();
    max2->displayInformation();
    max3->displayInformation();
}

int main() {

    // Animals

    // Lion
    Lion lion1(12, 180.0);
    Lion lion2(std::move(lion1));

    // Tiger
    Tiger tiger(15, 300.0);

    // Panda
    Panda panda(18, 110.0);

    // Bear
    Bear bear(25, 300.0);

    // Horse
    Horse horse(30, 350.0);  

    Animals* animals[] = {&lion1, &tiger, &panda, &bear, &horse};
    findAndDisplayTopBigAnimals(animals, 5);

    return 0;
}
