#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
void test1()
{
	ST st;
	
	STInit(&st);

	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);


	while (!isEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}
	STDestroy(&st);
}
int main()
{
	test1();
	return 0;
}