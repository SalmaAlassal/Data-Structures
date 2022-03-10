#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(void)
{
    capacity = 10;
    elements = 0;
    arr = new int [capacity];

}

Stack::Stack(int capacity)
{
    this -> capacity = capacity;
    elements = 0;
    arr = new int [capacity];
}

void Stack::push(int newValue)
{

    if ( capacity == elements )
    {
        expand();
    }

    arr[elements] = newValue;
    elements++;

}

void Stack::pop()
{
    elements--;
}

int Stack::top()
{
    return arr[elements-1];
}

int Stack::size()
{
    return elements;
}

bool Stack::empty()
{
    return ( elements == 0);
}

void Stack::expand()
{
    int* newArr = new int [capacity*2];
    for(int i=0 ; i< capacity  ; i++)
    {
        newArr[i] = arr[i];
    }
    capacity *= 2;
    delete [] arr;
    arr = newArr;
}

Stack::~Stack(void)
{

}



