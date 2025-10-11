#include <iostream>
#include <iomanip>
#include <cmath>   // for fabs

using namespace std;

int main() {
    double inputNumber, tolerance, estimate;
    double difference, result;

    string keepRunning = "y";

    while (keepRunning == "y" || keepRunning == "yes") {    //outer loop for the inputs
         int fieldWidth = 25;
         int precision = 18;
        cout << "Enter the floating point number:";
        cin >> inputNumber;

        cout << "Enter the tolerance value:";
        cin >> tolerance;

        cout << "Enter the initial estimate:";
        cin >> estimate;

        cout << setw(fieldWidth) << "tolerance = "
             << setprecision(precision) << fixed << tolerance << endl;

        cout << "Estimating square root of "
             << setprecision(precision) << fixed << inputNumber << endl << endl;

        cout << setw(3) << "N" //the headers
             << setw(fieldWidth) << "estimate"
             << setw(fieldWidth) << "quotient"
             << setw(fieldWidth) << "difference" << endl;

        cout << setw(3) << "_"
             << setw(fieldWidth) << "________"
             << setw(fieldWidth) << "________"
             << setw(fieldWidth) << "________" << endl;

        int n = 0;
        do { //inner loops
            n++;
            double quotient = inputNumber / estimate;
            difference = fabs(estimate - quotient);

            cout << setw(3) << n
                 << setw(fieldWidth) << setprecision(precision) << fixed << estimate
                 << setw(fieldWidth) << quotient
                 << setw(fieldWidth) << difference << endl;

            result = estimate;
            estimate = (estimate + quotient) / 2.0;

        } while (difference >= tolerance);

        cout << "The square root of" //outputs
             << setprecision(precision) << fixed << inputNumber << endl
             << setw(fieldWidth) << "is"
             << setw(fieldWidth) << result << endl
             << setw(fieldWidth) << "(+/-"
             << setw(fieldWidth) << tolerance << ")" << endl << endl;

        cout << "Keep running?";
        cin >> keepRunning;
    }

    return 0;
}
