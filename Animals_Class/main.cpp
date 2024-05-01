#include "animals.hpp"

#include "lion.hpp"
#include "tiger.hpp"
#include "bear.hpp"
#include "wolf.hpp"
#include "elephant.hpp"

int main() {
    const int numAnimals = 5;

    Animals *animals[numAnimals] = { new Lion(5, 200), new Tiger(10, 250), new Bear(20, 500), new Wolf(8, 60), new Elephant(30, 5000) };

    std::cout << "Animals: \n" << std::endl;

    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->animalInformation();
        std::cout << std::endl;
    }

    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}