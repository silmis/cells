PROGRAM = cells
CXX = g++
LDFLAGS = -Wall -g -std=c++0x
RM = rm -f
SRC_FILES = src/main.cpp src/Grid.cpp src/Ruleset.cpp src/Simulator.cpp
#SRC_FILES = src/$(SRC_NAMES)
OBJECTS = $(patsubst %.cpp, %.o, $(SRC_FILES))
TARGET = bin

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(TARGET)/$@ $(OBJECTS)

%.o: %.cpp
	$(CXX) -c -o $@ $< -std=c++0x

clean:
	$(RM) $(OBJECTS)
