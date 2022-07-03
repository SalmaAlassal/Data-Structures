template <class T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node();
    Node(T value);
};

enum Order
{
    InOrder = 0,
    PreOrder = 1,
    PostOrder = 2,
    LevelOrder = 3
};

template <class T>
class BST
{

private:
    Node<T> *root;

    void inOrder(Node<T> *node);    // left, root, right
    void preOrder(Node<T> *node);   // root, left, right
    void postOrder(Node<T> *node);  // left, right, root
    void levelOrder(Node<T> *node); // level1, level 2, etc.

public:
    BST();

    bool contain(T value);
    
    void insert(T value);

    void traverse(Order order);

    Node<T> *findNode(T value);
    Node<T> *findParent(T value);
    Node<T> *findMin(Node<T> *node);

    int getLevel(int value);
    int getHeight(Node<T> *node);

    void remove(T value);
    void deleteBST(Node<T> *node);

    ~BST();
};