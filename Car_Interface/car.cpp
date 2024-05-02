#include "car.hpp"

void Car::move() {
    std::cout << _year << " " << _brand << " is moving.\n";
}

void Car::stop() {
    std::cout << _year << " " << _brand << " stopped.\n";
}

void Car::turnOnSportMode() {
    std::cout << _year << " " << _brand << " sport mode turned on.\n";
}

void Car::increaseSpeed() {
    std::cout << _year << " " << _brand << " speed increased.\n";
}

void Car::brake() {
    std::cout << _year << " " << _brand << " brakes applied.\n";
}