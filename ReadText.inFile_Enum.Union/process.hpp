#ifndef __PROCESS_HPP__
#define __PROCESS_HPP__

#include <iostream>
#include <fstream>
#include <string>

enum Types {
    INTEGER,
    STRING,
    DOUBLE,
    CHAR,
};

union WordUnion {
    int intValue;
    char stringValue[50];
    double doubleValue;
    char charValue;
};

struct Date {
    Types type;
    WordUnion typeValue;
};

bool isInteger(const std::string &str);
bool isDouble(const std::string &str);
bool isChar(const std::string &str);

int stringToInt(const std::string &str);
double stringToDouble(const std::string &str);

void processLine(const std::string& line, Date& date);
void printDate(const Date& date);

#endif // __PROCESS_HPP__