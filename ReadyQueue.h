/*
ReadyQueue definition
Jonathan Tapia
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

    //Various methods to get indexes of parents/children
    int getParentIndex(int i);
    int getLeftIndex(int i);
    int getRightIndex(int i);

    //Swaps the processes at the indicated indexes
    void swapNodes(int a, int b);

    public: 
    ReadyQueue();

    //Insert a PCB pointer to the heap
    void insertProc(PCB* inserted);

    //Remove the pointer pointing the the highest priority process
    PCB* removeHighestProc();
    
    //Displays the heap in array order
    void displayQueue();
};