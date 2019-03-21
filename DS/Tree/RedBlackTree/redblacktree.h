#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

typedef struct RedBlackTreeNode *RedBlackTree;
struct RedBlackTreeNode
{
    int val;
    int color; // red 0, black 1
    RedBlackTree left;
    RedBlackTree right;
    RedBlackTree parent;
};

RedBlackTree insert(RedBlackTree rbt, int key);
RedBlackTree remove(RedBlackTree rbt, int key);
RedBlackTree find(RedBlackTree rbt, int key);



#endif