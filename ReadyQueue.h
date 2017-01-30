/**
 * ReadyQueue definition
 */
#pragma once
#include "PCB.h"
using namespace std;

class ReadyQueue {
	protected:

	//Maximum number of processes to hold
	static const int MAX_PROCESS_COUNT = 20;

	//Minimum heap of all ready processes
	PCB* heap[MAX_PROCESS_COUNT];

	//Current number of processes in the heap
	int size;

	// Retrieve the index of node i's parent
	int getParentIndex(int i);
	// Retrieve the index of node i's left child
	int getLeftIndex(int i);
	// Retrieve the index of node i's right child
	int getRightIndex(int i);

	// Swap the nodes at the given indices
	void swapNodes(int a, int b);

	public:
	ReadyQueue();

	// Insert the given PCB instance into the queue
	void insertProc(PCB* inserted);
	// Remove the highest priority process from the queue
	PCB* removeHighestProc();
	// Display each node in the queue, one node per line, in array-order
	void displayQueue();
};
