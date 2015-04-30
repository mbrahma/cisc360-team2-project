CC = gcc
CFLAGS = -g -Wall -Werror -std=c99 -m64

all: sort 

sort: sort.c 
	$(CC) $(CFLAGS) -o sort sort.c  -lm
#
# Clean the src dirctory
#
clean:
	rm -rf *.o
	rm -f *.tar
	rm -f sort
