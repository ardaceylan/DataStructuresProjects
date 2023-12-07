
#include "AlgebraicExpression.h"
#include "Stack.h"
#include <string>
#include <sstream>
using namespace std;

string infix2prefix( const string exp ) {
    string postfix = infix2postfix(exp);
    string prefix = postfix2prefix(postfix);
    return prefix;
}
string infix2postfix( const string exp ) {
    Stack sResult;
    Stack sItems;
    string result;
    string ch;

    getItems(exp, sItems);
    sItems.reverseStack();

    while (sItems.pop(ch)) {
        if (ch == "(")
            sResult.push(ch);
        else if (ch == ")") {
            while (sResult.getTop() != "(") {
                result += sResult.getTop() + " ";
                sResult.pop();
            }
            sResult.pop();
        }
        else if (isOperator(ch)) {
            while (!sResult.isEmpty() && precedence(ch) <= precedence(sResult.getTop())
                   && sResult.getTop() != "(") {
                result = result + sResult.getTop() + " ";
                sResult.pop();
            }
            sResult.push(ch);
        }
        else {
            ch += " ";
            result += ch;
        }
    }
    while (!sResult.isEmpty()) {
        result = result + sResult.getTop() + " ";
        sResult.pop();
    }
    return result;
}
string prefix2infix( const string exp ) {
    Stack sResult;
    Stack sItems;
    string result;
    string ch;

    getItems(exp, sItems);

    while (sItems.pop(ch)) {
        if (isOperator(ch)) {
            string op1 = sResult.getTop();
            sResult.pop();
            string op2 = sResult.getTop();
            sResult.pop();

            string temp = "";
            if (precedence(ch) == 1)
                temp = "( " + op1 + " " + ch + " " + op2 + " )";
            else
                temp = op1 + " " + ch + " " + op2;
            sResult.push(temp);
        }
        else
            sResult.push(ch);
    }
    result = sResult.getTop();
    return result;
}
string prefix2postfix( const string exp ) {
    string infix = prefix2infix(exp);
    string postfix = infix2postfix(infix);
    return postfix;
}
string postfix2infix( const string exp ) {
    string prefix = postfix2prefix(exp);
    string infix = prefix2infix(prefix);
    return infix;
}
string postfix2prefix( const string exp ) {
    Stack sResult;
    Stack sItems;
    string result;
    string ch;

    getItems(exp, sItems);
    sItems.reverseStack();

    while (sItems.pop(ch)) {
        if (isOperator(ch)) {
            string op1 = sResult.getTop();
            sResult.pop();
            string op2 = sResult.getTop();
            sResult.pop();

            string temp = ch + " " + op2 + " " + op1;
            sResult.push(temp);
        }
        else
            sResult.push(ch);
    }
    result = sResult.getTop();
    return result;
}
double evaluateInfix( const string exp ) {
    string postfix = infix2postfix(exp);
    double result = evaluatePostfix(postfix);
    return result;
}
double evaluatePrefix( const string exp ) {
    string postfix = prefix2postfix(exp);
    double result = evaluatePostfix(postfix);
    return result;
}
double evaluatePostfix( const string exp ) {
    Stack sResult;
    Stack sItems;
    double result;
    string ch;
    stringstream stream;

    getItems(exp, sItems);
    sItems.reverseStack();

    while (sItems.pop(ch)) {
        if (isOperator(ch)) {
            string op2 = sResult.getTop();
            sResult.pop();
            string op1 = sResult.getTop();
            sResult.pop();
            double val1;
            double val2;
            istringstream(op1) >> val1;
            istringstream(op2) >> val2;


            double value;
            string temp;

            if (ch == "+")
                value = val1 + val2;
            else if (ch == "-")
                value = val1 - val2;
            else if (ch == "*")
                value = val1 * val2;
            else if (ch == "/")
                value = val1 / val2;


            stream << value;
            temp = stream.str();

            sResult.push(temp);
            stream.str("");
            stream.clear();
        }
        else
            sResult.push(ch);
    }
    string sNum = sResult.getTop();
    istringstream(sNum) >> result;
    return result;
}
//Additional Methods
void getItems(const string exp, Stack& s){
    string item = "";
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ') {
            s.push(item);
            item = "";
        }
        else {
            item += exp[i];
            if (i == exp.length() - 1) {
                s.push(item);
                item = "";
            }
        }
    }
}
bool isOperator(const string ch) {
    bool success = ch == "+" || ch == "-" || ch == "*" || ch == "/";
    return success;
}
int precedence (const string ch) {
    if(ch == "*" || ch == "/")
        return 2;
    else if(ch == "+" || ch == "-")
        return 1;
    else
        return -1;
} // end of the AlgebraicExpression implementation
