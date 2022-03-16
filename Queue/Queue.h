template <class T>
class Queue
{
    T* arr;
    int elements;
    int capacity;
    int Front;
    int Back;

    public:
        Queue();
        Queue(int capacity);
        bool empty();
        int size();
        T front();
//        void front(T newValue);
        T back();
//        void back(T newValue);
        void push(T);
        void pop();
        bool full();
        void expand();
        ~Queue();


};

//**empty()**-Returns whether the queue is empty.
//**size()**-Returns the size of the queue.
//**front()**-Returns a reference to the first element of the queue.
//**back()**-Returns a reference to the last element of the queue.
//**push(x)**-Adds the element 'x' at the end of the queue.
//**pop()**-Deletes the first element of the queue.

//queue::swap()	Exchange the contents of two queues but the queues must be of the same type, although sizes may differ.
//queue::emplace()	Insert a new element into the queue container, the new element is added to the end of the queue.


