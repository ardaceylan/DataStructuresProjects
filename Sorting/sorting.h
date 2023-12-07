/*
* Title: Sorting and Algorithm Efficiency
* Description: Analyzing of sorting algorithms
*/
#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

//Functions
void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
bool isSorted(int *arr, const int size);

//Helper functions
void swapItems(int& x, int& y);
void recursiveMergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void mergeHalves(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void recursiveQuickSort(int *arr, int first, int last, int &compCount, int &moveCount);
void partitionArr(int *arr, int first, int last, int &pIndex, int &compCount, int &moveCount);
bool isSortedHelper(int *arr, int first, int last);

//Additional functions
void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void performanceAnalysis();
#endif // SORTING_H_INCLUDED
