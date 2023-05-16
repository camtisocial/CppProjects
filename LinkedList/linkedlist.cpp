/*
 * Name: Cameron Thompson
 * Coding: 05
 * Purpose: doubly linked list toy class implementation
 */

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    clearList();
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*****PRIVATE FUNCTIONS******@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool LinkedList::isEmpty() {
    return head == NULL;
}

bool LinkedList::isValid(int id, string *info) {
    bool isValid = false;
    if (id > 0 && !(info->empty())) {
        isValid = true;
    }
    return isValid;
}

void LinkedList::printForward() {
    Node *position = head;
    while (position) {
        std::cout << position->data.id << ": " << position->data.data << std::endl;
        position = position->next;
    }
}

void LinkedList::printBackward() {
    Node *position = head;
    bool tail = false;
    while (position && !tail) {
        if (position->next) {
            position = position->next;
        } else {
            tail = true;
        }
    }
    while (position) {
        std::cout << position->data.id << ": " << position->data.data << std::endl;
        position = position->prev;
    }
}

bool LinkedList::addHead(int id, string *info) {
    bool nodeAdded = false;
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *info;

    if (head == NULL) {
        head = newNode;
        newNode->prev = NULL; 
        nodeAdded = true;
    } else {
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;
        head=newNode;
        nodeAdded = true;
    }
    return nodeAdded;
}

bool LinkedList::addMiddle(int id, string *info, Node *position) {
    bool nodeAdded = false;
    //Assigning values to new node
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *info;

    if (id != position->data.id) {
        newNode->next = position;
        newNode->prev = position->prev;
        position->prev->next = newNode;
        position->prev = newNode;
        nodeAdded = true;
    }
    return nodeAdded;
}

bool LinkedList::addTail(int id, string *info, Node *position) {
    bool nodeAdded = false;
    //Assigning values to new node
    if (id != position->data.id) {
        Node *newNode = new Node;
        newNode->data.id = id;
        newNode->data.data = *info;
    //Assigning pointers
        newNode->next = NULL;
        newNode->prev = position;
        position->next = newNode;
        nodeAdded = true;
    } 
    return nodeAdded;
}

bool LinkedList::deleteHead(Node *position) {
    if(head->next == NULL) {
        head = NULL;
        delete position;
    } else {
        head = head->next;
        head->prev = NULL;
        delete position;
    }
    return true;
}
bool LinkedList::deleteMiddle(Node *position) {
    position->prev->next = position->next;
    position->next->prev = position->prev;
    delete position;
    return true;
}
bool LinkedList::deleteTail(Node *position) {
    position->prev->next = NULL;
    delete position;
    return true;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*****PUBLIC FUNCTIONS******@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

bool LinkedList::addNode(int id, string *info) {
    bool nodeAdded = false;
    Node *position = head;
    //determine if data is valid 
    if (isValid(id, info)) {
        //determine if new node will be a head
        if (head == NULL || id < position->data.id) {
            nodeAdded = addHead(id, info);
        } else {
            //determine whether to add node to middle or tail
            bool tail = false, middle = false;
            while (position && !tail && !middle) {
                if (id <= position->data.id) {
                    nodeAdded = addMiddle(id, info, position);
                    middle = true;
                } else if(position->next == NULL) {
                    nodeAdded = addTail(id, info, position);
                    tail = true;
                } else {
                    position = position->next;
                }
            }
        } 
    }
    return nodeAdded;
}

bool LinkedList::deleteNode(int id) {
    bool stop = false;
    bool nodeRemoved = false;
    Node *position = head;
    while (position && !nodeRemoved && !stop) {
        if (position->data.id == id && position->prev == NULL) {
            nodeRemoved = deleteHead(position);
            stop = true;
        } else if (position->data.id == id && position->next != NULL) {
            nodeRemoved= deleteMiddle(position);
            stop = true;
        } else if (position->data.id == id && position->next == NULL) {
            nodeRemoved = deleteTail(position);
            stop = true;
        } else if (position->data.id != id && position->next == NULL) {
            stop = true;
        } else {
            position = position->next;
        }
    }
    return nodeRemoved;
}

bool LinkedList::getNode(int id, Data *node) {
    Node *position = head;
    bool nodeFound = false;
    while (position && !nodeFound) {
        if (position->data.id == id) {
            node->id = position->data.id;
            node->data = position->data.data;
            nodeFound = true;
        } else {
            position = position->next;
        }
    }
    return nodeFound;
}

void LinkedList::printList(bool backward) {

    if(backward && head != NULL) {
        printBackward();
    } else if (!backward && head != NULL) {
        printForward();
    } else {
        std::cout << "List is empty" << std::endl;
    }
}

int LinkedList::getCount() {
    Node *position = head;
    int count{};
    if (!isEmpty()) {
        while (position) {
            count += 1;
            position = position->next;
        }
    }
    return count;
}

bool LinkedList::clearList() {
    Node *position;
    while (head != NULL) {
        position = head;
        head = head->next;
        delete position;
    }
    return head == NULL;


}

bool LinkedList::exists(int id) {
    Node *position = head;
    bool nodeExists = false;
    while (position && !nodeExists) {
        if (position->data.id == id) {
            nodeExists = true;
        } else {
            position = position->next;
        }
    }
    return nodeExists;
}

