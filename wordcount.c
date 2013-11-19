#include <ctype.h>
#include <string.h>
#include <stdio.h>

enum state {OUT = 0, IN};

void wordcount(FILE *fp)
{
	enum state st = OUT;
	int nc, nl, nw;
	int c;

	nc = nl = nw = 0;
	while ((c = fgetc(fp)) != EOF) {
		if (isalnum(c)) {
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
	}
	printf("nw is %d, nl is %d, nc is %d\n", nw, nl, nc);
}

char *get_file_name(char *pathfile)
{
	char *p = strrchr(pathfile, '/');
	return p + 1;
}

int main(int argc, char *argv[]) 
{
	FILE *fp;
	printf("wordcount file is %s\n", get_file_name(argv[1]));
	fp = fopen(argv[1], "r");
	if (fp != NULL) {
		wordcount(fp);
		fclose(fp);
	}
	
	return 0;
}
