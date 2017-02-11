#!/usr/bin/make

CC = g++ -O2
SRC = PCB.cpp PCBTable.cpp ReadyQueue.cpp main.cpp
PROG = process-queue.out

# Clean project and compile program
build: clean $(PROG)

# Clean project by removing existing executable file
clean:
	rm -f $(PROG)

# Compile the program from the latest source
$(PROG): $(SRC)
	$(CC) $(SRC) -o $(PROG)
