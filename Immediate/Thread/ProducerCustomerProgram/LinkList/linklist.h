#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include "node.h"
  
// Node class to represent
// a node of the linked list.

  
// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;
  
public:
    // Default constructor
    Linkedlist() { head = NULL; }
  
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);
  
    // Function to print the
    // linked list.
    void printList();
  
    // Function to delete the
    // node at given position
    void deleteNode(int);

    int printFistList();
};
  


#endif