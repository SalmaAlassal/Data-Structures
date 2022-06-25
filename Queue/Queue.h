template <class T>
class Queue
{
private:
    T *arr;
    int capacity;
    int elements;
    int Front;
    int Back;
    
    void expand();

public:
    Queue();
    Queue(int capacity);
    bool empty();
    int size();
    bool full();
    T front();
    T back();
    void push(T newValue);
    void pop();
    ~Queue();
};