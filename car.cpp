#include <iostream>
#include <string>

using str = const std::string&;

class Car {

    public:

        Car(str mark, str model, const int &year, str e, const double &eV, str bB, const int &speed, str sW) :
         _mark(mark), _model(model), _year(year), _engine(e), _engineVolume(eV), _broadcostBox(bB), _speed(speed), _stceringWheel(sW) {}

        void displayInfo() const {
            
            std::cout << "Is the vehicle data:\n" << std::endl;

            std::cout << "Mark: " << _mark << std::endl;
            std::cout << "Model: " << _model << std::endl;
            std::cout << "Year: " << _year << std::endl;
            std::cout << "Engine: " << _engine << std::endl;
            std::cout << "Engine Volume: " << _engineVolume << std::endl;
            std::cout << "Broadcost Box: " << _broadcostBox << std::endl;
            std::cout << "Speed: " << _speed << std::endl;
            std::cout << "Stcering Wheel: " << _stceringWheel << std::endl;
        }

    private:
        std::string _mark;
        std::string _model;
        int _year;
        std::string _engine;
        double _engineVolume;
        std::string _broadcostBox;
        int _speed;
        std::string _stceringWheel;
};

int main() {
    
    Car car("BMW", "5 Series", 2020, "Dizel", 3.0, "Automatic", 400, "left");

    car.displayInfo();

    return 0;
}