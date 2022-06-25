#include "Vector.h"
#include <assert.h>

template <class T>
Vector<T>::Vector()
{
    elements = 0;
    Capacity = 10;
    arr = new T[Capacity];
}

template <class T>
Vector<T>::Vector(int capacity)
{
    elements = 0;
    this->Capacity = capacity;
    arr = new T[capacity];
}

template <class T>
int Vector<T>::size()
{
    return elements;
}

template <class T>
int Vector<T>::capacity()
{
    return Capacity;
}

template <class T>
bool Vector<T>::empty()
{
    return (elements == 0);
}

template <class T>
void Vector<T>::expand()
{
    T *temp = new T[Capacity * 2];
    for (int i = 0; i < Capacity; i++)
        temp[i] = arr[i];

    Capacity *= 2;
    delete[] arr;
    arr = temp;
}

template <class T>
void Vector<T>::insert(int position, T value)
{
    assert(position >= 0 && position <= elements);

    if (elements == Capacity)
        expand();

    for (int i = elements; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    elements++;
}

template <class T>
void Vector<T>::push_back(T newValue)
{
    if (elements == Capacity)
        expand();

    arr[elements++] = newValue;
}

template <class T>
T Vector<T>::back()
{
    assert(!elements == 0);
    return arr[elements - 1];
}

template <class T>
T Vector<T>::front()
{
    assert(!elements == 0);
    return arr[0];
}

template <class T>
void Vector<T>::pop_back()
{
    assert(!elements == 0);
    elements--;
}

template <class T>
void Vector<T>::clear()
{
    elements = 0;
    Capacity = 10;
    delete[] arr;
    arr = new T[Capacity];
}

template <class T>
Vector<T>::~Vector()
{
    delete[] arr;
}