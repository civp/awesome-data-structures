/*
 * Library of Graph Algorithms
 * Assume static graph implementation
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct AdjacentListNode *AdjacentList;
typedef struct AdjacentListNode *NodePtr;
struct AdjacentListNode
{
	int val; // Indexed from 0
	struct AdjacentListNode *next;
};

// Graph as adjacent list, AOV
typedef struct GraphInfo
{
	int v; // Vertices number, fixed
	int e; // Edges number
	AdjacentList *vertex; // Adjacent list
} *Graph;

/*
 * createGraph
 * :param int size: Number of vertices
 * :param const int *vals: Pointer to the array of vertex values
 * :return Graph
 */
Graph createGraph(int size, const int *vals);

/*
 * deleteGraph
 * :param Graph g
 */
void deleteGraph(Graph g);

/*
 * isVertex
 * :param Graph g
 * :param int val: vertex value
 * :return int: 1/0
 */
int isVertex(Graph g, int val);

/*
 * addEdge
 * :param Graph g
 * :param int src: source
 * :param int dst: destination
 */
void addEdge(Graph g, int src, int dst);

/* Shortest Path */
#define DIJKSTRA 0
#define BELLMAN_FORD 1
/*
 * singleSourceShortestPath
 * :param Graph g
 * :param int s: source
 * :param int p: predecessor
 * :param method: methods defined
 */
void singleSourceShortestPath(Graph g, int s, int *p, int method);
void Dijkstra(Graph g, int s, int *p);

/* Network Flow */

#endif