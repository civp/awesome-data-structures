/*
 * #5 Smallest multiple
 * Find the common prime divisors from 1 to 20, multiply them
 */
#include <iostream>
#include <vector>
#include <set>

int main()
{
	long long ans = 1;
	std::vector<int> power(21, 0);
	std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
	for (int i = 2; i <= 20; ++i)
	{
		int n = i;
		std::vector<int> localPower(21, 0);
		for (auto p : primes)
		{
			while (n % p == 0)
			{
				++localPower[p];
				n /= p;
			}
		}
		for (int j = 0; j < power.size(); ++j)
			if (localPower[j] > power[j])
			{
				for (int k = 0; k < localPower[j] - power[j]; ++k)
					ans *= j;
				power[j] = localPower[j];
			}
	}
	
	std::cout << ans << std::endl;

}

