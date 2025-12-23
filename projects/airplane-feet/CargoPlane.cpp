#include "CargoPlane.h"

// mutator
void CargoPlane::setMaxCargoWeight(int s) {
    maxCargoWeight = s;
}

// accessor
int CargoPlane::getMaxCargoWeight() const {
    return maxCargoWeight;
}

// override getDescription to add cargo info
string CargoPlane::getDescription() const {
    return Airplane::getDescription() + ", max cargo: " + to_string(maxCargoWeight);
}

// static helper to create a new CargoPlane from user input
CargoPlane* CargoPlane::addNewCargoPlane() {
    string man, mod;
    int year, hours, weight;


    cout << "Enter name of manufacturer: ";
    if (cin.peek() == '\n') cin.ignore();
    getline(cin, man);

    cout << "Enter model: ";
    getline(cin, mod);

    cout << "Enter year built: ";
    cin >> year;

    cout << "Enter flight hours: ";
    cin >> hours;

    cout << "Enter maximum cargo weight: ";
    cin >> weight;

    // create new dynamic object
    CargoPlane* newPlane = new CargoPlane(man, mod, year, hours, weight);

    // output confirmation as per sample
    cout << "New airplane: " << newPlane->getDescription() << endl;

    return newPlane;
}