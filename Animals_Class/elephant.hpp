#ifndef __ELEPHANT__
#define __ELEPHANT__

#include "animals.hpp"

class Elephant : public Animals {
    public:
        Elephant(const int &age, const double &weight) : Animals("Elephant", age, weight) {}
        void animalInformation() override;
};

#endif // __ELEPHANT__