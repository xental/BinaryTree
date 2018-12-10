#include "SplayTree.h"

template <class T>

Node<T>*::RR_Rotate(splay* k2)
{
	splay* k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;
	return k1;
}

Node<T>*::LL_Rotate(splay* k2)
{
	splay* k1 = k2->rchild;
	k2->rchild = k1->lchild;
	k1->lchild = k2;
	return k1;
}