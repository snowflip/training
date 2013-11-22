OBJS = sort.o search.o string.o

all:	sort search string clean

sort:	sort.o 
	gcc -g -Wall sort.o -o sort
	rm -f sort.o

wordcount:	wordcount.c
	gcc -g -Wall wordcount.c -o wordcount

dimenarray:	dimenarray.c
	gcc -g -Wall dimenarray.c -o dimenarray

search:	search.o
	gcc -g -Wall search.o -o search

string:string.o
	gcc -g -Wall string.o -o string

clean:
	rm -f  $(OBJS)
