CC = gcc
CFLAGS = -g -Wall -Werror -std=c99 -m64

all: radixsort mergesort quicksort 

radixsort: radixsort.c 
	$(CC) $(CFLAGS) -o radixsort radixsort.c  -lm
mergesort: mergesort.c 
	$(CC) $(CFLAGS) -o mergesort mergesort.c  -lm
quicksort: quicksort.c 
	$(CC) $(CFLAGS) -o quicksort quicksort.c  -lm
#
# Clean the src dirctory
#
clean:
	rm -rf *.o
	rm -f *.tar
	rm -f sort
