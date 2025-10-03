#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getLowest(int arr[], int size) {
    int lowest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    return lowest;
}

int getHighest(int arr[], int size) {
    int highest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

int getSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double getAverage(int arr[], int size) {
    int total = getSum(arr, size);
    return (double)total / size;
}

int main() {
    const int ARRAY_SIZE = 100;
    int numbers[ARRAY_SIZE];
    string filename;
    
    cout << "Enter name of the file:";
    cin >> filename;
    
    ifstream inputFile(filename);
    
    int count = 0;
    while (count < ARRAY_SIZE && inputFile >> numbers[count]) {
        count++;
    }
    
    cout << count << " numbers read from the file." << endl;
    cout << "The highest value is " << getHighest(numbers, count) << endl;
    cout << "The lowest value is " << getLowest(numbers, count) << endl;
    cout << "The sum of the numbers is " << getSum(numbers, count) << endl;
    cout << "The average of the numbers is " << getAverage(numbers, count) << endl;
    
    return 0;
}
