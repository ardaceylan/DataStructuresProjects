/*
* Title: Trees
* Description: Binary Search Tree header file
*/
#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include "BinaryNode.h"
using namespace std;

class BinarySearchTree{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    bool add(int newEntry);
    bool remove(int anEntry);
    bool contains(int anEntry);
    void inorderTraverse();
    int getWidth();
    int count(int a, int b);
    int select(int anEntry);
    int successor(int anEntry);
private:
    int size;
    BinaryNode* rootPtr;
    //Helper Functions
    void insertItem(BinaryNode*& root, int newItem);
    bool deleteItem(BinaryNode*& root, int item);
    void deleteNode(BinaryNode*& nodePtr);
    void getAndDeleteSuccessor(BinaryNode*& nodePtr, int& repItem);
    void inorderTraverseHelper(BinaryNode* root);
    bool containsHelper(BinaryNode* root, int searched);
    void countHelper(BinaryNode* root, int a, int b, int& counter);
    void selectHelper(BinaryNode* root, int item, int& index);
    void successorHelper(BinaryNode* root, int item, int& suc);
    int getHeightHelper(BinaryNode* root);
    int getWidthHelper(BinaryNode* root, int level);
};

#endif // BINARYSEARCHTREE_H_INCLUDED
