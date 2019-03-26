CC=g++
SOURCES=castle.cpp main.cpp room.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
