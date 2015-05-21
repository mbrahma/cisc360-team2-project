/*
* Comparing sorting algorithms
*
* Mark Acosta
* Marshilla Brahma
* Sam Flomenberg
* Tongming Li
* Justin Tse
*/

// http://www.cs.cityu.edu.hk/~lwang/ccs4335/mergesort.c
// Quicksort:
// http://www.comp.dit.ie/rlawlor/Alg_DS/sorting/quickSort.c
// RadixSort:
// http://austingwalters.com/radix-sort-in-c/

/*
* Dual-pivot QuickSort 
* optimization: dual-pivot, in-place by swapping elements elements within the array. 
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


//by swapping elements within the array, we avoid the memory allocation of more arrays. 
void exchange (int input[], int a , int b){
      int temp = input[a];
      input[a] = input[b];
      input[b] = temp;
  }
 void sort(int input[], int lowIndex, int highIndex) {
      if (highIndex<=lowIndex) return;
      int pivot1=input[lowIndex];
      int pivot2=input[highIndex];
      if (pivot1>pivot2){
          exchange(input, lowIndex, highIndex);
          pivot1=input[lowIndex];
          pivot2=input[highIndex];
      }
      else if (pivot1==pivot2){
          while (pivot1==pivot2 && lowIndex<highIndex){
              lowIndex++;
              pivot1=input[lowIndex];
          }
      }
      int i=lowIndex+1;
      int lt=lowIndex+1;
      int gt=highIndex-1;
      while (i<=gt){
          if (input[i]<pivot1){
              exchange(input, i++, lt++);
          }
          else if (pivot2<input[i]){
              exchange(input, i, gt--);
          }
          else{
              i++;
          }
      }
      exchange(input, lowIndex, --lt);
      exchange(input, highIndex, ++gt);
      sort(input, lowIndex, lt-1);
      sort(input, lt+1, gt-1);
      sort(input, gt+1, highIndex);
  }
  void sort (int input[] ){
      int size = sizeof(input)-1;
      sort (input, 0, size);
  }
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
  printf("Please the letter of the number of elements you wish to sort: " );
  scanf("%d", &n);
  switch(n) {
      case 1: file = "Data/reversed100.txt";
              m = 100;
              break;
      case 2: file = "Data/reversed1000.txt";
              m = 1000;
              break;
      case 3: file = "Data/reversed10000.txt";
              m = 10000;
              break;
      case 4: file = "Data/reversed100000.txt";
              m = 100000;
              break;
      default: printf("Please enter 1, 2, 3, or 4.");
              return 0;
  }

  A = (int *)malloc(sizeof(int) * m);

  data = fopen(file, "r");
 
  for (i = 0; fscanf (data, "%d", A + i) != EOF; i++);
  fclose(data);
  gettimeofday(&start, NULL);
  sort(A,0,m);
  gettimeofday(&end, NULL);
  elapsedTime = (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;
  printf("\n");
  printf("\nElapsed time for sort is: ");
  printf("%ld", elapsedTime); 
  printf("%s\n", " ns");
  free(A);
}
