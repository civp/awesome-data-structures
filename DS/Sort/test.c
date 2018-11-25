#include <stddef.h>
#include <stdio.h>
#include "sort.h"

int strictlyIncreasing(T a, T b)
{
	return b - a;
}

int strictlyDecreasing(T a, T b)
{
	return a - b;
}

void printArray(int *a, const size_t n)
{
	for (size_t i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	const size_t n = 5;
	int a[5] = {123, -213, 15543, 2142, -2342};

	insertionSort(a, a + n - 1, strictlyDecreasing);
	printArray(a, n);

	shellSort(a, a + n - 1, strictlyIncreasing);
	printArray(a, n);

	quickSort(a, a + n - 1, strictlyDecreasing);
	printArray(a, n);

	return 0;
}