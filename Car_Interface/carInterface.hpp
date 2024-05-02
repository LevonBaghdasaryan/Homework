#ifndef __CARINTERFACE__
#define __CARINTERFACE__

#include <iostream>
#include <string>

class CarInterface {
    public:
        virtual void move() = 0;
        virtual void stop() = 0;
        virtual void turnOnSportMode() = 0;
        virtual void increaseSpeed() = 0;
        virtual void brake() = 0;

        virtual ~CarInterface() {}
};

#endif // __CARINTERFACE__