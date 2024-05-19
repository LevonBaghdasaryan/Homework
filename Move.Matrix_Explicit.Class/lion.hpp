#ifndef __LION_HPP__
#define __LION_HPP__

#include "animals.hpp"

class Lion : public Animals {
    public:
        explicit Lion(const int &age, const double &weight) : Animals("Lion", age, weight) {}
        void displayInformation() override;
};

#endif // __LION_HPP__