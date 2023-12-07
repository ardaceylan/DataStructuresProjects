/*
* Title: Heaps, Priority Queues
* Description: Heap cpp file
*/
#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap() {
    size = 0;
}
void Heap::operator=(const Heap& other) {
    size = other.size;
    for (int i = 0; i < size; i++)
        items[i] = other.items[i];
}
bool Heap::heapIsEmpty() const {
    return size == 0;
}
bool Heap::heapInsert(const Request& newItem) {
    if (size >= MAX_HEAP) {
        cout << "Heap is full!" << endl;
        return false;
    }
	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ((place > 0) && (items[place].getPriority() >= items[parent].getPriority())
        && (items[place].getComingTime() <= items[parent].getComingTime())) {

        Request temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
	}
 	++size;
 	return true;
}
bool Heap::heapDeleteRetrieve(Request& rootItem) {
    if (heapIsEmpty()) {
        cout << "Heap is empty!" << endl;
        return false;
    }
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
		return true;
	}
}
bool Heap::heapDelete() {
    if (heapIsEmpty()) {
        cout << "Heap is empty!" << endl;
        return false;
    }
	else {
		items[0] = items[--size];
		heapRebuild(0);
		return true;
	}
}
void Heap::heapPrint() {
    cout << "Heap: ";
    for (int i = 0; i < size; i++)
        cout << items[i].getId() << " " << items[i].getPriority() << " " << items[i].getComingTime() << endl;
}
void Heap::heapRebuild(int root) {
    int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < size) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ((rightChild < size) && (items[rightChild].getComingTime() <= items[child].getComingTime())) {
            if (items[rightChild].getComingTime() < items[child].getComingTime())
                child = rightChild;
			else if ((items[rightChild].getComingTime() == items[child].getComingTime())
            && (items[rightChild].getPriority() > items[child].getPriority()))
                child = rightChild; // index of larger child
		}

		// If root�s item is smaller than larger child, swap values
		if (items[root].getComingTime() >= items[child].getComingTime()) {
            if (items[root].getComingTime() > items[child].getComingTime()) {
                Request temp = items[root];
                items[root] = items[child];
                items[child] = temp;
            }
            else if ((items[root].getComingTime() == items[child].getComingTime())
                     && (items[root].getPriority() < items[child].getPriority())) {
                Request temp = items[root];
                items[root] = items[child];
                items[child] = temp;
            }
			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}
