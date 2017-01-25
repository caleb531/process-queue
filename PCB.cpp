/**
 * Process control block implementation
 * Caleb Evans
 */
#include "PCB.h"
using namespace std;


PCB::PCB(int ID, int priority) {
	this->ID = ID;
	this->priority = priority;
	this->state = PCB::NEW;
}
