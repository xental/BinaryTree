//
// Created by skulish on 28.10.18.
//

#include "../include/Node.h"

template <class T>
bool Node<T>::operator>(Node<T> &node) const {
    return key>node.key;
}

template <class T>
bool Node<T>::operator==(Node<T> &node) const {
    return key==node.key;
}

template <class T>
bool Node<T>::operator<(Node<T> &node) const {
    return key<node.key;
}