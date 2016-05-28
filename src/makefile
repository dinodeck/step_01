#g++

CC=g++
CFLAGS=-c -Wall -Dmain=SDL_main
LDFLAGS= -lSDLmain -lSDL
SOURCES=Dinodeck.cpp Main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=dinodeck

ifeq (${PLATFORM_DD},WINDOWS)
	CFLAGS+= -I/usr/include
	CFLAGS+= `sdl-config --cflags --static-libs`
	# LDFLAGS+= `sdl-config --libs`
	LDFLAGS:=-Wl,-Bstatic -L/usr/local/lib -lmingw32 $(LDFLAGS)
	LDFLAGS+=-L/usr/lib -static-libstdc++ -lopengl32 -lws2_32 -lwinmm
	LDFLAGS+=-liconv -lm -luser32 -lgdi32 -lwinmm -static-libgcc -static-libstdc++
endif

ifeq (${PLATFORM_DD},MAC)
	SDLLIBS= -Bstatic `sdl-config --static-libs`

	LDFLAGS+= $(SDLLIBS)
	LDFLAGS+= -L/opt/local/lib -framework OpenGL -framework Cocoa
endif

default: mingw

mingw: $(SOURCES) $(EXECUTABLE)

clean:
	rm *.o $(EXECUTABLE) 2> /dev/null || true

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $? $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@