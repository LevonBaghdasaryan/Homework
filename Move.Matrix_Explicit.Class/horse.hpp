#ifndef __HORSE_HPP__
#define __HORSE_HPP__

#include "animals.hpp"

class Horse : public Animals {
    public:
        explicit Horse(const int &age, const double &weight) : Animals("Horse", age, weight) {}
        void displayInformation() override;
};

#endif // __HORSE_HPP__