#include <stdio.h>

#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define SQUARE(X) ((X) * (X))

#define INFINITE for(;;)

int main()
{
	int x = MAX(3, 5);
	printf("%d\n", x);
	
	x = SQUARE(x);
	printf("%d\n", x);
	
	INFINITE {
		if (x == 25) break;
	}
	return 0;
}


