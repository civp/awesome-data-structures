/* Sort problem
 * std::qsort sucks
 * Use std::sort instead
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 200010;

int a[MAXN];
int h[MAXN];

int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	// I don't know why, but TLE can only happen here
	// Maybe qsort sucks
	qsort(a, n, sizeof(int), compare);

	// Better solution:
	// record a[k - 1], count the numbers less than or equal a[k - 1]
	int front = a[0];
	for (int i = 1; i <= n; ++i) {
		if (a[i] != front)
			h[i] = a[i - 1];
		front = a[i];
	}
	if (k == 0) {
		if (a[0] > 1)
			printf("%d", a[0] - 1);
		else
			printf("-1");
	}
	else if(h[k])
		printf("%d", h[k]);
	else
		printf("-1");
}