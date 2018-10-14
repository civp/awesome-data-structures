#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	vector<int> a;
	int n = 0;
	char c = getchar();
	bool judge = false;
	for (int i = 0; c != '\n'; ++i)
	{
		if (c == '5' || c == '0')
			judge = true;
		a.push_back(c - '0');
		++n;
		c = getchar();
	}

	if (!judge || n == 1)
	{
		cout << -1;
		return 0;
	}

	queue<decltype(a)> q;
	q.push(a);
	int cnt = 0;
	bool flag = false;
	while(!q.empty())
	{
		++cnt;
		auto u = q.front();
		q.pop();

		if (u[0] == 0)
			continue;

		if (u[n - 2] == 0 && u[n - 1] == 0 || u[n - 2] == 2 && u[n - 1] == 5 || u[n - 2] == 5 && u[n - 1] == 0 || u[n - 2] == 7 && u[n - 1] == 5)
		{
			flag = true;
			break;
		}

		for (int i = 0; i < n - 1; ++i)
		{
			swap(u[i], u[i + 1]);
			q.push(u);
			swap(u[i], u[i + 1]);
		}
	}

	if (flag)
	{
		int step = 0;
		int sum = 1;
		for (int i = 1; sum < cnt; i *= (n - 1), sum += i)
			++step;
		cout << cnt << endl;
		cout << step;
	}
	else
		cout << -1;

	return 0;
}