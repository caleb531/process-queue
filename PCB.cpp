/**
 * Process control block implementation
 * Caleb Evans
 */
#include "PCB.h"
using namespace std;


PCB::PCB(int ID) {
	this->ID = ID;
	this->state = PCB::NEW;
}
