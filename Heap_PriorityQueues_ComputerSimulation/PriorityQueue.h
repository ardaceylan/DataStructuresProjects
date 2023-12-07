/*
* Title: Heaps, Priority Queues
* Description: Priority Queue header file
*/
#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "Heap.h"
#include "Request.h"
using namespace std;

class PriorityQueue{
public:
    void operator=(const PriorityQueue& other);
    bool pqIsEmpty() const;
	void pqInsert(const Request& newItem);
	void pqDelete(Request& priorityItem);
	void pqPrint();
private:
    Heap h;
};


#endif // PRIORITYQUEUE_H_INCLUDED
