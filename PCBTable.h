/**
 * PCB Table definition
 * Caleb Evans
 */
#pragma once
#include "PCB.h"
using namespace std;


class PCBTable {

	protected:

		// The maximum number of running processes to allow (for efficiency)
		static const int MAX_PROCESS_COUNT = 20;

		// The ordered list of all running processes in the table
		PCB processes[MAX_PROCESS_COUNT];

		// The current number of processes in the PCB table
		int process_count;

	public:

		PCBTable();

};
