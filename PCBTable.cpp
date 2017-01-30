/**
 * PCB Table implementation
 * Caleb Evans
 */
#include <cstddef>
#include "PCBTable.h"
using namespace std;


PCBTable::PCBTable() {
	process_count = 0;
}

// Add the supplied PCB instance to the table
void PCBTable::insertProc(PCB* added) {
	// Only add process if there is space in the table
	if ((process_count + 1) < MAX_PROCESS_COUNT) {
		process_count++;
		processes[process_count] = added;
	}
}

// Retrieve a reference to a PCB instance in the table by its index
PCB* PCBTable::getPCB(int i) {
	return processes[i];
}

// Remove all elements in the PCB table
void PCBTable::clear() {
	for (int i = 0; i < process_count; i++) {
		delete processes[i];
		processes[i] = NULL;
	}
	process_count = 0;
}
