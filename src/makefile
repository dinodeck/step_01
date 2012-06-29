#g++
CC=g++
CFLAGS=-c -Wall -Dmain=SDL_main
LDFLAGS=-L/usr/local/lib -static-libgcc -static-libstdc++ -lmingw32 -lSDLmain -lSDL -lopengl32 -lws2_32 -lwinmm
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=gameloop

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $? $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@