#g++
CC=g++
CFLAGS=-c -Wall -Dmain=SDL_main
LDFLAGS=-L/usr/local/lib -static-libgcc -static-libstdc++ -lmingw32 -lSDLmain -lSDL -lopengl32 -lws2_32 -lwinmm
SOURCES=DancingSquid.cpp Main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=gameloop
EXECUTABLE_CYGWIN=gameloop

default: mingw

mingw: $(SOURCES) $(EXECUTABLE)

clean:
	rm *.o *.exe

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $? $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@