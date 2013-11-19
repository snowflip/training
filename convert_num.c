#include <stdio.h>
#include <stdlib.h>

int invert_num(int num)
{
	int base = 1;
	int digit = 0;
	int c[10];
	int result = 0;
	int i;
	while (num / 10 != 0) {
		c[digit++] = num % 10;
		num = num / 10;
		base *= 10;
	}
	c[digit] = num;
	
	for (i = 0; i <= digit; i++) {
		result = result + c[i] * base;
		base /= 10;
	}

	return result;
}

int main(int argc, char **argv)
{
	int a = atoi(argv[1]);
	printf("a is %d\n", a);
	int b = invert_num(a);
	printf("b is %d\n", b);

	return 0;
} 

