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
	void insert(T key, T priority);
	void print(Node<T>* node);
	void print();
	T find(T key);
};