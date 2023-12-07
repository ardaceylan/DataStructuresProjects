
#ifndef FLOWER_H_INCLUDED
#define FLOWER_H_INCLUDED

#include <string>
using namespace std;

class Flower{
public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower& aFlower);
    Flower& operator=(const Flower&);
    ~Flower();
    bool isEmpty() const;
    int getLength() const;
    bool add(string feature);
    bool remove(string feature);
    string printFlower() const;
    string getFlowerName() const;
    bool containFeature(string feature) const;
private:
    struct FeatureNode {
        string feature;
        FeatureNode* next;
    };
    int size;
    string flowerName;
    FeatureNode* head; //the features are stored in a sorted singly linear linked list
    int getIndex(string feature) const;
    FeatureNode* findNode(int index) const;
};

#endif // FLOWER_H_INCLUDED
