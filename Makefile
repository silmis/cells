

PROGRAM = cells
CXX = g++
RM = rm -f
SRC_NAMES = main.cpp
SRC_FILES = src/$(SRC_NAMES)
OBJECTS = $(patsubst %.cpp, %.o, $(SRC_FILES))
TARGET = bin

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(TARGET)/$@ $(OBJECTS)

%.o: %.cpp
	$(CXX) -c -o $@ $<

clean:
	$(RM) $(OBJECTS)
