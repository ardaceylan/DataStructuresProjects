
#include <iostream>
#include <bits/stdc++.h>
#include<ctime>

using namespace std;

//Helper Functions Prototypes
int binarySearch(int* arr, int N, int searched);
void fillArray(int* arr, int arrSize, int num);

//Algorithm 1 (Simple algorithm using linear search)(O(n*m))
bool isSubsetFirst(int* arr1, int* arr2, int n, int m) {
    int i = 0;
    int j = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
        if (j == n)
            return 0;
    }
    return 1;
}

//Algorithm 2 (Using sorted arrays with binary search)(O(m*log(n)))
bool isSubsetSecond(int* arr1, int* arr2, int n, int m) {
    int i = 0;

    for (i = 0; i < m; i++) {
        if (binarySearch(arr1, n, arr2[i]) == -1)
            return 0;
    }
    return 1;
}

//Algorithm 3: (Using a frequency table)(O(n+m+k))
bool isSubsetThird(int* arr1, int* arr2, int n, int m) {
    int maxNum = 0;
    int counter = 0;

    for(int i = 0; i < n; i++) {
        if(arr1[i] > maxNum)
            maxNum = arr1[i];
    }
    //Form an array that represents a frequency table
    int freqSize = maxNum + 1;
    int* frequency = NULL;
    frequency = new int[freqSize];
    fillArray(frequency, freqSize, 0); //Fill it with zeros.

    for(int i = 0; i < n; i++)
        frequency[arr1[i]]++;

    for (int i = 0; i < m; i++)
    {
        if (arr2[i] <= maxNum && frequency[arr2[i]] > 0)
            frequency[arr2[i]]--;
        else
        {
            delete [] frequency;
            return 0;
        }
    }
    delete [] frequency;
    return 1;
}

//Driver
int main()
{
    int n = 100000;
    int m = 1000;
    int range = 1000; //[0,999]

    int* arr1 = new int[n];
    int* arr2 = new int[m];
    for(int i = 0; i < n; i++)
        arr1[i] = rand() % range;
    for(int i = 0; i < m; i++)
        arr2[i] = rand() % range;
    //To make sure that array 2 contains unique items
    arr2[m-2] = 1000;
    arr2[m-1] = 1000;

    sort(arr1, arr1 + n); //Sorting array 1

    double duration;
    clock_t startTime = clock();

    //Code block
    if (isSubsetThird(arr1, arr2, n, m))
        cout << "arr2[] is subset of arr1[]" << endl;
    else
        cout << "arr2[] is not a subset of arr1[]" << endl;

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete [] arr2;
    delete [] arr1;

    return 0;
}

//Helper Functions Implementations
int binarySearch(int* arr, int N, int searched) {
    int low = 0, high = N - 1;
    while ( low <= high ) {
        int mid = (low + high) / 2;
        if ( arr[ mid ] < searched )
            low = mid + 1;
        else if ( arr[ mid ] > searched )
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
void fillArray(int* arr, int arrSize, int num) {
    for(int i = 0; i < arrSize; i++)
        arr[i] = num;
}
