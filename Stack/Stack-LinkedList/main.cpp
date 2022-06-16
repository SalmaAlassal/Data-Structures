#include "Stack.cpp"
#include <iostream>

using namespace std;

int main() {

    Stack <int>  stack;

    stack.push(10); 
    stack.push(20); 

    cout << stack.top() << endl; // print the top of stack -> 20 at this moment

    stack.push(30); 

    cout << stack.top() << endl; // print the top of stack -> 30 at this moment

    cout << stack.size() << endl; // print the size of stack -> 3 at this moment

    stack.pop(); 

    while (!stack.empty())
    {
        cout <<stack.top()<< endl;
        stack.pop();
    }

    // the output of the previous loop is : 20 10
}