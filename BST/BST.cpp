#include "BST.h"
#include <assert.h>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node()
{
    data = left = right = NULL;
}

template <class T>
Node<T>::Node(T value)
{
    data = value;
    left = right = NULL;
}

template <class T>
BST<T>::BST(void)
{
    root = NULL;
}

template <class T>
bool BST<T>::contain(T value)
{
    return (findNode(value) != NULL);
}

template <class T>
void BST<T>::insert(T value)
{
    if (contain(value))
        return;

    if (root == NULL)
        root = new Node<T>(value);
    else
    {
        Node<T> *temp = root;

        while (true)
        {
            if (value < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node<T>(value);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node<T>(value);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

template <class T>
void BST<T>::traverse(Order order)
{
    if (order == InOrder)
        inOrder(root);
    else if (order == PreOrder)
        preOrder(root);
    else if (order == PostOrder)
        postOrder(root);
    else
        levelOrder(root);
}

// left, root, right
template <class T>
void BST<T>::inOrder(Node<T> *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

// root, left, right
template <class T>
void BST<T>::preOrder(Node<T> *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// left, right, root
template <class T>
void BST<T>::postOrder(Node<T> *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

// level1, level2, etc.
template <class T>
void BST<T>::levelOrder(Node<T> *node)
{
    if (node == NULL)
        return;

    queue<Node<T> *> buffer;
    buffer.push(node);

    while (!buffer.empty())
    {
        Node<T> *temp = buffer.front();

        cout << temp->data << " ";

        buffer.pop();

        if (temp->left != NULL)
            buffer.push(temp->left);

        if (temp->right != NULL)
            buffer.push(temp->right);
    }
}

template <class T>
Node<T> *BST<T>::findNode(T value)
{
    Node<T> *temp = root;

    while (temp != NULL)
    {
        if (temp->data == value)
            return temp;
        else if (temp->data < value)
            temp = temp->right;
        else
            temp = temp->left;
    }

    return temp;
}

template <class T>
Node<T> *BST<T>::findParent(T value)
{
    if (root->data == value)
        return NULL;

    Node<T> *temp = root;
    Node<T> *parent;

    while (true)
    {
        if (value == temp->data)
        {
            return parent;
        }
        else if (value < temp->data)
        {
            parent = temp;
            temp = temp->left;
        }
        else
        {
            parent = temp;
            temp = temp->right;
        }
    }
}

template <class T>
Node<T> *BST<T>::findMin(Node<T> *node)
{
    while (node->left != NULL)
        node = node->left;

    return node; // return the minimum node
}

template <class T>
int BST<T>::getLevel(int value)
{
    Node<T> *temp = root;

    int level = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
            return level;
        else if (value > temp->data)
        {
            temp = temp->right;
            level++;
        }

        else
        {
            temp = temp->left;
            level++;
        }
    }

    return -1;
}

template <class T>
int BST<T>::getHeight(Node<T>* node)
{

    if ( node == NULL )
        return -1;
    else
    {
        int lHeight = getHeight(node->left);

        int rHeight = getHeight(node->right);

        return max(lHeight + 1 , rHeight + 1);
    }

}

template <class T>
void BST<T>::remove(T value)
{
    assert(contain(value));

    Node<T> *node = findNode(value);

    if (node->left == NULL && node->right == NULL) // leaf node
    {
        if (node == root)
        {
            root = NULL;
        }
        else
        {
            Node<T> *parent = findParent(value);
            if (value < parent->data)
                parent->left = NULL;
            else
                parent->right = NULL;
        }

        delete node;
    }
    else if (node->left == NULL && node->right != NULL) // has 1 right child
    {
        if (node == root)
        {
            root = node->right;
        }
        else
        {
            Node<T> *parent = findParent(value);

            if (value < parent->data)
                parent->left = node->right;
            else
                parent->right = node->right;
        }

        delete node;
    }
    else if (node->left != NULL && node->right == NULL) // has 1 left child
    {
        if (node == root)
        {
            root = node->left;
        }
        else
        {
            Node<T> *parent = findParent(value);

            if (value < parent->data)
                parent->left = node->left;
            else
                parent->right = node->left;
        }

        delete node;
    }
    else // has 2 childern
    {
        // Find the smallest value in the right subtree
        Node<T> *minNode = findMin(node->right);

        Node<T> *parent = findParent(minNode->data);

        node->data = minNode->data;

        if (parent == node) // it has no child
            parent->right = minNode->right;
        else // it has  right child
            parent->left = minNode->right;

        delete minNode;
    }
}

template <class T>
void BST<T>::deleteBST(Node<T> *node)
{
    if (node != NULL)
    {
        deleteBST(node->left);
        deleteBST(node->right);
        delete node;
    }
}

template <class T>
BST<T>::~BST()
{
    deleteBST(root);
}