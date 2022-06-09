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

void HeapSort(HeapDataType* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&(a[end]), &(a[0]));
		AdjustDown(a, end, 0);
		end--;
	}
}
void test2()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(a, sizeof(a) / sizeof(int));
}
int main()
{
	test2();
	//test1();
	return 0;
}