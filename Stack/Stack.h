class Stack
{
    int* arr;
    int capacity;
    int elements;

public:
    Stack(void);
    Stack(int capacity);
    void push(int newValue);
    void pop ();
    int top();
    int size();
    bool empty();
    void expand();
    ~Stack(void); // destructor

};
