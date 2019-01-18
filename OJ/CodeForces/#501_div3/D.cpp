#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long n, k, s;

void dfs(const long long pos, long long cur, long long sum, vector<int> &ans)
{
	for (int val = n - 1; val > 0; --val)
	{
		long long org = cur;
		if (cur + val <= n)
			cur += val;
		else if (cur - val >= 1)
			cur -= val;
		else
			continue;
		ans[pos] = cur;
		sum += val;
		if (sum > s)
			return;
		if (pos == k - 1 && sum == s)
			return;
		dfs(pos + 1, cur, sum, ans);
		if (pos == k - 1 && sum == s)
			return;
		sum -= val;
		cur = org;
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> k >> s;
	if (s < k || (n - 1) * k < s)
		cout << "NO";
	else
	{
		cout << "YES" << endl;
		long long sum = 0;
		vector<int> ans(k);
		dfs(0, 1, sum, ans);
		for (auto i : ans)
			cout << i << " ";
	}
	return 0;
}