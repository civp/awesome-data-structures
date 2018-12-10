/*
 * A library for sortings
 * Ranked in the order of complexity
 */
#ifndef SORT_H
#define SORT_H

/*
 * abstract datatype
 * support basic arithmatic and logic operations
 */
typedef int T;

/*
 * abstract compare function
 * (a, b) is sorted iff Compare(a, b) > 0
 */
typedef int (*Compare)(T, T);

/*
 * sorting functions
 * sort the interval [fst, lst] with Compare
 */
void insertionSort(T *fst, T *lst, Compare comp);

void shellSort(T *fst, T *lst, Compare comp); // hard version

void heapSort(T *fst, T *lst, Compare comp);

void mergeSort(T *fst, T *lst, Compare comp);

void quickSort(T *fst, T *lst, Compare comp); // quick sort packs
T *pickPivot(T **fst, T **lst, Compare comp); // auxiliary
T *median3(T **fst, T **lst, Compare comp);
void swap(T *a, T *b); // use xor

void tableSort(T *fst, T *lst, Compare comp);

void bucketSort(T *fst, T *lst, Compare comp);

#endif