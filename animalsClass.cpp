#include <iostream>
#include <string>

class Animals {
    public:
        std::string _name;

        virtual void speak() {
            std::cout << _name << std::endl;
        }

        virtual void voice() = 0;

        virtual ~Animals() {}
};

class Lion : public Animals {
    public:
        void voice() override {
            speak();
            std::cout << "The lion (Panthera leo) is a large cat of the genus Panthera, native to Africa and India:" << std::endl;
        }
};

class Tiger : public Animals {
    public:
        void voice() override {
            speak();
            std::cout << "The tiger (Panthera tigris) is the largest living member of the cat family, the Felidae:" << std::endl;
        }
};

class Bear : public Animals {
    public:
        void voice() override {
            speak();
            std::cout << "Bears are carnivoran mammals of the family Ursidae: " << std::endl;
        }
};

class Wolf : public Animals {
    public:
        void voice() override {
            speak();
            std::cout << "Wolf is the largest extant member of the Canidae family: " << std::endl;
        }
};

class Elephant : public Animals {
    public:
        void voice() override {
            speak();
            std::cout << "Large terrestrial mammals with trunks from Africa and Asia: " << std::endl;
        }
};

int main() {

    const int numAnimals = 5;

    Animals *animals[numAnimals] = { new Lion(), new Tiger(), new Bear(), new Wolf(), new Elephant() };

    animals[0]->_name = "Lion";
    animals[1]->_name = "Tiger";
    animals[2]->_name = "Bear";
    animals[3]->_name = "Wolf";
    animals[4]->_name = "Elephant";

    std::cout << "Animals: \n" << std::endl;

    for (size_t i = 0; i < numAnimals; ++i) {
        animals[i]->voice();
        std::cout << std::endl;
    }

    for (size_t i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}