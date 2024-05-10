#ifndef __FROG__
#define __FROG__

#include "animals.hpp"
#include "amphibian.hpp"

class Frog : public Animals, public Amphibian  {
    public:
        Frog(str name, str habitat) : Amphibian(name, habitat) {}

        void additionalInfo() override;
};

#endif // __FROG__