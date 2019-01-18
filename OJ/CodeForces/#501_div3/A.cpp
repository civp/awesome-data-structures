#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<bool> v(m + 1);
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;
		for (int j = l; j <= r; ++j)
			v[j] = true;
	}
	int cnt = 0;
	vector<int> res;
	for (int i = 1; i <= m; ++i)
	{
		if (!v[i])
		{
			res.push_back(i);
			++cnt;
		}

	}
	cout << cnt << endl;
	if (cnt)
		for (int pos : res)
			cout << pos << " ";
	return 0;
}