/*
 * #10 Summation of primes
 */
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	const int size = 2000000;
	std::vector<bool> isPrime(size, true);
	long long sum = 0;
	for (long long i = 2; i < size; ++i)
		if (isPrime[i])
		{
			sum += i;
			for (long long j = i * i; j < size; j += i)
				isPrime[j] = false;
		}

	std::cout << sum << std::endl;
	
	return 0;
}