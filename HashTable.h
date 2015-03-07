// Assignment #5
// Name: Jing Liang
// ASU Email Address: jliang28@asu.edu
// Description: This is the header for the LinkedList class.

#include <string> //to use strings
#include "LinkedList.h"

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
    private:
    int size; 
    LinkedList* slots;
    
    public:
    HashTable(int size);
    ~HashTable();
    bool insertElement(string number, string title);
	string searchElement(string number);
    bool deleteElement(string number, string title);
	int hashFunction(string number);
    void printList();
};


#endif