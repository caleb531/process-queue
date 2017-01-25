#!/usr/bin/make

CC = g++
SRC = pcb.cpp main.cpp
PROG = process-queue.out

# Execute program (the default task when calling `make`)
run: build
	./$(PROG)

# Clean project and compile program
build: clean $(PROG)

# Clean project by removing existing executable file
clean:
	rm -f $(PROG)

# Compile the program from the latest source
$(PROG): $(SRC)
	$(CC) $(SRC) -o $(PROG)
