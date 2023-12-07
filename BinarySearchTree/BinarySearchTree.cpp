/*
* Title: Trees
* Description: Binary Search Tree cpp(implementation) file
*/
#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    size = 0;
    rootPtr = NULL;
}
BinarySearchTree::~BinarySearchTree() {
    while (!isEmpty())
        remove(rootPtr->item);
}
bool BinarySearchTree::isEmpty() {
    return size == 0;
}
int BinarySearchTree::getHeight() {
    return getHeightHelper(rootPtr);
}
int BinarySearchTree::getNumberOfNodes() {
    return size;
}
bool BinarySearchTree::add(int newEntry) {
    if (newEntry <= 0) {
        cout << "The entry cannot be added: The entry should be positive integer!" << endl;
        return false;
    }
    else if (contains(newEntry)) {
        //cout << "The entry cannot be added: The entry is already in the BST!" << endl;
        return false;
    }
    else {
        insertItem(rootPtr, newEntry);
        size++;
    }
    return true;
}
bool BinarySearchTree::remove(int anEntry) {
    if (!contains(anEntry)) {
        cout << "Item cannot be removed: The item is not in the BST!" << endl;
        return false;
    }
    bool success = deleteItem(rootPtr, anEntry);
    if (success)
        size--;
    return success;
}
bool BinarySearchTree::contains(int anEntry) {
    return containsHelper(rootPtr, anEntry);
}
void BinarySearchTree::inorderTraverse() {
    if (isEmpty())
        cout << "No item in the BST" << endl;
    else {
        inorderTraverseHelper(rootPtr);
        cout << endl;
    }
}
int BinarySearchTree::getWidth() {
    int maxW = 0;
    int width = 0;
    int height = getHeight();

    for (int i = 1; i <= height; i++) {
        width = getWidthHelper(rootPtr, i);
        if (width > maxW)
            maxW = width;
    }
    return maxW;
}
int BinarySearchTree::count(int a, int b) {
    int counter = 0;
    countHelper(rootPtr, a, b, counter);
    return counter;
}
int BinarySearchTree::select(int anEntry) {
    if (!contains(anEntry))
        return -1;
    int index = 0;
    selectHelper(rootPtr, anEntry, index);
    return index;
}
int BinarySearchTree::successor(int anEntry) {
    if (!contains(anEntry))
        return -1;
    int successor = -2;
    successorHelper(rootPtr, anEntry, successor);
    return successor;
}

//Helper Functions
void BinarySearchTree::insertItem(BinaryNode*& root, int newItem) {
    if (root == NULL)
        root = new BinaryNode(newItem, NULL, NULL, NULL);
    else if (root->sizeOfSubtree == 0) {
        BinaryNode* newNode = new BinaryNode(newItem, root, NULL, NULL);
        root->sizeOfSubtree++;

        if(newItem < root->item)
            root->leftChildPtr = newNode;
        else
            root->rightChildPtr = newNode;
    }

    else if (newItem < root->item)
        insertItem(root->leftChildPtr, newItem);
    else
        insertItem(root->rightChildPtr, newItem);

}
bool BinarySearchTree::deleteItem(BinaryNode*& root, int item) {
    if (root == NULL) {
        return false;
    }
    else if (item == root->item) {
        deleteNode(root);
        return true;
    }
    else if (item < root->item)
        return deleteItem(root->leftChildPtr, item);
    else
        return deleteItem(root->rightChildPtr, item);
}
void BinarySearchTree::deleteNode(BinaryNode*& nodePtr) {
    BinaryNode* delPtr = NULL;
    int repItem = 0;

    // leaf
    if (nodePtr->leftChildPtr == NULL && nodePtr->rightChildPtr == NULL) {
        nodePtr->parentPtr = NULL;
        delete nodePtr;
        nodePtr = NULL;
    }
    // only right child
    else if (nodePtr->leftChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr->rightChildPtr->parentPtr = nodePtr->parentPtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
        delPtr = NULL;
    }
    // only left child
    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr->leftChildPtr->parentPtr = nodePtr->parentPtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
        delPtr = NULL;
    }
    // 2 children
    else {
        getAndDeleteSuccessor(nodePtr->rightChildPtr, repItem);
        nodePtr->item = repItem;
    }
}
void BinarySearchTree::getAndDeleteSuccessor(BinaryNode*& nodePtr, int& repItem) {
    if (nodePtr->leftChildPtr == NULL) {
        repItem = nodePtr->item;
        BinaryNode* delPtr;
        delPtr = nodePtr;
        nodePtr->rightChildPtr->parentPtr = nodePtr->parentPtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
        delPtr = NULL;
    }
    else
        getAndDeleteSuccessor(nodePtr->leftChildPtr, repItem);
}
void BinarySearchTree::inorderTraverseHelper(BinaryNode* root) {
    if (root != NULL) {
        inorderTraverseHelper(root->leftChildPtr);
        cout << root->item << " ";
        inorderTraverseHelper(root->rightChildPtr);
    }
}
bool BinarySearchTree::containsHelper(BinaryNode* root, int searched) {
    if (root == NULL)
        return false;
    else if (searched == root->item)
        return true;
    else if (searched < root->item)
        return containsHelper(root->leftChildPtr, searched);
    else
        return containsHelper(root->rightChildPtr, searched);
}
void BinarySearchTree::countHelper(BinaryNode* root, int a, int b, int& counter) {
    if (root != NULL) {
        if (a <= root->item && b >= root->item)
            counter++;
        countHelper(root->leftChildPtr, a, b, counter);
        countHelper(root->rightChildPtr, a, b, counter);
    }
}
void BinarySearchTree::selectHelper(BinaryNode* root, int item, int& index) {
    if (root != NULL) {
        selectHelper(root->leftChildPtr, item, index);
        if (root->item < item)
            index++;
        selectHelper(root->rightChildPtr, item, index);
    }
}
void BinarySearchTree::successorHelper(BinaryNode* root, int item, int& suc) {
    if (root != NULL) {
        successorHelper(root->rightChildPtr, item, suc);
        if (root->item > item) {
            suc = root->item;
        }
        successorHelper(root->leftChildPtr, item, suc);
    }
}
int BinarySearchTree::getHeightHelper(BinaryNode* root) {
    if (root == NULL)
        return 0;
    else {
        int lHeight = getHeightHelper(root->leftChildPtr);
        int rHeight = getHeightHelper(root->rightChildPtr);

        if (rHeight > lHeight)
            return (rHeight + 1);
        else
            return (lHeight + 1);
    }
}
int BinarySearchTree::getWidthHelper(BinaryNode* root, int level) {
    if (root == NULL)
        return 0;
    else if (level == 1)
        return 1;
    else if (level > 1)
        return (getWidthHelper(root->leftChildPtr, level - 1) + getWidthHelper(root->rightChildPtr, level - 1));
    else
        return -1;
}
