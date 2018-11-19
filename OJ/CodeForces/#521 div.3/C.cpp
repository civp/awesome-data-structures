#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::map<int, int> mp;
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < n; ++i)
		mp[2 * a[i]] = i;

	int cnt = 0;
	std::vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		// auto it = mp.find(sum - i);
		if (mp.find(sum - a[i]) != mp.end() && mp[sum - a[i]] != i)
		{
			++cnt;
			ans.push_back(i + 1);
		}
	}

	std::cout << cnt << std::endl;
	for (int i = 0; i < cnt; ++i)
		std::cout << ans[i] << ' ';

	return 0;
}