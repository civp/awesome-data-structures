/*
 * 10001st prime
 * Prime sieve
 */
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	const int size = 500000, max = 10001;
	bool isPrime[size];
	std::vector<int> primes;
	for (int i = 0; i < size; ++i)
		isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	for (long long i = 2; i < size; ++i)
		if (isPrime[i])
		{
			primes.push_back(i);
			for (long long j = i * i; j < size; j += i)
				isPrime[j] = false;
		}

	if (primes.size() >= max)
		std::cout << primes[max - 1] << std::endl;
	else
		std::cout << "Size is too small!" << std::endl;

	return 0;
}