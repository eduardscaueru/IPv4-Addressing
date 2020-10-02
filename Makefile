CC=gcc
CFLAGS=-std=c99 -Wall -Wextra
EXE=ip

all: build

build: ip.c
	$(CC) $^ $(CFLAGS) -o $(EXE)

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE)

.PHONY: clean run
