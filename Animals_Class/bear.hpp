#ifndef __BEAR__
#define __BEAR__

#include "animals.hpp"

class Bear : public Animals {
    public:
        Bear(const int &age, const double &weight) : Animals("Bear", age, weight) {} 
        void animalInformation() override;
};

#endif // __BEAR__