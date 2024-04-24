#include <iostream>
#include <string>

class Car {
public:
    Car(const std::string &name, const std::string &licensePlate) : _name(name), _licensePlate(licensePlate) {}

    std::string getName() const {
        return _name;
    }

    std::string getLicensePlate() const {
        return _licensePlate;
    }

private:
    std::string _name;
    std::string _licensePlate;
};

class Parking {
public:
    Parking(const unsigned int &size) : _size(size), _occupied(0), _parkedCar(new Car *[size]) {}

    ~Parking() {
        for (unsigned int i = 0; i < _occupied; ++i) {
            delete _parkedCar[i];
        }
        delete[] _parkedCar;
        _parkedCar = nullptr;
    }

    void parkCar(Car *car) {
        if (_occupied < _size) {
            _parkedCar[_occupied++] = car;
        } else {
            std::cout << "Parking is full. Cannot park the car." << std::endl;
        }
    }

    void printInfo() const {
        std::cout << "Parking Information:" << std::endl;
        std::cout << "Occupied Spaces: " << _occupied << std::endl;
        for (unsigned int i = 0; i < _occupied; ++i) {
            std::cout << "Car " << i + 1 << ": " << std::endl;
            std::cout << "Name - " << _parkedCar[i]->getName() << std::endl;
            std::cout << "License Plate - " << _parkedCar[i]->getLicensePlate() << std::endl;
            std::cout << std::endl;
        }
    }

private:
    Car **_parkedCar;
    unsigned int _size;
    unsigned int _occupied;
};

int main() {

    Parking parkingLot(2);

    Car car1("BMW", "00 OO 000");
    Car car2("Mercedes", "11 AA 111");

    parkingLot.parkCar(&car1);
    parkingLot.parkCar(&car2);

    parkingLot.printInfo();

    return 0;
}