/**
 * Process control block definition
 * Caleb Evans
 */
#pragma once


class PCB {

	protected:

		// An enum representing the state of the process in a memory-efficient way
		enum PCBState { NEW, READY, RUNNING, WAITING, TERMINATED };

		// A unique identifier for the process
		int ID;

		// The priority of the process (smaller values indicate greater priority)
		int priority;

		// The current state of the process
		PCBState state;

	public:

		PCB();
		PCB(int ID, int priority);

};
