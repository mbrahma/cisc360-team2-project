MAKEFILE = Makefile
SOURCES = sort.c
OBJECTS = sort.o
INCLUDES = 


CC = gcc
CFLAGS = -ggdb # -O4 -g -DNDEBUG -pg
LFLAGS = -lm # -g -lm -pg

make:	$(BINARIES)
	
$(OBJECTS):     $(INCLUDES)
 
$(OBJECTS):     $(MAKEFILE)