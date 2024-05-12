#include "zoo.hpp"
#include "animals.hpp"
#include "lion.hpp"
#include "bear.hpp"

int main() {

    Zoo& zoo = Zoo::getInstance("Safari Park");

    zoo.addAnimals(new Lion(8));
    zoo.addAnimals(new Bear(20));

    zoo.displayAnimals(); 
    return 0;
}