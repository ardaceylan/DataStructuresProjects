/*
* Title: Heaps, Priority Queues
* Description: Request cpp file
*/
#include "Request.h"
using namespace std;

Request::Request() {
    id = 0;
    priority = 0;
    comingTime = 0;
    processingTime = 0;
}
Request::Request(int anId, int aPriority, int aComingTime, int aProcessingTime) {
    id = anId;
    priority = aPriority;
    comingTime = aComingTime;
    processingTime = aProcessingTime;
}
//Methods
int Request::getId() const {
    return id;
}
int Request::getPriority() const {
    return priority;
}
int Request::getComingTime() const {
    return comingTime;
}
int Request::getProcessingTime() const {
    return processingTime;
}
