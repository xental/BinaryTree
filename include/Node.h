#include <string>

template <class T>
struct Node {
    T key;
    Node* left_node = nullptr;
    Node* right_node = nullptr;
    int height;

    bool operator==(Node<T> &node) const;
    bool operator>(Node<T> &node) const;
    bool operator<(Node<T> &node) const;
};