/*
* Title: CS202 Spring 2022
* Description: Driver code
*/
#include "AirlineSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int numOfAirports, numOfOps;
    fstream newfile;
    char* fileName = argv[1];
    //string fileName = "in.txt";

    int data[3];
    newfile.open(fileName, ios::in); //open a file to perform read operation using file object (fileName.c_str())
    if (newfile.is_open()){   //checking whether the file is open
        string numOfAirportsStr, numOfOpsStr;

        getline(newfile, numOfAirportsStr);
        getline(newfile, numOfOpsStr);

        stringstream sToInt(numOfAirportsStr);
        sToInt >> numOfAirports;
        stringstream sToInt2(numOfOpsStr);
        sToInt2 >> numOfOps;

        AirlineSystem AL1(numOfAirports);

        string line;
        for(int i = 0; i < numOfOps; i++) {
            getline(newfile, line);
            int sizeOfLine = line.size();
            string linePart;
            if(sizeOfLine >= 3)
                linePart  = line.substr(2, sizeOfLine - 2);

            stringstream ss(linePart);
            string word;
            int index = 0;
            while (ss >> word) {
                stringstream sToInt3(word);
                sToInt3 >> data[index];
                index++;
            }

            if(line[0] == 'I') {
                AL1.insertFlight(data[0], data[1], data[2]);
                AL1.insertMsg(data[0], data[1], data[2]);
            }
            else if(line[0] == 'L') {
                AL1.listFlights(data[0]);
            }
            else if(line[0] == 'M') {
                cout << "Total cost of operations before minimization: " << AL1.getTotalCost() << endl;
                AirlineSystem AL2(numOfAirports);
                AL1.getMinST(AL2);
                AL1 = AL2;
                cout << "Total cost of operations after minimization: " << AL1.getTotalCost() << endl;
            }
            else if(line[0] == 'S') {
                AL1.getSP(data[0], data[1]);
            }
            else
                cout << "Invalid operation!" << endl;

        }
        newfile.close(); //close the file object.
    }

    return 0;
}

