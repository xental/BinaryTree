#pragma once

#include "Node.h"


template <class T>
class BinaryTree{
protected:
    Node *root;
    virtual Node* createNode(const T &key) = 0;
    virtual void deleteNode(Node *&node) = 0;

public:
    BinaryTree(){root = nullptr};
    virtual void insertRecord(T &key) = 0;
    virtual void getRecord(T &key) = 0;
};
