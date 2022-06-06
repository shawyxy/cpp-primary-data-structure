#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void test1()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 7,6,5,4,3,2,1};

	for (int i = 0; i < 7; i++)
	{
		HeapPush(&hp, a[i]);
	}

	HeapPop(&hp);
	HeapPrint(&hp);
}

int main()
{
	test1();
	return 0;
}