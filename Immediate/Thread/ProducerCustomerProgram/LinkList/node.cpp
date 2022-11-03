#include "node.h"

Node::Node()
{
    data = 0;
    next = NULL;
}

// Parameterised Constructor
Node::Node(int data)
{
    this->data = data;
    this->next = NULL;
}