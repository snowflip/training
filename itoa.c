#include <stdio.h>

void itoa(int n, char *s)
{
/*
    while (n > 0) {
	*s++ = n % 10 + '0';
	n /= 10;
    }
    *s = '\0';
*/
    //k&R code
    //while body run at least once
    do {
	*s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
}

void itoa_mycode(int n, char *s)
{
    int base;
    char *p = s;

    if (n != 0) {
	if (n < 0) {
	    *p++ = '-';
	    n = -1 * n;
	}
	base = 1;
	while (base <= n)
	    base *= 10;
	base /= 10;
	
	while (n != 0) {
	    *p++ = n / base + '0';
	    n %= base;
	    base /= 10;
	}

	while (base != 0) {
	    *p++ = '0';
	    base /= 10;
	}
    } else 
	*p++ = '0';

    *p = '\0';
}

int  main() {
     char s[20];
     itoa(123, s);
     printf("%s\n", s);
     return 0;
}
