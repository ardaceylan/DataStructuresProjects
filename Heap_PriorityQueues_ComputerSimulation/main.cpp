/*
* Title: Heaps, Priority Queues
* Description: Main file
*/
#include "PriorityQueue.h"
#include "Computer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    PriorityQueue pq;
    fstream newfile;
    //string fileName = "log.txt";//argv[1];
    //int waitingUpperLimit = 20;

    string waitingUpperLimitS = argv[2];

    stringstream sToInt(waitingUpperLimitS);
    int waitingUpperLimit = 0;
    sToInt >> waitingUpperLimit;

    int data[4];
    newfile.open(argv[1], ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string sizePq;
        getline(newfile, sizePq);

        string line;
        while(getline(newfile, line)){  //read data from file object and put it into string.
            stringstream ss(line);
            string word;
            int index = 0;
            while (ss >> word) {
                stringstream sToInt2(word);
                sToInt2 >> data[index++];
            }
            Request rI(data[0], data[1], data[2], data[3]);
            pq.pqInsert(rI);
        }
        newfile.close(); //close the file object.
    }
    PriorityQueue temp;
    temp = pq;

    Request r;
    int numOfComputer = 0;
    double avgWaitingTime = 0;
    int compId;
    int requestId;
    int start = 0;
    int waitTime;
    int sumOfWaitingTime = 0;
    int numOfRequests = 0;

    //Simulation Part
    Computer* compArray;
    Computer c;
    avgWaitingTime = waitingUpperLimit + 1;

    while (avgWaitingTime > waitingUpperLimit) {
        numOfComputer++;
        compArray = new Computer[numOfComputer];
        //cout << "NumOfComp: " << numOfComputer << endl;

        for (int i = 0; i < numOfComputer; i++) {
            Computer tempC(i, true, 0);
            compArray[i] = tempC;
        }
        pq = temp;
        while (!pq.pqIsEmpty()) {
            /*for (int i = 0; i < numOfComputer; i++) {
                if (compArray[i].isAvailable()) {
                    c = compArray[i];
                    done = 1;
                    i = numOfComputer; //breaks the loop
                }
            }*/
            int earliest = compArray[0].getAvailableTime();

            for (int i = 1; i < numOfComputer; i++) {
                if (compArray[i].getAvailableTime() < earliest)
                    earliest = compArray[i].getAvailableTime();
            }
            for (int i = 0; i < numOfComputer; i++) {
                if (compArray[i].getAvailableTime() == earliest) {
                    c = compArray[i];
                    i = numOfComputer; //breaks the loop
                }
            }
            //Takes the request from the priority queue
            pq.pqDelete(r);
            start = r.getComingTime();

            if (c.getAvailableTime() > r.getComingTime())
                start = c.getAvailableTime();

            c.getWork(start, r.getProcessingTime());
            waitTime = start - r.getComingTime();

            sumOfWaitingTime += waitTime;
            numOfRequests++;
        }
        avgWaitingTime = double (sumOfWaitingTime) / numOfRequests;
        /*
        for (int i = 0; i < numOfComputer; i++)
            delete compArray[i];*/
        delete[] compArray;
    }
    cout << "Minimum number of computers required: " << numOfComputer << endl;
    cout << endl;
    cout << "Simulation with " << numOfComputer << " computers:" << endl;
    cout << endl;

    compArray = new Computer[numOfComputer];
    for (int i = 0; i < numOfComputer; i++) {
        Computer tempC(i, true, 0);
        compArray[i] = tempC;
    }
    pq = temp;
    while (!pq.pqIsEmpty()) {
        /*for (int i = 0; i < numOfComputer; i++) {
            if (compArray[i].isAvailable()) {
                cout << "available" << endl;
                c = compArray[i];
                done = 1;
                i = numOfComputer; //breaks the loop
            }
        }*/
        int earliest = compArray[0].getAvailableTime();
        for (int i = 1; i < numOfComputer; i++) {
            if (compArray[i].getAvailableTime() < earliest)
                earliest = compArray[i].getAvailableTime();
        }
        for (int i = 0; i < numOfComputer; i++) {
            if (compArray[i].getAvailableTime() == earliest) {
                c = compArray[i];
                i = numOfComputer; //breaks the loop
            }
        }
        pq.pqDelete(r);
        requestId = r.getId();
        start = r.getComingTime();

        if (c.getAvailableTime() > r.getComingTime())
            start = c.getAvailableTime();

        c.getWork(start, r.getProcessingTime());
        waitTime = c.getAvailableTime() - r.getComingTime();
        compId = c.getId();
        printf("%-9s%-2d%-15s%-3d%-7s%-5d%-8s%-3d%-5s\n",
               "Computer", compId, " takes request", requestId, " at ms", start, " (wait:", waitTime, " ms)");

        sumOfWaitingTime += waitTime;
        numOfRequests++;
    }
    /*
    for (int i = 0; i < numOfComputer; i++)
        delete compArray[i];*/
    delete[] compArray;

    avgWaitingTime = double (sumOfWaitingTime) / numOfRequests;
    cout << endl;
    cout << "Average waiting time: " << avgWaitingTime <<  " ms" << endl;

    return 0;
}
