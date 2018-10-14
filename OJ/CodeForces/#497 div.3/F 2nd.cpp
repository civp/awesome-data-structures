/* Fuck off global variables
 * Use map instead of manual hash
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 200010;
const int MAXA = 1000 * 1000 * 100;

int d[MAXN];
// Use map instead to save space and AC :(
short h[MAXA];

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int res = 0;
	int ans = 0;
	// Avoid [[]], use more variables
	for (int i = 0; i < n; ++i) {
		if (i > 0 && h[a[i] - 1])
			d[i] = d[h[a[i] - 1] - 1] + 1;
		else
			d[i] = 1;
		h[a[i]] = i + 1;
		if (d[i] > res) {
			res = d[i];
			ans = i;
		}
	}
	printf("%d\n", res);
	for (int i = 0; i < res; ++i)
		printf("%d ", h[a[ans] - res + i + 1]);
}