// #1038 0-1 knapsack
#include <stdio.h>
#define MAX_N 500
#define MAX_M 100001

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);
	int need[MAX_N];
	int value[MAX_N];
	for (int i = 0; i < N; ++i)
		scanf("%d %d", &need[i], &value[i]);
	int gain[MAX_M] = {0}; // The biggest gain for the first i items and total need <= j
	for (int i = 0; i < N; ++i)
		for (int j = M; j >= need[i]; --j)
			gain[j] = max(gain[j], gain[j - need[i]] + value[i]);

	printf("%d\n", gain[M]);
	return 0;
}