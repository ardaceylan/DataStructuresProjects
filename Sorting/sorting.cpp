/*
* Title: Sorting and Algorithm Efficiency
* Description: Analyzing of sorting algorithms
*/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <bits/stdc++.h>
#include<ctime>
#include "sorting.h"

using namespace std;

void swapItems(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void insertionSort(int *arr, const int size, int &comparisonCount, int &moveCount) {
    comparisonCount = 0;
    moveCount = 0;
    for (int unsorted = 1; unsorted < size; unsorted++) {
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;

        for (  ; (arr[loc-1] > nextItem && (loc > 0)); --loc) {
            comparisonCount++;
            arr[loc] = arr[loc-1];
            moveCount++;
        }
        comparisonCount++;

        arr[loc] = nextItem;
        moveCount++;
    }
}
void bubbleSort(int *arr, const int size, int &comparisonCount, int &moveCount) {
    comparisonCount = 0;
    moveCount = 0;
    bool sorted = false;

    for (int pass = 1; (pass < size) && !sorted; pass++) {
        sorted = true;
        for (int index = 0; index < size - pass; index++) {
            int nextIndex = index + 1;
            comparisonCount++;
            if (arr[index] > arr[nextIndex]) {
                swapItems(arr[index], arr[nextIndex]);
                moveCount += 3; // 3 moves happen in swap operation
                sorted = false; // it means that the array is not sorted initially
            }
        }
    }
}
void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    int first = 0;
    int last = size - 1;
    recursiveMergeSort(arr, first, last, compCount, moveCount);
}
void recursiveMergeSort(int *arr, int first, int last, int &compCount, int &moveCount) {
    if (first < last) {
        int mid = (first + last) / 2;
        recursiveMergeSort(arr, first, mid, compCount, moveCount);
        recursiveMergeSort(arr, mid + 1, last, compCount, moveCount);

        mergeHalves(arr, first, mid, last, compCount, moveCount);
    }
}
void mergeHalves(int *arr, int first, int mid, int last, int &compCount, int &moveCount) {
    int tempArr[last + 1];

    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArr

    for (; (first1 <= last1) && (first2 <= last2); index++) {
        compCount++;
        if (arr[first1] < arr[first2]) {
            moveCount++;
            tempArr[index] = arr[first1];
            first1++;
        }
        else {
            moveCount++;
            tempArr[index] = arr[first2];
            first2++;
        }
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; first1++, index++) {
        moveCount++;
        tempArr[index] = arr[first1];
    }
    // finish off the second subarray, if necessary
    for (; first2 <= last2; first2++, index++) {
        moveCount++;
        tempArr[index] = arr[first2];
    }
    // copy the result back into the original array
    for (index = first; index <= last; index++) {
        moveCount++;
        arr[index] = tempArr[index];
    }
}
void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    int first = 0;
    int last = size - 1;
    recursiveQuickSort(arr, first, last, compCount, moveCount);
}
void recursiveQuickSort(int *arr, int first, int last, int &compCount, int &moveCount) {
    int pIndex;

    if (first < last) {
        partitionArr(arr, first, last, pIndex, compCount, moveCount);

        recursiveQuickSort(arr, first, pIndex - 1, compCount, moveCount);
        recursiveQuickSort(arr, pIndex + 1, last, compCount, moveCount);
    }
}
void partitionArr(int *arr, int first, int last, int &pIndex, int &compCount, int &moveCount) {
    int pivot = arr[first];
    moveCount++;
    pIndex = first + 1;

    for (int i = first + 1; i <= last; i++) {
        compCount++;
        if (arr[i] < pivot) {
            swapItems(arr[i], arr[pIndex]);
            moveCount += 3;
            pIndex++;
        }
    }
    swapItems(arr[first], arr[pIndex - 1]);
    moveCount += 3;
    pIndex--;
}
void displayArray(const int *arr, const int size) {
    cout << "The array: [";
    for (int i = 0; i < size - 1; i++)
        cout << arr[i] << ", ";

    cout << arr[size - 1] << "]" << endl;
}
bool isSorted(int *arr, const int size) {
    int first = 0;
    int last = size - 1;

    return isSortedHelper(arr, first, last);
}
bool isSortedHelper(int *arr, int first, int last) {
    if(arr[first] > arr[last])
        return false;
    if (first < last) {
        int mid = (first + last) / 2;
        return (isSortedHelper(arr, first, mid) && isSortedHelper(arr, mid + 1, last));
    }
    return true;
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    int random;
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++) {
        random = rand();
        arr1[i] = random;
        arr2[i] = random;
        arr3[i] = random;
        arr4[i] = random;
    }
}
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;
    }
    int i1;
    int i2;
    for (int i = 0; i < size/20; i++) {
        i1 = rand() % size;
        i2 = rand() % size;
        swapItems(arr1[i1], arr1[i2]);
        swapItems(arr2[i1], arr2[i2]);
        swapItems(arr3[i1], arr3[i2]);
        swapItems(arr4[i1], arr4[i2]);
    }
}
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++) {
        arr1[i] = size - (1 + i);
        arr2[i] = size - (1 + i);
        arr3[i] = size - (1 + i);
        arr4[i] = size - (1 + i);
    }
    int i1;
    int i2;
    for (int i = 0; i < size/20; i++) {
        i1 = rand() % size;
        i2 = rand() % size;
        swapItems(arr1[i1], arr1[i2]);
        swapItems(arr2[i1], arr2[i2]);
        swapItems(arr3[i1], arr3[i2]);
        swapItems(arr4[i1], arr4[i2]);
    }
}
void performanceAnalysis() {
    int initialSize = 5000;
    int incrementAmount = 5000;
    int arraySize;
    int *arr1, *arr2, *arr3, *arr4;
    int compC, moveC;

    double duration;
    clock_t startTime = clock();
    //Code block
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Insertion Sort" << endl;
    printf("%-20s%-15s%-20s%-20s%-20s\n", "Array Type", "Array Size", "Elapsed Time (ms)", "Comparison Count", "Move Count");


    for (int i = 0; i < 8; i++) {
        arraySize = initialSize + incrementAmount * i;
        createRandomArrays(arr1, arr2, arr3, arr4, arraySize);

        double duration;
        clock_t startTime = clock();
        //Code block
        insertionSort(arr1, arraySize, compC, moveC);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        printf("%-20s%-15d%-20.2f%-20d%-20d\n", "Random", arraySize, duration, compC, moveC);

        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
    }

    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    printf("%-20s%-15s%-20s%-20s%-20s\n", "Array Type", "Array Size", "Elapsed Time (ms)", "Comparison Count", "Move Count");

    for (int i = 0; i < 8; i++) {
        arraySize = initialSize + incrementAmount * i;
        createRandomArrays(arr1, arr2, arr3, arr4, arraySize);

        double duration;
        clock_t startTime = clock();
        //Code block
        bubbleSort(arr1, arraySize, compC, moveC);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        printf("%-20s%-15d%-20.2f%-20d%-20d\n", "Random", arraySize, duration, compC, moveC);

        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
    }

    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    printf("%-20s%-15s%-20s%-20s%-20s\n", "Array Type", "Array Size", "Elapsed Time (ms)", "Comparison Count", "Move Count");

    for (int i = 0; i < 8; i++) {
        arraySize = initialSize + incrementAmount * i;
        createRandomArrays(arr1, arr2, arr3, arr4, arraySize);

        double duration;
        clock_t startTime = clock();
        //Code block
        mergeSort(arr1, arraySize, compC, moveC);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        printf("%-20s%-15d%-20.2f%-20d%-20d\n", "Random", arraySize, duration, compC, moveC);

        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
    }

    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    printf("%-20s%-15s%-20s%-20s%-20s\n", "Array Type", "Array Size", "Elapsed Time (ms)", "Comparison Count", "Move Count");

    for (int i = 0; i < 8; i++) {
        arraySize = initialSize + incrementAmount * i;
        createRandomArrays(arr1, arr2, arr3, arr4, arraySize);

        double duration;
        clock_t startTime = clock();
        //Code block
        quickSort(arr1, arraySize, compC, moveC);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        printf("%-20s%-15d%-20.2f%-20d%-20d\n", "Random", arraySize, duration, compC, moveC);

        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
    }
}
