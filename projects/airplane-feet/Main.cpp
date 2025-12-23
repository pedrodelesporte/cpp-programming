// Main.cpp
// Airplane Fleet Application Program
// Student Name: Pedro Delesporte
// Due Date: December 15, 2025

#include <iostream>
#include <vector>
#include <string>
#include "Airplane.h"
#include "CargoPlane.h"
#include "PassengerPlane.h"

using namespace std;

// Function Prototypes
void printHelp();
void addAirplane(vector<Airplane*>& fleet);
void printFleet(const vector<Airplane*>& fleet);
void flyPlane(vector<Airplane*>& fleet);
void removeAirplane(vector<Airplane*>& fleet);

int main() {
    // create vector of pointers to Airplane objects
    vector<Airplane*> fleet;
    char command;
    bool keepRunning = true;

    // command Loop
    while (keepRunning) {
        cout << "Enter command (or 'h' for help): ";
        cin >> command;

        switch (command) {
        case 'a':
        case 'A':
            addAirplane(fleet);
            break;
        case 'f':
        case 'F':
            flyPlane(fleet);
            break;
        case 'h':
        case 'H':
            printHelp();
            break;
        case 'p':
        case 'P':
            printFleet(fleet);
            break;
        case 'r':
        case 'R':
            removeAirplane(fleet);
            break;
        case 'q':
        case 'Q':
        {
            char confirm;
            cout << "Are you sure that you want to exit the program? ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                keepRunning = false;
            }
            break;
        }
        default:
            cout << "Invalid command: " << command << endl;
            break;
        }
    }

    return 0;
}

// Phelp
void printHelp() {
    cout << "Supported commands:" << endl;
    cout << "add a new airplane to the fleet.      a" << endl;
    cout << "fly a plane in the fleet.             f" << endl;
    cout << "print help text.                      h" << endl;
    cout << "print fleet information.              p" << endl;
    cout << "quit (end the program).               q" << endl;
    cout << "remove airplane from the fleet.       r" << endl;
}

// handles logic to add a new plane
void addAirplane(vector<Airplane*>& fleet) {
    char type;
    cout << "Enter type of airplane (c = cargo, p = passenger): ";
    cin >> type;

    Airplane* newPlane = nullptr;

    if (type == 'c' || type == 'C') {
        newPlane = CargoPlane::addNewCargoPlane();
    }
    else if (type == 'p' || type == 'P') {
        newPlane = PassengerPlane::addNewPassengerPlane();
    }
    else {
        cout << "Invalid airplane type." << endl;
        return;
    }

    if (newPlane != nullptr) {
        fleet.push_back(newPlane);
        cout << "addNewAirplane: Size of fleet = " << fleet.size() << endl;
    }
}

// prints all planes in the fleet
void printFleet(const vector<Airplane*>& fleet) {
    if (fleet.empty()) {
        cout << "Current fleet contains 0 airplane(s):" << endl;
        return;
    }
    cout << "Current fleet contains " << fleet.size() << " airplane(s):" << endl;
    for (const auto& plane : fleet) {
        cout << plane->getDescription() << endl;
    }
}

// finds a plane by ID and adds flight hours
void flyPlane(vector<Airplane*>& fleet) {
    int id, hours;
    cout << "Which airplane do you want to fly? ";
    cin >> id;
    cout << "Length of flight (hours)? ";
    cin >> hours;

    bool found = false;
    for (auto& plane : fleet) {
        if (plane->getAirplane_ID() == id) {
            found = true;
            // report current status
            cout << "Choosing airplane: " << plane->getDescription() << endl;

            // update hours
            plane->setFlightHours(plane->getFlightHours() + hours);

            // report new status
            cout << "Flight complete: " << plane->getDescription() << endl;
            break;
        }
    }

    if (!found) {
        cout << "Airplane " << id << " not found." << endl;
    }
}

// removes a plane by ID and frees memory
void removeAirplane(vector<Airplane*>& fleet) {
    int id;
    cout << "Which airplane do you want to remove? ";
    cin >> id;

    bool found = false;
    // we use an iterator so we can erase from the vector efficiently
    for (auto it = fleet.begin(); it != fleet.end(); ++it) {
        if ((*it)->getAirplane_ID() == id) {
            found = true;
            cout << "Choosing airplane: " << (*it)->getDescription() << endl;

            // save description for final message
            string oldDesc = (*it)->getDescription();

            // delete the object with destructor
            delete *it;

            // remove pointer from vector
            fleet.erase(it);

            cout << "Removal complete: Airplane [" << oldDesc << "] has been removed." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Airplane " << id << " not found." << endl;
    }
}