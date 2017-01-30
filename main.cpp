/**
 * CS 433 Programming Assignment 1: Priority Queue for Processes
 * Caleb Evans, Jonathan Tapia
 */
#include <iostream>
#include "PCB.h"
#include "PCBTable.h"
#include "ReadyQueue.h"
using namespace std;

void test1() {
	PCBTable pcb_table;
	ReadyQueue q1;
	cout << "Adding 20 processes to table..." << endl;
	PCB* pcb;
	for (int i = 1; i <= 20; i++) {
		pcb = new PCB(i, i);
		pcb_table.insertProc(pcb);
	}
	cout << "Adding processes 5, 1, 8, and 11..." << endl;
	q1.insertProc(pcb_table.getPCB(5));
	q1.insertProc(pcb_table.getPCB(1));
	q1.insertProc(pcb_table.getPCB(8));
	q1.insertProc(pcb_table.getPCB(11));
	q1.displayQueue();
	cout << "Removing highest-priority process..." << endl;
	q1.removeHighestProc();
	q1.displayQueue();
	cout << "Removing highest-priority process..." << endl;
	q1.removeHighestProc();
	q1.displayQueue();
	cout << "Adding processes 3, 7, 2, 12, and 9..." << endl;
	q1.insertProc(pcb_table.getPCB(3));
	q1.insertProc(pcb_table.getPCB(7));
	q1.insertProc(pcb_table.getPCB(2));
	q1.insertProc(pcb_table.getPCB(12));
	q1.insertProc(pcb_table.getPCB(9));
	q1.displayQueue();
	// Clean up when test is finished by deallocating used memory
	pcb_table.clear();
}

int main() {

	test1();

	return 0;

}
