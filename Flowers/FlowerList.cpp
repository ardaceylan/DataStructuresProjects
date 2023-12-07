
#include "FlowerList.h"
#include <string>
#include <iostream>

FlowerList::FlowerList() {
    size = 0;
    head = NULL;
}
FlowerList::FlowerList(const FlowerList& aList) {
    size = aList.size;
    if (aList.head == NULL) //empty linked list
        head = NULL;
    else {
        head = new FlowerNode;
        head->f = aList.head->f;

        FlowerNode* newPtr = head;
        for (FlowerNode* otherPtr = aList.head->next;
             otherPtr != NULL;
             otherPtr = otherPtr->next){
                 newPtr->next = new FlowerNode;
                 newPtr = newPtr->next;
                 newPtr->f = otherPtr->f;
      }
      newPtr->next = NULL;
    }
}
FlowerList::~FlowerList() {
    while (!isEmpty())
        remove(head->f.getFlowerName());
}
bool FlowerList::isEmpty() const {
    return size == 0;
}
int FlowerList::getLength() const {
    return size;
}
bool FlowerList::retrieve(string flowerName, Flower& flower) const {
    int index = getIndex(flowerName);
    if ( index == 0)
        return false;

    FlowerNode* cur = findNode(index);
    flower = cur->f;
    return true;
}
bool FlowerList::add(string flowerName) {
    if (getIndex(flowerName) > 0)
        return false;

    int index = 1;

    FlowerNode* newPtr = new FlowerNode;
    newPtr->f = Flower(flowerName);
    size = getLength() + 1;

    for (FlowerNode* cur = head; cur != NULL && flowerName.compare(cur->f.getFlowerName()) > 0; cur = cur->next)
        index++;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        FlowerNode* prev = findNode(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}
bool FlowerList::remove(string flowerName) {
    if (getIndex(flowerName) == 0)
        return false;

    size--;
    int index = 1;
    for (FlowerNode* cur = head; cur != NULL && flowerName.compare(cur->f.getFlowerName()) > 0; cur = cur->next)
        index++;

    FlowerNode* cur = NULL;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        FlowerNode* prev = findNode(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}
Flower& FlowerList::getFlower(int index) const {
    FlowerNode* cur = head;
    for (int i = 1; i < index; i++)
        cur = cur->next;
    return cur->f;

}
int FlowerList::getIndex(string flowerName) const {
   int index = 0;
   for (FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        index++;
        if (cur->f.getFlowerName() == flowerName)
            return index;
   }
   return 0;
}
FlowerList::FlowerNode* FlowerList::findNode(int index) const {
    if (index < 1 || index > getLength())
        return NULL;
    else {
        FlowerNode* cur = head;
        for (int i = 1; i < index; i++)
            cur = cur->next;
        return cur;
    }
} // end of the FlowerList implementation
