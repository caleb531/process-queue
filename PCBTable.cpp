/**
 * PCB Table implementation
 */
#include <cstddef>
#include "PCBTable.h"
using namespace std;


PCBTable::PCBTable() {
	process_count = 0;
}

void PCBTable::insertProc(PCB* added) {
	// Only add process if there is space in the table
	if (process_count < MAX_PROCESS_COUNT) {
		processes[process_count] = added;
		process_count++;
	}
}

PCB* PCBTable::getPCB(int i) {
	return processes[i];
}

int PCBTable::getIndex(int PCBID) {
	int result = -1;
	for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
		if (processes[i]->getID() == PCBID) {
			result = i;
			break;
		}
	}

	return result;
}

void PCBTable::clear() {
	for (int i = 0; i < process_count; i++) {
		delete processes[i];
		processes[i] = NULL;
	}
	process_count = 0;
}
