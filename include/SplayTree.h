#ifndef SPLAY_TREE
#define SPLAY_TREE

#include "BinaryTree.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

template <class T>
struct splay
{
	T key;
	splay* lchild;
	splay* rchild;

	bool operator==(Node<T> &node) const {
		return key == node.key;
	}

	bool operator>(Node<T> &node) const {
		return key>node.key;
	}
	bool operator<(Node<T> &node) const {
		return key<node.key;
	}
};


template <class T>
class SplayTree
{
public:
	SplayTree() {}
	splay<T>* RR_Rotate(splay<T>* k_rr);
	splay<T>* LL_Rotate(splay<T>* k_ll);
	splay<T>* Splay(T key, splay<T>* root);
	splay<T>* New_Node(T key);
	splay<T>* Insert(T key, splay<T>* root);
	splay<T>* Delete(T key, splay<T>* root);
	splay<T>* Search(T key, splay<T>* root);
	void InOrder(splay<T>* root);
};



#endif // !SPLAY_TREE
