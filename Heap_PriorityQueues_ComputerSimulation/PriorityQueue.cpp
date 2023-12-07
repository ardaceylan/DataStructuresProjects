/*
* Title: Heaps, Priority Queues
* Description: Priority Queue cpp file
*/
#include "PriorityQueue.h"
#include <iostream>
using namespace std;

void PriorityQueue::operator=(const PriorityQueue& other) {
    h = other.h;
}
bool PriorityQueue::pqIsEmpty() const {
    return h.heapIsEmpty();
}
void PriorityQueue::pqInsert(const Request& newItem) {
    if (!h.heapInsert(newItem))
        cout << "Priority queue is full!" << endl;
}
void PriorityQueue::pqDelete(Request& priorityItem) {
    if (!h.heapDeleteRetrieve(priorityItem))
        cout << "Priority queue is empty!" << endl;
}
void PriorityQueue::pqPrint() {
    if (!h.heapIsEmpty())
        h.heapPrint();
}
