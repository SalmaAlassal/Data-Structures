#include "ArrayList.h"
#include <assert.h>

template <class T>
ArrayList<T>::ArrayList()
{
    elements = 0;
    capacity = 10;
    Back = -1;
    arr = new T[capacity];
}

template <class T>
ArrayList<T>::ArrayList(int capacity)
{
    elements = 0;
    this -> capacity = capacity;
    Back = -1;
    arr = new T[this -> capacity];
}

template <class T>
int ArrayList<T>::size()
{
    return elements ;
}

template <class T>
bool ArrayList<T>::empty()
{
    return (elements == 0);
}


template <class T>
void ArrayList<T>::expand()
{
    T* temp = new T [capacity * 2 ];
    for (int i = 0 ; i < capacity ; i++ )
         temp[i] = arr[i];

    capacity *= 2;
    delete [] arr;
    arr =  temp;

}

template <class T>
void ArrayList<T>::insert(int position, T value)
{
    assert( position >= 0 && position <= elements);

    if ( elements == capacity)
        expand();

    for(int i = elements  ; i > position ; i--)
    {
        arr[i] = arr [i-1];
    }

    arr[position] = value ;
    Back++;
    elements++;
}

template <class T>
void ArrayList<T>::push_back(T newValue)
{

    if ( elements == capacity)
        expand();

    Back++;
    arr[Back] = newValue ;

    elements++;
}

template <class T>
void ArrayList<T>::push_front(T newValue)
{
    if ( elements == capacity)
        expand();

      T* temp = new T [capacity];
      temp [0] = newValue;

      for(int i = 0 ; i < elements ; i++)
      {
          temp [i+1] = arr[i];
      }

      arr = temp;

      Back++;
      elements++;
}

template <class T>
T ArrayList<T>::back()
{
    assert(! elements == 0);
    return arr[Back];
}

template <class T>
T ArrayList<T>::front()
{
    assert(! elements == 0);
    return arr[0];
}

template <class T>
void ArrayList<T>::pop_back()
{
    assert(! elements == 0);
    Back--;
    elements--;
}

template <class T>
void ArrayList<T>::pop_front()
{
    assert(! elements == 0);

    T* temp = new T [capacity];

    for(int i = 0 ; i < capacity - 1 ; i++)
    {
        temp [i] = arr[i+1];
    }

    arr = temp;
    Back--;
    elements--;
}


template <class T>
void ArrayList<T>::clear()
{
    elements = 0;
    capacity = 10;
    Back = -1;
    delete [] arr;
    arr = new T[capacity];

}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete [] arr;
}
