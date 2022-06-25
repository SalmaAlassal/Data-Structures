template <class T>
class Vector
{
private:
    T *arr;
    int elements;
    int Capacity;

    void expand();

public:
    Vector();
    Vector(int capacity);

    int size();
    int capacity();
    bool empty();

    void insert(int position, T value);
    void push_back(T value);

    void pop_back();

    T back();
    T front();

    void clear();

    ~Vector();
};