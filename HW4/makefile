CC=g++
SOURCES1=diary.cpp pdadd.cpp
OBJECTS1=$(SOURCES1:.cpp=.o)
SOURCES2=diary.cpp pdlist.cpp
OBJECTS2=$(SOURCES2:.cpp=.o)
SOURCES3=diary.cpp pdremove.cpp
OBJECTS3=$(SOURCES3:.cpp=.o)
SOURCES4=diary.cpp pdshow.cpp
OBJECTS4=$(SOURCES4:.cpp=.o)
EXECUTABLE=pdadd pdlist pdshow pdremove

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS1) $(OBJECTS2) $(OBJECTS3) $(OBJECTS4)
	$(CC) $(OBJECTS1) -o pdadd
	$(CC) $(OBJECTS2) -o pdlist
	$(CC) $(OBJECTS3) -o pdremove
	$(CC) $(OBJECTS4) -o pdshow

clean:
	rm -rf $(OBJECTS1) $(OBJECTS2) $(OBJECTS3) $(OBJECTS4) $(EXECUTABLE)
