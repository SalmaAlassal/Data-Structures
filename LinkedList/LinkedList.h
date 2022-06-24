#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value);
};

template <class T>
struct operations
{
    string type;
    T value;
    int pos;
};

template <class T>
class LinkedList
{

private:
    int elements;

    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList(void);

    int size();
    bool empty();

    T front();
    T back();
    T at(int pos);

    void insert(int pos, T value);
    void push_front(T value);
    void push_back(T value);

    void pop_front();
    void pop_back();
    void deleteAt(int pos);

    void undo();

    ~LinkedList();
};