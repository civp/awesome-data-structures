#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#define nullptr ((void*)0)

struct Node;
typedef struct Node *ptrToNode;
typedef struct DoublyLinkedList *dList;
typedef ptrToNode pos;
typedef int bool;
typedef int dataType; // Integer implementation

// Assume arguments in uppercase
dList createDlist();
dList makeEmpty(dList L);
bool isEmpty(dList L);
pos find(dataType X, dList L);
void delete(dataType X, dList L);
void insert(dataType X, dList L, pos P);
void append(dataType X, dList L);
void swap(dList L, pos P, pos Q);
void traverse(dList L, void (*func)(dataType));
void deleteDlist(dList L);
pos first(dList L);
pos last(dList L);
pos advance(pos P); // What's this?
dataType retrieve(pos P);
int compare(dataType X, dataType Y);

#endif