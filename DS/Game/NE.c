/*
 * Find Nash Equilibium
 * Trivial implementation
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	const int size = 100;
	// const int V = 30;
	FILE *fp = fopen("ball1.txt", "r");
	double g[size];
	int num[size], m = 0; // grade, #S for Tj, #T
	while (! feof(fp))
	{
		if (m > size - 1)
		{
			printf("Two Many Teachers!\n");
			break;
		}
		fscanf(fp, "%lf %d", &g[m], &num[m]);
		++m;
	}
	for (int i = 0; i < m; ++i)
		printf("%.2f %d\n", g[i], num[i]);

	int n = 0; // #S
	for (int i = 0; i < m; ++i)
		n += num[i];

	double pm[m][m][2]; // payoff matrix
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (i == j)
			{
				pm[i][j][0] = g[i] / n;
				pm[i][j][1] = g[i] * (n - 1) / n;
			}
			else
			{
				pm[i][j][0] = g[i];
				pm[i][j][1] = g[j];
			}
		}

	int res[m][m]; // results
	memset(res, 0, sizeof(int) * m * m);
	for (int i = 0; i < m; ++i)
	{
		int rowMaxPos = 0;
		for (int j = 1; j < m; ++j)
			if (pm[i][j][1] > pm[i][rowMaxPos][1])
				rowMaxPos = j;
		++res[i][rowMaxPos];
	}

	for (int j = 0; j < m; ++j)
	{
		int colMaxPos = 0;
		for (int i = 1; i < m; ++i)
			if (pm[i][j][0] > pm[colMaxPos][j][0])
				colMaxPos = i;
		++res[colMaxPos][j];
	}

	printf("NE:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			if (res[i][j] == 2)
				printf("(%d,%d)\n", i, j);
	}
	fclose(fp);

	return 0;
}