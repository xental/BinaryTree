//
// Created by skulish on 28.10.18.
//
#include "Node.h"
#include <string>

template <class T>
class AVLTree{
private:
    struct Node<T>* root;
    struct Node<T>* newNode(T& key);
    int height(struct Node<T> *N);
    int max(int a, int b);
    struct Node<T> *rightRotate(struct Node<T> *y);
    struct Node<T> *leftRotate(struct Node<T> *x);
    int getBalance(struct Node<T> *N);
    struct Node<T> *find(struct Node<T>* node, T key);
    struct Node<T> *insert(struct Node<T>* node, T key);
    struct Node<T> *minValueNode(struct Node<T>* node);
    struct Node<T>* deleteNode(struct Node<T>* root, T key);
public:
    AVLTree(): root(nullptr){};
    // ~AVSTree() {};
    void insertRecord(T& key);
    void deleteRecord(T& key);
    Node<T>* findRecord(T& key);
    int getHeight();
};


template class AVLTree<double>;
template class AVLTree<std::string>;
template class AVLTree<int>;
template class AVLTree<float>;