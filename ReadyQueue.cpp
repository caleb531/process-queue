/*
ReadyQueue implementation
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
    //Swap only if both indexes are legal
    if(a < size && b < size){
        PCB* temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }
}

ReadyQueue::ReadyQueue(){
    size = 0;
}

void ReadyQueue::insertProc(PCB* inserted){
    if(size >= MAX_PROCESS_COUNT){
        //If queue is already full, do nothing
        return;
    }

    heap[size] = inserted;
	inserted->markAsReady();
    int i = size;
    size++;

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
}

PCB* ReadyQueue::removeHighestProc(){
    if(size == 0){
        //If empty, return pointer pointing to nowhere
        return NULL;
    }

    PCB* result = heap[0];

    //Replace root with bottom rightmost node
    heap[0] = heap[size-1];
    size--;

    //The index that is currently being checked
    int currentIndex = 0;

    //Sift the root down
    while(true){
        int leftChild = getLeftIndex(currentIndex);
        int rightChild = getRightIndex(currentIndex);
        int smallest;

        //Determine the smallest value between currentIndex vs leftChild
        //If leftChild doesn't exist, smallest is set to currentIndex
        if(leftChild < size && heap[currentIndex]->getPriority() > heap[leftChild]->getPriority()){
            smallest = leftChild;
        }
        else{
            smallest = currentIndex;
        }

        //Determine the smallest value between currentIndex/parent(determined before) vs rightChild
        //If rightChild doesn't exist, smallest is kept as determined before
        if(rightChild < size && heap[smallest]->getPriority() > heap[rightChild]->getPriority()){
            smallest = rightChild;
        }

        //If the smallest was one of the children, swap
        if(smallest != currentIndex){
            swapNodes(currentIndex, smallest);
            currentIndex = smallest;
        }
        else{
            //Otherwise the smallest was the current index, or left and right children don't exist, so sifting is done
            break;
        }
    }

	result->markAsRunning();
    return result;
}

void ReadyQueue::displayQueue(){
    for(int i = 0; i < size; i++){
        cout <<"Process " << heap[i]->getID() << " Priority " << heap[i]->getPriority() << endl;
    }
}
