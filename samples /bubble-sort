// This program uses the bubble sort algorithm to sort an array 
// in ascending order.  (Adapted from Program 8-4)
#include <iostream>
using namespace std;

// Function prototypes
void sortArray(int[], int);
void showArray(const int[], int);

int main()
{
	// Array of unsorted values
	int values[6] = { 5, 7, 2, 8, 9, 1 };

	// Display the values.
	cout << "BUBBLE SORT: The unsorted values are:             ";
	showArray(values, 6);

	// Sort the values.
	sortArray(values, 6);

	// Display them again.
	cout << "The sorted values are:                            ";
	showArray(values, 6);
	system("pause");
	return 0;
}

//***********************************************************
// Definition of function sortArray                         *
// This function performs an ascending order bubble sort on *
// array. size is the number of elements in the array.     *
//***********************************************************

void sortArray(int array[], int size)
{
	bool swap;
	int swapCount=0;
	int temp;
	int pass = 0;
	do
	{
		pass++;   // Count the passes over the array.
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				cout << "Pass " << pass << ": swap [" << count << "] " << array[count] <<
					" with [" << count + 1 << "] " << array[count + 1] << ".";
			
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
				swapCount++;
				cout << "    modified array: ";
				showArray(array, size);
			}
		}
	} while (swap);
	cout << "Total passes = " << pass
		<< "    Total swaps = " << swapCount << endl;
}



void showArray(const int array[], int size)
{
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;
}
