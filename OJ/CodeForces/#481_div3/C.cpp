#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		long long tmp;
		cin >> tmp;
		if (i > 0)
			a[i] = tmp + a[i - 1];
		else
			a[i] = tmp;
	}

	long long b;
	int last = 0;
	for (int i = 0; i < m; ++i) {
		cin >> b;
		for (int j = last; j < n; ++j)
			if (b <= a[j]) {
				if (j != 0)
					cout << j + 1 << " " << b - a[j - 1] << endl;
				else
					cout << j + 1 << " " << b << endl;
				last = j;
				break;
			}
	}
}