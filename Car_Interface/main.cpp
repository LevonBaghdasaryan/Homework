#include "carInterface.hpp"
#include "car.hpp"

int main() {

    Car car("BMW", 2024);

    car.move();
    car.turnOnSportMode();
    car.increaseSpeed();
    car.brake();
    car.stop();
    
    return 0;
}