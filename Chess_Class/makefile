CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS := main.cpp king.cpp queen.cpp boat.cpp horse.cpp elephant.cpp soldier.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET = myprogram

$(TARGET): $(OBJS) $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(CXX) $(CXXFLAGS) -c -o $@ $^

.PHONY: clean
clean: rm -f $(TARGET) $(OBJS)