template <class T>

class ArrayList
{

   private:
    int elements;
    int capacity;
    T* arr;
    int Back;

    void expand();

    public:
        ArrayList();
        ArrayList(int capacity);

        int size();
        bool empty();

        void insert(int position , T value);
        void push_back(T);
        void push_front(T);

        void pop_back();
        void pop_front();

        T back();
        T front();

        void clear();

        ~ArrayList();

};
