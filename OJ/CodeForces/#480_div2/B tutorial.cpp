#include <iostream>

using namespace std;

void print(int n, int k) {
	for (int j = 0; j < n; ++j) {
		if ((1 <= j && j <= k / 2) || (n - k / 2 - 1 <= j && j <= n - 2))
			cout << '#';
		else if (j == n / 2 && k % 2 == 1)
			cout << '#';
		else
			cout << '.';
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << "YES" << endl;
	for (int j = 0; j < n; ++j)
		cout << '.';
	cout << endl;
	print(n, k);
	cout << endl;
	print(n, k - n + 2);
	cout << endl;
	for (int j = 0; j < n; ++j)
		cout << '.';
	cout << endl;

	return 0;
}