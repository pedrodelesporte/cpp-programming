#include <iostream>
#include <iomanip> // to use setprecision
using namespace std;

int main() {

    double previousOdometer, latestOdometer, gallons; // double for decimal points

    cout << "Enter your previous Odometer fill-up: ";
    cin >> previousOdometer;

    cout << "Enter your latest Odometer fill-up: ";
    cin >> latestOdometer;

    double milesTravelled = latestOdometer - previousOdometer; //double to declare a new variable
    cout << fixed << setprecision(1); //sets the number of decimal places to 1
    cout << "Miles Travelled: " << milesTravelled << endl;

    cout << "Enter your gallons: ";
    cin >> gallons;

    double mpg = milesTravelled / gallons; //calculates the miles per gallon using division and assigns to mpg
    cout << "Your MPG is: " << mpg << endl;
    return 0;
