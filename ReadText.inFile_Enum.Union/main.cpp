#include "process.hpp"

int main() {

    std::fstream file("input.txt");

    if (!file.is_open()) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        Date date;
        processLine(line, date);
        printDate(date);
    }

    file.close();

    return 0;
}