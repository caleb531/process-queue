/**
 * CS 433 Programming Assignment 1: Priority Queue for Processes
 * Caleb Evans, Jonathan Tapia
 */
#include <iostream>
#include <algorithm>
#include <deque>
#include "PCB.h"
#include "PCBTable.h"
#include "ReadyQueue.h"
using namespace std;

void test1(PCBTable &pcb_table, ReadyQueue &q1) {
	cout << "Starting test 1!" << endl;
	cout << "Adding 20 processes to table..." << endl;
	for (int i = 1; i <= 20; i++) {
		PCB* pcb = new PCB(i, i);
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

	int queueSize = q1.getSize();
	for(int i = 0; i < queueSize; i++){
		cout << "Removing highest-priority process..." << endl;
		q1.removeHighestProc();
		q1.displayQueue();
	}
	
}

void test2(PCBTable &pcb_table, ReadyQueue &q1){
	cout << "Starting test 2!" << endl;
	//Seed random number generator
	srand(time(NULL));
	//table_order contains the indexes of all processes not in the queue
	deque<int> table_order;
	for(int i = 0; i < 20; i++){
		table_order.push_back(i);
	}
	//Sets up a random order to access processes in
	random_shuffle(table_order.begin(), table_order.end());

	for(int i = 0; i < 10; i++){
		//Choose a PCB from the table at random and assign a random priority from 1 throguh 50
		int pos = table_order.front();
		int randomPriority = rand() % 50 + 1;

		PCB* process = pcb_table.getPCB(pos);
		process->setPriority(randomPriority);
		q1.insertProc(process);

		table_order.pop_front();
	}

	for(int i = 0; i < 1000000; i++){
		int choice = rand() % 2;

		if(choice == 0){
			//Remove a PCB from the queue and mark it as not in the queue
			PCB* removed = q1.removeHighestProc();

			if(removed != NULL){
				int posRemoved = pcb_table.getIndex(removed->getID());
				table_order.push_back(posRemoved);
				//Keep the order truly random
				random_shuffle(table_order.begin(), table_order.end());
			}
		}
		else{
			if(table_order.size() != 0){
				//Choocse a process not in the queue at random
				int pos = table_order.front();
				int randomPriority = rand() % 50 + 1;

				//Assign a random new priority [1-50] and insert it into the queue
				PCB* process = pcb_table.getPCB(pos);
				process->setPriority(randomPriority);
				q1.insertProc(process);
				table_order.pop_front();
			}
			//Else if all processes are in the queue, do nothing
		}
	}
	q1.displayQueue();
}

int main() {
	PCBTable pcb_table;
	ReadyQueue q1;

	test1(pcb_table, q1);
	test2(pcb_table, q1);

	pcb_table.clear();
	return 0;
}
