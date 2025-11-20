
// CSC237 Project1: Text Packing / Unpacking Operations
// Student: Pedro Delesporte
// Due Date: 10 15 2025
// Description:
// This program reads a text document, “packs” the ASCII characters
// from that document into unsigned int variables, and outputs those variables
// to another text file as integers.
// This program also reverses the process, converting the unsigned int numbers
// back into a copy of the original text document.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void helpText();
void pCommand();
void uCommand();

int main() {
    string command;

    helpText();

    while (true) {

        cout << "\nEnter command: ";
        getline(cin, command);

        switch(toupper(command[0])) {
            case 'Q': cout << "Goodbye!\n"; return 0;
            case 'U': uCommand(); break;
            case 'P': pCommand(); break;
            case 'H': helpText(); break;
            default:  cout << "Invalid command. Type 'H' for help.\n"; break;
        }
    }
}

void helpText() {
        cout << "------------------ LIST OF COMMANDS ----------------- \n"
             << "P        Pack a text document into unsigned integers. \n"
             << "U        Unpack unsigned integers to text \n"
             << "H        Output help text \n"
             << "Q        Exit the program.\n"
             << "-----------------------------------------------------" << endl;
    }

void pCommand() {
    ifstream inputFile;
    ofstream outputFile;

    string in, out;

    cout << "Please enter a name for the input file you'd like to PACK: ";
    getline(cin, in);
    inputFile.open(in, ios::in);

    cout << "Please enter a name for the output file with the PACKED text: ";
    getline(cin, out);
    outputFile.open(out, ios::out);


    if (inputFile.is_open()) {
        char ch;
        string read;

        cout << "Opening the INPUT file: " << in << "\n" << endl;

        while (getline(inputFile, read)) {
            read += '\n';

            cout << "TEXT LENGTH: " << read.length() << " = " << read;

            for (size_t i = 0; i < read.length(); i += 4) {
                unsigned int packed = 0;

                // Pack 4 characters into one unsigned int using bitwise operations
                for (int j = 0; j < 4; j++) {
                    if (i + j < read.length()) {
                        // Get the character
                        ch = read[i + j];

                        packed |= static_cast<unsigned int>(ch) << (8 * (3 - j));
                        //this formula 8 * (3-j) make 1st char go to position 24-31
                        //2nd char position 16-23
                        //3rd char position 8-15
                        //4th char position 0-7
                    }
                }

                outputFile << packed << endl;
            }

            outputFile << endl;
        }

        cout << "\nClosing the INPUT file: " << in << endl;

        inputFile.close();
        outputFile.close();

        cout << "Packing completed." << endl;
        cout << "File: " << in << "created" << endl;

    } else {
        cout << "ERROR when opening INPUT file: " << in << endl;
    }
}

void uCommand() {
    ifstream inputFile;
    ofstream outputFile;

    string in, out;

    cout << "Please enter a name of the PACKED file you'd like to UNPACK: ";
    getline(cin, in);
    cout << "Please enter a name for the output file with the UNPACKED text: ";
    getline(cin, out);

    inputFile.open(in, ios::in);
    outputFile.open(out, ios::out);

    if (inputFile.is_open()) {
        unsigned int packed;
        cout << "Opening the INPUT file: " << in << endl;

        while (inputFile >> packed) {
            // Skip empty lines (blank lines between groups)
            if (packed == 0) {
                continue;
            }

            // UNPACK the integer into 4 characters
            for (int j = 0; j < 4; j++) {
                // Extract one character at a time
                unsigned char ch = (packed >> (8 * (3 - j))) & 0xFF;

                // Only output non-null characters
                if (ch != 0) {
                    outputFile << ch;
                }
            }
        }

        cout << "\nClosing the INPUT file: " << in << endl;

        inputFile.close();
        outputFile.close();

        cout << "Unpacking completed successfully!" << endl;

    } else {
        cout << "ERROR when opening INPUT file: " << in << endl;
    }
}
