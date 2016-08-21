CC=g++
CFLAGS=-c -Wall
LDFLAGS= 
SDLFLAGS=-lSDL2 -lSDL2_gfx
SOURCES=main.cpp Vec.cpp Mat.cpp Transform.cpp LTimer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=VillageEngine

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(SDLFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm $(EXECUTABLE) $(OBJECTS)
