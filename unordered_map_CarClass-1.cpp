#include <iostream>
#include <string>
#include <unordered_map>

using str = const std::string&;

class Car {
    public:
        Car(str make, str model, int year) : _make(make), _model(model), _year(year) {}

        bool operator==(const Car &other) const {
            return _make == other._make && _model == other._model && _year == other._year;
        }

        std::string getMake() const {
            return _make;
        }

        std::string getModel() const {
            return _model;
        }

        int getYear() const {
            return _year;
        }

    private:
        std::string _make;
        std::string _model;
        int _year;
};

struct CarHash {
    std::size_t operator()(const Car &car) const {
        std::size_t hashValue = 0;
        const std::string& make = car.getMake();
        const std::string& model = car.getModel();
        int year = car.getYear();

        for (char ch : make) {
            hashValue = hashValue * 31 + ch;
        }

        for (char ch : model) {
            hashValue = hashValue * 31 + ch;
        }

        hashValue = hashValue * 31 + std::hash<int>()(year);

        return hashValue;
    }
};

int main() {

    std::unordered_map<Car, int, CarHash> carMap;

    Car car1("BMW", "X5", 2022);
    Car car2("Mercedes", "C-Class", 2021);
    Car car3("Toyota", "Camry", 2020);

    carMap[car1] = 1;
    carMap[car2] = 2;
    carMap[car3] = 3;

    for (const auto& pair : carMap) {
        const Car& car = pair.first;
        std::cout << "Car: " << car.getMake() << " " << car.getModel() << " " << car.getYear() << " -> Value: " << pair.second << std::endl;
    }

    return 0;
}