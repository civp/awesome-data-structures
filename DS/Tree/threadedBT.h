/*
 * In computing, a threaded binary tree is a binary tree variant
 * that facilitates traversal in a particular order
 * (often the same order already defined for the tree)
 * -Wikipedia
 *
 * Advantages:
 * Space complexity is greatly reduced
 * Enable traversals starting from any node
 *
 * This implementation assumes inorder traversal and double threaded
 */
#ifndef THREADED_BST_H
#define THREADED_BST_H
typedef struct TBSTNode *ThreadedBST;
struct TBSTNode
{
	ElementType key;
	ThreadedBST left;
	ThreadedBST right;
	bool rightThread;
};

typedef int ElementType;
typedef void (*Operation)(ElementType key);

void addKey(ElementType key, ThreadedBST root);
void deleteKey(ElementType key, ThreadedBST root);
ThreadedBST findKey(ElementType key, ThreadedBST root);
void inorderTraverse(Operation visit, ThreadedBST root);
Operation print;