
#ifndef FLOWERLIST_H_INCLUDED
#define FLOWERLIST_H_INCLUDED

#include "Flower.h"
#include <string>
using namespace std;

class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    Flower& getFlower(int index) const;
private:
    struct FlowerNode {
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head; //the flowers are stored in a sorted singly linear linked list
    int getIndex(string flowerName) const;
    FlowerNode* findNode(int index) const;
};

#endif // FLOWERLIST_H_INCLUDED
