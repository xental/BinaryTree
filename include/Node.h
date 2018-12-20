#include <string>

template <class T>
struct Node {
    T key;
    Node<T>* left_node = nullptr;
    Node<T>* right_node = nullptr;
    int height = 0;

    bool operator==(Node<T> &node) const;
    bool operator>(Node<T> &node) const;
    bool operator<(Node<T> &node) const;
};