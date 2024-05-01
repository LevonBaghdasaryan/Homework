#ifndef __TIGER__
#define __TIGER__

#include "animals.hpp"

class Tiger : public Animals {
    public:
        Tiger(const int &age, const double &weight) : Animals("Tiger", age, weight) {}
        void animalInformation() override;
};

#endif // __TIGER__