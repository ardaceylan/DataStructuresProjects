/*
* Title: Sorting and Algorithm Efficiency
* Description: Analyzing of sorting algorithms
*/
#include <iostream>
#include "sorting.h"

using namespace std;

int main() {
    //performanceAnalysis();

    int arr[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int temp[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int a, b;
    /*
    int size = sizeof(arr) / sizeof(arr[0]);
    int compC, moveC;

    cout << "-----------------Insertion Sort-----------------" << endl;
    insertionSort(arr, size, compC, moveC);

    cout << "Key Comparisons: " << compC << endl;
    cout << "Data Moves: " << moveC << endl;
    displayArray(arr, size);

    cout << "------------------Bubble Sort------------------" << endl;
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
    bubbleSort(arr, size, compC, moveC);

    cout << "Key Comparisons: " << compC << endl;
    cout << "Data Moves: " << moveC << endl;
    displayArray(arr, size);

    cout << "-------------------Merge Sort-------------------" << endl;
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
    mergeSort(arr, size, compC, moveC);

    cout << "Key Comparisons: " << compC << endl;
    cout << "Data Moves: " << moveC << endl;
    displayArray(arr, size);

    cout << "-------------------Quick Sort-------------------" << endl;
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
    quickSort(arr, size, compC, moveC);

    cout << "Key Comparisons: " << compC << endl;
    cout << "Data Moves: " << moveC << endl;
    displayArray(arr, size);
    */
    cout << isSorted(arr, 16) << endl;

    mergeSort(arr, 16, a, b);
    displayArray(arr, 16);

    cout << isSorted(arr, 16) << endl;
    return 0;
}
