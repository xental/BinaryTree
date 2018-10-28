#pragma once

#include "Node.h"


template <class T>
class BinaryTree{
protected:
    Node<T> *root;
    virtual Node<T>* createNode(const T &key) = 0;
    virtual void deleteNode(Node<T> *&node) = 0;

public:
    BinaryTree(){root = nullptr;};
    virtual void insertRecord(T &key) = 0;
    virtual void getRecord(T &key) = 0;
};
