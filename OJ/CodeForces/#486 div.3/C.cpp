#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k;
	cin >> k;

	vector<vector<int>> v;
	for (int i = 0; i < k; ++i)
	{
		int n;
		cin >> n;

		vector<int> vt(n);
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			sum += t;
			vt[i] = t;
		}

		for (int i = 0; i < n; ++i)
		{
			vt[i] = sum - vt[i];
		}

		v.push_back(vt);
	}

	for (int i = 0; i < k; ++i)
		for (int j = i + 1; j < k; ++j)
			for (int k = 0; k < v[i].size(); ++k)
				for (int l = 0; l < v[j].size(); ++l)
				{
					if (v[i][k] == v[j][l])
					{
						cout << "YES" << endl;
						cout << i + 1 << " " << k + 1 << endl;
						cout << j + 1 << " " << l + 1 << endl;
						return 0;
					}
				}

	cout << "NO" << endl;
	return 0;
}