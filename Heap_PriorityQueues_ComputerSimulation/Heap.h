/*
* Title: Heaps, Priority Queues
* Description: Heap header file
*/
#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "Request.h"
using namespace std;

const int MAX_HEAP = 300;

class Heap{
public:
    Heap();
    void operator=(const Heap& other);
    bool heapIsEmpty() const;
	bool heapInsert(const Request& newItem);
	bool heapDeleteRetrieve(Request& rootItem);
    bool heapDelete();
    void heapPrint();
protected:
    void heapRebuild(int root);
private:
    Request items[MAX_HEAP];
    int size;
};

#endif // HEAP_H_INCLUDED
