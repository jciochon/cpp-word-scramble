CC=g++ -I./scrambler.hpp
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=scrambler.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=scrambler

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE)
	rm $(OBJECTS)