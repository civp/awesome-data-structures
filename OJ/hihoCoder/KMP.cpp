#include <iostream>
#include <string>
#include <vector>

int kmp(std::string pattern, std::string text)
{
	int *next = new int[pattern.size()]; // Auxiliary next
	next[0] = -1;
	int k = -1;
	for (size_t i = 0; i <= pattern.size(); ++i)
	{
		while (k >= 0 && pattern[k + 1] != pattern[i])
			k = next[k];
		next[i] = ++k;
	}

	k = 0;
	for (size_t i = 0; i <= text.size(); ++i)
	{
		while (k >= 0 && pattern[k + 1] != text[i])
			k = next[k];
		++k;
		if (k == pattern.size())
		{
			// pattern matches text[i - m + 1..i]
			k = next[k];
		}
	}

	delete[] next;
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