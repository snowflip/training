#include <stdio.h>

class A
{
    public:
	virtual int test();
	virtual double test2();
	int test3();
    protected:
	double test4();
    private:
	int a, b, c;
};

int main()
{
    int a = sizeof(A);
    printf("a is %d\n", a);
}
