# Compiler
CC=gcc

# Compiler flags
CFLAGS=-c -DLINUX -I/mingw64/include/SDL2 -D_WINDOWS

# Linker flags
LDFLAGS=-L/mingw64/lib -lSDL2 -lSDL2_gfx

# Source files
SOURCES=Main.cpp Game.cpp Board.cpp IO.cpp Pieces.cpp

# Object files
OBJECTS=$(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE=tetris

# Default target
all: $(EXECUTABLE)

# Link object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Rule for compiling .cpp files to .o files
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# Clean up build files
clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)
