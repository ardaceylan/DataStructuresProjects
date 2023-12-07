
#include <iostream>
#include "AlgebraicExpression.h"
using namespace std;

int main()
{
    cout << infix2prefix("( 15 - 5 ) + 30 * 2") << endl;
    cout << infix2postfix("( 15 - 5 ) + 30 * 2") << endl;
    cout << evaluateInfix("( 15 - 5 ) + 30 * 2") << endl;
    cout << prefix2infix("/ + * 100 3 50 - 11 4") << endl;
    cout << prefix2postfix("/ + * 100 3 50 - 11 4") << endl;
    cout << evaluatePrefix("/ + * 100 3 50 - 11 4") << endl;
    cout << postfix2infix("10 12 25 + 2 * - 4 /") << endl;
    cout << postfix2prefix("10 12 25 + 2 * - 4 /") << endl;
    cout << evaluatePostfix("10 12 25 + 2 * - 4 /") << endl;

    return 0;
}

