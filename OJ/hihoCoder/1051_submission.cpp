#include <cstdio>

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		int mis[N];
		for (int i = 0; i < N; ++i)
			scanf("%d", &mis[i]);
		if (M >= N)
			printf("100\n");
		else
		{
			int a = mis[M] - 1;
			int b = 100 - mis[N - M - 1];
			int ans = a > b ? a : b;
			for (int i = M + 1; i < N; ++i)
			{
				int cur = mis[i] - mis[i - M - 1] - 1;
				if (cur > ans)
					ans = cur;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}