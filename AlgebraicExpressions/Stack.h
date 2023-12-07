
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string>
using namespace std;

class Stack{
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();
    bool isEmpty() const;
    bool push(string newItem);
    bool pop();
    bool pop(string& stackTop);
    string getTop() const;
    void reverseStack();

private:
    struct StackNode {
        string item;
        StackNode* next;
    };
    StackNode* topPtr;
};

#endif // STACK_H_INCLUDED
