
#ifndef CHEMICAL_H_INCLUDED
#define CHEMICAL_H_INCLUDED

#include <string>
using namespace std;

class Chemical{
public:
    Chemical(int anId, int aCabinetId, string aLocation, string aChemType);
    Chemical();
    Chemical(const Chemical& chem);
    //Chemical& operator=(const Chemical& another);
    ~Chemical();
    int getId() const;
    void setID(int anId);
    string getLocation() const;
    char getAbbreviated() const;

private:
    int id;
    int cabinetId;
    string location;
    string chemType;
    char abbreviated;
};

#endif // CHEMICAL_H_INCLUDED
