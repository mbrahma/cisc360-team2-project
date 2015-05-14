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


void printArray(int * array, int size){

  int i;
  printf("[ ");
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("]\n");
}

int findLargestNum(int * array, int size){

  int i;
  int largestNum = -1;

  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }

  return largestNum;
}

// Radix Sort
void radixSort(int * array, int size){

  printf("\n\nRunning Radix Sort on Unsorted List!\n\n");

  // Base 10 is used
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);

  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){

    printf("\tSorting: %d's place ", significantDigit);
    printArray(array, size);

    int bucket[10] = { 0 };

    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;

    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    // Use the bucket to fill a "semiSorted" array
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];


    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];

    // Move to next significant digit
    significantDigit *= 10;

    printf("\n\tBucket: ");
    printArray(bucket, 10);
  }
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

	  printf("\n\nRunning Radix Sort Example in C!\n");
	  printf("----------------------------------\n");

/*	  int size = 12;
	  int list[] = {10, 2, 303, 4021, 293, 1, 0, 429, 480, 92, 2999, 14};*/

	  printf("\nUnsorted List: ");
	  printArray(A, n);

	  radixSort(A, n);

	  printf("\nSorted List:");
	  printArray(A, n);
	  printf("\n");

	  return 0;
}

