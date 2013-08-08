
#include <iostream>

#include "BST.h"
#include "ProvidedData.h"
#include "Student.h"

using namespace std;

int main(int argc, char *argv[])
{
	BST<unsigned int, Student> bstree;

	for(int i = 0 ; i < PROVIDED_DATA_SIZE ; i++)
	{
		bstree.Insert(PROVIDED_DATA[i].GetStudentID(), PROVIDED_DATA[i]);
	}

	bstree.InOrder(cout);
	cout << endl << "Height of the resulting tree: " << bstree.Height() << endl;

	unsigned int inputID;
	Student output(0, "", "");
	cout << endl << "Please enter a student ID to search for (0 to exit): ";
	cin >> inputID;
	while(inputID != 0)
	{
		if(bstree.Find(inputID, &output))
			cout << output << endl;
		else
			cout << "Error: Not found" << endl;

		Student output(0, "", "");
		cout << endl << "Please enter a student ID to search for (0 to exit): ";
		cin >> inputID;
	}

	return 0;
}
