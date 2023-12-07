
#ifndef FLOWERLIBRARY_H_INCLUDED
#define FLOWERLIBRARY_H_INCLUDED

#include "FlowerList.h"
#include <string>
using namespace std;

class FlowerLibrary{
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(string name);
    void removeFlower(string name);
    void listFlowers() const;
    void listFeatures(string name) const;
    void addFeature(string name,string feature);
    void removeFeature(string name, string feature);
    void findFlowers(string feature) const;
private:
    FlowerList flowers;

};

#endif // FLOWERLIBRARY_H_INCLUDED
