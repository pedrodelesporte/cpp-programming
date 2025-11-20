#include <iostream>
#include "InventoryItem.h"
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void helpCommand();
void AddPartsCommand(InventoryItem items[], int& itemCount, int limit);
void InputInventoryDataCommand(InventoryItem items[], int& itemCount, int limit);
void CreateInventoryCommand(InventoryItem items[], int& itemCount, int limit);
void OutputInventoryCommand(InventoryItem items[], int& itemCount);
void PrintInventoryCommand(InventoryItem items[], int itemCount);
void RemovePartsCommand(InventoryItem items[], int& itemCount);
int splitLineToArray(string inputText, string inputDelim, string outputFieldArray[], int maxFields);


int main() {
    string command;
    const int limit = 100;
    InventoryItem items[limit];
    int ItemCount = 0;

    helpCommand();

    while (true) {

        cout << "\nEnter a command: ";
        getline(cin, command);

        switch(toupper(command[0])) {
            case 'Q': cout << "Goodbye!\n"; return 0;

            case 'A': AddPartsCommand(items, ItemCount, limit); break;
            case 'I': InputInventoryDataCommand(items, ItemCount, limit); break;
            case 'N': CreateInventoryCommand(items, ItemCount, limit); break;
            case 'O': OutputInventoryCommand(items, ItemCount); break;
            case 'P': PrintInventoryCommand(items, ItemCount); break;
            case 'R': RemovePartsCommand(items, ItemCount); break;
            case 'H': helpCommand(); break;

            default: cout << "Invalid command. Type 'H' for help.\n"; break;
        }
    }
}


void helpCommand() {
    cout << "A   Increase the units value for an existing InventoryItem object.\n"
         << "H   Prints help text.\n"
         << "I   Input inventory data from a file.\n"
         << "N   Create a New inventory Item.\n"
         << "O   Output inventory data to a file.\n"
         << "P   Print inventory list on the screen.\n"
         << "Q   Quit from the program.\n"
         << "R   Reduce the units value for an existing InventoryItem object." << endl;
}

void AddPartsCommand(InventoryItem items[], int& itemCount, int limit) {
    int itemNumber;

    cout << "Please enter the item number: ";
    cin >> itemNumber;
    cin.ignore();

    // validate if item exists
    if (itemNumber < 0 || itemNumber >= itemCount) {
        cout << "Item number " << itemNumber << " does not exist." << endl;
        return;
    }

    int unitsToAdd;

    do {
        cout << "How many units would you like to add? ";
        cin >> unitsToAdd;
        cin.ignore();

        if (unitsToAdd < 0) {
            cout << "You can't add negative units." << endl;
        }

    } while (unitsToAdd < 0);

    // calculate new total and validate
    int newTotal = items[itemNumber].getUnits() + unitsToAdd;

    if (newTotal > 30) {
        cout << "You can't exceed 30 units. Current units are: " << items[itemNumber].getUnits() << ", attempted to: +" << unitsToAdd << endl;
        return;
    }

    // update the item
    items[itemNumber].setUnits(newTotal);

    cout << "Successfully added " << unitsToAdd << " units to item number (" << itemNumber << ") " << items[itemNumber].getDescription() << endl;
}


void InputInventoryDataCommand(InventoryItem items[], int& itemCount, int limit) {
    string filename;
    cout << "Enter the name of input file: ";
    getline(cin, filename);

    ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		cout << "File does not exist. " << filename << "'" << endl;
		return;
	}

    string line;
    int newInventory = 0;

    while (getline(inputFile, line) && itemCount < limit) {


        string fields[4];  // expect 4 fields per line
        int fieldCount = splitLineToArray(line, "|", fields, 4);

        if (fieldCount >= 4) {  //  all 4 fields


            string description = fields[1]; // skip field 0
            double cost = stod(fields[2]);  // convert string to double
            int units = stoi(fields[3]);    // convert string to int

            if (units >= 0 && units <= 30) {


                InventoryItem newItem;
                newItem.setDescription(description);
                newItem.setCost(cost);
                newItem.setUnits(units);


                items[itemCount] = newItem;
                itemCount++;
                newInventory++;
            }
        }
    }

    inputFile.close();
    cout << newInventory << " items added to the inventory." << endl;
}

void CreateInventoryCommand(InventoryItem items[], int& itemCount, int limit) {
    if (itemCount > limit) {
        cout << "There is no space for a new item." << endl;
    } else {
        string description;
        double cost;
        int units;


        cout << "Enter item description: " << endl;
        getline(cin, description);


        cout << "Enter item cost: " << endl;
        cin >> cost;
        cin.ignore();

        do {
            cout << "Enter initial quantity for the new Item: ";
            cin >> units;
            cin.ignore();

            if (units < 0 || units > 30) {
                cout << "Units must be between 0-30!" << endl;
            }
        } while (units < 0 || units > 30);


        InventoryItem NewItem;

        //calling setters with the input
        NewItem.setDescription(description);
        NewItem.setCost(cost);
        NewItem.setUnits(units);


        //add to array and increment count
        items[itemCount] = NewItem;
        itemCount++;

    	cout << "Announcing a new inventory Item: " << description << endl;
    	cout << "We now have " << itemCount << " different inventory Items in stock!" << endl;

    }
}

