//
// Created by stasm2011 on 05.11.18.
//

#include "../include/DecartTree.h"
#include <iostream>

template <class T>
void DecartTree<T>::split(Node<T> *node, T key, Node<T> *&left, Node<T> *&right) {
	if (node == nullptr) {
		left = right = nullptr;
		return;
	}
	
	if (key < node->key) {
		split(node->left_node, key, left, node->left_node);
		right = node;
	}
	else {
		split(node->right_node, key, node->right_node, right);
		left = node;
	}
}

template <class T>
void DecartTree<T>::insert(Node<T> *&node, Node<T>* n) {
	if (node == nullptr) {
		node = n;
		return;
	}

	if (n->height > node->height) {
		split(node, n->key, n->left_node, n->right_node);
		node = n;
	}
	else {
		insert(n->key < node->key ? node->left_node : node->right_node, n);
	}
}

template <class T>
void DecartTree<T>::merge(Node<T> *&node, Node<T>* left, Node<T>* right) {
	if (left == nullptr || right == nullptr) {
		node = left != nullptr ? left : right;
		return;
	}

	if (left->height > right->height) {
		merge(left->right_node, left->right_node, right);
		node = left;
	}
	else {
		merge(right->left_node, left, right->left_node);
		node = right;
	}
}

template <class T>
void DecartTree<T>::deleteRecord(Node<T> *&node, T key) {
	if (node->key == key)
		merge(node, node->left_node, node->right_node);
	else
		deleteRecord(key < node->key ? node->left_node : node->right_node, key);
}

template <class T>
void DecartTree<T>::deleteRecord(T key) {
	deleteRecord(root, key);
}


template <class T>
void DecartTree<T>::insert(T key, int priority) {
	Node<T>* n = new Node<T>();
	n->key = key;
	n->height = priority;
	n->left_node = nullptr;
	n->right_node = nullptr;
	insert(root, n);
}


template <class T>
void DecartTree<T>::insert(T key) {
	insert(key, rand());
	Node<T>* n = new Node<T>();
	n->key = key;
	n->height = rand() % 500;
	n->left_node = nullptr;
	n->right_node = nullptr;
	insert(root, n);
}

template <class T>
void DecartTree<T>::print(Node<T>* node) {
	if (node == nullptr)
		return;
	std::cout << "==========" << std::endl;
	std::cout << node->key << " " << node->height << std::endl;
	if (node->left_node != nullptr)
		std::cout << "Left: " << node->left_node->key << " " << node->left_node->height << std::endl;
	if (node->right_node != nullptr)
		std::cout << "Right: " << node->right_node->key << " " << node->right_node->height << std::endl;
	if (node->left_node != nullptr)
		print(node->left_node);
	if (node->right_node != nullptr)
		print(node->right_node);
}

template <class T>
Node<T>* DecartTree<T>::find(T key) {
	Node<T>* currentNode = root;
	while (currentNode != nullptr && key != currentNode->key)
		if (key > currentNode->key) {
			currentNode = currentNode->right_node;
		}
		else {
			currentNode = currentNode->left_node;
		}
		if (currentNode == nullptr)
			return 0;
		else
			return currentNode;
}

template <class T>
void DecartTree<T>::print() {
	print(root);
}

template class DecartTree<int>;