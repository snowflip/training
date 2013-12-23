#include <stdio.h>

#define IS_TAB_SPACE(a) ((a == ' ') || (a == '\t'))

void squeeze(char *s, int n)
{
    char *p, *q;

    while (*s != '\0') 
	if ((*s == n) && (*(s + 1) == n)) {
	    for (q = s + 2; *q != '\0'; q++)
		if (*q != n) break;
	    p = s + 1;
	    while ((*p++ = *q++) != '\0')
		;
	    }
	else
	    s++;
}

char *sins(char *s, char *t)
{
    char *p, *q;

    for ( ; *s != '\0'; s++) {
	for (q = s, p = t; (*q != '\0') && (*p != '\0'); p++, q++)
	    if (*p != *q) break;
	if (*p == '\0') return s;
    }

    return NULL;
}

		

int main()
{
    char a[] = "aabaa";
    char *b = sins("ab", "aabbb");
    printf("%s\n", b);

    return 0;
}
