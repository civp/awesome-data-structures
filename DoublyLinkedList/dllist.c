#include "dllist.h"
#include <stdio.h>
#include <stdlib.h>

// Integer implementation
int compare(dataType X, dataType Y)
{
	return X - Y;
}

struct Node
{
	dataType data;
	pos prev;
	pos next;
};

struct DoublyLinkedList
{
	pos firstNode;
	pos lastNode;
};


// Time Complexity: O(1)
dList createDlist()
{
	dList l = calloc(1, sizeof(struct DoublyLinkedList));
	l->firstNode = nullptr;
	l->lastNode = nullptr;

	return l;
}

// Time Complexity: O(N)
dList makeEmpty(dList L)
{
	if (L == nullptr)
	{
		printf("Error: makeEmpty(Invalid list)\n");
		return nullptr;
	}

	for (pos p = L->firstNode; p != nullptr;)
	{
		pos tmp = p->next;
		free(p);
		p = tmp;
	}

	L->firstNode = nullptr;
	L->lastNode = nullptr;

	return L;
}

// Time Complexity: O(1)
bool isEmpty(dList L)
{
	return L->firstNode == nullptr;
}

// Time Complexity: O(N)
// Find the first occurence of X
pos find(dataType X, dList L)
{
	if (L == nullptr)
	{
		printf("Error: find(Invalid list)\n");
		return nullptr;
	}

	pos p;
	for (p = L->firstNode; p != nullptr && compare(p->data, X); p = p->next);

	return p;
}

// Time Complexity: O(N)
// Delete the first occurence of X
void delete(dataType X, dList L)
{
	pos p = find(X, L);

	if (p == nullptr)
	{
		printf("Error: delete(Not found)\n");
		return;
	}

	if (p == L->firstNode)
		L->firstNode = p->next;
	else
		p->prev->next = p->next;
	if (p == L->lastNode)
		L->lastNode = p->prev;
	else
		p->next->prev = p->prev;
	
	free(p);
}

// Insert X before P of L
// Time Complexity: O(N)
void insert(dataType X, dList L, pos P)
{
	if (L == nullptr)
	{
		printf("Error: insert(Invalid list)\n");
		return;
	}

	pos newNode = calloc(1, sizeof(struct Node));
	newNode->data = X;
	pos prevNode;
	if (P == nullptr)
		prevNode = L->lastNode;
	else
		prevNode = P->prev;

	newNode->prev = prevNode;
	if (prevNode != nullptr)
		prevNode->next = newNode; // Doubly Linked
	newNode->next = P;

	// Exception pocess
	// Reason: update struct DoublyLinkedList
	if (P == L->firstNode)
		L->firstNode = newNode;
	if (P == nullptr)
		L->lastNode = newNode;
}

// Time Complexity: O(N)
// Could have been merged into insert with overloading
void append(dataType X, dList L)
{
	insert(X, L, nullptr);
}

// Time Complexity: O(N)
// Traverse and process data
void traverse(dList L, void (*func)(dataType))
{
	if (L == nullptr)
	{
		printf("Error: traverse(Invalid list)\n");
		return;
	}
	for (pos p = L->firstNode; p != nullptr; p = p->next)
		func(p->data);
}

// Time Complexity: O(N)
void deleteDlist(dList L)
{
	makeEmpty(L);
	free(L);
}

// Interface
pos first(dList L)
{
	return L->firstNode;
}

// Interface
pos last(dList L)
{
	return L->lastNode;
}

// Interface
dataType retrieve(pos P)
{
	return P->data;
}