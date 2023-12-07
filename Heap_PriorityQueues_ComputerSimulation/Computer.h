/*
* Title: Heaps, Priority Queues
* Description: Computer header file
*/
#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

class Computer {
  private:
      //Attributes
      int id;
      bool available;
      int availableTime;
  public:
    //Constructor
    Computer();
    Computer(int anId, bool anAvailable, int time);
    void operator=(const Computer& other);
    //Methods
    int getId() const;
    bool isAvailable() const;
    int getAvailableTime() const;
    void setId(int anId);
    void setAvailable(bool anAvailable);
    void setAvailableTime(int time);
    void getWork(int start, int workTime);
};

#endif // COMPUTER_H_INCLUDED
