
#include "Stack.h"
#include <string>
#include <iostream>
using namespace std;

Stack::Stack() {
    topPtr = NULL;
}
Stack::Stack(const Stack& aStack) {
    cout << "Copy  called" << endl;
    if (aStack.topPtr == NULL)
        topPtr = NULL;  // original stack is empty

    else {
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        StackNode *newPtr = topPtr;
        for (StackNode *origPtr = aStack.topPtr->next;
                      origPtr != NULL;
                      origPtr = origPtr->next){
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}
Stack::~Stack() {
    while (!isEmpty())
        pop();
}
bool Stack::isEmpty() const {
    return topPtr == NULL;
}
bool Stack::push(string newItem) {
    StackNode* newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}
bool Stack::pop() {
    if (isEmpty())
        return false;
    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        //delete the popped node
        temp->next = NULL;
        delete temp;
        temp = NULL;
        return true;
    }
}
bool Stack::pop(string& stackTop) {
    if (isEmpty())
        return false;
    else {
        stackTop = topPtr->item;
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        //delete the popped node
        temp->next = NULL;
        delete temp;
        temp = NULL;
        return true;
    }
}
string Stack::getTop() const {
    if (isEmpty())
        return "";
    else
        return topPtr->item;

}
void Stack::reverseStack() {
    StackNode *prev, *cur, *successor;
    cur = prev = topPtr;
    cur = cur->next;
    prev->next = NULL;
    while (cur != NULL) {

        successor = cur->next;
        cur->next = prev;
        prev = cur;
        cur = successor;
    }
    topPtr = prev;
}
 // end of the Stack implementation
