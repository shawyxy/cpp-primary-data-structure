#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void test1()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPrint(&s);

	printf("\n");

	while (!StackEmpty(&s))
	{
		printf("%d ", (StackTop(&s)));//Õ»¶¥ÔªËØ
		StackPop(&s);
	}
	printf("\n");

	StackDestroy(&s);

}

int main()
{
	test1();
	return 0;
}