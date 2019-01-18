#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
	int n, k;
	std::cin >> n >> k;

	int tmp;
	std::map<int, int> mp;
	std::vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		if (mp.find(tmp) == mp.end())
			mp[tmp] = 0;
		++mp[tmp];
	}

	int min = INT_MAX;
	for (auto it : mp)
	{
		if (ans.size() < k)
			ans.push_back(it.first);
		
	}

	return 0;
}