#include "sort.h"
#include <stdio.h>

void insertionSort(T *fst, T *lst, Compare comp)
{
	for (T *p = fst + 1; p != lst + 1; ++p)
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
			T tmp = *(fst + i); // local insertion sort, i = 1, reduced to total insertion sort
			int j;
			for (j = i; j >= inc && comp(*(fst + j - inc), tmp) < 0; j -= inc)
				*(fst + j) = *(fst + j - inc);
			*(fst + j) = tmp;
		}
}

void mergeSort(T *fst, T *lst, Compare comp)
{

}

// BUG
void quickSort(T *fst, T *lst, Compare comp)
{
	if (lst - fst <= 1)
		return;

	T *pivot = pickPivot(&fst, &lst, comp);

	T *pi = fst, *pj = lst;
	while (pi < pj)
	{
		while (comp(*(++pi), *pivot) > 0);
		while (comp(*pivot, *(--pj)) > 0);
		if (pi < pj)
			swap(pi, pj);
	}
	swap(pi, lst); // restore pivot

	quickSort(fst, pi - 1, comp);
	quickSort(pi + 1, lst, comp);
}

/*
 * parameters are passed by address
 * for pickPivot may change the pointers
 */
T *pickPivot(T **fst, T **lst, Compare comp)
{
	return median3(fst, lst, comp);
}

/*
 * return: median of left, middle, right
 * order these and hide the pivot
 */
T *median3(T **fst, T **lst, Compare comp)
{
	T *left = *fst, *right = *lst;
	T *mid = left + (right - left) / 2;

	if (comp(*left, *mid) < 0)
		swap(left, mid);
	if (comp(*left, *right) < 0)
		swap(left, right);
	if (comp(*mid, *right) < 0)
		swap(mid, right);

	swap(mid, right - 1); // hide the pivot
	*lst -= 1; // the last is sorted

	return right - 1;
}

void swap(T *a, T *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}