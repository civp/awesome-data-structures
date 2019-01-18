#include <iostream>
#include <vector>
using namespace std;

bool vis[101];

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		if (!vis[tmp])
		{
			vis[tmp] = true;
			v.push_back(i + 1);
			++cnt;
		}
		if (cnt == k)
			break;
	}

	if (cnt == k)
	{
		cout << "YES" << endl;
		for (auto i : v)
			cout << i << " ";
	}
	else
		cout << "NO";


}