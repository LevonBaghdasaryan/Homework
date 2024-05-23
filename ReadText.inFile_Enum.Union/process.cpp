#include "process.hpp"
#include <cmath>

// empty() function is used to check whether the set container is empty or not.
// The isdigit() in C is a function that can be used to check if the passed character is a digit or not.

bool isInteger(const std::string& str) {
    if (str.empty() || ((str[0] != '-') && !std::isdigit(str[0]))) { 
        return false;
    } 
    for (size_t i = 1; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}


bool isDouble(const std::string& str) {
    std::string modifiedStr = str;
    std::replace(modifiedStr.begin(), modifiedStr.end(), ',', '.');

    if (modifiedStr.empty() || ((modifiedStr[0] != '-') && !std::isdigit(modifiedStr[0]))) {
        return false;
    }

    bool decimalPointFound = false;
    for (size_t i = 1; i < modifiedStr.length(); ++i) {

        if (!std::isdigit(modifiedStr[i]) && modifiedStr[i] != '.') {
            return false;
        }
        if (modifiedStr[i] == '.') {
            if (decimalPointFound) {
                return false;
            }
            decimalPointFound = true;
        }
    }
    return decimalPointFound;
}


bool isChar(const std::string& str) {
    return str.length() == 1;
}


int stringToInt(const std::string& str) {
    int result = 0;
    bool isNegative = false;
    std::size_t index = 0;

    if (str[index] == '-') {
        isNegative = true;
        ++index;
    } 
    else if (str[index] == '+') {
        ++index;
    }

    for (; index < str.length(); ++index) {

        char digit = str[index];
        if (digit >= '0' && digit <= '9') {
            result = result * 10 + (digit - '0');
        } 
        else {
            return 0;
        }
    }

    if (isNegative) {
        result = -result;
    }

    return result;
}

// std::stod is a somehow generic way of converting a std::string to a double.

double stringToDouble(const std::string& str) {
    std::string modifiedStr = str;
    std::replace(modifiedStr.begin(), modifiedStr.end(), ',', '.');
    return std::stod(modifiedStr);
}

void processLine(const std::string& line, Date& date) {

    if (isInteger(line)) {
        date.type = INTEGER;
        date.typeValue.intValue = stringToInt(line);
    }
     else if (isDouble(line)) {
        date.type = DOUBLE;
        date.typeValue.doubleValue = stringToDouble(line);
    } 
    else if (isChar(line)) {
        date.type = CHAR;
        date.typeValue.charValue = line[0];
    } 
    else {
        date.type = STRING;
        std::strncpy(date.typeValue.stringValue, line.c_str(), sizeof(date.typeValue.stringValue) - 1);
        date.typeValue.stringValue[sizeof(date.typeValue.stringValue) - 1] = '\0'; // Ensure null-termination
    }
}

void printDate(const Date& date) {

    switch (date.type) {
        case INTEGER:
            std::cout << "Integer " << date.typeValue.intValue << std::endl;
            break;
        case STRING:
            std::cout << "String " << date.typeValue.stringValue << std::endl;
            break;
        case DOUBLE:
            std::cout << "Double " << date.typeValue.doubleValue << std::endl;
            break;
        case CHAR:
            std::cout << "Char " << date.typeValue.charValue << std::endl;
            break;
        default:
            throw std::runtime_error("Unknown data type");
    }
}