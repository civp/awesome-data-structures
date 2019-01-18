#include <stdio.h>
#include "BST.h"

void addKey(const Type k, BST root)
{
	if (root == NULL)
	{
		root = malloc(sizeof(struct BSTNode));
		root->key = k;
		root->left = root->right = NULL;
		return;
	}

	BST prt = findKey(k, root);
	if (prt->key == k) // Already in the BST
		return;

	BST cur = malloc(sizeof(struct BSTNode));
	cur->key = k;
	cur->left = cur->right = NULL;
	if (k < prt->key)
		prt->left = cur;
	else
		prt->right = cur;
}

void deleteKey(const Type k, BST root)
{
	BST pos = findKey(k, root);
	if (pos == NULL || pos->key != k)
	{
		printf("Deletion Failure: Key is not found!\n");
		return;
	}
	// Assume key is distributed randomly
	// Random side deletion can help maintain balance to some degree
	// But im lazy, cuz i need to write a function for the perticular Type
	sgt = pos->left; // scapegoat
	while (sgt->right)
		sgt = sgt->right;
}

/*
 * For reusability
 * found: return the node pointer
 * else: return the parent pointer
 */
BST findKey(const Type k, const BST root)
{
	BST cur = root, lst = NULL;
	while (cur)
	{
		lst = cur;
		if (k < cur->key)
			cur = cur->left;
		else if (k > cur->key)
			cur = cur->right;
		else
			break;
	}
	return cur ? cur : lst;
}
void traverse(BST root, Order ord, Operation op);


BST inorderTraverse(BST root, Operation op);
BST preorderTraverse(BST root, Operation op);
BST postorderTraverse(BST root, Operation op);
BST levelorderTraverse(BST root, Operation op);

#ifdef TEST
int main(int argc, char const *argv[])
{
	
	return 0;
}
#endif