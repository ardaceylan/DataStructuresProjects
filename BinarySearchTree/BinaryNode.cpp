/*
* Title: Trees
* Description: Binary Node cpp(implementation) file
*/
#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinaryNode::BinaryNode() {
    item = 0;
    sizeOfSubtree = 0;
    parentPtr = NULL;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
BinaryNode::BinaryNode(const int& nodeItem, BinaryNode* parent,
                       BinaryNode* left, BinaryNode* right) {
    item = nodeItem;
    sizeOfSubtree = 0;
    parentPtr = parent;
    leftChildPtr = left;
    rightChildPtr = right;
}
// end of the BinaryNode implementation
