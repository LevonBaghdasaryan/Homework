#ifndef __PANDA_HPP__
#define __PANDA_HPP__

#include "animals.hpp"

class Panda : public Animals {
    public:
        explicit Panda(const int &age, const double &weight) : Animals("Panda", age, weight) {}
        void displayInformation() override;
};

#endif // __PANDA_HPP__