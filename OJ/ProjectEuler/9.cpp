/*
 * #9 Special Pythagorean triplet
 */
#include <iostream>

int main(int argc, char const *argv[])
{
	int a, b;
	bool isFound = false;
	for (a = 1; a < 1000; ++a)
	{
		for (b = a + 1; 1000 - a - b > b; ++b)
			if (a * a + b * b == (1000 - a - b) * (1000 - a - b))
			{
				std::cout << a * b * (1000 - a - b) << std::endl;
				isFound = true;
				break;
			}
		if (isFound)
			break;
	}
	
	return 0;
}