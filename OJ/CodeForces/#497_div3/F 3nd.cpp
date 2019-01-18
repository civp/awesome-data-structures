#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 200010;

int d[MAXN];

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int res = 0;
	int ans = 0;
	map<int, int> h;
	for (int i = 0; i < n; ++i) {
		// Maybe error in the second judgement
		// What's the default value of map?
		// Learn more about map
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