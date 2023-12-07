/*
* Title: Trees
* Description: Binary Node header file
*/
#ifndef BINARYNODE_H_INCLUDED
#define BINARYNODE_H_INCLUDED

using namespace std;

class BinaryNode{
private:
    //Member Functions
    BinaryNode();
    BinaryNode(const int& nodeItem, BinaryNode* parent, BinaryNode* left,
               BinaryNode* right);

    //Data Members
    int item; // a data item in the node
    int sizeOfSubtree; // the number of nodes in its subtree
    BinaryNode* leftChildPtr; // pointer to the left child
    BinaryNode* rightChildPtr; // pointer to the right child
    BinaryNode* parentPtr; // pointer to the parent

	// friend class - can access private parts
	friend class BinarySearchTree;
};

#endif // BINARYNODE_H_INCLUDED
