#include <iostream>
#include <string>
using namespace std;

struct MovieData {
    string title;
    string director;
    int yearReleased;
    double runningTime;
};

// Function prototypes
void displayMovie(MovieData *moviePtr);
void populateMovieDataArray(MovieData *arrayPtr, int arraySize);
void displayMovieDataArray(MovieData *arrayPtr, int arraySize);
MovieData *findLongestMovie(MovieData *arrayPtr, int arraySize);

int main() {
    int arraySize;
    cout << "Enter desired array size: ";
    cin >> arraySize;
    cin.ignore();

    // allocate memory for array of structs
    MovieData *movieArray = new MovieData[arraySize];
    cout << "arrayPtr = " << movieArray << endl;
    
    // call the functions
    populateMovieDataArray(movieArray, arraySize);
    displayMovieDataArray(movieArray, arraySize);
    MovieData *longestMoviePtr = findLongestMovie(movieArray, arraySize);
    
    // call displayMovie with the pointer from findLongestMovie
    cout << "\nLongest Movie in list:" << endl;
    displayMovie(longestMoviePtr);
    cout << "Longest Movie is: " << longestMoviePtr->runningTime << " minutes long" << endl;
    
    // delete dynamically allocated array
    cout << "DELETING array at arrayPtr = " << movieArray << endl;
    delete[] movieArray;
    
    cout << "Exit the program." << endl;
    return 0;
}

void displayMovie(MovieData *moviePtr) {
    cout << "    Title : " << moviePtr->title << endl;
    cout << "    Director : " << moviePtr->director << endl;
    cout << "    Released : " << moviePtr->yearReleased << endl;
    cout << "    Running Time: " << moviePtr->runningTime << " minutes" << endl;
    cout << endl;
}

void populateMovieDataArray(MovieData *arrayPtr, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << "Enter Title " << i << ": ";
        getline(cin, arrayPtr[i].title);
        
        cout << "Enter Director " << i << ": ";
        getline(cin, arrayPtr[i].director);
        
        cout << "Enter Year Released " << i << ": ";
        cin >> arrayPtr[i].yearReleased;
        
        cout << "Enter running time (minutes) " << i << ": ";
        cin >> arrayPtr[i].runningTime;
        cin.ignore();
    }
}

void displayMovieDataArray(MovieData *arrayPtr, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << hex << &arrayPtr[i] << ": arrayPtr[" << i << "] = " << endl;
        displayMovie(&arrayPtr[i]);
    }
}

MovieData *findLongestMovie(MovieData *arrayPtr, int arraySize) {
    MovieData *longestMovie = &arrayPtr[0];
    for (int i = 1; i < arraySize; i++) {
        if (arrayPtr[i].runningTime > longestMovie->runningTime) {
            longestMovie = &arrayPtr[i];
        }
    }
    
    return longestMovie;
}
