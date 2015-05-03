/*
* Comparing sorting algorithms
*
* Mark Acosta
* Marshilla Brahma
* Sam Flomenberg
* Tongming Li
* Justin Tse
*/


/**
 *  Mergesort.c
 *  Sort the inpwutted integers, using merge-sort algorithm.
 **/
// http://www.cs.cityu.edu.hk/~lwang/ccs4335/mergesort.c
// Quicksort:
// http://www.comp.dit.ie/rlawlor/Alg_DS/sorting/quickSort.c
// RadixSort:
// http://austingwalters.com/radix-sort-in-c/

#include <stdio.h>
#include <stdlib.h>



int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;

   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r )
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }

}
void printArray(int * array, int size){

  int i;
  printf("[ ");
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("]\n");
}

/**
 *  main()
 *  The main function for input and output
 **/
int main(int argv, char** args)
{
	int i, n;
	int *A;

	  printf("Please input the number of elements: " );
	  scanf("%d", &n);

	  A = (int *)malloc(sizeof(int) * n);
	  printf("Please input %d integers: ", n);
	  for (i = 0; i < n; i++) {
	    scanf("%d", &(A[i]));
	  }

/*	int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};*/

	printf("\n\nUnsorted array is:  ");
	for(i = 0; i < n; ++i)
		printf(" %d ", A[i]);

	quickSort( A, 0, n);

	printf("\n\nThe sorted array is:  ");
	for(i = 0; i < n; ++i)
		printf(" %d ", A[i]);
	printf(" \n");

}

