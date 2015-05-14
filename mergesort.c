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

 #define KNRM  "\x1B[0m"
 #define KRED  "\x1B[31m"
 #define KGRN  "\x1B[32m"
 #define KYEL  "\x1B[33m"
 #define KBLU  "\x1B[34m"
 #define KMAG  "\x1B[35m"
 #define KCYN  "\x1B[36m"
 #define KWHT  "\x1B[37m"

#include <stdio.h>
#include <stdlib.h>

/**
 * merge()
 * Merge two sorted arrays, A with a  integers and
 * B with b integers, into a sorted array C.
 **/
void merge (int *A, int a, int *B, int b, int *C)
{
  int i,j,k;
  i = 0;
  j = 0;
  k = 0;
  while (i < a && j < b) {
    if (A[i] <= B[j]) {
	  /* copy A[i] to C[k] and move the pointer i and k forward */
	  C[k] = A[i];
	  i++;
	  k++;
    }
    else {
      /* copy B[j] to C[k] and move the pointer j and k forward */
      C[k] = B[j];
      j++;
      k++;
    }
  }
  /* move the remaining elements in A into C */
  while (i < a) {
    C[k]= A[i];
    i++;
    k++;
  }
  /* move the remaining elements in B into C */
  while (j < b)  {
    C[k]= B[j];
    j++;
    k++;
  }
}

/**
 * merge_sort()
 * Sort array A with n integers, using merge-sort algorithm.
 **/
void
merge_sort(int *A, int n)
{
  int i;
  int *A1, *A2;
  int n1, n2;

  if (n < 2)
    return;   /* the array is sorted when n=1.*/

  /* divide A into two array A1 and A2 */
  n1 = n / 2;   /* the number of elements in A1 */
  n2 = n - n1;  /* the number of elements in A2 */
  A1 = (int*)malloc(sizeof(int) * n1);
  A2 = (int*)malloc(sizeof(int) * n2);

  /* move the first n/2 elements to A1 */
  for (i =0; i < n1; i++) {
    A1[i] = A[i];
  }
  /* move the rest to A2 */
  for (i = 0; i < n2; i++) {
    A2[i] = A[i+n1];
  }
  /* recursive call */
  merge_sort(A1, n1);
  merge_sort(A2, n2);

  /* conquer */
  merge(A1, n1, A2, n2, A);
  free(A1);
  free(A2);
}


/**
 *  main()
 *  The main function for input and output
 **/
int main(int argv, char** args)
{
  int m, n, x;
  int i = 0;
  FILE data;
  char * file;
  int *A;
//  char c;

  printf("1. 100\n2. 1000\n3. 10000\n4. 100000 ", n);
  printf("Please the letter of the number of elements you wish to sort: " );
  scanf("%d", &n);
  switch(n) {
  	  case 1: file = 'rd100.txt';
  	  	  	  m = 100;
  	  break;
  	  case 2: file = 'rd1000.txt';
  	  	  	  m = 1000;
  	  break;
  	  case 3: file = 'rd10000.txt';
  	  	  	  m = 10000;
  	  break;
  	  case 4: file = 'rd100000.txt';
  	  	  	  m = 100000;
  	  break;
  	  default: "Please enter 1, 2, 3, or 4.";
  	  break;
  }
  if (file == NULL) {
	  return 0;
  }
  FILE *data = fopen(file, "r");
	   if ( data != NULL )
	   {
		    while(fscanf(file, "%d", &x) == 1 ) {
		    	A[i] = x;
		    	i++;
		    }
	   }

/*  A = (int *)malloc(sizeof(int) * n);
  printf("Please input %d integers: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &(A[i]));
  }*/

/*   print the original array
  printf("%s************** Result **************\n",KYEL);
  printf("%sThe input array is: ", KCYN);
  for (i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");*/

  /* merge sort A */
  merge_sort(A, n);

  /* print the sorted array */
  printf("%sThe sorted array is: ", KGRN);
  for (i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  free(A);

//  printf("Press ENTER to return.\n");
//  c = _getch();

  printf("%sred\n", KRED);
  printf("%sgreen\n", KGRN);
  printf("%syellow\n", KYEL);
  printf("%sblue\n", KBLU);
  printf("%smagenta\n", KMAG);
  printf("%scyan\n", KCYN);
  printf("%swhite\n", KWHT);
  printf("%snormal\n", KNRM);

}

