// Assignment #5
// Name: Jing Liang
// ASU Email Address: jliang28@asu.edu
// Description: This is the header for the HashTable class.

#include <string> //to use strings

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
    private:
    struct Course * head;
    
    public:
    LinkedList();
    ~LinkedList();
    bool insertElement(string number, string title);
	string searchElement(string number);
    bool deleteElement(string number, string title);
	int getSize();
    void printList();
};


#endif