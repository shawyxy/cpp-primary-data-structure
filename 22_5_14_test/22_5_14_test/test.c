#include <stdio.h>
int Add(int x, int y)
{
	int z = x + y;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;

	int c = Add(a, b);

	printf("%d\n", c);
	return 0;
}