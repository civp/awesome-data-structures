#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	int cnt = 0;
	bool isPos = true;
	vector<int> ans;
	for (int i = 0; i < n; ++i)
		if (s[i] != t[i])
		{
			int j;
			for (j = i + 1; j < n; ++j)
				if (s[j] == t[i])
				{
					cnt += 2 * (j - i) - 1;
					break;
				}
			if (j == n || cnt > 10000)
			{
				isPos = false;
				break;
			}
			ans.push_back(i);
			ans.push_back(j);
			char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}

	if (isPos)
	{
		cout << cnt << endl;
		for (int i = 0; i < ans.size(); i += 2)
		{
			for (int j = ans[i]; j < ans[i + 1]; ++j)
				cout << j + 1 << " ";
			for (int j = ans[i + 1] - 2; j >= ans[i]; --j)
				cout << j + 1 << " ";
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}