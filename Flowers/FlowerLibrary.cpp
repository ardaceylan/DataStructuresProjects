
#include "FlowerLibrary.h"
#include <string>
#include <iostream>

FlowerLibrary::FlowerLibrary() {
    flowers = FlowerList();
}
FlowerLibrary::~FlowerLibrary() {
    flowers.~FlowerList();
}
void FlowerLibrary::addFlower(string name) {
    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);

    if (flowers.add(name))
        cout << name << " has been added into the library." << endl;
    else
        cout << name << " cannot be added into the library because it already exists!" << endl;
}
void FlowerLibrary::removeFlower(string name) {
    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);

    if (flowers.remove(name))
        cout << name << " has been removed from the library." << endl;
    else
        cout << name << " cannot be removed because it's not in the library!" << endl;
}
void FlowerLibrary::listFlowers() const {
    if (flowers.isEmpty())
        cout << "Library is empty." << endl;
    else {
        for (int i = 1; i <= flowers.getLength(); i++)
            cout << flowers.getFlower(i).printFlower() << endl;

    }
}
void FlowerLibrary::listFeatures(string name) const {
    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);

    Flower f;
    if (flowers.retrieve(name, f))
        cout << f.printFlower() << endl;
    else
        cout << name << " is not found in the library!" << endl;
}
void FlowerLibrary::addFeature(string name,string feature) {
    int counter = 0;
    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);

    for (int i = 0; i < feature.length(); i++)
        feature[i] = tolower(feature[i]);

    for (int i = 1; i <= flowers.getLength(); i++) {
        if (flowers.getFlower(i).getFlowerName() == name) {
            counter++;
            if (flowers.getFlower(i).add(feature))
                cout << feature << " is added into " << name << endl;
            else
                cout << feature << " already exists in " << name << endl;
        }
    }
    if (counter == 0)
        cout << name << " is not found in the library!" << endl;
}
void FlowerLibrary::removeFeature(string name, string feature) {
    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);

    for (int i = 0; i < feature.length(); i++)
        feature[i] = tolower(feature[i]);

    for (int i = 1; i <= flowers.getLength(); i++) {
        if (flowers.getFlower(i).getFlowerName() == name) {
            if (flowers.getFlower(i).remove(feature))
                cout << feature << " is removed from " << name << endl;
            else
                cout << feature << " does not exist in " << name << endl;
        }
    }
}
void FlowerLibrary::findFlowers(string feature) const {
    for (int i = 0; i < feature.length(); i++)
        feature[i] = tolower(feature[i]);

    int counter = 0;
    string s = feature + " flowers: ";
    for (int i = 1; i <= flowers.getLength(); i++) {
        if (flowers.getFlower(i).containFeature(feature)) {
            s = s + flowers.getFlower(i).getFlowerName() + ", ";
            counter ++;
        }
    }
    if (counter == 0)
        s += "there is no such flower!";
    else
        s.erase(s.size() - 2);
    cout << s << endl;
} // end of the FlowerLibrary implementation
