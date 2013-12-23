#include <stdio.h>

int bitcounts(unsigned char n)
{
    int b;
    for (b = 0; n > 0; n &= (n - 1))
	b++;
    return b;
}


void trim_single_space(char *s)
{
    int c;
    char *p, *q;

    while ((c = *s++) != '\0') {
	if (c != ' ') continue;
	if (c == ' ' && *s == ' ') {
	    for (q = s, p = s + 1; *p != '\0'; p++) 
		if (*p != ' ')
		    break;
	    while ((*q++ = *p++) != '\0')
		;
	}
    }
}

void trim_left_right(char *s)
{
    char *p, *q;

    for (q = s, p = s; *p != '\0'; p++)
	if (*p != ' ') 
	    break;
    if (p != q) {
	while (*q++ = *p++)
	    ;
    }

    for (p = s; *p != '\0'; p++)
	;
    for (--p; *p == ' '; p--)
	;
    *(++p) = '\0';
}

void trim_space(char *s)
{
    char *p, *q, *r;

    for (p = s; *p != '\0'; p++) {
	if (*p != ' ') continue;
	r = p;
	for (q = r; *q != '\0'; q++)
	    if (*q != ' ')
		break;
	if (r != q)
	    while (*r++ = *q++)
		;
    }   
}

int strindex(char *s, char *t)
{
    char *p, *q, *r;

    for (r = s; *r != '\0'; r++) {
	for (p = r, q = t; *q != '\0'; p++, q++)
	    if (*p != *q)
		break;
        if (*q == '\0') return r - s;
    }
    return -1;
}

int reverse_num(int n)
{
    int sum, sign;

    sign = 0;
    if (n < 0) {
	n = -1 * n;
	sign = 1;
    }
    sum = 0;
    do {
	sum = sum * 10 + n % 10;
    }while ((n /= 10) > 0);
    if (sign) sum = sum * -1;
    return sum;
}

unsigned char reverse_byte(unsigned char n)
{
    unsigned char m;
    int bit, shift;

    for (shift = 7, m = 0; n > 0; n >>= 1, shift--) {
      bit = n & 01;	
      m = m + (bit * (1 << shift)); 
    }
    return m;
}

int fib(n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int fib_iter(int n)
{
    int p1, p2;
    int j;
    int sum;

    if (n == 0) return 0;
    if (n == 1) return 1;
    p1 = 0;
    p2 = 1;
    for (j = 2; j <= n; j++) {
	sum = p1 + p2;
	p1 = p2;
	p2 = sum;
    }
    return sum;
}

    
void partition(int a[], int n)
{
    int i, j;
    int temp;
    
    i = 0;
    j = n - 1;

    while (i < j) {
	while (a[i] % 2 == 1) 
	    i++;
	while (a[j] % 2 == 0)
	    j--;
	if (i != j) {
	    temp = a[i];
	    a[i] = a[j];
	    a[j] = temp;
	    i++;
	    j--;
	}
    }
}

int main(int argc, char *argv[])
{
    /*
    char s[] = "abcefg";
    char d[] = "abe";
    printf("%s\n", s);
    trim_single_space(s);
    printf("%s\n", s);
    */
    /*
    int n = bitcounts(0xff);
    printf("n = %d\n", n);
    */
    //int index = fib(10000);
    //printf("%d\n", index);
    int i;
    int a[] = {8, 6, 4, 2, 9, 7, 5, 3, 1};
    partition(a, 9);
    for (i = 0; i < 9; i++)
     printf("%d\n", a[i]);	
    return 0;
}
