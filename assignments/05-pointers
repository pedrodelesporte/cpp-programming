#include <iostream>
#include <iomanip>

using namespace std;

void populateIntegerArray(int *arrayPtr, int arraySize);
void displayIntegerArray(const int *arrayPtr, int arraySize);
int findMaximumInteger(const int *arrayPtr, int arraySize);

int main() {
    int arraySize;
    int *arrayPtr = nullptr;

    cout << "Enter the array size: ";
    cin >> arraySize;
    
    arrayPtr = new int[arraySize];
    cout << "arrayPtr = " << arrayPtr << endl;
    
    populateIntegerArray(arrayPtr, arraySize);
    displayIntegerArray(arrayPtr, arraySize);
    
    int maxValue = findMaximumInteger(arrayPtr, arraySize);
    cout << "Maximum integer in array is: " << maxValue << endl;
    
    cout << "Deleting array at = " << arrayPtr << endl;
    delete[] arrayPtr;
    
    cout << "Exit the program." << endl;
    
    return 0;
}

void populateIntegerArray(int *arrayPtr, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << "Enter value for array element " << i << ": ";
        cin >> arrayPtr[i];
    }
}

void displayIntegerArray(const int *arrayPtr, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        // Display address
        cout << arrayPtr + i << ": arrayPtr[" << i << "] = ";
        
        // Display decimal value
        cout << setw(10) << arrayPtr[i];
        
        // Display hexadecimal value
        cout << " (Hex ";
        cout << hex << setw(8) << setfill('0') << arrayPtr[i];
        cout << dec << ")" << endl;
    }
}

int findMaximumInteger(const int *arrayPtr, int arraySize) {
    int max = arrayPtr[0];
    for (int i = 1; i < arraySize; i++) {
        if (arrayPtr[i] > max) {
            max = arrayPtr[i];
        }
    }
    return max;
}
