/* 
 * #2 Even Fibonacci numbers
 * Denote even as 0, odd as 1, find the 101 loop body
 * The generation process reminds me of Gray Code, but what's the correlation?
 */
#include <iostream>

int main(int argc, char const *argv[])
{
	int a = 1, b = 1;
	int sum = 0;
	while (a <= 4e6)
	{
		if (a % 2 == 0)
			sum += a;
		int tmp = a;
		a = a + b;
		b = tmp;
	}

	std::cout << sum << std::endl;

	return 0;
}