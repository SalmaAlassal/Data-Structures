template <class T>
class Node
{
public:
    T data;
    Node<T> *next; // A pointer to the next stack node

    Node(T value);
};

template <class T>
class Stack
{
private:
    Node<T> *head; // A pointer to the top of the stack
    int elements;

public:
    Stack(void);

    int size();
    bool empty();

    T top();

    void push(T newValue);

    void pop();
    void clear(); // Deleting all nodes of the stack one by one

    ~Stack(void); // destructor
};