#include "Queue.h"
#include <assert.h>

template <class T>
Queue<T>::Queue(void)
{
    elements = 0;
    capacity = 10;
    arr = new T[capacity];
    Front = Back = -1;
}

template <class T>
Queue<T>::Queue(int capacity)
{
    elements = 0;
    this->capacity = capacity;
    arr = new T[capacity];
    front = back = -1;
}

template <class T>
bool Queue<T>::empty()
{
    return (elements == 0);
}

template <class T>
int Queue<T>::size()
{
    return elements;
}

template <class T>
bool Queue<T>::full()
{
    return (elements == capacity);
}

template <class T>
T Queue<T>::front()
{
    assert(!empty());
    return arr[Front];
}

template <class T>
T Queue<T>::back()
{
    assert(!empty());
    return arr[Back];
}

template <class T>
void Queue<T>::push(T newValue)
{
    if (elements == capacity)
        expand();

    if (elements == 0)
        Front = 0;

    Back = (Back + 1) % capacity;

    arr[Back] = newValue;

    elements++;
}

template <class T>
void Queue<T>::expand()
{
    T *newArr = new T[capacity * 2];
    for (int i = 0; i < capacity; i++)
        newArr[i] = arr[i];

    capacity *= 2;
    delete[] arr;
    arr = newArr;
}

template <class T>
void Queue<T>::pop()
{
    assert(!empty());

    if (elements == 1)
        Front = Back = -1;
    else
        Front = (Front + 1) % capacity;

    elements--;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] arr;
}