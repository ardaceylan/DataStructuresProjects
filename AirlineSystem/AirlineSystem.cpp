/*
* Title: CS202 Spring 2022
* Description: AirlineSystem cpp file
*/
#include "AirlineSystem.h"
#include <iostream>
#include <limits.h>
using namespace std;

bool AirlineSystem::deleted = false;

AirlineSystem::AirlineSystem() {
    size = 1;
    airports = new EdgeNode*[size];
    airports[0] = NULL;
}
AirlineSystem::AirlineSystem(int aSize) {
    size = aSize;
    airports = new EdgeNode*[size];
    for(int i = 0; i < size; i++)
        airports[i] = NULL;
}
void AirlineSystem::operator=(const AirlineSystem& other) {
    for(int i = 0; i < size; i++)
        clearAirport(i);

    delete [] airports;
    airports = NULL;

    size = other.size;
    airports = other.airports;
}
AirlineSystem::~AirlineSystem() {
    if(!deleted) {
        for(int i = 0; i < size; i++)
            clearAirport(i);

        delete [] airports;
        airports = NULL;
        AirlineSystem::deleted = true;
    }
}
bool AirlineSystem::isEmpty() const {
    return size == 0;
}
int AirlineSystem::getSize() const {
    return size;
}
void AirlineSystem::insertFlight(int startP, int endP, int time) {
    EdgeNode* newPtr = new EdgeNode; //For the first edge
    newPtr->destination = endP;
    newPtr->duration = time;
    newPtr->next = NULL;

    if(airports[startP] == NULL)
        airports[startP] = newPtr;
    else {
        newPtr->next = airports[startP];
        airports[startP] = newPtr;
    }

    EdgeNode* newPtr2 = new EdgeNode; //For the second edge
    newPtr2->destination = startP;
    newPtr2->duration = time;
    newPtr2->next = NULL;

    if(airports[endP] == NULL)
        airports[endP] = newPtr2;
    else {
        newPtr2->next = airports[endP];
        airports[endP] = newPtr2;
    }
}
void AirlineSystem::insertMsg(int startP, int endP, int time) {
    int numOfFlights = getNumOfFlights(startP);
    cout << "Inserted a new flight between " << startP << " and " << endP << "." << endl;
    cout << "\tThe number of flights from " << startP << " is " << numOfFlights << "." << endl;
}
bool AirlineSystem::clearAirport(int id) {
    int number = getNumOfFlights(id);
    if(number == 0)
        return false;
    else {
        EdgeNode* head = airports[id];
        EdgeNode* cur;
        while(head != NULL) {
            cur = head;
            head = head->next;
            cur->next = NULL;
            delete cur;
            cur = NULL;
        }
        return true;
    }
}
int AirlineSystem::getNumOfFlights(int id) {
    EdgeNode* head = airports[id];
    int number = 0;

    for(EdgeNode* cur = head; cur != NULL; cur = cur->next)
        number++;

    return number;
}
void AirlineSystem::listFlights(int id) {
    cout << "List of flights from " << id << ":" << endl;
    EdgeNode* head = airports[id];
    int numOfFlights = getNumOfFlights(id);

    for(EdgeNode* cur = head; cur != NULL; cur = cur->next)
        cout << "\t" << id << " to " << cur->destination << " with a duration of " << cur->duration << "." << endl;
    cout << "\tThe number of flights is " << numOfFlights << "." << endl;
}
int AirlineSystem::getNearest(int* dur, int* vis) const{
    int minDur = INT_MAX;
    int index;

    for(int i = 0; i < size; i++) {
        if(vis[i] == 0 && dur[i] <= minDur) {
            minDur = dur[i];
            index = i;
        }
    }
    return index;
}
int AirlineSystem::getNearestDif(int* dur, int* vis) const{
    int minDur = INT_MAX;
    int index;

    for(int i = 0; i < size; i++) {
        if(vis[i] == 0 && dur[i] <= minDur && dur[i] != 0) {
            minDur = dur[i];
            index = i;
        }
    }
    return index;
}
int AirlineSystem::getDuration(int startP, int endP) {
    EdgeNode* head = airports[startP];
    int duration = INT_MAX;

    if(startP == endP)
        duration = 0;

    else {
        for(EdgeNode* cur = head; cur != NULL; cur = cur->next) {
            if(cur->destination == endP) {
                duration = cur->duration;
            }
        }
    }
    return duration;
}
void AirlineSystem::getSP(int startP, int endP) {
    int durations[size];
    int visited[size];
    int previous[size];
    int path[size];

    if(startP == endP) {
        cout << "Airports given are the same! The flight duration is 0." << endl;
        return;
    }

    for(int i = 0; i < size; i++) {
        durations[i] = INT_MAX;
        visited[i] = 0;
        previous[i] = -1;
        path[i] = -1;
    }
    durations[startP] = 0;
    for(int i = 0; i < size; i++) {
        int u = getNearest(durations, visited);
        visited[u] = 1;

        for(int j = 0; j < size; j++) {
            if(visited[j] == 0 && durations[u] != INT_MAX && getDuration(u, j) != INT_MAX && (durations[j] > durations[u] + getDuration(u, j))) {
                durations[j] = durations[u] + getDuration(u, j);
                previous[j] = u;
            }
        }
    }
    if(durations[endP] == INT_MAX)
        cout << "No paths from " << startP << " to " << endP << "." << endl;
    else {
        cout << "The shortest path from " << startP << " to " << endP << ":" << endl;
        bool success = false;
        int tempEnd = endP;
        int index;
        int i = size - 1;
        while(!success) {
            index = tempEnd;
            success = (previous[index] == startP);
            path[i] = tempEnd;
            tempEnd = previous[index];
            i--;
        }
        path[i] = startP;
        for(int j = 0; j < size - 1; j++) {
            if(path[j] != -1)
                cout << "\t" << path[j] << " to " << path[j + 1] << " with a duration " << getDuration(path[j], path[j + 1]) << "." << endl;
        }
        cout << "\tTotal flight duration of the path: " << durations[endP] << endl;
    }
}
void AirlineSystem::getMinST(AirlineSystem& as) {
    int v = 0;
    int u, k, duration, time;
    int visited[size];
    int durations[size];
    for(int i = 0; i < size; i++) {
        duration = getDuration(v, i);
        durations[i] = duration;
        visited[i] = 0;
    }
    visited[v] = 1;
    for(int i = 1; i < size; i++) {
        u = getNearestDif(durations, visited);
        visited[u] = 1;
        time = getDuration(v, u);
        if(time != INT_MAX)
            as.insertFlight(v, u, time);
        else {
            v = u;
            for(int j = 0; j < size; j++) {
                duration = getDuration(v, j);
                durations[j] = duration;
                visited[j] = 0;
            }
            k = getNearestDif(durations, visited);
            visited[k] = 1;
            time = getDuration(v, k);
            if(time != INT_MAX)
                as.insertFlight(v, k, time);
        }
    }
}
int AirlineSystem::getTotalCost() {
    int total = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(getDuration(i, j) != 0 && getDuration(i, j) != INT_MAX)
                total += getDuration(i, j);
        }
    }
    return total / 2; //Since it is an undirected graph
}
