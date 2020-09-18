#include <stdio.h>
#include <stdlib.h>
#include "redblacktree.h"

RedBlackTree insert(RedBlackTree rbt, int key)
{
    if (rbt == NULL)
    {
        rbt = malloc(sizeof(struct RedBlackTreeNode));
        rbt->val = key;
        rbt->color = 0;
        rbt->left = rbt->right = NULL;
        rbt->parent = NULL;
        return rbt;
    }
    if (key < rbt->val)
        rbt->left = insert(rbt->left, key);
    else if (key > rbt->val) // ignore duplicates
        rbt->right = insert(rbt->right, key);
    
}

RedBlackTree remove(RedBlackTree rbt, int key)
{

}

RedBlackTree find(RedBlackTree rbt, int key)
{
    if (rbt == NULL)
        return NULL;
    if (key < rbt->val)
        return find(rbt->left, key);
    else if (key > rbt->val)
        return find(rbt->right, key);
    else
        return rbt;
}
