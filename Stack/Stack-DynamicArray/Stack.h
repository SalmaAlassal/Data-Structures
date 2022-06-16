template <class T>
class Stack
{

private:
    T *arr;
    int capacity; // array size
    int elements; // Actual size

    void expand(); // Doubling the stack by twice

public:
    Stack(void);
    Stack(int capacity);

    int size();
    bool empty();

    T top();

    void push(T newValue);

    void pop();
    
    ~Stack(void); // destructor
};