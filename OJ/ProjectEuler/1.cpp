// Multiples of 3 and 5
#include <iostream>

int main(int argc, char const *argv[])
{
	int sum = 0;
	for (int i = 3; i < 1000; ++i)
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;

	std::cout << sum << std::endl;

	return 0;
}