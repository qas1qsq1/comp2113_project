# Makefile

CXX = g++
CXXFLAGS = -Wall -g
TARGET = game

SOURCES = main.cpp \
           buff.cpp \
           debuff.cpp \
           debuff1.cpp \
           fight.cpp \
           randomevent.cpp \
           winner.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
