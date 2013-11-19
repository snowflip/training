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


int main()
{
	Point p = makepoint(2, 3);
	printf("%d %d\n", p.x, p.y);

	return 0;
}
