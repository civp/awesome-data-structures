/* Water problem
 * Just brute force and ac
 * But I used storage to reach O(N)
 * Sad :(
 */

#include <cstdio>
#include <iostream>
using namespace std;

// Discard global variables
const int MAX = 101;
const int N = 26;
char s[MAX];
int t[N * N];
int ans[N * N];

int main() {
	int n;
	scanf("%d", &n);
	// Use string instead
	getchar();
	gets(s);
	int cnt = 0;
	// O(N), exchange time with space, but MAX is weak
	for (int i = 0; i < n - 1; ++i) {
		// Hash here to store frequency
		int x = s[i] - 'A';
		int y = s[i + 1] - 'A';
		++t[x * N + y];
		// Remember the stored position
		ans[cnt++] = x * N + y;
	}

	int idx = 0;
	for (int i = 1; i < cnt; ++i)
		if (t[ans[i]] > t[ans[idx]])
			idx = i;
	printf("%c%c", ans[idx] / N + 'A', ans[idx] % N + 'A');
}