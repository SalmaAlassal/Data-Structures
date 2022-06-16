#include "Stack.h"
#include <assert.h>
#define NULL 0

template <class T>
Node<T>::Node(T value)
{
    data = value;
    next = NULL;
}

template <class T>
Stack<T>::Stack(void)
{
    head = NULL;
    elements = 0;
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

    return head->data;
}

template <class T>
void Stack<T>::push(T value)
{
    Node<T> *node = new Node<T>(value); // Allocate memory for a new node

    if (head == NULL)
    {
        head = node;
    }
    else
    {
        node->next = head; // Point to previous node
        head = node;       // Make the new node the top element of the stack
    }

    elements++;
}

template <class T>
void Stack<T>::pop()
{
    assert(!empty());

    Node<T> *temp = head;

    head = head->next; // Make the previous node the top element of the stack

    delete temp; // Delete the top node

    elements--;
}

template <class T>
void Stack<T>::clear()
{
    Node<T> *temp;

    // Deleting all nodes one by one
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    elements = 0;
}

template <class T>
Stack<T>::~Stack()
{
    clear();
}