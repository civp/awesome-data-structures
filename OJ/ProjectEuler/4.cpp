// #4 Largest palindrome product
#include <iostream>

int main(int argc, char const *argv[])
{
	int max = 0;
	for (int i = 100; i < 1000; ++i)
		for (int j = 100; j < 1000; ++j)
		{
			int num = i * j;
			int cur = num;
			if (cur % 10 == 0)
				continue;

			int rev = 0;
			while (cur > rev)
			{
				rev = rev * 10 + cur % 10;
				cur /= 10;
			}
			if ((cur == rev || cur == rev / 10) && num > max)
				max = num;
		}

	std::cout << max << std::endl;

	return 0;
}