#include <iostream>
#include <string>

using str = const std::string&;

class Car {
public:
    Car(str brand, const int &year) : _brand(brand), _year(year) {}

    void display() const {
        std::cout << "Brand - " << _brand << std::endl;
        std::cout << "Year - " << _year << std::endl;
    }

protected:
    std::string _brand;
    int _year;
};

class Engine : public Car {
public:
    Engine(str brand, const int &year, str type) : Car(brand, year), _type(type) {}

    void display() const {
        Car::display();
        std::cout << "Engine type - " << _type << std::endl;
    }

protected:
    std::string _type;
};

class GearBox : public Engine {
public:
    GearBox(str brand, const int &year, str type, str gearBox) : Engine(brand, year, type), _gearBox(gearBox) {}

    void display() const {
        Engine::display();
        std::cout << "GearBox - " << _gearBox << std::endl;
    }

private:
    std::string _gearBox;
};

class Style : public GearBox {
public:
    Style(str brand, const int &year, str type, str gearBox, str carColor) : GearBox(brand, year, type, gearBox), _carColor(carColor) {}

    void display() const {
        GearBox::display();
        std::cout << "Car color - " << _carColor << std::endl;
    }

private:
    std::string _carColor;
};

// --------------------------Models------------------------------

class TheBestCar : public Style { 
public:
    TheBestCar(str brand, const int &year, str type, str gearBox, str carColor, bool hasSoftTop) : Style(brand, year, type, gearBox, carColor), _hasSoftTop(hasSoftTop) {}

    void display() const {
        std::cout << "The Best Car: " << std::endl;
        Style::display();
        std::cout << "Convertible - " << (_hasSoftTop ? "Yes" : "No") << std::endl;
    }
private:
    bool _hasSoftTop;
};

class SportsCar : public Style {
public:
    SportsCar(str brand, const int &year, str type, str gearBox, str carColor, bool isConvertible) : Style(brand, year, type, gearBox, carColor), _isConvertible(isConvertible) {}

    void display() const {
        std::cout << "Sports Car: " << std::endl;
        Style::display();
        std::cout << "Convertible - " << (_isConvertible ? "Yes" : "No") << std::endl;
    }
private:
    bool _isConvertible;
};

class ElectricCar : public Style {
public:
    ElectricCar(str brand, const int &year, str type, str gearBox, str carColor, const int &batteryCapacity) : Style(brand, year, type, gearBox, carColor), _batteryCapacity(batteryCapacity) {}

    void display() const {
        std::cout << "Electric Car: " << std::endl;
        Style::display();
        std::cout << "Battery Capacity - " << _batteryCapacity << std::endl;
    }
private:
    int _batteryCapacity;
};

int main() {
    
    TheBestCar car("BMW", 2024, "V8", "Automatic", "Black", false);
    car.display();
    std::cout << std::endl;

    SportsCar sportsCar("Ferrari", 2023, "V12", "Manual", "Yellow", true);
    sportsCar.display();
    std::cout << std::endl;

    ElectricCar electricCar("Tesla", 2024, "Electric", "Automatic", "Silver", 100);
    electricCar.display();
    std::cout << std::endl;

    return 0;
}