OBJS = sort.o search.o string.o

all:	sort hash wordcount tree dimenarray struct search string clean

sort:	sort.o 
	gcc -g -Wall sort.o -o sort
	rm -f sort.o

hash:	hash.c
	gcc -g -Wall hash.c -o hash

wordcount:	wordcount.c
	gcc -g -Wall wordcount.c -o wordcount

tree:	tree.c
	gcc -g -Wall tree.c -o tree

dimenarray:	dimenarray.c
	gcc -g -Wall dimenarray.c -o dimenarray

struct:	struct.c
	gcc -g -Wall struct.c -o struct

search:	search.c
	gcc -g -Wall search.c -o search

string:	string.c
	gcc -g -Wall string.c -o string

clean:
	rm -f  $(OBJS)
