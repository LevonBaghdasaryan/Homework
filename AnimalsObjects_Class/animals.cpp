#include "animals.hpp"

int Animals::_count = 0;

Animals::Animals() {
    if(_count == 10) {
        std::cout << "Termination of the program. It is not allowed to use more than 10 objects: " << std::endl;
        exit(0);
    }
    ++_count;
}

Animals::Animals(const Animals& other) {
    _count++;
}

Animals::~Animals() {
    --_count;
}

int Animals::getCount() {
    return Animals::_count;
}
