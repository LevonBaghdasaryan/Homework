#ifndef __CAR__
#define __CAR__

#include "carInterface.hpp"

class Car : public CarInterface {
    public:
        Car(const std::string &brand, const int &year) : _brand(brand), _year(year) {}

        void move() override;
        void stop() override;
        void turnOnSportMode() override;
        void increaseSpeed() override;
        void brake() override;

    private:
        std::string _brand;
        int _year;
};

#endif // __CAR__