/*
* Title: Trees
* Description: analyze cpp(implementation) file
*/
#include "analyze.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

void analyzeBST() {
    BinarySearchTree b;
    int size = 10000;
    int* arr;
    arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = rand() % size + 1;

    cout << "Random BST size vs. height (Insertion)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        int entry = arr[i];
        b.add(entry);
        if (i != 0 && i%100 == 0)
            cout << b.getNumberOfNodes() << "  " << b.getHeight() << endl;
    }

    //Shuffle
    shuffle(arr, size);

    cout << "Random BST size vs. height (Deletion)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        int entry = arr[i];
        b.remove(entry);
        if (i != 0 && i%100 == 0)
            cout << b.getNumberOfNodes() << "  " << b.getHeight() << endl;

    }
}

void swapItems(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void shuffle(int *&arr, const int size) {
    int i1;
    int i2;
    for (int i = 0; i < size/2; i++) {
        i1 = rand() % size;
        i2 = rand() % size;
        swapItems(arr[i1], arr[i2]);
    }
}
