/* Sadly
 * Optimized brute force can't pass
 * Because MAX is too big
 * Dp instead
 * A typical LIS variation
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#define mem(a) (memset(a, 0, sizeof(a)))
using namespace std;

const int MAX = 200010;

int a[MAX];
int ans[MAX];
int cur[MAX];
bool tans[MAX];
bool tcur[MAX];
int res, tmp;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	// O(N^2)
	for (int i = 1; i <= n; ++i) {
		// Cut branches
		if (n - i + 1 <= res)
			break;
		if (tans[i])
			continue;
		int tmp = 0;
		cur[++tmp] = i;
		tcur[i] = true;
		int next = a[i] + 1;
		for (int j = i + 1; j <= n; ++j)
			if (a[j] == next) {
				cur[++tmp] = j;
				tcur[i] = true;
				next = a[j] + 1;
			}
		if (tmp > res) {
			res = tmp;
			for (int i = 1; i <= tmp; ++i) {
				ans[i] = cur[i];
				tans[cur[i]] = true;
			}
		}
	}
	printf("%d\n", res);
	for (int i = 1; i <= res; ++i)
		printf("%d ", ans[i]);
}