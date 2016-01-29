CC=g++
SDL2_CFLAGS := $(shell sdl2-config --cflags)
SDL2_LDFLAGS := $(shell sdl2-config --libs) -lSDL2_image
# -Weffc++ disabled for now
CFLAGS=-Wall -Wextra -Og -ansi -pedantic -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wzero-as-null-pointer-constant -Wuseless-cast -Wsign-conversion -Waggregate-return -Wno-aggressive-loop-optimizations -Wpadded -Wredundant-decls -fsanitize=address
OPTFLAGS=-O2 -Wdisabled-optimization
SRC=*.cpp
INC=../headers

.PHONY: all
all: main

.PHONY: debug
debug: main_debug

main: $(SRC)
	$(CC) $(CFLAGS) $(SDL2_CFLAGS) -I$(INC) -o $@ $^ $(SDL2_LDFLAGS)
