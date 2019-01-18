#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 100;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'x')
			++cnt;
		else
			cnt = 0;

		if (cnt >= 3)
			++ans;
	}

	cout << ans << endl;
}