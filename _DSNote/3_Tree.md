# Trees

## Binary Trees

Every tree can be represented in the form of child/next sibling, which means every tree can be converted to a binary tree if you like.

### Applications

* Expression Trees

## Tree Traversal

The main problem is how to **remember** the other siblings when we visit one child.

### With a Stack

1. A POJ Problem

> Recover a binary tree from inorder/preorder/postorder traversal.

* Inorder/preorder/postorder **share** the stack operation sequence.

* *in* + *pre* implies *post*, *in* + *post* implies *pre*, while *pre* + *post* fails to fix *in*. Proof: *rLR*, *LRr* implies *L~R*, which means we can't tell *L* from *R* given preorder and postorder traversal results.

1. Pop Sequence

> Given a pop sequence, recover a tree.

* The number of pop sequences of length n is **C(n)**, the Catalan number.

C<sub>n</sub> = &Sigma; C<sub>i</sub> C<sub>n - i - 1</sub>

<img src="https://latex.codecogs.com/svg.latex?\frac{1}{n&plus;1}C(2n,&space;n)" title="\frac{1}{n+1}C(2n, n)" />

<img src="https://latex.codecogs.com/svg.latex?C(n)&space;=&space;\sum&space;C(i)C(n&space;-&space;i&space;-&space;1)" title="C(n) = \sum C(i)C(n - i - 1)" />

### With a Queue

Level Order Traversal, or BFS.