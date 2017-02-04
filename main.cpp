/**
 * CS 433 Programming Assignment 1: Priority Queue for Processes
 * Caleb Evans, Jonathan Tapia
 * February 3, 2017
 * DESCRIPTION
 * This program includes a full C++ priority queue implementation, as well as a
 * series of tests to verify its behavior.
 * HOW TO RUN
 * To compile and run the program, run the `make` command in your favorite
 * shell; the compiled executable will automatically run after compilation.
 */
#include <iostream>
#include <algorithm>
#include <deque>
#include <sys/time.h>
#include "PCB.h"
#include "PCBTable.h"
#include "ReadyQueue.h"
using namespace std;

// Get the current time as a UNIX timestampts (in seconds)
double getCurrentTime() {
	timeval timePtr;
	gettimeofday(&timePtr, NULL);
	return timePtr.tv_sec + (timePtr.tv_usec / 1000000.0);
}

// Populate the given PCB table with the given number of processes (where ID =
// priority = i)
void populateTable(PCBTable &pcb_table, int process_count) {
	for (int i = 1; i <= process_count; i++) {
		PCB* pcb = new PCB(i, i);
		pcb_table.insertProc(pcb);
	}
}

// Dequeue the highest-priority process in the given queue and display the new
// contents of the queue
void dequeueAndDisplay(ReadyQueue &q1) {
	cout << "Dequeuing highest-priority process..." << endl;
	q1.removeHighestProc();
	q1.displayQueue();
}

// Run the first test according to the instructions given in the assignment
void test1(PCBTable &pcb_table, ReadyQueue &q1) {
	cout << "Starting test 1!" << endl;
	cout << "Adding 20 processes to table..." << endl;
	populateTable(pcb_table, 20);
	cout << "Enqueuing processes 5, 1, 8, and 11..." << endl;
	q1.insertProc(pcb_table.getPCB(5));
	q1.insertProc(pcb_table.getPCB(1));
	q1.insertProc(pcb_table.getPCB(8));
	q1.insertProc(pcb_table.getPCB(11));
	q1.displayQueue();
	dequeueAndDisplay(q1);
	dequeueAndDisplay(q1);
	cout << "Enqueuing processes 3, 7, 2, 12, and 9..." << endl;
	q1.insertProc(pcb_table.getPCB(3));
	q1.insertProc(pcb_table.getPCB(7));
	q1.insertProc(pcb_table.getPCB(2));
	q1.insertProc(pcb_table.getPCB(12));
	q1.insertProc(pcb_table.getPCB(9));
	q1.displayQueue();

	while (!q1.isEmpty()) {
		dequeueAndDisplay(q1);
	}
}

// Run the second test according to the instructions given in the assignment
void test2(PCBTable &pcb_table, ReadyQueue &q1) {
	cout << "Starting test 2!" << endl;
	// Seed random number generator
	srand(time(NULL));
	// table_order contains the indexes of all processes not in the queue
	deque<int> table_order;
	for (int i = 0; i < 20; i++) {
		table_order.push_back(i);
	}
	// Sets up a random order to access processes in
	random_shuffle(table_order.begin(), table_order.end());

	for (int i = 0; i < 10; i++) {
		// Choose a PCB from the table at random and assign a random priority
		// from 1 throguh 50
		int pos = table_order.front();
		int randomPriority = rand() % 50 + 1;

		PCB* process = pcb_table.getPCB(pos + 1);
		process->setPriority(randomPriority);
		q1.insertProc(process);

		table_order.pop_front();
	}

	// Begin time profiling by recording start time
	double startTime = getCurrentTime();
	for (int i = 0; i < 1000000; i++) {
		// Random value which determines if this iteration will add processes
		// (value of 1) or remove processes (value of 0) from the queue
		int choice = rand() % 2;

		if (choice == 0) {
			// Remove a PCB from the queue and mark it as not in the queue
			PCB* removed = q1.removeHighestProc();

			if (removed != NULL) {
				int posRemoved = pcb_table.getIndex(removed->getID());
				table_order.push_back(posRemoved);
				// Keep the order truly random
				random_shuffle(table_order.begin(), table_order.end());
			}
		}
		else {
			// Otherwise, add PCB to queue
			if (table_order.size() != 0) {
				// Choocse a process not in the queue at random
				int pos = table_order.front();
				int randomPriority = rand() % 50 + 1;

				// Assign a random new priority [1-50] and insert it into the
				// queue
				PCB* process = pcb_table.getPCB(pos + 1);
				process->setPriority(randomPriority);
				q1.insertProc(process);
				table_order.pop_front();
			}
			// Else if all processes are in the queue, do nothing
		}
	}
	// Finish time profiling by recording end time and taking the difference
	double endTime = getCurrentTime();
	cout << "Duration: " << ((endTime - startTime) * 1000) << " ms" << endl;
	q1.displayQueue();
}

int main() {
	PCBTable pcb_table;
	ReadyQueue q1;

	test1(pcb_table, q1);
	// Print blank line between tests for readability
	cout << endl;
	test2(pcb_table, q1);

	pcb_table.clear();
	return 0;
}
