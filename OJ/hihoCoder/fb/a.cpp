#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
	int N;
	std::cin >> N;

	std::vector<int> cost(N);
	std::vector<bool> hasA(N), hasB(N), hasC(N);
	int minCost[N][2][2][2];

	for (int i = 0; i < N; ++i)
		for (int a = 0; a < 2; ++a)
			for (int b = 0; b < 2; ++b)
				for (int c = 0; c < 2; ++c)
					minCost[i][a][b][c] = INT_MAX;

	for (int i = 0; i < N; ++i)
	{
		std::string attr;
		std::cin >> cost[i] >> attr;
		hasA[i] = attr.find('A') != std::string::npos;
		hasB[i] = attr.find('B') != std::string::npos;
		hasC[i] = attr.find('C') != std::string::npos;
		minCost[0][hasA[i]][hasB[i]][hasC[i]] = cost[i];
	}

	for (int i = 1; i < N; ++i)
		for (int a = 0; a < 2; ++a)
			for (int b = 0; b < 2; ++b)
				for (int c = 0; c < 2; ++c)
				{
					if (minCost[i - 1][a][b][c] != INT_MAX)
					{
						minCost[i][a][b][c] = std::min(minCost[i][a][b][c], minCost[i - 1][a][b][c]);
						minCost[i][a || hasA[i]][b || hasB[i]][c || hasC[i]] = std::min(minCost[i][a || hasA[i]][b || hasB[i]][c || hasC[i]], minCost[i - 1][a][b][c] + cost[i]);
					}
				}

	if (minCost[N - 1][1][1][1] == INT_MAX)
		std::cout << -1 << std::endl;
	else
		std::cout << minCost[N - 1][1][1][1] << std::endl;

	return 0;
}