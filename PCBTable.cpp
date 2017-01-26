/**
 * PCB Table implementation
 * Caleb Evans
 */
#include "PCBTable.h"
using namespace std;


PCBTable::PCBTable() {
	process_count = 0;
}

// Add the supplied PCB instance to the table
void PCBTable::add(PCB added) {
	// Only add process if there is space in the table
	if ((process_count + 1) < MAX_PROCESS_COUNT) {
		process_count++;
		processes[process_count] = added;
	}
}
