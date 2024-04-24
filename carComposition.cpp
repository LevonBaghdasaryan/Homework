#include <iostream>
#include <string>

class Engine {
    public:
        Engine(const std::string &type) : _type(type) {}

        void engineInfo() const {
            std::cout << "Starting " << _type << " engine:" << std::endl;
        }
    private:
        std::string _type;
};

class GearBox {
    public:
        GearBox(const std::string &gearBox) : _gearBox(gearBox) {}

        void gearBoxInfo() const {
            std::cout << "The transmission is - " << _gearBox << ": " << std::endl;
        }
    private:
        std::string _gearBox;
};

class Car {
    public:
        Car(const std::string &name, const std::string &engineType, const std::string &gearBoxType) : _name(name), c_engine(engineType), c_gearBox(gearBoxType) {}

        void printCarName() const {
            std::cout << "Car name - " << _name << std::endl;
        }

        void engineInfo() {
            c_engine.engineInfo();
        }

        void gearBoxInfo() {
            c_gearBox.gearBoxInfo();
        }
    private:
        std::string _name;
        Engine c_engine;
        GearBox c_gearBox;
};

int main() {

    Car car("BMW", "TwinPower Turbo", "Automatic");

    car.printCarName();
    car.engineInfo();
    car.gearBoxInfo();

    return 0;
}