// #1037 Numerical Triangle
#include <stdio.h>

#define MAX_N 100
int maze[MAX_N][MAX_N];
// int ans[MAX_N];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
			scanf("%d", &maze[i][j]);
	for (int i = N - 2; i >= 0; --i)
		for (int j = 0; j <= i; ++j)
			maze[i][j] = max(maze[i + 1][j], maze[i + 1][j + 1]) + maze[i][j];
	printf("%d\n", maze[0][0]);
	return 0;
}