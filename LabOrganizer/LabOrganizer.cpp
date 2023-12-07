
#include <iostream>
#include <string>
#include <cstdio>
#include "LabOrganizer.h"
#include "Cabinet.h"

using namespace std;

LabOrganizer::LabOrganizer() {
    cabinets = NULL;
    numOfCabinets = 0;
}
LabOrganizer::~LabOrganizer() {
    if(cabinets) {
        delete [] cabinets;
        cabinets = NULL;
    }
}
int LabOrganizer::getNumOfCabinets() const {
    return numOfCabinets;
}
void LabOrganizer::setNumOfCabinets(int num) {
    numOfCabinets = num;
}
void LabOrganizer::addCabinet(int id, int rows, int columns) {
    int sameIdFounded = 0;
    for(int i = 0; i < numOfCabinets; i++) {
        if(cabinets[i].getId() == id)
            sameIdFounded++;
    }

    if(rows > 9 || columns > 9)
        cout << "Cannot add the cabinet: dimensions are out of bounds: at most row = 9, column = 9" << endl;
    else if(sameIdFounded)
        cout << "Cannot add the cabinet: ID " << id  << " is already in the system!" << endl;
    else {
        numOfCabinets++;
        Cabinet cb(id, rows, columns);
        cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;

        if(cabinets == NULL) {
            cabinets = new Cabinet[numOfCabinets];
            cabinets[numOfCabinets-1] = cb;
        }
        else {
            Cabinet* temp = cabinets;
            cabinets = new Cabinet[numOfCabinets];
            for(int i = 0; i < numOfCabinets-1; i++)
                cabinets[i] = temp[i];
            cabinets[numOfCabinets-1] = cb;

            delete [] temp;
        }
    }
}
void LabOrganizer::removeCabinet(int id) {
    if(numOfCabinets <= 0)
        cout << "The array is empty!" << endl;
    else if(numOfCabinets == 1) {
        if(id == cabinets[numOfCabinets-1].getId()){
            cabinets = NULL;
            numOfCabinets--;
            cout << "Cabinet " << id << " has been removed." << endl;
        }
        else
            cout << "Cabinet " << id << " does not exist in the system!" << endl;
    }
    else {
        int founded = 0;
        Cabinet* temp = cabinets;
        for(int i = 0; i < numOfCabinets; i++) {
            if(id == temp[i].getId()) {
                founded++;
                cabinets = new Cabinet[numOfCabinets-1];

                if(i < numOfCabinets - 1) {
                    for(int j = i; j < numOfCabinets-1; j++)
                    temp[j] = temp[j+1];
                }
                for(int i = 0; i < numOfCabinets-1; i++)
                    cabinets[i] = temp[i];

                numOfCabinets--;
            }
        }
        if(founded) {
            cout << "Cabinet " << id << " has been removed." << endl;
            delete [] temp;
        }
        else
            cout << "Cabinet " << id << " does not exist in the system!" << endl;
    }
}
void LabOrganizer::listCabinets() {
    cout << "List of all cabinets: " << endl;
    for(int i = 0; i < numOfCabinets; i++) {
        int id = cabinets[i].getId();
        int rows = cabinets[i].getRows();
        int cols = cabinets[i].getColumns();
        int numOfEmptySlots = cabinets[i].getNumOfEmpty();

        printf("ID: %d, Dim: %dx%d, Number of empty slots: %d", id, rows, cols, numOfEmptySlots);
        cout << endl;
    }
}
void LabOrganizer::cabinetContents(int id) {
    int found = 0;
    for(int i = 0; i < numOfCabinets; i++) {
        if(cabinets[i].getId() == id){
            found++;
            cabinets[i].showCabinet();
            cout << endl;
        }
    }
    if(found == 0)
        cout << "Cabinet " << id << " is not in the system!" << endl;
}
void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    int numOfChems = 0;
    bool isUnique = true;

    for(int i = 0; i < numOfCabinets; i++) {
        numOfChems = cabinets[i].getRows() * cabinets[i].getColumns() - cabinets[i].getNumOfEmpty();
        int* chemIds = cabinets[i].getChemIds();
        for(int j = 0; j < numOfChems; j++) {
            if(chemID == chemIds[j])
                isUnique = false;
        }

        delete [] chemIds;
    }
    if(!isUnique)
        cout << "Chemical with ID " << chemID <<" already exists in the system." << endl;
    else {
        for(int i = 0; i < numOfCabinets; i++) {
            if(cabinets[i].getId() == cabinetId) {
                cabinets[i].locateChemical(location, chemType, chemID);
            }
        }
    }
}
void LabOrganizer::findChemical(int id) {
    int numOfChems = 0;
    Cabinet cb;
    Chemical chem;

    for(int i = 0; i < numOfCabinets; i++) {
        numOfChems = cabinets[i].getRows() * cabinets[i].getColumns() - cabinets[i].getNumOfEmpty();
        int* chemIds = cabinets[i].getChemIds();
        for(int j = 0; j < numOfChems; j++) {
            if(id == chemIds[j])
                cb = cabinets[i];
        }

        delete [] chemIds;
    }
    if(cb.getCabinet()) {
        for(int i = 0; i < cb.getRows(); i++) {
            for(int j = 0; j < cb.getColumns(); j++) {
                if(cb.getCabinet()[i][j].getId() == id)
                    chem = cb.getCabinet()[i][j];
            }
        }
        cout << "Chemical " << id << " is at location "<< chem.getLocation() << " in cabinet " << cb.getId() << endl;
    }
    else
        cout << "Chemical " << id << " is not in the system!" << endl;
}
void LabOrganizer::removeChemical(int id) {
    int numOfChems = 0;
    int index = 0;
    int found = 0;
    Chemical emptyChem;

    for(int i = 0; i < numOfCabinets; i++) {
        numOfChems = cabinets[i].getRows() * cabinets[i].getColumns() - cabinets[i].getNumOfEmpty();
        int* chemIds = cabinets[i].getChemIds();
        for(int j = 0; j < numOfChems; j++) {
            if(id == chemIds[j]) {
                index = i;
                found++;
            }

        }
        delete [] chemIds;
    }
    if(found != 0) {
        for(int i = 0; i < cabinets[index].getRows(); i++) {
            for(int j = 0; j < cabinets[index].getColumns(); j++) {
                if(cabinets[index].getCabinet()[i][j].getId() == id) {
                    cabinets[index].getCabinet()[i][j] = emptyChem;
                    cabinets[index].incrementNumOfEmpty();

                    cout << "Chemical " << id << " has been removed from cabinet " << cabinets[index].getId() << endl;
                }
            }
        }
    }
    else
        cout << "Chemical " << id << " is not in the system!" << endl;
}
