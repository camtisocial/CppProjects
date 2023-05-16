/*
 * Name: Cameron Thompson
 * Coding: 05
 * Purpose: Declaration of linked list class 
 */

#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include "data.h"

class LinkedList {

public:
    LinkedList();
    ~LinkedList();
    
	bool addNode(int, string*);
	bool deleteNode(int);
	bool getNode(int, Data*);
	void printList(bool = false);
	int getCount();
	bool clearList();
	bool exists(int);

private:
    //attributes 
	Node *head;
    //misc
    bool isEmpty();
    bool isValid(int, string*);
    //printing
    void printForward();
    void printBackward();
    //adding/deleting nodes
	bool addHead(int, string*);
	bool addMiddle(int, string*, Node*);
	bool addTail(int, string*, Node*);
    bool deleteHead(Node *position);
    bool deleteMiddle(Node *position);
    bool deleteTail(Node *position);
};

#endif //LLIST_H
