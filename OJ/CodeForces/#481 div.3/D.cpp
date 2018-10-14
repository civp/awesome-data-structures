#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000001;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> b(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);

	int low = INF;
	if (n == 1 || n == 2)
		low = 0;
	else {
		for (int i = b[0] - 1; i <= b[0] + 1; ++i)
			for (int j = b[n - 1] - 1; j <= b[n - 1] + 1; ++j)
				if ((j - i) % (n - 1) == 0) {
					int r = (j - i) / (n - 1);
					bool flag = true;
					int cnt = 0;
					if (i != b[0])
						++cnt;
					if (j != b[n - 1])
						++cnt;
					for (int k = 1; k < n - 1; ++k) {
						int exp = i + r * k;
						if (b[k] != exp && b[k] + 1 != exp && b[k] - 1 != exp) {
							flag = false;
							break;
						}
						else if (b[k] + 1 == exp || b[k] - 1 == exp)
							++cnt;
					}
					if (flag && cnt < low)
						low = cnt;
				}
	}

	if (low != INF)
		printf("%d\n", low);
	else
		printf("-1\n");
}