// Assignment #5
// Name: Jing Liang
// ASU Email Address: jliang28@asu.edu
// Description:  This program reads an input data set consisting of four parts: the first part is a hash table size 
//               entered by a user; the second part is a list of course numbers followed by its title; 
//               the third part is an unordered list of course numbers; the fourth part is a list of course 
//               numbers with its title to delete.

#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

int main()
{
	// local variables, can be accessed anywhere from the main method
	char fuc = 'z';
	string input;
	string courseNumber, courseTitle;
	int size;

	// instantiate a Hash Table object
	HashTable * table1;

	cout << "Please enter a hash table size:\n";
	cin >> size;
	cin.ignore(20, '\n'); //flush the buffer
	table1 = new HashTable(size);
	do  // will ask for user input
	{
		courseNumber ="";
		courseTitle = "";
		getline(cin,input);
		if(input=="Insertion") fuc = 'I';
		else if (input=="Search")
		{
			if(fuc == 'I') table1->printList();
			fuc = 'S';
		}
		else if (input=="Delete")
		{
			if(fuc == 'I') table1->printList();
			else cout << endl;
			fuc = 'D';
		}
		else if (input=="Display") table1->printList();
		else
		{
			// matches one of the case statement
			switch (fuc)
			{
			case 'I':   //insert element
				{
					int i =input.find('/');
					courseNumber = input.substr(0,i);
					courseTitle = input.substr(i+1);
					table1->insertElement(courseNumber,courseTitle);
					break;
				}
			case 'S':    //search element
				{
					courseNumber = input;
					courseTitle = table1->searchElement(courseNumber);
					if (courseTitle == "-1") cout << "The course " << courseNumber << " notfound" <<endl;
					else cout << "The course " << courseNumber << " has the title: " << courseTitle <<endl;
					break;
				}
			case 'D':     //delete element
				{
					int i =input.find('/');
					courseNumber = input.substr(0,i);
					courseTitle = input.substr(i+1);
					if (table1->deleteElement(courseNumber,courseTitle)==true)
					{
						cout << "Course Number " << courseNumber << " with Title " << courseTitle << " is removed" << endl;
					}
					else
					{
						cout << "Course Number " << courseNumber << " with Title " << courseTitle << " not found" << endl;
					}
					break;
				}
			default:
				{
					cout << "Unknown action\n";
					break;
				}
			}
		}

	}while(input != "Display");
	return 0;
}
