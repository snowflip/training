#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist *hashtab[HASHSIZE];


unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) 
	hashval = *s * 31 + hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
/*
	struct nlist *head = hashtab[hash(s)];
	if (head != NULL) 
		for (; head != NULL; head = head->next)
			if (strcmp(s, head->name) == 0)
				return head;
	return NULL;
*/
	/* K&R code */
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
	if (strcmp(s, np->name) == 0)
	    return np;
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
/*
	struct nlist *node;
	if ((node = lookup(name)) != NULL)
		strcpy(node->defn, defn);
	else {
		
		node = malloc(sizeof(struct nlist));
		node->name = strdup(name);
		node->defn = strdup(defn);
		node->next = hashtab[hash(name)];
		hashtab[hash(name)] = node;
	}

	return node;
*/
	/* K&R code */
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *)malloc(sizeof(struct nlist));
		if ((np == NULL) || ((np->name = strdup(name)) == NULL))
		     return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np->defn);
	if ((np->defn = strdup(defn)) == NULL)
	     return NULL;
	return np;
}
	

void freehashtab()
{
	int i;
	struct nlist *head, *node;
	for (i = 0; i < HASHSIZE; i++) {
		head = hashtab[i];		
		while (head != NULL) {
			node = head->next;
			
			if (head->name)
				free(head->name);
			if (head->defn)
				free(head->defn);
			if (head)
				free(head);
			head = node;
		}
	}
}

void inithashtab()
{
	int i;
	for (i = 0; i < HASHSIZE; i++)
		hashtab[i] = NULL;
}

int main()
{
	inithashtab();
	
	struct nlist *node;
	install("hello", "world");
	
	node = lookup("hello");
	if (node != NULL)
		printf("%s %s\n", node->name, node->defn);
	
	install("hello", "linux");
	
	node = lookup("hello");
	if (node != NULL)
		printf("%s %s\n", node->name, node->defn);

	freehashtab();	

	return 0;
}

