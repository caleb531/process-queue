/**
 * Process control block implementation
 * Caleb Evans
 */
#include "PCB.h"
using namespace std;


// Initialize process properties to null values when no arguments are supplied
PCB::PCB() {
	// Valid process IDs and priorities are values greater than 1
	this->ID = 0;
	this->priority = 0;
	this->state = PCB::NEW;
}


// Initialize process ID and priority on instantiation (for convenience)
PCB::PCB(int ID, int priority) {
	this->ID = ID;
	this->priority = priority;
	this->state = PCB::NEW;
}

// Retrieve the constant ID of the process
int PCB::getID() {
	return ID;
}

// Retrieve the current priority of the process
int PCB::getPriority() {
	return priority;
}

// Indicate the process is now ready (meaning it has been enqueued)
void PCB::markAsReady() {
	this->state = READY;
}

// Indicate the process is currently running (meaning it has been dequeued)
void PCB::markAsRunning() {
	this->state = RUNNING;
}
