#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	if (k % 2 == 0) {
		cout << "YES" << endl;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < n; ++j) {
				if (0 < i && i < 3 && 0 < j && j <= k / 2)
					cout << "#";
				else
					cout << ".";
			}
			cout << endl;
		}
	}
	else if (k >= n - 2) {
		cout << "YES" << endl;
		for (int i = 0; i < 4; ++i) {
			if (i == 1) {
				cout << '.';
				for (int j = 0; j < n - 2; ++j)
					cout << "#";
				cout << '.';
			}
			else if (i == 2) {
				cout << '.';
				for (int j = 0; j < n - 3; ++j)
					if (j < k - n + 1)
						cout << '#';
					else
						cout << '.';
				if (k > n - 2)
					cout << '#';
				else
					cout << '.';
				cout << '.';
			}
			else
				for (int j = 0; j < n; ++j)
					cout << '.';
			cout << endl;
		}
	}
	else
		cout << "NO" << endl;
	return 0;
}