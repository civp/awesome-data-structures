/*
 * #645 Every Day is a Holiday
 * 51730.681043 #1m
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	srand(time(0));
	const int D = 10000, iteration = 1000000;
	int days[D];
	double expectation = 0;
	for (int i = 0; i < iteration; ++i)
	{
		memset(days, 0, sizeof(days));
		int holiday = 0, emperor = 0;
		while(holiday != D)
		{
			int birth = rand() % D;
			++emperor;
			if (!days[birth])
			{
				days[birth] = 1;
				++holiday;
				if (days[(birth + D - 2) % D] && !days[(birth + D - 1) % D])
				{
					days[(birth + D - 1) % D] = 1;
					++holiday;
				}
				if (days[(birth + 2) % D] && !days[(birth + 1) % D])
				{
					days[(birth + 1) % D] = 1;
					++holiday;
				}
			}
		}
		expectation += emperor;
	}
	expectation /= iteration;
	printf("%f\n", expectation);

	return 0;
}