#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node();
    // Parameterised Constructor
    Node(int data);
};

#endif