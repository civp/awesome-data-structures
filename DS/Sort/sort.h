/*
 * A library of sortings
 * Rank in efficiency
 */
#ifndef SORT_H
#define SORT_H

typedef int T; // abstract datatype
typedef int (*Compare)(T, T); // (a, b) iff Compare(a, b) > 0

// sort interval [fst, lst)
void insertionSort(T *fst, T *lst, Compare comp);
void shellSort(T *fst, T *lst, Compare comp); // hard version
void heapSort(T *fst, T *lst, Compare comp);
void mergeSort(T *fst, T *lst, Compare comp);
void quickSort(T *fst, T *lst, Compare comp);
void tableSort(T *fst, T *lst, Compare comp);
void bucketSort(T *fst, T *lst, Compare comp);

#endif