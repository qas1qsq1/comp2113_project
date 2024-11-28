CC = g++
CFLAGS = -Wall -Wextra -g3
SOURCES = main.cpp randomevent.cpp buff.cpp debuff1.cpp fight.cpp winner.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = output

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
