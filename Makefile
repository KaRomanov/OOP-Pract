CXX = g++

TARGET = main

SRC = $(wildcard util/*.cpp) $(wildcard *.cpp)

HDR = $(wildcard util/*.hpp)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

# Phony targets
.PHONY: all clean
