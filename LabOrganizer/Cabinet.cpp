
#include <iostream>
#include <string>
#include<sstream>
#include <cmath>
#include <cstdio>
#include "Cabinet.h"
#include "Chemical.h"

using namespace std;

Cabinet::Cabinet(int anId, int numOfRows, int numOfColumns, char anEmptySlotChar) {
    id = anId;
    rows = numOfRows;
    columns = numOfColumns;
    numOfEmptySlots = rows * columns;
    emptySlotChar = anEmptySlotChar;
    maxSize = 9;
    rowNames = new char[maxSize];
    rowNames[0] = 'A';rowNames[1] = 'B';rowNames[2] = 'C';rowNames[3] = 'D';rowNames[4] = 'E';
    rowNames[5] = 'F';rowNames[6] = 'G';rowNames[7] = 'H';rowNames[8] = 'I';

    columnNums = new int[9];
    columnNums[0] = 1;columnNums[1] = 2;columnNums[2] = 3;columnNums[3] = 4;columnNums[4] = 5;
    columnNums[5] = 6;columnNums[6] = 7;columnNums[7] = 8;columnNums[8] = 9;

    cabinet = new Chemical*[rows];

    for(int i = 0; i < rows; i++) {
        cabinet[i] = new Chemical[columns];

        for(int j = 0; j < columns; j++){
            Chemical chem;
            cabinet[i][j] = chem;
        }
    }
}
Cabinet::Cabinet() {
    id = 0;
    rows = 0;
    columns = 0;
    numOfEmptySlots = rows * columns;
    maxSize = 0;
    rowNames = NULL;
    columnNums = NULL;
    cabinet = NULL;
}
//Cabinet& Cabinet::operator=(const Cabinet& another) {
//     if ( &another != this ) { // to avoid self-assignment
//        id = another.id;
//        numOfEmptySlots = another.numOfEmptySlots;
//        maxSize = another.maxSize;
//
//        if(maxSize > 0) {
//            rowNames = new char[maxSize];
//            columnNums = new int[maxSize];
//            for(int i = 0; i < maxSize; i++) {
//                rowNames[i] = another.rowNames[i];
//                columnNums[i] = another.columnNums[i];
//            }
//        }
//        else {
//            rowNames = NULL;
//            columnNums = NULL;
//        }
//
//        if ( rows > 0 && columns > 0)
//            for(int i = 0; i < rows; i++)
//                delete [] cabinet[i];
//            delete [] cabinet;
//        rows = another.rows;
//        columns = another.columns;
//        if ( rows > 0 && columns > 0) {
//            cabinet = new Chemical*[rows];
//
//            for(int i = 0; i < rows; i++) {
//                cabinet[i] = new Chemical[columns];
//
//                for(int j = 0; j < columns; j++){
//                    cabinet[i][j] = another.cabinet[i][j];
//                }
//            }
//         }
//         else
//            cabinet = NULL;
//     }
//     return *this; // to allow cascading
//}
Cabinet::Cabinet(const Cabinet& cb) {
    id = cb.id;
    rows = cb.rows;
    columns = cb.columns;
    numOfEmptySlots = cb.numOfEmptySlots;
    maxSize = cb.maxSize;

    if(maxSize > 0) {
        rowNames = new char[maxSize];
        columnNums = new int[maxSize];
        for(int i = 0; i < maxSize; i++) {
            rowNames[i] = cb.rowNames[i];
            columnNums[i] = cb.columnNums[i];
        }
    }
    else {
        rowNames = NULL;
        columnNums = NULL;
    }

    if(rows > 0 && columns > 0) {
        cabinet = new Chemical*[rows];
        for(int i = 0; i < rows; i++) {
            cabinet[i] = new Chemical[columns];
            for(int j = 0; j < columns; j++){
                cabinet[i][j] = cb.cabinet[i][j];
            }
        }
    }
    else
        cabinet = NULL;
}
Cabinet::~Cabinet() {
    if(rowNames){
        delete [] rowNames;
    }
    if(columnNums) {
        delete [] columnNums;
    }

    for(int i = 0; i < rows; i++) {
        if(cabinet[i])
            delete [] cabinet[i];
    }
    if(cabinet) {
        delete [] cabinet;
        cabinet = NULL;
    }
}
int Cabinet::getId() const {
    return id;
}
int Cabinet::getRows() const {
    return rows;
}
int Cabinet::getColumns() const {
    return columns;
}
int Cabinet::getNumOfEmpty() const {
    return numOfEmptySlots;
}
void Cabinet::incrementNumOfEmpty() {
    numOfEmptySlots++;
}
Chemical** Cabinet::getCabinet() const {
    return cabinet;
}
int* Cabinet::getChemIds() const {
    int numOfChems = 0;
    int counter = 0;
    numOfChems = rows * columns - numOfEmptySlots;
    int* chemIds = NULL;

    if(numOfChems > 0)
        chemIds = new int[numOfChems];
    else
        return NULL;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(cabinet[i][j].getId())
                chemIds[counter++] = cabinet[i][j].getId();
        }
    }
    return chemIds;
}
template <typename T>
void Cabinet::printArray(const T* arr, const int arrSize) {
    if(arrSize <= 0)
        cout << "Array has nothing to be printed!";
    else {
        for(int i = 0; i < arrSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
void Cabinet::showCabinet() {
    bool success = rowNames && columnNums && cabinet;
    if(success) {
        printf("ID: %d, %dx%d, empty: %d. Chemicals: ", id, rows, columns, numOfEmptySlots);
        int numOfChems = 0;
        int counter = 0;
        numOfChems = rows * columns - numOfEmptySlots;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(cabinet[i][j].getId()){
                    cout << cabinet[i][j].getLocation() << ": " << cabinet[i][j].getId();
                    counter++;
                    if(numOfChems > 1 && counter < numOfChems)
                        cout << ", ";
                }
            }
        }
        cout << endl;
        cout << " ";
        for(int i = 0; i < columns; i++) {
            cout << " " << columnNums[i];
        }
        cout << endl;

        char** cabinetView = new char*[rows];

        for(int i = 0; i < rows; i++) {
            cabinetView[i] = new char[columns];
            for(int j = 0; j < columns; j++) {
                cabinetView[i][j] = cabinet[i][j].getAbbreviated();
            }
        }
        for(int i = 0; i < rows; i++) {
            cout << rowNames[i] << " ";
            printArray(cabinetView[i], columns);
        }
        for(int i = 0; i < rows; i++) {
            if(cabinetView[i])
                delete [] cabinetView[i];
        }
        if(cabinetView) {
            delete [] cabinetView;
            cabinetView = NULL;
        }
    }
    else
        cout << "Cabinet has nothing to be shown" << endl;
}
template <typename T>
int Cabinet::getIndex(const T* arr, const int arrSize, T value) {
    if(arrSize <= 0)
        cout << "Array has no item!" << endl;

    else {
        for(int i = 0; i < arrSize; i++) {
            if(arr[i] == value)
                return i;
        }
        cout << "Value has not been founded!" << endl;
    }
    return -1;
}
string Cabinet::getLocation(int rowNum, int colNum) {
    stringstream stream;
    stream << columnNums[colNum];
    string s;
    stream >> s;

    return rowNames[rowNum] + s;
}
string* Cabinet::getNearestLocs(int rowNum, int colNum, int range, int& outputSize) {
    string* output = NULL;
    outputSize = 0;
    string allNearests = "";

    for(int i = 0; i < rows; i++) { //cabinet[i][j]
        for(int j = 0; j < columns; j++) {
            double distance = sqrt((rowNum - i)*(rowNum - i) + (colNum - j)*(colNum - j));
            if((distance >= range && distance <= range * sqrt(2)) && (abs(rowNum - i) <= range && abs(colNum - j) <= range)
               && !(i == rowNum && j == colNum)) {
                allNearests += getLocation(i, j);
            }
        }
    }
    outputSize = allNearests.length() / 2;

    if(outputSize != 0) {
        output = new string[outputSize];

        for(int i = 0; i < outputSize; i++) {
            output[i] = allNearests.substr((i*2), 2);
        }
    }
    return output;
}
string* Cabinet::getNearestPossibleLocs(const string* arr, const int arrSize, int& outputSize) {
    string* output = NULL;
    outputSize = 0;
    string allNearestPossibles = "";
    int nearestsOfNearestSize = 0;
    string* nearestsOfNearest = NULL;

    for(int i = 0; i < arrSize; i++) {
        int combustiveInNearestsOfNearest = 0;
        int rowNearest = getIndex(rowNames, rows, arr[i][0]);
        int colNearest = getIndex(columnNums, columns, int(arr[i][1] - '0'));

        nearestsOfNearest = getNearestLocs(rowNearest, colNearest, 1, nearestsOfNearestSize);

        for(int j = 0; j < nearestsOfNearestSize; j++) {
            int rowNearestOfNearest = getIndex(rowNames, rows, nearestsOfNearest[j][0]);
            int colNearestOfNearest = getIndex(columnNums, columns, int(nearestsOfNearest[j][1] - '0'));
            if(cabinet[rowNearestOfNearest][colNearestOfNearest].getAbbreviated() == 'c' ||
               cabinet[rowNearestOfNearest][colNearestOfNearest].getAbbreviated() == 'C')
                combustiveInNearestsOfNearest++;
        }

        if(cabinet[rowNearest][colNearest].getAbbreviated() == emptySlotChar && combustiveInNearestsOfNearest == 0){
            allNearestPossibles += getLocation(rowNearest, colNearest);
        }
    }
    outputSize = allNearestPossibles.length() / 2;
    if(outputSize != 0) {
        output = new string[outputSize];

        for(int i = 0; i < outputSize; i++) {
            output[i] = allNearestPossibles.substr((i*2), 2);
        }
    }

    delete [] nearestsOfNearest;
    return output;
}
void Cabinet::locateChemical(string location, string chemType, int chemID) {
    int row = getIndex(rowNames, rows, location[0]);
    int column = getIndex(columnNums, columns, int(location[1] - '0'));

    int range = 1;
    int nearestSize = 0;
    string* nearestLocations = NULL;
    nearestLocations = getNearestLocs(row, column, range, nearestSize);

    int nearestPossibleSize = 0;
    string* nearestPossibleLocations = NULL;
    nearestPossibleLocations = getNearestPossibleLocs(nearestLocations, nearestSize, nearestPossibleSize);

    if(row >= 0 && column >= 0) {
        if(cabinet[row][column].getAbbreviated() != emptySlotChar) {
            cout << "Location " << location << " in cabinet " << id << " is already occupied. Nearest possible locations for this chemical: ";

            if(chemType == "combustive" || chemType == "Combustive") {
                while(nearestPossibleSize == 0){
                    delete [] nearestPossibleLocations;
                    delete [] nearestLocations;

                    range++;
                    nearestLocations = getNearestLocs(row, column, range, nearestSize);
                    nearestPossibleLocations = getNearestPossibleLocs(nearestLocations, nearestSize, nearestPossibleSize);
                }
                for(int i = 0; i < nearestPossibleSize; i++){
                    cout << nearestPossibleLocations[i];
                    if(nearestPossibleSize > 1 && i < nearestPossibleSize - 1)
                       cout << ", ";
                }
                cout << endl;
            }
            else {
               for(int i = 0; i < nearestSize; i++){
                   cout << nearestLocations[i];
                   if(nearestSize > 1 && i < nearestSize - 1)
                       cout << ", ";
               }
               cout << endl;
            }
        }
        else {
            int combustiveInNearest = 0;

            for(int i = 0; i < nearestSize; i++) {
                int rowNearest = getIndex(rowNames, rows, nearestLocations[i][0]);
                int colNearest = getIndex(columnNums, columns, int(nearestLocations[i][1] - '0'));
                if((chemType == "combustive" || chemType == "Combustive") &&
                   (cabinet[rowNearest][colNearest].getAbbreviated() == 'c' || cabinet[rowNearest][colNearest].getAbbreviated() == 'C'))
                    combustiveInNearest++;
            }
            if(combustiveInNearest) {
                cout << "Location " << location << " in cabinet " << id <<
                " is not suitable for a combustive chemical. Nearest possible locations for this chemical: ";

                while(nearestPossibleSize == 0){
                    delete [] nearestPossibleLocations;
                    delete [] nearestLocations;

                    range++;
                    nearestLocations = getNearestLocs(row, column, range, nearestSize);
                    nearestPossibleLocations = getNearestPossibleLocs(nearestLocations, nearestSize, nearestPossibleSize);
                }
                for(int i = 0; i < nearestPossibleSize; i++){
                    cout << nearestPossibleLocations[i];
                    if(nearestPossibleSize > 1 && i < nearestPossibleSize - 1)
                        cout << ", ";
                }
                cout << endl;
            }
            else {
                Chemical chem(chemID, id, location, chemType);
                cabinet[row][column] = chem;
                numOfEmptySlots--;
                cout << chemType << " chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << id << endl;
            }
        }
    }
    delete [] nearestPossibleLocations;
    delete [] nearestLocations;
}
