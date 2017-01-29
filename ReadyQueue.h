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
    int size;

    //Various methods to get indexes of parents/children
    int getParentIndex(int i);
    int getLeftIndex(int i);
    int getRightIndex(int i);

    void swapNodes(int a, int b);

    public: 
    ReadyQueue();

    void insertProc(PCB* inserted);
    PCB* removeHighestProc();
    
    void displayQueue();
};