void OutputInventoryCommand(InventoryItem items[], int& itemCount) {
	string filename;
	cout << "Enter the name of output file: ";
	getline(cin, filename);

	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cout << "Error creating the file. " << filename << endl;
		return;
	}

	// set precision for cost values
	outputFile << fixed << setprecision(2);

	for (int i = 0; i < itemCount; i++) {
		outputFile << i << "|"
				   << items[i].getDescription() << "|"
				   << items[i].getCost() << "|"
				   << items[i].getUnits() << endl;
	}

	outputFile.close();
	cout << itemCount << " items successfully written to file: " << filename << endl;
}

void PrintInventoryCommand(InventoryItem items[], int itemCount) {
	if (itemCount == 0) {
		cout << "No items in inventory.\n";
		return;
	}

	cout << "Item Num    Description                Cost    Quantity" << endl;
	cout << "_______     ___________                ____    ________" << endl;

	cout << fixed << setprecision(2);

	for (int i = 0; i < itemCount; i++) {
		cout << " " << setw(3) << i << "    "
			 << setw(28) << left << items[i].getDescription()
			 << "  "
			 << setw(6) << right << items[i].getCost()
			 << "    "
			 << setw(3) << items[i].getUnits() << endl;
	}

}


void RemovePartsCommand(InventoryItem items[], int& itemCount) {
    //TODO
    int itemNumber;

    cout << "Please enter the item number: ";
    cin >> itemNumber;
    cin.ignore();

    // validate if item exists
    if (itemNumber < 0 || itemNumber >= itemCount) {
        cout << "Item number " << itemNumber << " does not exist." << endl;
        return;
    }

    int unitsToRemove;

    do {
        cout << "How many units would you like to remove? ";
        cin >> unitsToRemove;
        cin.ignore();

        if (unitsToRemove < 0) {
            cout << "You can't remove negative units." << endl;
        }

    } while (unitsToRemove < 0);

    // calculate new total and validate
    int newTotal = items[itemNumber].getUnits() - unitsToRemove;

    if (newTotal < 0) {
        cout << "You can't remove more than what it's available. Current units are: " << items[itemNumber].getUnits() << ", you attempted to remove: " << unitsToRemove << endl;
        cout << "Which would be: " << newTotal << endl;
        return;
    }

    // update the item
    items[itemNumber].setUnits(newTotal);

    cout << "Successfully removed " << unitsToRemove << " units from item number (" << itemNumber << ") " << items[itemNumber].getDescription() << endl;

}

int splitLineToArray(string inputText, string inputDelim,
	string outputFieldArray[], int maxFields)
{
	//	Local Variables:
	size_t nextFieldPosition = 0;		//	Start position of data field.
	size_t foundPosition;				//  Position where delimiter was found,
	int fieldCount = 0;		        //  Number of data fields found so far,
	bool endOfLine = false;			//	Flag -- end of input line detected,
	string dataField;				//  Copy of the data field.

	if (inputDelim == "") {
		cout << "ERROR(splitLineToArray): the inputDelim parameter "
		     << "must NOT be the empty string." << endl;
		return 0;
	}
	while (!endOfLine)
	{
		foundPosition = inputText.find(inputDelim, nextFieldPosition);
		if (foundPosition != string::npos)
		{
			// (Here if 'inputDelim' was found in the input string.)
			// Copy the data field contents from the input string to the
			// 'dataField' local variable.
			dataField = inputText.substr(nextFieldPosition, foundPosition - nextFieldPosition);
			fieldCount++;

			// Adjust 'nextFieldPosition' as preparation for finding NEXT delimiter.
			nextFieldPosition = foundPosition + inputDelim.length();
		}
		else
		{
			// (Here if the string 'find' function reached the end of the input
			// string WITHOUT finding the inputDelim value.)
			endOfLine = true;   // (The "while-loop" will not repeat again.)

			// Set foundPosition to the LENGTH of the original inputText, to handle
			// the case where there is more text AFTER the last occurrence of the
			// inputDelim string.
			foundPosition = inputText.length();

			// If there is text to output to the caller, use the substr function
			// (in the string class) to copy that text to the dataField local
			// variable, and increment the fieldCount local variable.
			if (foundPosition > nextFieldPosition)
			{
				dataField = inputText.substr(nextFieldPosition,
					foundPosition - nextFieldPosition);
				fieldCount++;
			}
		}


		if (fieldCount > 0)
		{
			if (fieldCount > maxFields)
			{
				cout << "ERROR at line __LINE__: too many input fields, fieldCount="
					<< fieldCount << endl;
			}
			else
			{
				outputFieldArray[fieldCount - 1] = dataField;
			}
		}
	} // (end while)


	return fieldCount;
} // (end function splitLineToArray )
