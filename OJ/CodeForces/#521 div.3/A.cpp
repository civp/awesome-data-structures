#include <iostream>
#include <vector>
#include <string>

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long long a, b, k;
		std::cin >> a >> b >> k;
		long long ans = (k + 1) / 2 * a - (k / 2) * b;
		std::cout << ans << std::endl;
	}
	return 0;
}