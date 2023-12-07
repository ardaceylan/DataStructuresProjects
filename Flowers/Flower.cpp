
#include "Flower.h"
#include <string>
#include <iostream>
using namespace std;

Flower::Flower() {
    flowerName = "No name";
    size = 0;
    head = NULL;
}
Flower::Flower(string flowerName) {
    this->flowerName = flowerName;
    size = 0;
    head = NULL;
}
Flower::Flower(const Flower& aFlower) {
    flowerName = aFlower.flowerName;
    size = aFlower.size;
    if (aFlower.head == NULL) //empty linked list
        head = NULL;
    else {
        head = new FeatureNode;
        head->feature = aFlower.head->feature;

        FeatureNode* newPtr = head;
        for (FeatureNode* otherPtr = aFlower.head->next;
             otherPtr != NULL;
             otherPtr = otherPtr->next){
                 newPtr->next = new FeatureNode;
                 newPtr = newPtr->next;
                 newPtr->feature = otherPtr->feature;
      }
      newPtr->next = NULL;
    }
}
Flower& Flower::operator=(const Flower& aFlower) {
    while (!isEmpty())
        remove(head->feature);
    flowerName = aFlower.flowerName;
    size = aFlower.size;
    if (aFlower.head == NULL) //empty linked list
        head = NULL;
    else {
        head = new FeatureNode;
        head->feature = aFlower.head->feature;

        FeatureNode* newPtr = head;
        for (FeatureNode* otherPtr = aFlower.head->next;
             otherPtr != NULL;
             otherPtr = otherPtr->next){
                 newPtr->next = new FeatureNode;
                 newPtr = newPtr->next;
                 newPtr->feature = otherPtr->feature;
      }
      newPtr->next = NULL;
    }
}
Flower::~Flower() {
    while (!isEmpty())
        remove(head->feature);
}
bool Flower::isEmpty() const {
    return size == 0;
}
int Flower::getLength() const  {
    return size;
}
bool Flower::add(string feature) {
    if (getIndex(feature) > 0)
        return false;

    int index = 1;

    FeatureNode* newPtr = new FeatureNode;
    newPtr->feature = feature;
    size = getLength() + 1;

    for (FeatureNode* cur = head; cur != NULL && feature.compare(cur->feature) > 0; cur = cur->next)
        index++;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        FeatureNode* prev = findNode(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}
bool Flower::remove(string feature) {
    if (getIndex(feature) == 0)
        return false;

    size--;
    int index = 1;
    for (FeatureNode* cur = head; cur != NULL && feature.compare(cur->feature) > 0; cur = cur->next)
        index++;

    FeatureNode* cur = NULL;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        FeatureNode* prev = findNode(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}
string Flower::printFlower() const {
    string flower = flowerName + ": ";
    if (size == 0)
        flower += "No feature";
    else {
        for (FeatureNode* cur = head; cur != NULL; cur = cur->next)
            flower = flower + cur->feature + ", ";

        flower.erase(flower.size() - 2);
    }
    return flower;
}
string Flower::getFlowerName() const {
    return flowerName;
}
bool Flower::containFeature(string feature) const {
    if (getIndex(feature) == 0)
        return false;
    return true;
}
int Flower::getIndex(string feature) const {
   int index = 0;
   for (FeatureNode* cur = head; cur != NULL; cur = cur->next) {
        index++;
        if (cur->feature == feature)
            return index;
   }
   return 0;
}
Flower::FeatureNode* Flower::findNode(int index) const {
    if (index < 1 || index > getLength())
        return NULL;
    else {
        FeatureNode* cur = head;
        for (int i = 1; i < index; i++)
            cur = cur->next;
        return cur;
    }
} // end of the Flower implementation
