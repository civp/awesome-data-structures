#include <iostream>
#include <string>
#include <vector>

int kmp(std::string pattern, std::string text)
{
	std::vector<int> next(pattern.size() + 1); // Auxiliary next, index starts from 0
	next[0] = -1;
	int k = -1;
	for (size_t i = 0; i < pattern.size(); ++i)
	{
		while (k >= 0 && pattern[k] != pattern[i])
			k = next[k];
		next[i + 1] = ++k;
	}

	// for (auto i : next)
	// 	std::cout << i << ' ';
	// std::cout << std::endl;

	k = 0;
	int cnt = 0; // answer
	for (size_t i = 0; i < text.size(); ++i)
	{
		while (k >= 0 && pattern[k] != text[i])
			k = next[k];
		++k;
		if (k == pattern.size())
		{
			// pattern matches text[i - m + 1..i]
			++cnt;
			k = next[k];
		}
	}

	return cnt;
}

int main(int argc, char const *argv[])
{
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::string pattern, text;
		std::cin >> pattern >> text;
		std::cout << kmp(pattern, text) << std::endl;
	}

	return 0;
}