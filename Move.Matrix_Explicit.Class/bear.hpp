#ifndef __BEAR_HPP__
#define __BEAR_HPP__

#include "animals.hpp"

class Bear : public Animals {
    public:
        explicit Bear(const int &age, const double &weight) : Animals("Bear", age, weight) {}
        void displayInformation() override;
};

#endif // __BEAR_HPP__