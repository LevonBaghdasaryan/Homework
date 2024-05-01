#ifndef __WOLF__
#define __WOLF__

#include "animals.hpp"

class Wolf : public Animals {
    public:
        Wolf(const int &age, const double &weight) : Animals("Wolf", age, weight) {}
        void animalInformation() override;
};

#endif // __WOLF__