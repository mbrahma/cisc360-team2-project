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
 RadixSort:
 http://austingwalters.com/radix-sort-in-c/

 RadixSortOpt:\
 http://www.programering.com/a/MDN4AjMwATk.html

 */

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
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>

#define radix 1000

const double rp[]={
  1,
  1.0/(1.0*radix),
  1.0/(1.0*radix*radix),
  1.0/(1.0*radix*radix*radix),
  1.0/(1.0*radix*radix*radix*radix)
};

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

  // Base 10 is used
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);

  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){

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

  }
}

int get_part(int n,int i)
{
  return (int)(n*rp[i])%radix;
}

void radix_sort(int* a,int n)
{
    int* bucket=(int*)malloc(sizeof(int)*n);
    int count[radix];

    for(int i=0;i<2;++i)
    {
        memset(count,0,sizeof(int)*radix);

        for(int j=0;j<n;++j)
        {
            count[get_part(a[j],i)]++;
        }

        for(int j=1;j<radix;++j)
        {
            count[j]+=count[j-1];
        }

        for(int j=n-1;j>=0;--j)
        {
            int k=get_part(a[j],i);
            bucket[count[k]-1]=a[j];
            count[k]--;
        }

        memcpy(a,bucket,sizeof(int)*n);
    }

    free(bucket);
}


/**
 *  main()
 *  The main function for input and output
 **/
int main(int argv, char** args)
{
    int n;
    int i = 0;
    int m = 0;
    char * file;
    FILE * data;
    int *A;
    struct timeval start, end;
    long elapsedTime;


    printf("1. 100\n2. 1000\n3. 10000\n4. 100000\n ");
    printf("Please the letter of the number of elements you wish to sort:\n " );
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
          default: printf("Please enter 1, 2, 3, or 4.\n");
                          return 0;
    }

    A = (int *)malloc(sizeof(int) * m);

    data = fopen(file, "r");
    for (i = 0; fscanf (data, "%d", A + i) != EOF; i++);

    fclose(data);

    printf("%s************** Result **************\n",KYEL);
/*    printf("%sThe input array is: ", KCYN);
    for (i = 0; i < m; i++) {
        printf("%d ", A[i]);
    }
*/
    printf("\n");

    gettimeofday(&start, NULL);

    radixSort(A, m);

    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;

    /* print the sorted array */
/*    printf("%sThe sorted array is: ", KGRN);
    for(i = 1; i < m+1; ++i)
                printf(" %d ", A[i]);
*/
    printf("\n");
    printf("\nElapsed time for non-optimized Radix Sort is: ");
    printf("%ld", elapsedTime);
    printf("%s\n", " ns");

    gettimeofday(&start, NULL);

    radix_sort(A, m);

    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;
    printf("\n");
    printf("\nElapsed time for optimized Radix sort is: ");
    printf("%ld", elapsedTime);
    printf("%s\n", " ns");

    free(A);

}

