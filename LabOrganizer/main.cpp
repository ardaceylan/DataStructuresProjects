#include <iostream>
using namespace std;
#include "LabOrganizer.h"

int main(){
    LabOrganizer L;
    L.listCabinets();
    // Testing add cabinet
    cout << "Testing add cabinet" << endl;
    cout << endl;
    L.addCabinet(101, 3, 4);
    L.addCabinet(102, 5, 3);
    L.addCabinet(103, 8, 8);
    cout << endl;
    L.addCabinet(103, 3, 3);
    L.addCabinet(104, 9, 19);
    cout << endl;
    L.listCabinets();
    cout << endl;
    // Testing remove cabinet
    cout << endl;
    cout << "Testing remove cabinet" << endl;
    cout << endl;
    L.removeCabinet(452);
    L.removeCabinet(101);
    L.removeCabinet(205);
    cout << endl;
    L.addCabinet(101, 7, 7);
    cout << endl;
    L.listCabinets();
    cout << endl;
    // Testing place Chemical
    cout << endl;
    cout << "Testing place chemical" << endl;
    cout << endl;
    L.placeChemical( 101, "C1", "combustive", 200);
    L.placeChemical( 101, "C1", "retardant", 139);
    L.placeChemical( 101, "D3", "retardant", 139);
    cout << endl;
    L.placeChemical( 101, "E3", "combustive", 188);
    L.placeChemical( 101, "D2", "combustive", 888);
    L.placeChemical( 101, "E1", "combustive", 888);
    L.placeChemical( 102, "B2", "combustive", 200);
    L.placeChemical( 102, "B2", "combustive", 156);
    cout << endl;
    L.placeChemical( 102, "C3", "retardant", 190);
    L.placeChemical( 102, "A3", "combustive", 171);
    L.placeChemical( 102, "E1", "combustive", 171);
    cout << endl;
    L.placeChemical( 103, "B2", "combustive", 139);
    L.placeChemical( 103, "B2", "combustive", 144);
    L.placeChemical( 103, "C3", "retardant", 120);
    cout << endl;
    L.placeChemical( 103, "A1", "retardant", 127);
    L.placeChemical( 103, "G8", "combustive", 191);
    cout << endl;
    L.listCabinets();
    cout << endl;
    // Testing find chemical
    cout << endl;
    cout << "Testing find chemical" << endl;
    cout << endl;
    L.findChemical(191);
    L.findChemical(156);
    L.findChemical(171);
    cout << endl;
    L.findChemical(139);
    cout << endl;
    // Testing show cabinet contents
    cout << endl;
    cout << "Testing show cabinet contents" << endl;
    cout << endl;
    L.cabinetContents(101);
    cout << endl;
    L.cabinetContents(102);
    cout << endl;
    L.cabinetContents(103);
    cout << endl;
    L.cabinetContents(107);
    cout << endl;
    // Testing remove chemical
    cout << endl;
    cout << "Testing remove chemical" << endl;
    cout << endl;
    L.removeChemical(156);
    L.removeChemical(177);
    L.removeChemical(188);
    cout << endl;
    L.removeCabinet(103);
    cout << endl;
    L.removeCabinet(102);
    cout << endl;
    return 0;
}

