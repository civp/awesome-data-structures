/*
 * #6 Sum square difference
 */
#include <iostream>

int main()
{
	long long sumOfSquares = 0, squareOfSum = 0;
	for (int i = 1; i <= 100; ++i)
	{
		squareOfSum += i;
		sumOfSquares += i * i;
	}
	squareOfSum *= squareOfSum;
	
	std::cout << squareOfSum - sumOfSquares << std::endl;

	return 0;
}
