/*
 * Practice of Floyd-Warshall Algorithm
 * Distance 0 between two distinct represents disconnection
 */
#include <iostream>

using namespace std;

class Graph
{
public:
	Graph(int n);
	~Graph();
	void readGraph();
	int floyd(int a, int b);
private:
	const int v;
	int** g;
	int** f;
};

Graph::Graph(int n) : v(n)
{
	g = (int**)calloc(n, sizeof(int));
	for (int i = 0; i < n; ++i)
		g[i] = (int*)calloc(n, sizeof(int));
	f = (int**)calloc(n, sizeof(int));
	for (int i = 0; i < n; ++i)
		f[i] = (int*)calloc(n, sizeof(int));
}

Graph::~Graph()
{
	for (int i = 0; i < v; ++i)
		free(g[i]);
	free(g);
	for (int i = 0; i < v; ++i)
		free(f[i]);
	free(f);
}

void Graph::readGraph()
{
	for (int i = 0; i < v; ++i)
		for (int j = 0; j < v; ++j)
			cin >> g[i][j];
}

int Graph::floyd(int a, int b)
{
	const int inf = 65536;
	for (int i = 0; i < v; ++i)
		for (int j = 0; j < v; ++j)
			f[i][j] = (g[i][j] || i == j) ? g[i][j] : inf;
	for (int k = 0; k < v; ++k)
	{
		for (int i = 0; i < v; ++i)
			for (int j = 0; j < v; ++j)
				f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
		// for (int i = 0; i < v; ++i)
		// {
		// 	cout << endl; 
		// 	for (int j = 0; j < v; ++j)
		// 		cout << f[i][j] << " ";
		// 	cout << endl;
		// }
	}
	// for (int i = 0; i < v; ++i)
	// {
	// 	f[a][i] = (g[a][i] || i == a) ? g[a][i] : inf;
	// 	f[i][b] = (g[i][b] || i == b) ? g[i][b] : inf;
	// }
	// for (int k = 0; k < v; ++k)
	// 	f[a][b] = min(f[a][k] + f[k][b], f[a][b]);
	return f[a][b];
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number of vertices" << endl;
	cin >> n;
	Graph graph(n);

	cout << "Enter the weights of graph in the form of array" << endl;
	graph.readGraph();

	int m;
	cout << "Enter the number of check pairs" << endl;
	cin >> m;
	while(m--)
	{
		int a, b;
		cout << "Enter the start and end vertex" << endl;
		cin >> a >> b;
		cout << "The length of the Shortest Path from "
			<< a << " to " << b << " is " << graph.floyd(a, b) << endl;
	}

	return 0;
}