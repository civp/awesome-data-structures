// AVL Tree
#ifndef AVL_TREE
#define AVL_TREE

struct AvlTreeNode;
typedef struct AvlTreeNode* AvlTree;
typedef struct AvlTreeNode* Position;

AvlTree makeEmpty(AvlTree t);
Position find(int val, AvlTree t);
Position findMin(AvlTree t);
Position findMax(AvlTree t);
AvlTree insert(AvlTree t, int val);
AvlTree remove(AvlTree t, int val);
int retrieve(Position p);

struct AvlTreeNode
{
	int key;
	AvlTree left;
	AvlTree right;
	int height;
};

#endif