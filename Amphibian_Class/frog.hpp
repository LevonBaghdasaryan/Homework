#ifndef __FROG__
#define __FROG__

#include "amphibian.hpp"

class Frog : public Amphibian {
    public:
        Frog(str name, str habitat) : Amphibian(name, habitat) {}

        void additionalInfo() override;
};

#endif // __FROG__