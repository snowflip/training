#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

struct countnode {
	char *word;
	int count;
	struct countnode *left;
	struct countnode *right;
};

char *sdup(char *s)
{
	char *p;

	//p = (char *)malloc(sizeof(strlen(s)+1));
	//k&R code
	p = (char *)malloc(strlen(s)+1);
	if (p != NULL)
	    strcpy(p ,s);
	return p;
}

struct countnode *addtree(struct countnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = (struct countnode *)malloc(sizeof(struct countnode));
		if ((p->word = sdup(w)) == NULL) return NULL;
		p->count = 1;
		p->left = p->right = NULL;
		//return p;
	} else if ((cond = strcmp(w, p->word)) == 0) 
	     p->count++;
	else if (cond < 0) 
	     p->left = addtree(p->left, w);
	else 
	     p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct countnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s %d\n", p->word, p->count);
		treeprint(p->right);
	}
}

void releasetree(struct countnode *p)
{
	if (p != NULL) {
		releasetree(p->left);
		if (p->word != NULL) {
			free(p->word);
			p->word = NULL;
		}
		releasetree(p->right);
		free(p);
		p = NULL;
	}
}

int getword(FILE *fp, char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = fgetc(fp)))
		;
	if (c != EOF)
	    *w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
/*
	if (!isalpha(c)) {
		if (c == EOF) *w = '\0';
		else {
			*w++ = c;
			*w = '\0';
		}
		return c;
	}
	
	for (*w++ = c; --lim > 0; w++) {
*/
	for (; --lim > 0; w++) {
		if (!isalnum(*w = fgetc(fp))) {
			ungetc(*w, fp);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

int main() 
{
	char word[MAXWORD];
	struct countnode *root = NULL;
	FILE *fp = fopen("2.txt", "r");
	if (fp != NULL) {
		while (getword(fp, word, 10) != EOF) {
			if (isalpha(word[0])) {
				printf("%s\n", word);
				root = addtree(root, word);
			}
		}
		fclose(fp);
	}
	treeprint(root);
	releasetree(root);
	return 0;
}
