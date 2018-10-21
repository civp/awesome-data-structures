// Hash Table acceleration
// Pros: ez/speedup significantly
#include <iostream>
#include <string>
#include <vector>

// parameters: string s, first k characters, table size(prime)
int hash(std::string s, const size_t k, const int p)
{
	int hashVal = 0;
	const int len = s.size() > k ? s.size() : k;
	for (int i = 0; i < len; ++i)
		hashVal = (hashVal << 5) + int(s[i]);

	return hashVal % p;
}

int main(int argc, char const *argv[])
{
	std::string T, P;
	std::cin >> T >> P;

	const int K = P.size(), tbSize = 127; // K should be modified
	const int stVal = hash(P, K, tbSize); // standard hashVal
	std::vector<int> pos; // answer
	for (size_t i = 0; i < T.size(); ++i) // traverse substrings of length k
		if (hash(T.substr(i, K), K, tbSize) == stVal && T.substr(i, K) == P)
			pos.push_back(i);

	for (auto i : pos)
		std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}