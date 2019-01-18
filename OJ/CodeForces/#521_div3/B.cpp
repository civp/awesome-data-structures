#include <iostream>
#include <vector>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n + 2, 0);
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (int i = 1; i <= n; ++i)
		if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1)
		{
			++cnt;
			a[i + 1] = 0;
		}

	std::cout << cnt;

	return 0;
}