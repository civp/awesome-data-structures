#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int res = 0;
	string ans;
	for (int i = 0; i < n - 1; ++i) {
		int cur = 0;
		for (int j = 0; j < n - 1; ++j)
			if (s[j] == s[i] && s[j + 1] == s[i + 1])
				++cur;
			if (res < cur) {
				res = cur;
				ans = string(1, s[i]) + string(1, s[i + 1]);
			}
	}

	cout << ans << endl;

	return 0;
}