/*
 * Naive Binary Search Tree
 * Traversal without recursion
 */
#ifndef BST_H
#define BST_H

typedef int Type;
typedef void (*Operation)(BST node);
enum Order {IN, PRE, POST, LEVEL};

typedef struct BSTNode *BST;
struct BSTNode
{
	Type key;
	BST left;
	BST right;
};

// public
void addKey(const Type k, BST root);
void deleteKey(const Type k, BST root);
BST findKey(const Type k, const BST root);
void traverse(const BST root, const Order ord, const Operation op);

// private
BST inorderTraverse(const BST root, const Operation op);
BST preorderTraverse(const BST root, const Operation op);
BST postorderTraverse(const BST root, const Operation op);
BST levelorderTraverse(const BST root, const Operation op);

#endif