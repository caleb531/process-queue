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
		PCB* processes[MAX_PROCESS_COUNT];

		// The current number of processes in the PCB table
		int process_count;

	public:

		PCBTable();

		// Add the supplied PCB instance to the table
		void insertProc(PCB*);
		// Retrieve a PCB in the table by its index
		PCB* getPCB(int);

		//Returns the index of a PCB accoring to its ID 
		//Returns -1 if a PCB with the specified ID doesn't exist
		int getIndex(int PCBID);

		// Remove and deallocate all processes in the table
		void clear();

};
