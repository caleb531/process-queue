/**
 * Process control block implementation
 * Caleb Evans
 */
#include "PCB.h"
using namespace std;


PCB::PCB() {
	// Initialize process properties to null values when no arguments are
	// supplied; valid process IDs and priorities are values greater than 1
	this->ID = 0;
	this->priority = 0;
	this->state = PCB::NEW;
}


PCB::PCB(int ID, int priority) {
	// Initialize process ID and priority on instantiation (for convenience)
	this->ID = ID;
	this->priority = priority;
	this->state = PCB::NEW;
}

int PCB::getID() {
	return ID;
}

int PCB::getPriority() {
	return priority;
}

void PCB::setPriority(int newPriority){
	this->priority = newPriority;
}

void PCB::markAsReady() {
	this->state = READY;
}

void PCB::markAsRunning() {
	this->state = RUNNING;
}
