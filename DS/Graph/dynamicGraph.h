// Extendable graph
#ifndef DYNAMIC_GRAPH_H
#define DYNAMIC_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct AdjacentListNode *AdjacentList;
typedef struct AdjacentListNode *AdjacentListNodePtr;
typedef struct NeighborNode *NodePtr;

struct NeighborNode
{
	int val; // Integer
	NodePtr next;
};

struct AdjacentListNode
{
	int val; // Integer
	int neighbors; // Neighbors
	AdjacentListNodePtr nextVertex;
	NodePtr firstNeighbor;
};

// Graph as adjacent list, AOV
typedef struct GraphInfo
{
	int v; // Vertices number
	int e; // Edges number
	AdjacentList firstVertex; // Adjacent list
} *Graph;

#endif