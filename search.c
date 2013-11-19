#include <stdio.h>

int binsearch(int x, int *v, int n)
{
	int left, right, mid;
	left = 0;
	right = n - 1;
	
	while (left <= right) {
		mid = (left + right) / 2;
		if (x == *(v + mid)) return mid;
		else if (x < *(v + mid)) right = mid - 1;
		else left = mid + 1;
	}

	return -1;
}

int main()
{
	int v[] = {2, 5, 7, 8, 9, 13, 20};
	int a = binsearch(20, v, 7);
	printf("a is %d\n", a);

	return 0;
}

