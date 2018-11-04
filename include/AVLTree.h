//
// Created by skulish on 28.10.18.
//

#include "BinaryTree.h"
#include <string>

template <class T>
class AVLTree{
private:
    Node<T>* root;
    Node<T>* createNode(const T &key);
    void deleteNode(Node<T> *&node);
    Node<T>* getMaxNode(Node<T> *&node, T &key);
    void insertRecord(Node<T> *&node, T &key);
    Node<T>* getRecord(Node<T> *&node, T &key);
    int height(Node<T> *&node);
    int max(int left, int right);
public:
    AVLTree(): root(nullptr){};
    // ~AVSTree() {};
    void insertRecord(T &key);
    void deleteRecord(T &key);
    Node<T>* getRecord(T &key);
};