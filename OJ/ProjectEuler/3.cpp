/*
 * #3 Largest prime factor
 * Prime decomposition
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

int main(int argc, char const *argv[])
{
	const int maxSize = 800000;
	bool *isPrime = new bool [maxSize];
	std::vector<int> primes;
	for (int i = 0; i < maxSize; ++i)
		isPrime[i] = true;
	for (long long i = 2; i < maxSize; ++i)
		if (isPrime[i])
		{
			primes.push_back(i);
			for (long long j = i * i; j < maxSize; j += i)
				isPrime[j] = false;
		}
	delete[] isPrime;

	long long num = 600851475143, largestPrimeFactor;
	for (auto p : primes)
	{
		if (num % p == 0)
			largestPrimeFactor = p;
		while (num % p == 0)
			num /= p;
	}

	if (num != 1)
		largestPrimeFactor = num;

	std::cout << largestPrimeFactor << std::endl;

	return 0;
}