// Assignment #5
// Name: Jing Liang
// ASU Email Address: jliang28@asu.edu
// Description: This HashTable class provide methods to add, delete or print elements in the Hash Table and a hash function h.

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings
#include "HashTable.h"

using namespace std;

//Constructor to initialize the hash table
HashTable::HashTable(int size)
{
	HashTable::size = size;
	slots =new LinkedList[size];
	int i;
	for(i=0;i<size;i++)
	{
		slots[i] =* (new LinkedList());
	}
}

//Destructor
//Description: This is a destructor of the LinkedList class. It will remove the array of linked list and perform garbage collection (free their memory).
HashTable::~HashTable()
{
	delete slots;
}

//Description: This method contain the hash function for the hash table. It takes each character in course number and convert them to number according to ASCII Table. It will return the remainder sum of those numbers divide hash table size.
int HashTable::hashFunction(string number)
{
	int n = 0,i;
	for(i=0;i<number.length();i++)
	{
		n = n+ ((int) number[i]);
	}
	return (n % size);
}

//Description: This method call the insertElement function in LinkedList class
bool HashTable::insertElement(string number, string title)
{
	return slots[hashFunction(number)].insertElement(number,title);
}

//Description: This method call the searchElement function in LinkedList class
string HashTable::searchElement(string number)
{
	return slots[hashFunction(number)].searchElement(number);
}

//Description: This method call the deleteElement function in LinkedList class
bool HashTable::deleteElement(string number, string title)
{
	return slots[hashFunction(number)].deleteElement(number,title);
}

//Description: This method call the printList function in LinkedList class
void HashTable::printList()
{
	cout << "\n";
	int i;
	for(i=0;i<size;i++)
	{
		cout << "index: " << i << ", linked list size: " << slots[i].getSize() << endl;
		slots[i].printList();
		cout <<endl;
	}
}