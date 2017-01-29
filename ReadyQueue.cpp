/*
ReadyQueue implementatio
Jonathan Tapia
*/

#include <iostream>
#include "ReadyQueue.h"
using namespace std;

//Helper methods to compute indexes
//Starting index is at 0
int ReadyQueue::getParentIndex(int i){
    return (i-1)/2;
}

int ReadyQueue::getLeftIndex(int i){
    return i*2 + 1;
}

int ReadyQueue::getRightIndex(int i){
    return i*2+2;
}

void ReadyQueue::swapNodes(int a, int b){
    PCB* temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

ReadyQueue::ReadyQueue(){
    size = 0;
}

void ReadyQueue::insertProc(PCB *inserted){
    if(size >= MAX_PROCESS_COUNT){
        //TODO: Determine behavior for adding process to filled queue
    }

    heap[size] = inserted;
    int i = size;

    //Bubble up the new process
    while(i > 0){
        int p = getParentIndex(i);
        if(heap[i]->getPriority() < heap[p]->getPriority()){
            swapNodes(i, p);
            i = p;
        }
        else {
            break;
        }
    }

    size++;
}

PCB* ReadyQueue::removeHighestProc(){
    if(size == 0){
        //TODO: Determine behavior for removing from empty queue
    }

    PCB* result = heap[0];

    //Replace root with bottom rightmost node
    heap[0] = heap[size-1];
    size--;

    int pos = 0;
    bool notFinished = true;

    //Sift the root down
    while(notFinished){
        int leftChild = getLeftIndex(pos);
        int rightChild = getRightIndex(pos);
        int smallest;

        if(leftChild < size && heap[pos]->getPriority() > heap[leftChild]->getPriority()){
            smallest = leftChild;
        }
        else{
            smallest = pos;
        }

        if(rightChild < size && heap[smallest]->getPriority() > heap[rightChild]->getPriority()){
            smallest = rightChild;
        }

        if(smallest != pos){
            swapNodes(pos, smallest);
            pos = smallest;
        }
        else{
            notFinished = false;
        }
    }

    return result;
}

void ReadyQueue::displayQueue(){
    for(int i = 0; i < size; i++){
        cout <<"Process " << i << " Priority: " << heap[i]->getPriority() << endl;
    }
}
