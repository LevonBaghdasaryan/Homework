#ifndef __LION__
#define __LION__

#include "animals.hpp"

class Lion : public Animals {
    public:
        Lion(const int &age, const double &weight) : Animals("Lion", age, weight) {}
        void animalInformation() override;
};

#endif // __LION__