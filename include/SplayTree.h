#ifndef SPLAY_TREE
#define SPLAY_TREE
#include <iostream>
#include <cstdio>
#include <cstdlib>

struct splay
{
	int key;
	splay* lchild;
	splay* rchild;
};

class SplayTree
{
public:
	SplayTree() {}
	splay* RR_Rotate(splay* k2);
	splay* LL_Rotate(splay* k2);
	splay* Splay(int key, splay* root);
	splay* New_Node(int key);
	splay* Insert(int key, splay* root);
	splay* Delete(int key, splay* root);
	splay* Search(int key, splay* root);
	void InOrder(splay* root);
};



#endif // !SPLAY_TREE
