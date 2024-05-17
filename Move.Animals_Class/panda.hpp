#ifndef __PANDA_HPP__
#define __PANDA_HPP__

#include "animals.hpp"

class Panda : public Animals {
    public:
        Panda(const int &age) : Animals("Panda", age) {}
        void displayInformation() override;
};

#endif // __PANDA_HPP__