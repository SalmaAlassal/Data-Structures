#include <iostream>
#include "Stack.h"
using namespace std;

void convertDecimalToBinary(int decimalNumber)
{
    Stack stack;
    while(decimalNumber > 0)
    {
        stack.push( decimalNumber % 2 );
        decimalNumber /=2;
    }

    while (!stack.empty())
    {
        cout <<stack.top();
        stack.pop();
    }
}

int main()
{

    int decimalNumber;
    cout << "Enter decimal Number to convert:" << endl;
    cin >> decimalNumber;
    convertDecimalToBinary(decimalNumber);

    return 0;
}
