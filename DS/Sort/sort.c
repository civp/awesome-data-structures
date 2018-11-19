#include "sort.h"

void insertionSort(T *fst, T *lst, Compare comp)
{
	for (T *p = fst + 1; p != lst; ++p)
	{
		T tmp = *p, *q;
		for (q = p; q > fst && comp(*(q - 1), tmp) < 0; --q)
			*q = *(q - 1);
		*q = tmp;
	}
}

void shellSort(T *fst, T *lst, Compare comp)
{
	const int n = lst - fst + 1;

	int inc; // increment
	for (inc = n / 2; inc > 0; inc /= 2)
		for (int i = inc; i < n; ++i)
		{
			T tmp = *(fst + inc); // local insertion sort, i = 1, reduced to total insertion sort
			int j;
			for (j = i; j >= inc && comp(*(fst + j - inc), tmp) < 0; j -= inc)
				*(fst + j) = *(fst + j - inc);
			*(fst + j) = tmp;
		}
}