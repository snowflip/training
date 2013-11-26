#include <stdio.h>

typedef struct point {
	int x;
	int y;
}Point;

struct rectangle {
	struct point p1;
	struct point p2;
};

struct point makepoint(x, y) {
	struct point p;
	p.x = x;
	p.y = y;
	return p;
}

char* printmonth(int n)
{
	static char *month[] = {"illegal month", "Jan", "Feb", "Mar",
				"April", "May", "June", "July", "August",
				"Sep", "Oct", "Nov", "Dem"};
	
	return month[n];
}

int main()
{
	//Point p = makepoint(2, 3);
	//printf("%d %d\n", p.x, p.y);
	char *a = printmonth(1);
	printf("a is %s\n", a);
	return 0;
}
