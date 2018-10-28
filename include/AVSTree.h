//
// Created by skulish on 28.10.18.
//

#include "BinaryTree.h"

template <class T>
class AVSTree: public BinaryTree<T>{
private:
    Node<T>* createNode(T &key);
    void deleteNode(Node<T>* node);
    void insertRecord(Node<T> *&node, int &key);
    Node<T>* getRecord(Node<T> *&node, int &key);
public:
    AVSTree(){};
    // ~AVSTree() {};
    void insertRecord(T &key);
    void deleteRecord(T &key);
    Node<T>* getRecord(T &key);
};