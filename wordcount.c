#include <ctype.h>
#include <string.h>
#include <stdio.h>

enum state {OUT = 0, IN};
enum boolean {FALSE = 0, TRUE};

void wordcount(FILE *fp)
{
	enum state st = OUT;
	int nc, nl, nw;
	int c;

	nc = nl = nw = 0;
	while ((c = fgetc(fp)) != EOF) {
/*		if (isalnum(c)) {
			nc++;
			if (st == OUT) {
				st = IN;
				nw++;
			}
		} else if (c == '\n') {
			nl++;
			st = OUT;
		} else if (c == ' ' || c == '\t') {
			st = OUT;
		}
*/
	//k&R code,nice
		if (c == '\n')
			nl++;

		if (c == ' ' || c == '\t' || c == '\n')
			st = OUT;
		else {
			nc++;
			if (st == OUT) {
				st = IN;
				nw++;
			}
		} 
	}
	printf("nw is %d, nl is %d, nc is %d\n", nw, nl, nc);
}

char *get_file_name(char *pathfile)
{
	char *p = strrchr(pathfile, '/');
	return p + 1;
}

int getwordKR(FILE *fp, char *word, int lim)
{
//
//	int c;
//	char *w = word;
//	while ((c = fgetc(fp)) == ' ' || c == '\t' || c == '\n');
//	
//	if (!isalnum(c)) {
//		if (c == EOF) {
//			*w = '\0';
//		}
//		return c;
//	} else {
//		*w++ = c;
//		while (isalnum((c = fgetc(fp))) && --lim > 0) *w++ = c;
//		*w = '\0';
//		return c;
//	}

	int c;
	char *w = word;
	while (isspace(c = fgetc(fp)) || c == '\t' || c == '\n')
		;
	
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	
	//while (--lim > 0 && isalnum(c = fgetc(fp)))
	//	*w++ = c;		
	//ungetc(c, fp);
	//*w = '\0';
	for (; --lim > 0; w++) 
		if (!isalnum(*w = fgetc(fp))) {
			ungetc(*w, fp);
			break;
		}
	*w = '\0';
	return word[0];
}

void getword(FILE *fp, char *s, int limit)
{
	int c;
	enum state st = OUT;
	int l = limit;
	char *dest = s;
	while ((c = fgetc(fp)) != EOF)
	{
		if (isalnum(c))
		{
			if (l > 0) {
				if (st == OUT) 
					st = IN;
				*dest++ = c;
				l--;
			} else 
				continue;
		} else if ((st == IN) && ((c == ' ') || (c == '\t') || (c == '\n'))) {
			*dest = '\0';
			printf("word is %s\n", s);
			l = limit;
			st = OUT;
			dest = s;
		}
	}
}

struct key {
	char *word;
	int count;
};

struct key keytab[] = {
	{"aaa", 0},
	{"bbb", 0},
	{"ccc", 0},
	{"ddd", 0}
};

#define NKEYS (sizeof(keytab) / sizeof(struct key))

int search(struct key *keytab, int n, char *s)
{
	int left, right, mid;
	int result;

	left = 0;
	right = n - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		result = strcmp(s, ((struct key *)keytab + mid)->word);
		if (result == 0) return mid;
		else if (result > 0) left = mid + 1;
		else right = mid - 1;
	}

	return -1;
}

void printkeytab(struct key *keytab, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s %d\n", ((struct key*)keytab + i)->word, ((struct key*)keytab + i)->count);
}
int main(int argc, char *argv[])
{
	FILE *fp;
	int pos;
	char a[100];
	printf("wordcount file is %s\n", get_file_name(argv[1]));
	printf("nkeys is %d\n", NKEYS);

	fp = fopen(argv[1], "r");
	if (fp != NULL) {
		//wordcount(fp);
		//getword(fp, a, 100);
		while (getwordKR(fp, a, 100) != EOF)
			if ((pos = search(keytab, NKEYS, a)) != -1)
				((struct key *)keytab + pos)->count++;
			//printf("%s\n", a);
		printkeytab(keytab, NKEYS);
		fclose(fp);
	}
	
	return 0;
}
