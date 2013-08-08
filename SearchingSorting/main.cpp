#include <iostream>
// References: prac 8 material for find and prac 9 material for Sort algorithm.
#include "ProvidedData.h"

using namespace std;

template<class TYPE>
void Swap(TYPE &left, TYPE &right)
{
	TYPE temp;
	temp = left;
	left = right;
	right = temp;
}
// References: prac 8 tasks
bool Find(Student *array[], int size, unsigned int studentID, Student *output)
{
	// initialize intermediate variables
	bool found = false;
	int begin = 0;
	int end = size - 1;
	int middle;
	
	// Begin Search
	while(begin <= end && !found)
	{
		middle = (begin + end) / 2; // split search in halves
		if (array[middle]->GetStudentID() == studentID)
			found = true; 
		else if(array[middle]->GetStudentID() > studentID) // compare first half for result
			end = middle - 1; // if less set end to middle-1
		else 
			begin = middle + 1; // otherwise if higher set start middle +1
		
	}
	// when found..
	if (found) 
	{
		*output = *(array[middle]); // assign output to result
	}

	return found;	
}

void Sort(Student *array[], int size)
{
	// BubbleUp Sort
	for (int firstSorted = -1; firstSorted < size - 1; firstSorted++)
	{	
		// For each element in the unsorted list
		for (int current = size - 2; current > firstSorted; current --) 
		{
			//If this element and the next element are out of order, then swap the two elements
			if(array[current]->GetStudentID() > array[current + 1]->GetStudentID())
				Swap(array[current], array[current + 1]);
		}
	}
}

/*
** DO NOT MODIFY THIS FUNCTION
*/
int main(int argc, char *argv[])
{
	Student *sortArray[PROVIDED_DATA_SIZE];

	for(int i = 0 ; i < PROVIDED_DATA_SIZE ; i++)
		sortArray[i] = &(PROVIDED_DATA[i]);

	Sort(sortArray, PROVIDED_DATA_SIZE);

	for(int i = 0 ; i < PROVIDED_DATA_SIZE ; i++)
		cout << *(sortArray[i]) << endl;

	unsigned int inputID;
	Student output(0, "", "");
	cout << endl << "Please enter a student ID to search for (0 to exit): ";
	cin >> inputID;
	while(inputID != 0)
	{
		if(Find(sortArray, PROVIDED_DATA_SIZE, inputID, &output))
			cout << output << endl;
		else
			cout << "Error: Not found" << endl;

		Student output(0, "", "");
		cout << endl << "Please enter a student ID to search for (0 to exit): ";
		cin >> inputID;
	}

	return 0;
}
