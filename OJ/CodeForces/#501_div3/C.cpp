#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> dif(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		dif[i] = t1 - t2;
		sum += t2;
	}
	if (sum > m)
		cout << -1;
	else if (sum == m)
		cout << n;
	else
	{
		sort(dif.begin(), dif.end());
		bool isCom = false;
		for (int i = 0; i < n; ++i)
		{
			sum += dif[i];
			if (sum == m)
			{
				isCom = true;
				cout << n - i - 1;
				break;
			}
			if (sum > m)
			{
				isCom = true;
				cout << n - i;
				break;
			}
		}
		if (!isCom)
			cout << 0;
	}

	return 0;
}