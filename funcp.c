#include <stdio.h>

typedef int (*Cmpfunc)(int, int);

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

//int cmp(int a, int b, int (*pf)(int,int))
int cmp(int a, int b, Cmpfunc cmpfunc)
{
	return cmpfunc(a, b);
	//return (*pf)(a, b);
}

int main()
{
	//Cmpfunc min, max;
	int a = cmp(3, 5, min);
	printf("a is %d\n", a);

	return 0;
}
