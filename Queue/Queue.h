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
        T back();
        void push(T);
        void pop();
        bool full();
        void expand();
        ~Queue();


};
