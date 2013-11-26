#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct countnode {
	char *word;
	int count;
	struct countnode *left;
	struct countnode *right;
};

char *sdup(char *s)
{
	char *n = (char *)malloc(sizeof(strlen(s) + 1));
	strcpy(n ,s);
	return n;
}

struct countnode *addtree(struct countnode *node, char *s)
{
	int cond;
	if (node == NULL) {
		node = malloc(sizeof(struct countnode));
		node->word = sdup(s);
		node->count = 1;
		return node;
	} 

	if ((cond = strcmp(s, node->word)) == 0) {
		node->count++;
	} else if (cond < 0) {
		node->left = addtree(node->left, s);
	}
	else {
		node->right = addtree(node->right, s);
	}
	
	return node;
}

void printtree(struct countnode *n)
{
	if (n != NULL) {
		printtree(n->left);
		printf("%s %d\n", n->word, n->count);
		printtree(n->right);
	}
}

void releasetree(struct countnode *n)
{
	if (n != NULL) {
		releasetree(n->left);

		if (n->word != NULL) {
			free(n->word);
			n->word = NULL;
		}

		releasetree(n->right);

		free(n);
		n = NULL;
	}
}

int getword(FILE *fp, char *word, int lim)
{
	int ch;
	char *w = word;

	while (isspace(ch = fgetc(fp)))
		;
	
	if (!isalpha(ch)) {
		if (ch == EOF) *w = '\0';
		else {
			*w++ = ch;
			*w = '\0';
		}
		return ch;
	}
	
	for (*w++ = ch; --lim > 0; w++) {
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
	char s[10];
	struct countnode *root = NULL;
	FILE *fp = fopen("2.txt", "r");
	if (fp != NULL) {
		while (getword(fp, s, 10) != EOF) {
			if (isalpha(s[0])) {
				printf("%s\n", s);
				root = addtree(root, s);
			}
		}
	}


	printtree(root);
	
	releasetree(root);

	return 0;
}
