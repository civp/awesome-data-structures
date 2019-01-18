#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int p = 0, l = 0;
	for (auto i : s) {
		if (i == 'o')
			++p;
		else
			++l;
	}

	if (p == 0)
		cout << "YES" << endl;
	else if (l % p == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}