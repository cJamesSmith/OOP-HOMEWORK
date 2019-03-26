CC=g++
SOURCES=Course.cpp Lesson.cpp main.cpp Student.cpp 
INCLUDE=Student.h Course.h Lesson.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
