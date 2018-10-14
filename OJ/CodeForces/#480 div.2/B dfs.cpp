#include <iostream>

using namespace std;

int n, k;
int p1, p2;
bool a[100][5];
int cod[2 * 100][2];
int s[2 * 100][4];

int fact(int x) {
	int res = 1;
	for (int i = 1; i <= x; ++i)
		res *= i;
	return res;
}

int countPath(int x, int y) {
	return fact(x + y) / (fact(x) * fact(y)); 
}

void dfs(int x, int y, int cnt) {
	if (x > n - 1 || y > 3)
		return;

	a[x][y] = true;
	cod[cnt][0] = x;
	cod[cnt][1] = y;

	if (cnt == k) {
		for (int i = 1; i <= k; ++i) {
			s[i][0] = countPath(cod[i][0] - 1, cod[i][1] - 1);
			s[i][1] = countPath(n - cod[i][0], 4 - cod[i][1]);
			s[i][2] = countPath(cod[i][0] - 1, 4 - cod[i][1]);
			s[i][3] = countPath(n - cod[i][0], cod[i][1] - 1);
		}
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= k; ++j) {
				if (cod[i][0] > cod[j][0])
					continue;
				else if (cod[i][1] <= cod[j][1]) {
					if ((j - i) % 2 == 0)
						p1 -= s[i][0] * s[j][1];
					else
						p1 += s[i][0] * s[j][1];
				}
				else {
					if ((j - i) % 2 == 0)
						p2 -= s[i][2] * s[j][3];
					else
						p2 += s[i][2] * s[j][3];
				}
			}
		return;
	}

	dfs(x + 1, y, cnt + 1);
	a[x + 1][y] = false;
	if (p1 == p2)
		return;
	dfs(x, y + 1, cnt + 1);
	a[x][y + 1] = false;
	if (p1 == p2)
		return;
}

int main() {
	cin >> n >> k;
	dfs(2, 2, 1);
	// if (p1 == p2) {
	// 	cout << "YES" << endl;
		for (int i = 1; i <= 4; ++i) {
			for (int j = 1; j <= n; ++j)
				if (a[i][j])
					cout << '#';
				else
					cout << '.';
			cout << endl;
		}
	// }
	// else
	// 	cout << "NO" << endl;
}