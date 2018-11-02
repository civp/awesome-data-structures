// Longest palindrome substring O(N)
#include <iostream>
#include <vector>
#include <string>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char const *argv[])
{
	int N;
	std::cin >> N;

	for (int ii = 0; ii < N; ++ii)
	{
		std::string tmp;
		std::cin >> tmp;
		std::vector<char> s(2 * tmp.size() + 1); // odd-sized s
		for (int i = 0; i < s.size(); ++i)
			s[i] = (i % 2) ? tmp[i / 2] : 0; // special character 0

		const int len = s.size();
		std::vector<int> lps(len); // lps[i]: lps centered at position i
		lps[0] = 1;
		int j = 0; // j that maximizes j + lps[j] / 2, the right boundary
		int maxlen = 1;
		for (int i = 1; i < len; ++i)
		{
			lps[i] = min(lps[2 * j - i], lps[j] - 2 * (i - j)); // update lb
			lps[i] = max(1, lps[i]); // at least one
			for (int k = lps[i] / 2 + 1; k <= min(i, len - i - 1); ++k) // expand around center
			{
				if (s[i - k] != s[i + k])
					break;
				lps[i] += 2;
			}
			j = (i + lps[i] / 2 > j + lps[j] / 2) ? i : j; // update j
			// std::cout << i << ' ' << lps[i] << ' ' << j << std::endl;
			int curlen = lps[i] / 2; // real curlen
			maxlen = max(curlen, maxlen);
		}
		std::cout << maxlen << std::endl;
	}

	return 0;
}