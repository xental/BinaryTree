#ifndef SPLAY_TREE
#define SPLAY_TREE

#include "BinaryTree.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

template <class T>
struct splay
{
    int key;
    splay* lchild;
    splay* rchild;
};


template <class T>
class SplayTree
{
public:
	SplayTree() {}
	splay<T>* RR_Rotate(splay<T>* k2)
	{
		splay<T>* k1 = k2->lchild;
		k2->lchild = k1->rchild;
		k1->rchild = k2;
		return k1;
	}

	splay<T>* LL_Rotate(splay<T>* k2)
	{
		splay<T>* k1 = k2->rchild;
		k2->rchild = k1->lchild;
		k1->lchild = k2;
		return k1;
	}

	splay<T>* Splay(T key, splay<T>*& root)
	{
		if (!root)
			return NULL;
		splay<T> header;
		header.lchild = header.rchild = NULL;
		splay<T>* LeftTreeMax = &header;
		splay<T>* RightTreeMin = &header;
		while (1)
		{
			if (key < root->key)
			{
				if (!root->lchild)
					break;
				if (key < root->lchild->key)
				{
					root = RR_Rotate(root);	
					if (!root->lchild)
						break;
				}
				
				RightTreeMin->lchild = root;
				RightTreeMin = RightTreeMin->lchild;
				root = root->lchild;
				RightTreeMin->lchild = NULL;
			}
			else if (key > root->key)
			{
				if (!root->rchild)
					break;
				if (key > root->rchild->key)
				{
					root = LL_Rotate(root);
					if (!root->rchild)
						break;
				}
				
				LeftTreeMax->rchild = root;
				LeftTreeMax = LeftTreeMax->rchild;
				root = root->rchild;
				LeftTreeMax->rchild = NULL;
			}
			else
				break;
		}
		
		LeftTreeMax->rchild = root->lchild;
		RightTreeMin->lchild = root->rchild;
		root->lchild = header.rchild;
		root->rchild = header.lchild;
		return root;
	}

	splay<T>* New_Node(T key)
	{
		splay<T>* p_node = new splay<T>;
		if (!p_node)
		{
			fprintf(stderr, "Out of memory!\n");
			exit(1);
		}
		p_node->key = key;
		p_node->lchild = p_node->rchild = NULL;
		return p_node;
	}

	void<T>* Insert(T key, splay<T>*& root)
	{
		static splay<T>* p_node = NULL;
		if (!p_node)
			p_node = New_Node(key);
		else
			p_node->key = key;
		if (!root)
		{
			root = p_node;
			p_node = NULL;
			return root;
		}
		root = Splay(key, root);		
		if (key < root->key)
		{
			p_node->lchild = root->lchild;
			p_node->rchild = root;
			root->lchild = NULL;
			root = p_node;
		}
		else if (key > root->key)
		{
			p_node->rchild = root->rchild;
			p_node->lchild = root;
			root->rchild = NULL;
			root = p_node;
		}
		else
			return root;
		p_node = NULL;
		return;
	}

	void<T>* Delete(T key, splay<T>*& root)
	{
		splay<T>* temp;
		if (!root)
			return NULL;
		root = Splay(key, root);
		if (key != root->key)
			return root;
		else
		{
			if (!root->lchild)
			{
				temp = root;
				root = root->rchild;
			}
			else
			{
				temp = root;
				root = Splay(key, root->lchild);
				root->rchild = temp->rchild;
			}
			free(temp);
			return;
		}
	}

	splay<T>* Search(T key, splay<T>*& root)
	{
		return Splay(key, root);
	}

	void InOrder(splay<T>* root)
	{
		if (root) {
                cout << root->key << " ";
                if (!root->lchild) cout << -1 << " ";
                else cout << root->lchild->key << " ";
                if (!root->rchild) cout << -1 << " ";
                else cout << root->rchild->key << " ";
                cout << endl;
                InOrder(root->lchild);
                InOrder(root->rchild);
            } 
	}
};



#endif // !SPLAY_TREE
