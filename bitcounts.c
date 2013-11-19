#include <stdio.h>

int bitcount(unsigned x)
{
	int count = 0; 
	while (x)
	{
		if ((x & 1) == 1) count++;
		x = x >> 1;
	}
	
	return count;
}

int bitcounts(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01) 
		    b++;
	
	return b;
}

int bitcounts_b(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>=1)
		if ((x & (x - 1)) == (x - 1)) b++;
	//fast version
	/* for (b = 0; x != 0; x &= x-1) */
		/* b++; */
	return b;
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p - n + 1)) & ((1 << n) - 1);
	//K&R code nice
	//return (x >> (p+1-n) & ~(~0 << n));
}
int main() {
	//int count = bitcounts_b(6);
//	printf("count is %d\n", count);
	int a = getbits(10, 2, 2);
	printf("a is %d\n", a);

	return 0;
}
