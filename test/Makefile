CC=g++
SDL2_CFLAGS := $(shell sdl2-config --cflags)
SDL2_LDFLAGS := $(shell sdl2-config --libs)
CFLAGS=-Wall -Wextra -Og -ansi -pedantic -Weffc++ -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wzero-as-null-pointer-constant -Wuseless-cast -Wsign-conversion -Waggregate-return -Wno-aggressive-loop-optimizations -Wpadded -Wredundant-decls -fsanitize=address
OPTFLAGS=-O2 -Wdisabled-optimization
SRC=test.cpp

.PHONY: all
all: test

test: $(SRC)
	$(CC) $(CFLAGS) $(SDL2_CFLAGS) -o $@ $^ $(SDL2_LDFLAGS)
