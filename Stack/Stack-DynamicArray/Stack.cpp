#include "Stack.h"
#include <assert.h>

template <class T>
Stack<T>::Stack(void)
{
    elements = 0;
    capacity = 10;
    arr = new T[capacity];
}

template <class T>
Stack<T>::Stack(int capacity)
{
    this->capacity = capacity;
    elements = 0;
    arr = new T[capacity];
}

template <class T>
int Stack<T>::size()
{
    return elements;
}

template <class T>
bool Stack<T>::empty()
{
    return (elements == 0);
}

template <class T>
T Stack<T>::top()
{
    assert(!empty());

    return arr[elements - 1];
}

template <class T>
void Stack<T>::push(T newValue)
{
    if (elements == capacity)
        expand();

    arr[elements++] = newValue;
}

template <class T>
void Stack<T>::pop()
{
    assert(!empty());

    elements--;
}

template <class T>
void Stack<T>::expand()
{
    T *newArr = new T[capacity * 2];

    for (int i = 0; i < capacity; i++)
    {
        newArr[i] = arr[i];
    }

    capacity *= 2;

    delete[] arr;
    arr = newArr;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] arr; // to release memory before the class instance is destroyed
}