//
// Created by skulish on 28.10.18.
//

#include "../include/AVLTree.h"
template <class T>
Node<T>* AVLTree<T>::getRecord(T &key) {
    if (root->key==key) return root;

    return (root->key<key)?getRecord(root->right_node, key):getRecord(root->left_node, key);
}

template <class T>
Node<T>* AVLTree<T>::getRecord(Node<T> *&node, T &key) {
    if (node->key==key) return node;

    return (node->key<key)?getRecord(node->right_node, key):getRecord(node->left_node, key);
}

template <class T>
void AVLTree<T>::insertRecord(T &key) {
    if (root == nullptr){
        root= createNode(key);
        return;
    }
    if (root->key < key){
        insertRecord(root->right_node, key);
    } else {
        insertRecord(root->left_node, key);
    }
}

template <class T>
Node<T>* AVLTree<T>::createNode(const T &key) {
    Node<T>* node = new Node<T>();
    node->key         = key;
    node->left_node   = nullptr;
    node->right_node  = nullptr;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

template <class T>
void AVLTree<T>::deleteNode(Node<T> *&node) {}

template <class T>
void AVLTree<T>::insertRecord(Node<T> *&node, T &key) {
    if (node == nullptr){
        node = createNode(key);
        return;
    }

    if (node->key < key){
        insertRecord(node->right_node, key);
    } else {
        insertRecord(node->left_node, key);
    }
}

template <class T>
Node<T>* AVLTree<T>::getMaxNode(Node<T> *&node, T &key) {
    if (node->right_node == nullptr){
        Node<T>* tmp = node;
        if (node->left_node != nullptr){
            node = node->left_node;
        } else {
            node = nullptr;
        }
        return tmp;
    } else return getMaxNode(node->right_node, key);
}

template <class T>
void AVLTree<T>::deleteRecord(T &key) {}



template class AVLTree<float>;
template class AVLTree<double>;
template class AVLTree<std::string>;
template class AVLTree<int>;






