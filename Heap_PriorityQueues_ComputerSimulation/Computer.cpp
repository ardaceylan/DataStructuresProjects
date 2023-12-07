/*
* Title: Heaps, Priority Queues
* Description: Computer cpp file
*/
#include "Computer.h"
using namespace std;

Computer::Computer() {
    id = 0;
    available = true;
    availableTime = 0;
}
/*
Computer::Computer(const Computer& other) {
    id = other.id;
    available = other.available;
    availableTime = other.availableTime;
}*/
void Computer::operator=(const Computer& other) {
    id = other.id;
    available = other.available;
    availableTime = other.availableTime;
}

Computer::Computer(int anId, bool anAvailable, int time) {
    id = anId;
    available = anAvailable;
    availableTime = time;
}
int Computer::getId() const {
    return id;
}
bool Computer::isAvailable() const {
    return available;
}
int Computer::getAvailableTime() const {
    return availableTime;
}
void Computer::setId(int anId) {
    id = anId;
}
void Computer::setAvailable(bool anAvailable) {
    available = anAvailable;
}
void Computer::setAvailableTime(int time) {
    availableTime = time;
}
void Computer::getWork(int start, int workTime) {
    //setAvailable(false);
    int time = start + workTime;
    setAvailableTime(time);
}
