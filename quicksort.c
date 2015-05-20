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
#include <sys/time.h>


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
  int n;//, a;
  int i = 0;
  int m = 0;
  char * file;
  FILE * data;
  int *A;
  struct timeval start, end;
  long elapsedTime;
//  char c;

  printf("1. 100\n2. 1000\n3. 10000\n4. 100000\n ");
  printf("Please the letter of the number of elements you wish to sort: " );
  scanf("%d", &n);
  switch(n) {
  	  case 1: file = "Data/rd100.txt";
  	  	  	  m = 100;
  	  	  	  break;
  	  case 2: file = "Data/rd1000.txt";
  	  	  	  m = 1000;
  	  	  	  break;
  	  case 3: file = "Data/rd10000.txt";
  	  	  	  m = 10000;
  	  	  	  break;
  	  case 4: file = "Data/rd100000.txt";
  	  	  	  m = 100000;
  	  	  	  break;
  	  default: printf("Please enter 1, 2, 3, or 4.");
  	  	  	  return 0;
  }

  A = (int *)malloc(sizeof(int) * m);

  data = fopen(file, "r");
  for (i = 0; fscanf (data, "%d", A + i) != EOF; i++);

  fclose(data);

  

	// printf("\n\nUnsorted array is:  ");
	// for(i = 0; i < m; ++i)
	// 	printf(" %d ", A[i]);
	gettimeofday(&start, NULL);
	quickSort( A, 0, m);
	gettimeofday(&end, NULL);
	// printf("\n\nThe sorted array is:  ");
	// for(i = 1; i < m+1; ++i)
	// 	printf(" %d ", A[i]);
	// printf(" \n");
  
  elapsedTime = (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;
  printf("\n");
  printf("\nElapsed time for sort is: ");
  printf("%ld", elapsedTime); 
  printf("%s\n", " ns");
  free(A);

}

