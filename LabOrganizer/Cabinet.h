
#ifndef CABINET_H_INCLUDED
#define CABINET_H_INCLUDED

#include <string>
#include "Chemical.h"
using namespace std;

class Cabinet{
public:
    char* rowNames;
    int* columnNums;

    Cabinet(int anId, int numOfRows, int numOfColumns, char anEmptySlotChar = '+');
    Cabinet();
    Cabinet(const Cabinet& cb);
    //Cabinet& operator=(const Cabinet& another);
    ~Cabinet();
    int getId() const;
    int getRows() const;
    int getColumns() const;
    int getNumOfEmpty() const;
    void incrementNumOfEmpty();
    Chemical** getCabinet() const;
    int* getChemIds() const;
    void showCabinet();
    void locateChemical(string location, string chemType, int chemID);

private:
    Chemical** cabinet;
    int id;
    int rows;
    int columns;
    int numOfEmptySlots;
    int maxSize;
    char emptySlotChar;

    template <typename T>
    void printArray(const T* arr, const int arrSize);
    template <typename T>
    int getIndex(const T* arr, const int arrSize, T value);
    string* getNearestLocs(int rowNum, int colNum, int range, int& outputSize);
    string* getNearestPossibleLocs(const string* arr, const int arrSize, int& outputSize);
    string getLocation(int rowNum, int colNum);
};

#endif // CABINET_H_INCLUDED
