#include "animalsClass.hpp"
#include <iostream>

void Animals::speak() {
    std::cout << _name << std::endl;
}

Animals::~Animals() {}

void Lion::voice() {
    speak();
    std::cout << "The lion (Panthera leo) is a large cat of the genus Panthera, native to Africa and India:" << std::endl;
}

void Tiger::voice() {
    speak();
    std::cout << "The tiger (Panthera tigris) is the largest living member of the cat family, the Felidae:" << std::endl;
}

void Bear::voice() {
    speak();
    std::cout << "Bears are carnivoran mammals of the family Ursidae: " << std::endl;
}

void Wolf::voice() {
    speak();
    std::cout << "Wolf is the largest extant member of the Canidae family: " << std::endl;
}

void Elephant::voice() {
    speak();
    std::cout << "Large terrestrial mammals with trunks from Africa and Asia: " << std::endl;
}
