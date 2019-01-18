#include "graph.h"

Graph createGraph(int size, const int *vals)
{
	if (size <= 0)
		return NULL;
	Graph g = malloc(sizeof(struct GraphInfo));
	assert(g != NULL);
	g->v = size;
	g->e = 0;
	g->vertex = malloc(size * sizeof(struct AdjacentListNode));
	assert(g->vertex != NULL);
	for (int i = 0; i < size; ++i)
	{
		g->vertex[i]->val = vals[i];
		g->vertex[i]->next = NULL;
	}
	return g;
}

void deleteGraph(Graph g)
{
	for (int i = 0; i < g->v; ++i)
		free(g->vertex[i]);
	free(g);
}

int isVertex(Graph g, int )

void addEdge(Graph g, int src, int dst)
{
	assert(isVertex(g, src));
	if (isEdge(g, src, dst))
		return;
	NodePtr node = malloc(sizeof(struct AdjacentListNode));
	node->val = dst;
	node->next = NULL;
	g->vertex[src]->next = node;
}