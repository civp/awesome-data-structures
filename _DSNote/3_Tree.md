# Trees

## Some Maths

<img src="https://latex.codecogs.com/svg.latex?e=\sum&space;i&space;n_i=\sum&space;n_i&space;-&space;1" title="e=\sum i n_i=\sum n_i - 1" />

Specially, we have <img src="https://latex.codecogs.com/svg.latex?n_0&space;=&space;n_2&space;&plus;&space;1" title="n_0 = n_2 + 1" /> for binary tree.

Where *e* denotes number of edges, *n<sub>i</sub>* denotes the number of nodes with *i* children.

## Binary Trees

Every tree can be represented in the form of child/next sibling, which means every tree can be converted to a binary tree if you like.

### Applications

* Expression Trees

## Tree Traversal

The main problem is how to **remember** the other siblings when we visit one child.

### With a Stack

1. A POJ Problem

> Recover a binary tree from inorder/preorder/postorder traversal.

* *in* + *pre* implies *post*, *in* + *post* implies *pre*, while *pre* + *post* fails to fix *in*. Proof: *rLR*, *LRr* implies *L~R*, which means we can't tell *L* from *R* given preorder and postorder traversal results.

1. Push/Pop Sequence

> Given a push/pop sequence, recover a tree.

* Solution: push: go left, pop: go right

* Inorder/preorder/postorder **share** the stack operation sequence.

* The number of pop sequences of length n is **C(n)**, the Catalan number.

Recursive Definition: <img src="https://latex.codecogs.com/svg.latex?C(n)=\sum_{i=0}^{n-1}C(i)C(n-i-1)" title="C(n)=\sum_{i=0}^{n-1}C(i)C(n-i-1)" />

Analytical Expression: <img src="https://latex.codecogs.com/svg.latex?C(n)=\frac{1}{n&plus;1}C(2n,&space;n)" title="\frac{1}{n+1}C(2n, n)" />

* Push sequence of nodes = preorder traversal
  Pop sequence of nodes = inorder traversal

### With a Queue

Level Order Traversal, or BFS

### Thread Trees

Make full use of pointers

## Dynamic Search

* AVL Tree/Red Black Tree/B+ Tree

* Hash

### Binary Search Tree

Trivial