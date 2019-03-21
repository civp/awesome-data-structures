#include "avltree.hpp"

int height(AvlTree t)
{
	if (t == NULL)
		return -1;
	else
		return t->height;
}

void insert(AVLTree t, int val)
{
	if (t == NULL)
	{
		t = new AvlTreeNode;
		t->key = val;
		t->left = t->right = NULL;
	}
	else if (val < t->key)
	{
		t->left = insert(t, val);
		if (height(t->left) - height(t->right) == 2)
		{
			if (val < t->left->key)
				t = singleRotateWithLeft(t);
			else
				t = doubleRotateWithLeft(t);
		}
	}
}