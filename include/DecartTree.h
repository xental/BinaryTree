//
// Created by stasm2011 on 05.11.18.
//

#pragma once

#include "Node.h"

template <class T>
class DecartTree {
private:
	Node<T>* root;
	void merge(Node<T> *&node, Node<T>* left, Node<T>* right);
	void split(Node<T>* node, T key, Node<T> *&left, Node<T> *&right);
	void insert(Node<T> *&node, Node<T>* n);
	void deleteRecord(Node<T> *&node, T key);
public:
	DecartTree() : root(nullptr) {};
	void insert(T key, int priority);
	void insert(T key);
	void deleteRecord(T key);
	void print(Node<T>* node);
	void print();
	Node<T>* find(T key);
};
