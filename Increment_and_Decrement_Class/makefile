CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS := main.cpp incrementDecrement.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET = myprogram

$(TARGET): $(OBJS) $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(CXX) $(CXXFLAGS) -c -o $@ $^

.PHONY: clean
clean: rm -f $(TARGET) $(OBJS)