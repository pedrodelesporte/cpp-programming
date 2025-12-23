#include "PassengerPlane.h"

// mutator
void PassengerPlane::setMaxNumberOfPassengers(int passengers) {
    maxNumberOfPassengers = passengers;
}

// accessor
int PassengerPlane::getMaxNumberOfPassengers() const {
    return maxNumberOfPassengers;
}

// override getDescription to add passenger info
string PassengerPlane::getDescription() const {
    return Airplane::getDescription() + ", max passengers: " + to_string(maxNumberOfPassengers);
}

// static helper to create a new PassengerPlane from user input
PassengerPlane* PassengerPlane::addNewPassengerPlane() {
    string man, mod;
    int year, hours, passengers;

    cout << "Enter name of manufacturer: ";
    if (cin.peek() == '\n') cin.ignore();
    getline(cin, man);

    cout << "Enter model: ";
    getline(cin, mod);

    cout << "Enter year built: ";
    cin >> year;

    cout << "Enter flight hours: ";
    cin >> hours;

    cout << "Enter maximum Passenger count: ";
    cin >> passengers;

    // create new dynamic object
    PassengerPlane* newPlane = new PassengerPlane(man, mod, year, hours, passengers);

    // output confirmation as per sample
    cout << "New airplane: " << newPlane->getDescription() << endl;

    return newPlane;
}