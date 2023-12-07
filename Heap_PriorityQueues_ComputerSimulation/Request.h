/*
* Title: Heaps, Priority Queues
* Description: Request header file
*/
#ifndef REQUEST_H_INCLUDED
#define REQUEST_H_INCLUDED

class Request {
  private:
      //Attributes
      int id;
      int priority;
      int comingTime;
      int processingTime;
  public:
    //Constructor
    Request();
    Request(int anId, int aPriority, int aComingTime, int aProcessingTime);
    //Methods
    int getId() const;
    int getPriority() const;
    int getComingTime() const;
    int getProcessingTime() const;
};

#endif // REQUEST_H_INCLUDED
