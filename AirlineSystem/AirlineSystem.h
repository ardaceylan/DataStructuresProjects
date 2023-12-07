/*
* Title: CS202 Spring 2022
* Description: AirlineSystem header file
*/
#ifndef AIRLINESYSTEM_H_INCLUDED
#define AIRLINESYSTEM_H_INCLUDED

using namespace std;

class AirlineSystem{
public:
    AirlineSystem();
    AirlineSystem(int aSize);
    void operator=(const AirlineSystem&);
    ~AirlineSystem();
    bool isEmpty() const;
    int getSize() const;
    void insertFlight(int startP, int endP, int time);
    void insertMsg(int startP, int endP, int time);
    bool clearAirport(int id);
    int getNumOfFlights(int id);
    void listFlights(int id);
    int getNearest(int* dur, int* vis) const;
    int getNearestDif(int* dur, int* vis) const;
    int getDuration(int startP, int endP);
    void getSP(int startP, int endP);
    void getMinST(AirlineSystem& as);
    int getTotalCost();

private:
    struct EdgeNode {
        int destination;
        int duration;
        EdgeNode* next;
    };
    int size;
    EdgeNode** airports;
    static bool deleted;
};


#endif // AIRLINESYSTEM_H_INCLUDED
