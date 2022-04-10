#include "LinkedList.h"
#define NULL 0
#include <assert.h>
#include<stack>

template <class T>
Node<T>::Node(void)
{
    data = NULL;
    next = NULL;
}


template <class T>
Node<T>::Node(T value)
{
    data = value;
    next = NULL;
}


template <class T>
LinkedList<T>::LinkedList(void)
{
    head = tail = NULL;
    elements = 0;
}


template <class T>
LinkedList<T>::LinkedList(int length)
{
    head = tail = NULL;
    elements = length;
}


template <class T>
int LinkedList<T>::size()
{
    return elements;
}


template <class T>
bool LinkedList<T>::empty()
{
    return (elements == 0);
}


template <class T>
T LinkedList<T>::front()
{
   return head->data;
}


template <class T>
T LinkedList<T>::back()
{
   return tail->data;
}


template <class T>
T LinkedList<T>::at(int pos)
{
    assert( pos >= 0 && pos < elements);

    Node<T>* temp = head;

    for(int i=0 ; i < pos ; i++)
        temp = temp->next;

    return temp->data;
}


// To store the last operations done
template <class T>
operations<T> lastOp;

template <class T>
stack <operations<T> > buffer;

template <class T>
void LinkedList<T>::insert(int pos , T value)
{
     assert( pos >= 0 && pos <= elements);

     Node<T>* temp = head;
     Node<T>* newNode = new Node<T>(value);

    if (elements == 0)
    {
        head = tail = newNode;
    }

    if(pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {

        for(int i=0 ; i < pos-1 ; i++)
           temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    elements++;

    lastOp<T>.type = "insert";
    lastOp<T>.pos = pos;
    lastOp<T>.value = value;

    buffer<T>.push(lastOp<T>);
}


template <class T>
void LinkedList<T>::push_front(T value)
{
    Node<T>* newNode = new Node<T>(value);

    newNode->next = head;

    head = newNode;

    elements++;

     lastOp<T>.type = "push_front";
     buffer<T>.push(lastOp<T>);
}


template <class T>
void LinkedList<T>::push_back(T value)
{

    Node<T>* newNode = new Node<T>(value);

     if (elements == 0)
        head = tail = newNode;
     else
     {
         tail->next = newNode;
         tail = newNode;
     }

     elements++;

     lastOp<T>.type = "push_back";
     buffer<T>.push(lastOp<T>);
}


template <class T>
void LinkedList<T>::pop_front()
{
    assert( !elements == 0);

    Node<T>* temp = head;

    head = head->next;

    lastOp<T>.value = temp->data;

    delete temp;

    elements--;

    lastOp<T>.type = "pop_front";
     buffer<T>.push(lastOp<T>);
}


template <class T>
void LinkedList<T>::pop_back()
{
    assert( !elements == 0);

    Node<T>* temp = head;

    for(int i=0 ; i < elements-2 ; i++)
        temp = temp->next;

    tail = temp;

    temp = temp->next;

    lastOp<T>.value = temp->data;

    delete temp;

    elements--;

    lastOp<T>.type = "pop_back";
    buffer<T>.push(lastOp<T>);

}


template <class T>
void LinkedList<T>::deleteAt(int pos)
{
    assert( pos >= 0 && pos < elements);

    Node<T>* temp = head;

    if(pos == 0)
    {
        head = head->next;
        lastOp<T>.value = temp->data;
        delete temp;
    }
    else
    {

        for(int i=0 ; i < pos-1 ; i++)
            temp = temp->next;

        Node<T>* deletedNode = temp->next;

        temp->next = deletedNode->next;

        lastOp<T>.value = deletedNode->data;

        delete deletedNode;

        if ( pos == elements -1)
            tail = temp;
    }

    elements--;

    lastOp<T>.type = "delete";
    lastOp<T>.pos = pos;
    buffer<T>.push(lastOp<T>);
}


template <class T>
void LinkedList<T>::undo()
{
    lastOp<T> = buffer<T>.top();

    if (lastOp<T>.type == "push_back")
        pop_back();
    else  if (lastOp<T>.type == "push_front")
        pop_front();
    else if (lastOp<T>.type == "insert")
        deleteAt(lastOp<T>.pos);
    else if (lastOp<T>.type == "pop_back")
        push_back(lastOp<T>.value);
    else  if (lastOp<T>.type == "pop_front")
        push_front(lastOp<T>.value);
    else  if (lastOp<T>.type == "delete")
        insert(lastOp<T>.pos , lastOp<T>.value);

    buffer<T>.pop();
    buffer<T>.pop();
}


template <class T>
LinkedList<T>::~LinkedList()
{
    while(elements!=0)
		deleteAt(0);
}
