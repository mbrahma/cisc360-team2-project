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

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int index = 0;
void swap(int a, int b){
  int temp = a;
  a = b;
  b = temp;

}
void sort (int input[] ){
      //input=shuffle(input);
      sort (input, 0, (sizeof(input)-1));
  }

void exchange (int input[], int a , int b){
      //input=shuffle(input);
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
          //sort(input, lowIndex, highIndex);
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
      sort (input, lt+1, gt-1);
      sort(input, gt+1, highIndex);
          
  }

// void quickSort_Dual(int v[],int low,int high){
//     if(low>high){
//       swap(low,high);
//     }

//     int pivotL=low;
//     int pivotR=high;
//     int tmpL=low;
//     int tmpR=high;
//     int index=low+1;
//     while(index<=tmpR){
//          if(v[index]<pivotL)swap(v[index++],v[tmpL++]);
//          else if(v[index]>pivotR)swap(v[index],v[tmpR--]);
//          else index++;
//     }

//     // int tmpLdec = tmpL--;
//     // int tmpLinc = tmpL++;
//     // int tmpRdec = tmpR--;
//     // int tmpRinc = tmpR++;
    
//     swap(v[--tmpL],v[low]);
//     swap(v[++tmpR],v[high]);
    
//     quickSort_Dual(v,low,tmpL-1);
//     quickSort_Dual(v,tmpL+1,tmpR-1);
//     quickSort_Dual(v,tmpR+1,high);
//  }

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

  printf("1. 100\n2. 1000\n3. 10000\n4. 100000\n ");
  printf("Please the letter of the number of elements you wish to sort: " );
  scanf("%d", &n);
  switch(n) {
      case 1: file = "Data/random10.txt";
              m = 100;
              break;
      case 2: file = "Data/random1000.txt";
              m = 1000;
              break;
      case 3: file = "Data/random10000.txt";
              m = 10000;
              break;
      case 4: file = "Data/random100000.txt";
              m = 100000;
              break;
      default: printf("Please enter 1, 2, 3, or 4.");
              return 0;
  }

  A = (int *)malloc(sizeof(int) * m);

  data = fopen(file, "r");
 
  for (i = 0; fscanf (data, "%d", A + i) != EOF; i++);
  fclose(data);

 

  //printf("\n\nUnsorted array is:  ");
  //for(i = 0; i < m; ++i)
  //  printf(" %d ", A[i]);
  gettimeofday(&start, NULL);
  sort(A,0,m);
  gettimeofday(&end, NULL);
  //printf("\n\nThe sorted array is:  ");
  //for(i = 1; i < m+1; ++i)
  //  printf(" %d ", A[i]);
  //printf(" \n");
  
  elapsedTime = (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;
  printf("\n");
  printf("\nElapsed time for sort is: ");
  printf("%ld", elapsedTime); 
  printf("%s\n", " ns");
  free(A);
}

// void dual_qsort(int low,int high,vector<T> v){

//     if(low>high)swap(low,high);
//     int pivotL=low;
//     int pivotR=high;
//     int tmpL=low;
//     int tmpR=high;
//     int index=low+1;
//     while(index<=tmpR){
//          if(v[index]<pivotL)swap(v[index++],v[tmpL++]);
//          else if(v[index]>pivotR)swap(v[index],v[tmpR--]);
//          else index++;
//     }
//     swap(v[--tmpL],v[low]);
//     swap(v[++tmpR],v[high]);
//     dual_qsort(low,tmpL-1,v);
//     dual_qsort(tmpL+1，tmpR-1,v);
//     dual_qsort(tmpR+1,high,v);
//  }

