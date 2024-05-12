CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS := main.cpp zoo.cpp animals.cpp lion.cpp bear.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET = myprogram

$(TARGET): $(OBJS) $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(CXX) $(CXXFLAGS) -c -o $@ $^

.PHONY: clean
clean: rm -f $(TARGET) $(OBJS)