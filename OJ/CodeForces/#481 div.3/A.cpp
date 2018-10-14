#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000;

int n;
int a[MAX];
bool vis[MAX];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> res;
	int cnt = 0;
	for (int i = n - 1; i >= 0; --i)
		if (!vis[a[i]]) {
			vis[a[i]] = true;
			res.push_back(a[i]);
			++cnt;
		}
	reverse(res.begin(), res.end());

	cout << cnt << endl;
	for (int i = 0; i < cnt; ++i)
		cout << res[i] << " ";
	cout << endl;
}