#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//void test1()
//{
//	HP hp;
//	
//	int a[] = { 23,56,78,12,45,66 };
//	HeapInit(&hp);
//	for (int i = 0; i < 6; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	HeapPrint(&hp);
//}
void test2()
{
	HP hp;

	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	/*HeapPush(&hp, 10);
	HeapPrint(&hp);*/

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
}

int main()
{
	test2();
	return 0;
}