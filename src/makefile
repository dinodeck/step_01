#g++

CC=g++
CFLAGS=-c -Wall -Dmain=SDL_main
LDFLAGS= -lSDLmain -lSDL
SOURCES=Dinodeck.cpp Main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=dinodeck

ifeq (${PLATFORM_DS},WINDOWS)
	CFLAGS+= -I/usr/include
	CFLAGS+= `sdl-config --cflags --static-libs`
	# LDFLAGS+= `sdl-config --libs`
	LDFLAGS+=-L/usr/lib -static-libstdc++ -lmingw32 -lopengl32 -lws2_32 -lwinmm
endif

ifeq (${PLATFORM_DS},MAC)
	CFLAGS+= -I/opt/local/include
	LDFLAGS+= `sdl-config --cflags --static-libs` -BStatic
	LDFLAGS+= -L/opt/local/lib -framework OpenGL -framework Cocoa
endif

default: mingw

mingw: $(SOURCES) $(EXECUTABLE)

clean:
	rm *.o *.exe $(EXECUTABLE) 2> /dev/null || true

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $? $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@