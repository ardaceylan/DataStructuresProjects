
#include <iostream>
#include <string>
#include "Chemical.h"

using namespace std;

Chemical::Chemical(int anId, int aCabinetId, string aLocation, string aChemType) {
    id = anId;
    cabinetId = aCabinetId;
    location = aLocation;
    chemType = aChemType;
    abbreviated = chemType[0];
}
Chemical::Chemical() {
    id = 0;
    cabinetId = 0;
    location = "";
    chemType = "";
    abbreviated = '+';
}
//Chemical& Chemical::operator=(const Chemical& another) {
//    id = another.id;
//    cabinetId = another.cabinetId;
//    location = another.location;
//    chemType = another.chemType;
//    abbreviated = another.abbreviated;
//
//    return *this;
//}
Chemical::Chemical(const Chemical& chem) {
    id = chem.id;
    cabinetId = chem.cabinetId;
    location = chem.location;
    chemType = chem.chemType;
    abbreviated = chem.abbreviated;
}
Chemical::~Chemical() {
}
int Chemical::getId() const {
    return id;
}
void Chemical::setID(int anId) {
    id = anId;
}
string Chemical::getLocation() const {
    return location;
}
char Chemical::getAbbreviated() const {
    return abbreviated;
}
