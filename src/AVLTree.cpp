//
// Created by skulish on 28.10.18.
//

#include "../include/AVLTree.h"
#include <iostream>

template <class T>
int AVLTree<T>::height(Node<T> *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

template <class T>
int AVLTree<T>::max(int a, int b) {
    return (a > b)? a : b;
}


template <class T>
struct Node<T>* AVLTree<T>::newNode(T &key) {
    struct Node<T>* node = new Node<T>();
    node->key   = key;
    node->left_node   = nullptr;
    node->right_node  = nullptr;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}


template <class T>
struct Node<T>* AVLTree<T>::rightRotate(Node<T> *y) {
    struct Node<T> *x = y->left_node;
    struct Node<T> *T2 = x->right_node;

    // Perform rotation
    x->right_node = y;
    y->left_node = T2;

    // Update heights
    y->height = max(height(y->left_node), height(y->right_node))+1;
    x->height = max(height(x->left_node), height(x->right_node))+1;

    // Return new root
    return x;
}


template <class T>
struct Node<T>* AVLTree<T>::leftRotate(Node<T> *x) {
    struct Node<T> *y = x->right_node;
    struct Node<T> *T2 = y->left_node;

    // Perform rotation
    y->left_node = x;
    x->right_node = T2;

    //  Update heights
    x->height = max(height(x->left_node), height(x->right_node))+1;
    y->height = max(height(y->left_node), height(y->right_node))+1;

    // Return new root
    return y;
}


template <class T>
int AVLTree<T>::getBalance(Node<T> *N) {
    if (N == nullptr)
        return 0;
    return height(N->left_node) - height(N->right_node);
}


template <class T>
struct Node<T>* AVLTree<T>::find(Node<T> *node, T key) {
    if (node == nullptr) return nullptr;

    if (node->key == key) return node;

    if (node->key > key) return find(node->left_node, key);
    else return find(node->right_node, key);
}


template <class T>
struct Node<T>* AVLTree<T>::insert(Node<T> *node, T key) {
    /* 1.  Perform the normal BST rotation */
    if (node == nullptr)
        return(newNode(key));

    if (key < node->key)
        node->left_node  = insert(node->left_node, key);
    else if (key > node->key)
        node->right_node = insert(node->right_node, key);
    else // Equal keys not allowed
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left_node),
                           height(node->right_node));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left_node->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right_node->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left_node->key)
    {
        node->left_node =  leftRotate(node->left_node);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right_node->key)
    {
        node->right_node = rightRotate(node->right_node);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}


template <class T>
struct Node<T>* AVLTree<T>::minValueNode(Node<T> *node) {
    struct Node<T>* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left_node != nullptr)
        current = current->left_node;

    return current;
}


template <class T>
struct Node<T>* AVLTree<T>::deleteNode(Node<T> *root, T key) {
    if (root == nullptr)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( key < root->key )
        root->left_node = deleteNode(root->left_node, key);

        // If the key to be deleted is greater than the
        // root's key, then it lies in right subtree
    else if( key > root->key )
        root->right_node = deleteNode(root->right_node, key);

        // if key is same as root's key, then This is
        // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left_node == nullptr) || (root->right_node == nullptr) )
        {
            struct Node<T> *temp = root->left_node ? root->left_node :
                                   root->right_node;

            // No child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else // One child case
                *root = *temp; // Copy the contents of
            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node<T>* temp = minValueNode(root->right_node);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right_node = deleteNode(root->right_node, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left_node),
                           height(root->right_node));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left_node) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left_node) < 0)
    {
        root->left_node =  leftRotate(root->left_node);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right_node) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right_node) > 0)
    {
        root->right_node = rightRotate(root->right_node);
        return leftRotate(root);
    }

    return root;
}


template <class T>
void AVLTree<T>::insertRecord(T &key) {
    root = insert(root, key);
}

template <class T>
void AVLTree<T>::deleteRecord(T &key) {
    root = deleteNode(root, key);
}

template <class T>
Node<T>* AVLTree<T>::findRecord(T &key) {
    return find(root, key);
}

template <class T>
int AVLTree<T>::getHeight() {
    return root->height;
}



