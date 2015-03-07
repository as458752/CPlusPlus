// Assignment #5
// Name: Jing Liang
// ASU Email Address: jliang28@asu.edu
// Description: This LinkedList class provide methods to insert, delete, search or print elements in the linked list.

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings
#include "LinkedList.h"

using namespace std;

//struct Course represents some course information
struct Course
{
    string number;
    string title;
    struct Course * next;
};


//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Description: This is a destructor of the LinkedList class. It will remove all elements in the linked list and perform garbage collection (free their memory).
LinkedList::~LinkedList()
{
	Course* p = head;        
	int i = 0;                //count the size of the linked list
	while (p !=NULL)
	{
		i++;
		p = p->next;
	}
    cout << "The number of deleted courses is: " << i << endl;
    delete head;
}

//Description: This method attempts to add a new course data into the beginning of the linked list.
bool LinkedList::insertElement(string newNumber, string newTitle)
 {
	 Course* c = new Course();
	 c ->number = newNumber;
	 c ->title = newTitle;
	 c ->next = head;
	 head = c;
	 return true;
 }

//Description:  This method attempt to search the course with the parameter course number value and will return course name if it can find. It will return "-1" otherwise.
string LinkedList::searchElement(string someNumber)
{
	Course* p = head;
	while (p !=NULL)
	{
		if(p ->number == someNumber)  return p->title;
		else p = p->next;
	}
	return "-1";
}

//Description:  This method attempts to remove the course with the parameter course number value and course title and will return true if it can find and remove the course information. It will return false otherwise.
bool LinkedList::deleteElement(string someNumber, string someTitle)
 {
    Course* p = head, *before = NULL;
	
	while (p !=NULL)
	{
		if(p ->number == someNumber && p ->title == someTitle)
		{
			if (before == NULL) head = p ->next;
			else before ->next = p ->next;
			return true;
		}
		before = p;
		p = p ->next;
	}
	return false;
 }

////Description: It returns the size of the linked list.
int LinkedList::getSize()
{
	int i=0;
	Course* p = head;
	while (p !=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

//Description: It prints all entries in the linked list.
void LinkedList::printList()
{
    Course* p = head;
	while (p !=NULL)
	{
		cout << "Course Number: " << p ->number << ", Course Title: " << p ->title << endl;
		p = p ->next;
	}
}
