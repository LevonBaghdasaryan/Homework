#include "TV.hpp"

void TV::powerOn() {
    std::cout << "TV is powered on." << std::endl;
}

void TV::powerOff() {
    std::cout << "TV is powered off." << std::endl;
}

void TV::volumeUp() {
    std::cout << "Up the TV volume." << std::endl;
}

void TV::volumeDown() {
    std::cout << "Down the TV volume." << std::endl;
}

void TV::setChannel() {
    std::cout << "Enabled channel " << _channel << " is " << std::endl;
}